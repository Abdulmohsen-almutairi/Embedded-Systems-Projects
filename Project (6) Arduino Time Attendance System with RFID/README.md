# RFID Time and Attendance System

## Overview

An RFID attendance prototype that reads a tag UID, obtains the date and time from an RTC module, and sends a structured record to a computer over serial communication. The report describes storing records in Microsoft Access.

## Objectives

- Initialize SPI, RFID, RTC, and serial communication.
- Wait for a new RFID tag.
- Read the UID and current date/time.
- Format the attendance record and send it over serial.
- Use a computer-side process to store the record and apply attendance rules if implemented.

## Hardware Components

- Arduino-compatible microcontroller
- MFRC522 RFID reader and cards
- DS1307 or DS3231 RTC module (as wired/configured)
- SPI and serial connections
- Computer-side serial capture/database integration

## Technologies and Concepts

- RFID tag reading
- RTC timestamping
- SPI communication
- Serial data formatting
- Attendance data integration

## Repository Structure

```text
rfid-attendance-system/
├── README.md
├── code/
│   └── main.ino
├── docs/
│   └── rfid_attendance_system_report.pdf
└── images/
    ├── original-report-page-40.jpg
    ├── original-report-page-41.jpg
    └── original-report-page-43.jpg
```

## How to Use

1. Review the circuit diagram and component list in the report images and PDF.
2. Open `code/main.ino` in the Arduino IDE.
3. Install the required libraries listed in the source code.
4. Select the correct board and serial port, then upload the sketch to the wired board.
5. Test each sensor, output, and threshold with the hardware before relying on the results.

## Limitations and Safety

The supplied sketch sends UID, name, date, and time over serial. Database insertion and on-time/late classification require a matching computer-side integration; verify these parts before presenting them as implemented.

## Documentation

The `docs/` folder contains a standalone English project report. The `images/` folder contains selected pages from the original lab report for reference.

## Academic Context

Microprocessors & Embedded Systems Lab (CEN-412), Department of Computer Engineering, University of Tabuk.
