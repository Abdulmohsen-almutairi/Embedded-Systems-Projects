# Four-Way Traffic Light Control System

## Overview

An Arduino-based four-way intersection traffic-light controller with automatic sequencing and a manual mode for operator intervention. Buttons and interrupt handling are used to switch modes and select an intersection.

## Objectives

- Initialize LED outputs and button inputs.
- Start with all intersections showing red.
- In automatic mode, sequence the active green/yellow/red signals through the four intersections.
- In manual mode, allow the operator to select/control an intersection.
- Use a button interrupt to change operating mode.

## Hardware Components

- Arduino-compatible microcontroller
- 12 traffic LEDs (red, yellow, green) across four intersections
- Mode button and manual-control button
- Status LED
- Jumper wires and breadboard

## Technologies and Concepts

- Embedded C/C++
- Digital I/O
- Interrupt handling
- Finite-state/control logic
- Hardware prototyping

## Repository Structure

```text
traffic-light-control/
├── README.md
├── code/
│   └── main.ino
├── docs/
│   └── traffic_light_control_report.pdf
└── images/
    ├── original-report-page-02.jpg
    ├── original-report-page-03.jpg
    └── original-report-page-08.jpg
```

## How to Use

1. Review the circuit diagram and component list in the report images and PDF.
2. Open `code/main.ino` in the Arduino IDE.
3. Install the required libraries listed in the source code.
4. Select the correct board and serial port, then upload the sketch to the wired board.
5. Test each sensor, output, and threshold with the hardware before relying on the results.

## Limitations and Safety

This is an educational prototype, not a safety-certified traffic controller. Real road systems require fail-safe logic, conflict monitoring, and independent validation.

## Documentation

The `docs/` folder contains a standalone English project report. The `images/` folder contains selected pages from the original lab report for reference.

## Academic Context

Microprocessors & Embedded Systems Lab (CEN-412), Department of Computer Engineering, University of Tabuk.
