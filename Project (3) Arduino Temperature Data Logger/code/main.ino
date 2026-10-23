#include <Wire.h>
  #include "RTClib.h"

  RTC_DS3231 rtc;

  const int thermistorPin = A0;
  const float BETA = 3950;
  const float T0 = 298.15;
  const float R0 = 10000;

  bool alreadyRead = false;

  void setup() {
    Serial.begin(9600);
    rtc.begin();
    if (rtc.lostPower()) {
      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
  }

  void loop() {

    DateTime now = rtc.now();
    int minuteNow = now.minute();
    int secondNow = now.second();

    if ((minuteNow == 0 || minuteNow == 30) && !alreadyRead &&
       secondNow < 10) {
      int analogValue = analogRead(thermistorPin);
      float resistance = 10000.0 * ((1023.0 / analogValue) - 1);
      float temperatureK = 1 / (1 / T0 + (1.0 / BETA) * log(resistance / R0));
      float temperatureC = temperatureK - 273.15;

        Serial.print(now.year());
        Serial.print("/");
        Serial.print(now.month());
        Serial.print("/");
        Serial.print(now.day());
        Serial.print(" ");
        if (now.hour() < 10) Serial.print("0");
        Serial.print(now.hour());
        Serial.print(":");
        if (now.minute() < 10) Serial.print("0");
        Serial.print(now.minute());
        Serial.print(":");
        if (now.second() < 10) Serial.print("0");
        Serial.print(now.second());
        Serial.print(" - Temperature: ");
        Serial.print(temperatureC);
        Serial.println(" °C");

        alreadyRead = true;
    }

    if (minuteNow != 0 && minuteNow != 30 && alreadyRead) {
      alreadyRead = false;
    }

    delay(1000);
}
