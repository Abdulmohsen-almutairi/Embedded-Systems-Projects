# Smart Door Security System

## Overview

A two-step door-access prototype that checks an authorized RFID card and then requests a numeric keypad code. An LCD provides status messages, a buzzer signals feedback, and a servo represents the door lock.

## Objectives

- Initialize the RFID reader, keypad, LCD, buzzer, and servo.
- Wait for an RFID card and compare its UID with an authorized tag.
- If the tag is accepted, request a four-digit code.
- Compare the entered code and display the result.
- Unlock the servo for a short period when both checks pass, then lock again.

## Hardware Components

- Arduino-compatible microcontroller
- MFRC522 RFID reader and RFID tag
- Analog keypad
- Servo motor
- Buzzer
- 16×2 LCD with 74HC595 interface
- EEPROM library (included in source)

## Technologies and Concepts

- RFID authentication
- Keypad input processing
- Servo control
- LCD interfacing
- Embedded access-control logic

## Repository Structure

```text
smart-door-security/
├── README.md
├── code/
│   └── main.ino
├── docs/
│   └── smart_door_security_report.pdf
└── images/
    ├── original-report-page-24.jpg
    ├── original-report-page-25.jpg
    └── original-report-page-31.jpg
```

## How to Use

1. Review the circuit diagram and component list in the report images and PDF.
2. Open `code/main.ino` in the Arduino IDE.
3. Install the required libraries listed in the source code.
4. Select the correct board and serial port, then upload the sketch to the wired board.
5. Test each sensor, output, and threshold with the hardware before relying on the results.

## Limitations and Safety

The source code shown in the coursework uses a hard-coded password and tag UID. This is a learning prototype only and must not be used as a real security system without secure credential storage, lockout/rate limiting, and tamper-resistant design.

## Documentation

The `docs/` folder contains a standalone English project report. The `images/` folder contains selected pages from the original lab report for reference.

## Academic Context

Microprocessors & Embedded Systems Lab (CEN-412), Department of Computer Engineering, University of Tabuk.
