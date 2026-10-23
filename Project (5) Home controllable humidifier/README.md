# Automatic Home Humidifier Controller

## Overview

An Arduino-based humidity controller that reads temperature and humidity from a DHT11 sensor and compares measured humidity with a user-set target. A water-level sensor prevents operation when the reservoir is low.

## Objectives

- Read temperature, humidity, water level, and target humidity.
- If the water level is low, turn off the mist maker, fan, and indicator and display a warning.
- If water is available and humidity is below the target, turn on mist generation, fan, and LED.
- Otherwise turn those outputs off.
- Display current humidity, target humidity, temperature, and operating state.

## Hardware Components

- Arduino-compatible microcontroller
- DHT11 temperature/humidity sensor
- Water-level sensor
- Potentiometer for target humidity
- Relay and mist maker
- DC fan with L293D driver
- Status LED and 16×2 LCD

## Technologies and Concepts

- Sensor integration
- Closed-loop threshold control
- Relay and motor-driver control
- LCD status display
- Basic equipment interlocks

## Repository Structure

```text
automatic-humidifier/
├── README.md
├── code/
│   └── main.ino
├── docs/
│   └── automatic_humidifier_report.pdf
└── images/
    ├── original-report-page-33.jpg
    ├── original-report-page-34.jpg
    └── original-report-page-38.jpg
```

## How to Use

1. Review the circuit diagram and component list in the report images and PDF.
2. Open `code/main.ino` in the Arduino IDE.
3. Install the required libraries listed in the source code.
4. Select the correct board and serial port, then upload the sketch to the wired board.
5. Test each sensor, output, and threshold with the hardware before relying on the results.

## Limitations and Safety

Water and mains-powered equipment require proper electrical isolation and enclosure. The water-level threshold and relay polarity must be tested with the actual hardware.

## Documentation

The `docs/` folder contains a standalone English project report. The `images/` folder contains selected pages from the original lab report for reference.

## Academic Context

Microprocessors & Embedded Systems Lab (CEN-412), Department of Computer Engineering, University of Tabuk.
