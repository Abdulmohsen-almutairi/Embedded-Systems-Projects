# Embedded Systems Project Portfolio

This repository organizes six academic projects completed for the **Microprocessors & Embedded Systems Lab (CEN-412)** in the Department of Computer Engineering at the University of Tabuk. Each project has its own README, Arduino source file, standalone English PDF report, editable LaTeX source (.tex), and reference images from the original lab report.

## Projects

| # | Project | Main Concepts | Folder |
|---|---|---|---|
| 01 | Four-Way Traffic Light Control System | Embedded C/C++, Digital I/O, Interrupt handling | [`traffic-light-control/`](traffic-light-control/) |
| 02 | Ultrasonic Garage Parking Assistant | Ultrasonic distance measurement, Shift-register communication, Display multiplexing | [`garage-parking-sensor/`](garage-parking-sensor/) |
| 03 | Arduino Temperature Data Logger | Analog sensor reading, Thermistor resistance calculation, Beta-equation temperature conversion | [`temperature-data-logger/`](temperature-data-logger/) |
| 04 | Smart Door Security System | RFID authentication, Keypad input processing, Servo control | [`smart-door-security/`](smart-door-security/) |
| 05 | Automatic Home Humidifier Controller | Sensor integration, Closed-loop threshold control, Relay and motor-driver control | [`automatic-humidifier/`](automatic-humidifier/) |
| 06 | RFID Time and Attendance System | RFID tag reading, RTC timestamping, SPI communication | [`rfid-attendance-system/`](rfid-attendance-system/) |

## Repository Structure

```text
Embedded-Systems-Portfolio/
├── README.md
├── traffic-light-control/
│   ├── README.md
│   ├── code/main.ino
│   ├── docs/traffic_light_control_report.pdf
│   └── images/
├── garage-parking-sensor/
│   ├── README.md
│   ├── code/main.ino
│   ├── docs/garage_parking_sensor_report.pdf
│   └── images/
├── temperature-data-logger/
│   ├── README.md
│   ├── code/main.ino
│   ├── docs/temperature_data_logger_report.pdf
│   └── images/
├── smart-door-security/
│   ├── README.md
│   ├── code/main.ino
│   ├── docs/smart_door_security_report.pdf
│   └── images/
├── automatic-humidifier/
│   ├── README.md
│   ├── code/main.ino
│   ├── docs/automatic_humidifier_report.pdf
│   └── images/
├── rfid-attendance-system/
│   ├── README.md
│   ├── code/main.ino
│   ├── docs/rfid_attendance_system_report.pdf
│   └── images/
└── source_reference/ (optional original lab PDF)
```

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

## License

Unless a license is added, all rights remain with the respective authors. For a public portfolio, add a license only if you have permission to distribute the project materials and code.
