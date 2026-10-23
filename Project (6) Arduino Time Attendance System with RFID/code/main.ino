#include <SPI.h>
#include <MFRC522.h>
#include <RTClib.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);
RTC_DS1307 rtc;

String employee = "Abdulmohsen";

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  rtc.begin();
}

void loop() {
 if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
   return;

    DateTime now = rtc.now();

    char dateStr[20];
    sprintf(dateStr, "%02d/%02d/%04d", now.day(), now.month(), now.year());

    char timeStr[20];
    sprintf(timeStr, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());

    String UID = "";
    for (byte i = 0; i < rfid.uid.size; i++)
     UID += String(rfid.uid.uidByte[i], HEX);
    UID.toUpperCase();

    Serial.print("UID:");
    Serial.print(UID);
    Serial.print(" | Name:");
    Serial.print(employee);
    Serial.print(" | Date:");
    Serial.print(dateStr);
    Serial.print(" | Time:");
    Serial.println(timeStr);

    delay(1000);
}
