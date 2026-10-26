# ESP32 Embedded Project — Homework 02
## Dual LED Dimmer and OLED Information Panel

**Prepared by:* Muhammad Hassan Gulzar  
**Registration:** 24-NTU-CS-FL-1068
**Course:** Embedded IoT Systems  
**Hardware:** ESP32 DevKit  
**Development Tools:** VS Code, PlatformIO, Wokwi

---

## 1. System at a Glance

This assignment involves building an LED brightness controller using an ESP32 microcontroller. Two LEDs are controlled through independent PWM signals, allowing their brightness levels to change gradually in opposite directions.

An OLED screen is included to provide visual feedback about the controller's current operation. It shows the duty-cycle percentage of each LED and the frequency assigned to its PWM channel.

The system was developed using PlatformIO, simulated in Wokwi, and tested on a physical ESP32 board.

## 2. Bill of Materials and Development Tools

### Electronic Hardware
- ESP32 DevKit board
- Red LED and blue LED
- Two 220Ω resistors
- SSD1306 OLED screen, 128 × 64 resolution
- Breadboard
- Jumper wires
- USB cable

### Programming Resources
- Visual Studio Code
- PlatformIO
- Wokwi simulator
- Git and GitHub
- Arduino framework
- Wire library
- Adafruit GFX Library
- Adafruit SSD1306 Library

## 3. GPIO Assignment and Circuit Setup

The ESP32 handles LED control and display communication through dedicated GPIO connections.

| Circuit Element | ESP32 Pin |
|---|---|
| Red LED PWM input | GPIO 18 |
| Blue LED PWM input | GPIO 19 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |
| OLED supply | 3.3V |
| Common ground | GND |

A separate 220Ω resistor is placed in series with each LED to restrict current. Both LED cathodes connect to GND.

The OLED receives power from the 3.3V output and exchanges data with the ESP32 using I²C communication.

## 4. Experiment One — Creating the Fading Effect

The first experiment focuses on changing LED brightness with the ESP32 LEDC PWM peripheral.

PWM controls the proportion of each signal cycle during which the output remains active. By varying this proportion, the perceived brightness of an LED can be adjusted.

### Channel Settings

| Configuration | Red LED | Blue LED |
|---|---:|---:|
| GPIO | 18 | 19 |
| Operating frequency | 1000 Hz | 5000 Hz |
| PWM resolution | 8-bit | 8-bit |
| Minimum duty value | 0 | 0 |
| Maximum duty value | 255 | 255 |
| Startup value | 0 | 255 |

### Brightness Transition Logic

The red LED begins at its minimum duty value, while the blue LED starts at its maximum. The program changes their PWM values in opposite directions to produce complementary fading patterns.

Each update changes the duty value by five after a 20-millisecond interval. Once an LED reaches either end of its range, its direction reverses, allowing the cycle to repeat continuously.

The duty-cycle percentage is calculated as follows:

\[
\text{Duty Cycle}=\frac{\text{PWM Value}}{255}\times100
\]

For example, a PWM value of 128 produces approximately 50.2% duty cycle.

**Experiment outcome:** Both LEDs faded in opposite directions, using their assigned frequencies of 1000 Hz and 5000 Hz. The expected behavior was observed in simulation and on the physical board.

## 5. Experiment Two — OLED Telemetry Interface

The second experiment extends the LED controller by adding an SSD1306 OLED display.

The display provides a readable summary of the two PWM channels while the brightness transitions continue running. This allows the user to observe the changing output settings without relying solely on the LEDs' appearance.

### Display Readings

The screen reports the following information:

- Red LED duty-cycle percentage
- Red LED PWM frequency
- Blue LED duty-cycle percentage
- Blue LED PWM frequency

### Illustrative Screen Layout

```text
PWM MONITOR
----------------
LED1: 25%
F: 1000 Hz

LED2: 75%
F: 5000 Hz
```

The displayed percentages above are examples only. Actual percentages change as the PWM values are updated. The frequencies remain configured at 1000 Hz for the red LED and 5000 Hz for the blue LED.

The OLED communicates with the ESP32 over I²C. The `Wire.h`, Adafruit GFX, and Adafruit SSD1306 libraries support communication and screen rendering.

**Experiment outcome:** The OLED successfully showed the required readings while both LEDs continued their fading cycles.

## 6. Verification Log

Testing was performed in two stages: virtual circuit simulation and physical hardware operation.

| Verification Point | Result |
|---|---|
| Independent LED brightness control | Successful |
| Reverse fading behavior | Successful |
| 1000 Hz red LED configuration | Verified |
| 5000 Hz blue LED configuration | Verified |
| Duty-cycle percentage updates | Verified |
| OLED frequency information | Displayed correctly |
| Simultaneous LED and OLED operation | Successful |
| Physical ESP32 implementation | Tested successfully |

The physical circuit behaved as expected and produced results consistent with the Wokwi implementation.

### Online Circuit Demonstration

[Launch the Wokwi simulation](https://wokwi.com/projects/478574157477086209)

## 7. Application Files and Their Roles

The project includes the source code, board configuration, simulator files, and supporting evidence.

| Project Item | Role |
|---|---|
| `src/main.cpp` | Implements PWM fading and OLED monitoring |
| `platformio.ini` | Defines the PlatformIO environment and dependencies |
| `diagram.json` | Describes the Wokwi circuit arrangement |
| `wokwi.toml` | Provides Wokwi simulation settings |
| `screenshots/` | Stores simulation and hardware photographs |
| `README.md` | Explains the project and its outcomes |

These files collectively describe the implementation and its development environment.

## 8. Frameworks and Supporting Libraries

The application was written in C++ using the Arduino framework for the ESP32.

| Technology | Application |
|---|---|
| Arduino framework | Core program execution and hardware control |
| `Wire.h` | I²C communication with the OLED |
| Adafruit GFX | Drawing text and graphics |
| Adafruit SSD1306 | Managing the OLED display |
| PlatformIO | Project configuration and compilation |
| Wokwi | Circuit simulation |
| Git and GitHub | Version control and project hosting |

Visual Studio Code served as the primary development editor.

## 9. Source Control and Delivery

The completed implementation was added to the existing Embedded IoT Systems coursework repository. Both experiments are maintained as part of the same project.

**Online Repository:**

[View the submitted coursework on GitHub](https://github.com/Muhammad-Ahmar-Sajjad/AHMAR-SAJJAD_24-NTU-CS-FL-1056)

### Recorded Commits

1. `task1 completed` — Added the dual-LED PWM fading implementation.
2. `complete homework` — Integrated OLED monitoring and completed the project.

The repository serves as the central location for the project source files, configuration, and documentation.

## 10. Final Remarks

The completed assignment demonstrates the use of an ESP32 to coordinate multiple PWM outputs and provide real-time feedback through an OLED interface.

The two LEDs change brightness in opposite directions, with separate PWM frequencies assigned to each channel. At the same time, the OLED reports the current duty-cycle percentages and the configured frequencies.

Testing in Wokwi and on physical hardware confirmed the expected functionality of both experiments. This work provided practical experience with PWM configuration, GPIO connections, I²C communication, and embedded-system monitoring.