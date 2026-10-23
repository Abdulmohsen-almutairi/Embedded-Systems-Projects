#include <SimpleDHT.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int pinDHT = 2;
SimpleDHT11 dht11;

int waterPin = A0;
int potPin = A1;

int relayPin = 6;
int mistLedPin = 13;

#define ENABLE 5
#define DIRA 3
#define DIRB 4

void setup() {
 Serial.begin(9600);

    lcd.begin(16, 2);
    lcd.print("Humidifier Ready");

    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, HIGH);
    pinMode(mistLedPin, OUTPUT);
    digitalWrite(mistLedPin, LOW);

    pinMode(ENABLE, OUTPUT);
    pinMode(DIRA, OUTPUT);
    pinMode(DIRB, OUTPUT);

    digitalWrite(DIRA, LOW);
    digitalWrite(DIRB, LOW);
    digitalWrite(ENABLE, LOW);

    delay(1500);
}

void loop() {

    // Read DHT11
    byte temperature = 0;
    byte humidityNow = 0;
    dht11.read(pinDHT, &temperature, &humidityNow, NULL);

int humiditySet = map(analogRead(potPin), 0, 1023, 30, 80);

int waterValue = analogRead(waterPin);
bool waterLow = (waterValue < 50);

if (waterLow) {
  digitalWrite(relayPin, HIGH);
  digitalWrite(mistLedPin, LOW);

    digitalWrite(ENABLE, LOW);
    digitalWrite(DIRA, LOW);
    digitalWrite(DIRB, LOW);

    lcd.clear();
    lcd.print("Water Level LOW");
    lcd.setCursor(0, 1);
    lcd.print("Fill tank!");
    delay(700);
    return;
}

lcd.clear();
lcd.print("Hum:");
lcd.print(humidityNow);
lcd.print(" Set:");
lcd.print(humiditySet);

lcd.setCursor(0, 1);
lcd.print("T:");
lcd.print(temperature);
lcd.print("C ");

if (humidityNow < humiditySet) {
  // Mist ON
  digitalWrite(relayPin, LOW);
  digitalWrite(mistLedPin, HIGH);

    digitalWrite(ENABLE, HIGH);
    digitalWrite(DIRA, LOW);
    digitalWrite(DIRB, HIGH);

 lcd.print("Mist ON");
} else {
 // Mist OFF
 digitalWrite(relayPin, HIGH);
 digitalWrite(mistLedPin, LOW);

        digitalWrite(ENABLE, LOW);
        digitalWrite(DIRA, LOW);
        digitalWrite(DIRB, LOW);

        lcd.print("Mist OFF");
    }

    delay(700);
}
