# Arduino Temperature Data Logger

## Overview

A scheduled temperature logger built with an Arduino UNO, a thermistor, and a DS3231 real-time clock. It samples temperature every 30 minutes, timestamps the reading, and outputs it over serial for capture with CoolTerm.

## Objectives

- Initialize the RTC and serial connection.
- Read the current time from the RTC.
- Take one reading at minute 00 or 30.
- Convert the thermistor analog reading to resistance and then temperature in Celsius.
- Print timestamp and temperature to the serial monitor for logging.

## Hardware Components

- Arduino UNO
- Thermistor and voltage-divider resistor
- DS3231 RTC module
- USB serial connection
- CoolTerm or another serial logging utility

## Technologies and Concepts

- Analog sensor reading
- Thermistor resistance calculation
- Beta-equation temperature conversion
- RTC integration
- Serial data logging

## Repository Structure

```text
temperature-data-logger/
├── README.md
├── code/
│   └── main.ino
├── docs/
│   └── temperature_data_logger_report.pdf
└── images/
    ├── original-report-page-19.jpg
    ├── original-report-page-20.jpg
    └── original-report-page-22.jpg
```

## How to Use

1. Review the circuit diagram and component list in the report images and PDF.
2. Open `code/main.ino` in the Arduino IDE.
3. Install the required libraries listed in the source code.
4. Select the correct board and serial port, then upload the sketch to the wired board.
5. Test each sensor, output, and threshold with the hardware before relying on the results.

## Limitations and Safety

Accuracy depends on the thermistor parameters, resistor tolerance, circuit configuration, and calibration. Verify the voltage-divider formula against the actual wiring before use.

## Documentation

The `docs/` folder contains a standalone English project report. The `images/` folder contains selected pages from the original lab report for reference.

## Academic Context

Microprocessors & Embedded Systems Lab (CEN-412), Department of Computer Engineering, University of Tabuk.
