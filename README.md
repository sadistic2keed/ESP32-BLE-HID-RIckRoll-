# 🦆 ESP32 BLE Ducky HID Device

This Arduino project implements a Bluetooth Low Energy (BLE) Human Interface Device (HID). It allows your ESP32 board to function as a Bluetooth input device.

## ✨ Features

- 📡 Bluetooth Low Energy (BLE) connectivity
- 🖥️ HID protocol implementation
- 🔋 Low power consumption
- ⚙️ Easy to customize input configurations
- 🔘 Multiple triggers (3 GPIO pins) for different payloads
- 🔌 Simple hardware trigger mechanism using jumper wires

## 🛠️ Requirements

### 📦 Hardware

- 🖥️ ESP32 Board

### 🔧 Hardware Connections

1. 🔌 Connect one jumper wire from GND pin
2. 📍 Connect other jumper wires to GPIO pins: as your requirement.
   - 🎯 Trigger 1: GPIO 16
   - 🎯 Trigger 2: GPIO 17
   - 🎯 Trigger 3: GPIO 18
3. ⚡ When you want to activate a trigger, touch both jumper wires

### 💻 Arduino IDE Setup

1. ⚙️ Open Arduino IDE Preferences
2. 🔗 Add ESP32 board URL in Additional Board Manager URLs:
   ```
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
   ```
3. 🛠️ Go to Tools → Board Manager
4. 🔍 Search for "ESP32" and install version 2.0.15

### 📚 Required Libraries

1. 📦 ESP32 BLE Keyboard Library:
   - 📥 Download from: https://github.com/T-vK/ESP32-BLE-Keyboard
   - 💻 In Arduino IDE: Sketch → Include Library → Add .ZIP Library
   - 📁 Select the downloaded library file

## 🚀 Installation

1. 📂 Clone this repository:
   ```bash
   git clone https://github.com/sadistic2keed/ESP32-BLE-HID-RIckRoll-.git
   ```
2. 📝 Open `blehid.ino` in Arduino IDE
3. 🎯 Select your board and port - ESP32-Dev Module
4. ⬆️ Upload the code to your Arduino board

---

⚠️ This project is specifically designed and tested for **Kali Linux** and **Parrot OS** only. The keyboard shortcuts and commands may not work properly on other operating system!