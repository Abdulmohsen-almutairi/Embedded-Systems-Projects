#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <EEPROM.h>
#include <LiquidCrystal_74HC595.h>

LiquidCrystal_74HC595 lcd(2, 4, 3, 1, 3, 4, 5, 6, 7);

#define KEYPAD_ANALOG_PIN A0
#define BUZZ_PIN 6
#define SERVO_PIN 8

#define RFID_RST_PIN 9
#define RFID_SS_PIN 10
MFRC522 rfid(RFID_SS_PIN, RFID_RST_PIN);

Servo doorServo;

const int PASS_LEN = 4;

const byte AUTH_TAGS[][4] = {
 {0x73, 0xBF, 0xF1, 0x0B}
};
const byte AUTH_TAG_COUNT = sizeof(AUTH_TAGS)/sizeof(AUTH_TAGS[0]);

const int KEY_VALUES[] = {
 76, 95, 135,      // 1,2,3
 80, 101,150,      // 4,5,6
 83,109,169,       // 7,8,9
 117,195,87,       // 0,#,*
 265,346,507,992 // A,B,C,D
};

const char KEYS[] = {
 '1','2','3',
 '4','5','6',
 '7','8','9',
 '0','#','*',
 'A','B','C','D'
};

#define ANALOG_TOLERANCE 8
#define NO_PRESS_VALUE 5
char getKeypadKey() {

    int v1 = analogRead(KEYPAD_ANALOG_PIN);
    if (v1 < NO_PRESS_VALUE) return '\0';

    delay(40);
    int v2 = analogRead(KEYPAD_ANALOG_PIN);

    if (abs(v1 - v2) > 8) return '\0';

    for (int i = 0; i < 16; i++) {
        if (v2 >= KEY_VALUES[i] - ANALOG_TOLERANCE &&
             v2 <= KEY_VALUES[i] + ANALOG_TOLERANCE) {

            char k = KEYS[i];

            while (analogRead(KEYPAD_ANALOG_PIN) > NO_PRESS_VALUE)
             delay(15);

            return k;
        }
    }

    return '\0';
}
void beep(unsigned long ms=120){
    digitalWrite(BUZZ_PIN,HIGH);
    delay(ms);
    digitalWrite(BUZZ_PIN,LOW);
}

void lcdCenter(const char* s, int row=0){
    int len = strlen(s);
    int pad = (16 - len)/2;
    if (pad < 0) pad=0;
    lcd.setCursor(pad, row);
    lcd.print(s);
}

void setLocked(bool locked){
    doorServo.write(locked ? 0 : 90);
}

void showMsg2(const char* l1, const char* l2, int ms=1200){
    lcd.clear();
    lcdCenter(l1,0);
    lcdCenter(l2,1);
    delay(ms);
}

bool askPassword(char* out){
    lcd.clear();
    lcdCenter("Enter Code",0);
    lcd.setCursor(0,1);
    lcd.print("> ");

    int idx=0;

    while(idx < PASS_LEN){
        char k = getKeypadKey();
        if (!k) continue;

        if (k >= '0' && k <= '9'){
            out[idx++] = k;
            lcd.print('*');
            beep(40);
        }
    }
    return true;
}

bool checkPassword(const char* c){
    const char correct[4] = {'1','2','3','4'};
    for(int i=0;i<4;i++)
        if (c[i] != correct[i]) return false;
    return true;
}

bool anyAuthorizedTagPresent(){

    if(!rfid.PICC_IsNewCardPresent()) return false;
    if(!rfid.PICC_ReadCardSerial()) return false;

    for(byte i=0;i<4;i++){
        if(rfid.uid.uidByte[i] != AUTH_TAGS[0][i])
         return false;
    }

    return true;
}

void openDoorFlow(){
    setLocked(false);
    showMsg2("Door","Opened");
    delay(5000);
    setLocked(true);
    showMsg2("Door","Closed");
}
void setup(){
    Serial.begin(115200);

    pinMode(BUZZ_PIN, OUTPUT);
    doorServo.attach(SERVO_PIN);
    setLocked(true);

    lcd.begin(16,2);
    lcdCenter("Smart Door",0);
    lcdCenter("Ready",1);

    SPI.begin();
    rfid.PCD_Init();

    delay(600);
}
void loop(){

    lcd.setCursor(0,0);
    lcd.print("Scan Your Card ");
    lcd.setCursor(0,1);
    lcd.print("           ");

    if(anyAuthorizedTagPresent()){
        beep(70);
        char pw[PASS_LEN];

        if(askPassword(pw)){
            if(checkPassword(pw)){
                showMsg2("Correct","Password");
                openDoorFlow();
            }
            else {
                showMsg2("Wrong","Password");
                beep(400);
            }
        }
    }

    delay(10);
}
