# Embedded Systems Project Portfolio

This repository organizes six academic projects completed for the **Microprocessors & Embedded Systems Lab (CEN-412)** in the Department of Computer Engineering at the University of Tabuk. Each project has its own README, Arduino source file, standalone English PDF report, editable LaTeX source (.tex), and reference images from the original lab report.

## Projects

| # | Project | Main Concepts | Folder |
|---|---|---|---|
| 01 | Four-Way Traffic Light Control System | Embedded C/C++, Digital I/O, Interrupt handling | [`Project (1) Traffic Light/`](Project%20(1)%20Traffic%20Light/) |
| 02 | Ultrasonic Garage Parking Assistant | Ultrasonic distance measurement, Shift-register communication, Display multiplexing | [`Project (2) Parking Sensor for Garage Side/`](Project%20(2)%20Parking%20Sensor%20for%20Garage%20Side/) |
| 03 | Arduino Temperature Data Logger | Analog sensor reading, Thermistor resistance calculation, Beta-equation temperature conversion | [`Project (3) Arduino Temperature Data Logger/`](Project%20(3)%20Arduino%20Temperature%20Data%20Logger/) |
| 04 | Smart Door Security System | RFID authentication, Keypad input processing, Servo control | [`Project (4) Smart Home Security System/`](Project%20(4)%20Smart%20Home%20Security%20System/) |
| 05 | Automatic Home Humidifier Controller | Sensor integration, Closed-loop threshold control, Relay and motor-driver control | [`Project (5) Home controllable humidifier/`](Project%20(5)%20Home%20controllable%20humidifier/) |
| 06 | RFID Time and Attendance System | RFID tag reading, RTC timestamping, SPI communication | [`Project (6) Arduino Time Attendance System with RFID/`](Project%20(6)%20Arduino%20Time%20Attendance%20System%20with%20RFID/) |

## Repository Structure

```text
Embedded-Systems-Projects/
├── README.md
├── Project (1) Traffic Light/
├── Project (2) Parking Sensor for Garage Side/
├── Project (3) Arduino Temperature Data Logger/
├── Project (4) Smart Home Security System/
├── Project (5) Home controllable humidifier/
└──Project (6) Arduino Time Attendance System with RFID/
```

Each project folder contains its own project files, including documentation, source code, and images.

## Getting Started

1. Open the project folder you want to explore.
2. Read its README for the project overview, components, logic, and limitations.
3. Review the PDF report and reference images.
4. Open `code/main.ino` in Arduino IDE and install the libraries required by that sketch.
5. Select the appropriate Arduino board and port, then compile and test with the actual circuit.

## Important Notes

- These are educational prototypes, not certified production systems.
- Pin assignments, component models, library versions, and circuit wiring must match the actual build.
- The source files were transcribed from the supplied lab report. PDF text extraction can introduce formatting or transcription issues; review and compile each sketch before publishing or using it.
- The smart door project includes example credentials in the source and must not be used as a real access-control system without redesigning its security.
- The attendance project describes database integration, but the Arduino sketch primarily transmits records over serial; a separate computer-side integration may be required.

