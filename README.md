# esp32-digital-load

Welcome to the **esp32-digital-load** project! This repository contains everything you need to build your own digital load using an ESP32 and an IRF3205 MOSFET.

## 📁 Repository Structure

- **src/**: Contains the firmware code for the ESP32.
- **hardware/**: Contains the KiCAD files and schematics for the project.

## 📝 Project Overview

This Digital Load is designed to provide a way to control a MOSFET with a PWM signal, leveraging an ESP32 microcontroller to adjust the load current using a potentiometer, with visual feedback provided by LEDs.

### 📜 Firmware (src/)

The firmware, developed using the Arduino IDE, controls the PWM signal based on the potentiometer's position. Key features include:
- **Pin Definitions**: Specifies the pins for the potentiometer, PWM output, and LEDs.
- **PWM Parameters**: Sets the PWM frequency to 50 kHz and resolution to 8 bits.
- **Setup Function**: Initializes the Serial interface, configures the LED pins, and sets up the PWM on the specified pin.
- **Main Loop**: Continuously reads the potentiometer value, converts it to a voltage, and maps this voltage to a PWM duty cycle ranging from 0 to 50% of the maximum PWM value. The duty cycle is then written to the PWM pin, and debug information is printed to the Serial Monitor.

### 🔧 Hardware (hardware/)

The hardware folder contains all the necessary KiCAD files and schematics to build the esp32-digital-load. Key components include:
- **IRF3205 MOSFET**: Capable of handling high currents with a 55V threshold and 110A current rating.
- **ESP32 Microcontroller**: Connects to the potentiometer to adjust the PWM duty cycle, providing precise control over the load.

## 🚀 Getting Started

To get started with the ESP32-DigitalLoad, follow these steps:

1. **Clone the Repository**: `git clone https://github.com/ElektorLabs/esp32-digital-load.git`
2. **Upload the Firmware**: Open the `src/` folder in the Arduino IDE and upload the firmware to your ESP32.
3. **Assemble the Hardware**: Use the KiCAD files in the `hardware/` folder to assemble your electronic load controller.
4. **Test Your Setup**: Follow the instructions in the firmware to test and calibrate your ESP32-DigitalLoad.

## 🤝 Contributing

We welcome contributions to improve this project! Feel free to submit issues or pull requests.
