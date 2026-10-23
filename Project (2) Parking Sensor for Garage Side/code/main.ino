#define TRIG_PIN 12
#define ECHO_PIN 11
#define BUZZER 5

#define LED_G 2
#define LED_Y 3
#define LED_R 4

#define SER_PIN 8
#define RCLK_PIN 9
#define SRCLK_PIN 10

#define DIG1 A0
#define DIG2 A1
#define DIG3 A2
#define DIG4 A3

unsigned char seg[] =
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c
,0x39,0x5e,0x79,0x71,0x00};

long duration;
int distanceCm;

void sendData(byte data) {

    digitalWrite(RCLK_PIN, LOW);
    shiftOut(SER_PIN, SRCLK_PIN, MSBFIRST, data);
    digitalWrite(RCLK_PIN, HIGH);
}

void showDigit(char digit, char value) {

    digitalWrite(DIG1, HIGH);
    digitalWrite(DIG2, HIGH);
    digitalWrite(DIG3, HIGH);
    digitalWrite(DIG4, HIGH);

    sendData(seg[value]);

    switch (digit) {
        case 1: digitalWrite(DIG1, LOW); break;
        case 2: digitalWrite(DIG2, LOW); break;
        case 3: digitalWrite(DIG3, LOW); break;
        case 4: digitalWrite(DIG4, LOW); break;
    }

    delay(3);
}

void showNumber(int num) {
    int d1 = (num / 1000) % 10;
    int d2 = (num / 100) % 10;
    int d3 = (num / 10) % 10;
    int d4 = num % 10;

    for (int i = 0; i < 20; i++) {
        showDigit(4, d4);
        showDigit(3, d3);
        showDigit(2, d2);
        showDigit(1, d1);
    }

}

void readDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH, 30000UL);
    if (duration == 0) distanceCm = 400;
    else distanceCm = duration * 0.034 / 2;

    if (distanceCm > 400) distanceCm = 400;
}

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_Y, OUTPUT);
    pinMode(LED_R, OUTPUT);

    pinMode(SER_PIN, OUTPUT);
    pinMode(RCLK_PIN, OUTPUT);
    pinMode(SRCLK_PIN, OUTPUT);
    pinMode(DIG1, OUTPUT);
    pinMode(DIG2, OUTPUT);
    pinMode(DIG3, OUTPUT);
    pinMode(DIG4, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    readDistance();
    showNumber(distanceCm);

    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");

    if (distanceCm <= 10) {
        digitalWrite(LED_R, HIGH);
        digitalWrite(LED_Y, LOW);
        digitalWrite(LED_G, LOW);
        tone(BUZZER, 1000);
    }
    else if (distanceCm <= 30) {
        digitalWrite(LED_R, LOW);
        digitalWrite(LED_Y, HIGH);
        digitalWrite(LED_G, LOW);
        tone(BUZZER, 1000);
        delay(100);
        noTone(BUZZER);
        delay(100);
    }
    else {
        digitalWrite(LED_R, LOW);
        digitalWrite(LED_Y, LOW);
        digitalWrite(LED_G, HIGH);
        noTone(BUZZER);
    }

    delay(50);
}
