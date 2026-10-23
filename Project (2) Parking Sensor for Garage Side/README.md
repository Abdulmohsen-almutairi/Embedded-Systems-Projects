# Ultrasonic Garage Parking Assistant

## Overview

A distance-measuring assistant that uses an HC-SR04 ultrasonic sensor to estimate the distance to an object and display the result on a four-digit seven-segment display. LEDs and a buzzer provide proximity warnings.

## Objectives

- Trigger the ultrasonic sensor and measure the echo duration.
- Convert echo duration into distance in centimeters.
- Split the distance into digits and multiplex the display.
- Show green for a safe distance, yellow with intermittent beeps for warning, and red with a continuous tone for danger.

## Hardware Components

- Arduino-compatible microcontroller
- HC-SR04 ultrasonic sensor
- Four-digit seven-segment display
- 74HC595 shift register
- Green, yellow, and red LEDs
- Buzzer

## Technologies and Concepts

- Ultrasonic distance measurement
- Shift-register communication
- Display multiplexing
- Threshold-based alerts
- Embedded C/C++

## Repository Structure

```text
garage-parking-sensor/
├── README.md
├── code/
│   └── main.ino
├── docs/
│   └── garage_parking_sensor_report.pdf
└── images/
    ├── original-report-page-11.jpg
    ├── original-report-page-12.jpg
    └── original-report-page-16.jpg
```

## How to Use

1. Review the circuit diagram and component list in the report images and PDF.
2. Open `code/main.ino` in the Arduino IDE.
3. Install the required libraries listed in the source code.
4. Select the correct board and serial port, then upload the sketch to the wired board.
5. Test each sensor, output, and threshold with the hardware before relying on the results.

## Limitations and Safety

Thresholds are configured for a prototype and should be calibrated for the sensor, enclosure, and installation environment.

## Documentation

The `docs/` folder contains a standalone English project report. The `images/` folder contains selected pages from the original lab report for reference.

## Academic Context

Microprocessors & Embedded Systems Lab (CEN-412), Department of Computer Engineering, University of Tabuk.
