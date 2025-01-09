#Irrigation Bot

The **Arduino-Based Irrigation Bot** is a smart system that automates plant watering. It allows the user to set a moisture level between 0 and 1000 (by increments of 10), and keeps the moisture at that level. 

Designed to accomodate to plants of any required level of soil moisture.

## Features
- **Automated Watering:** Dynamically adjusts based on real-time soil moisture readings.
- **User defined Settings:** Supports up to 101 user-defined moisture level presets.
- **User Interaction:** LCD display for easy configuration and monitoring.

The system consists of the following major components:

1. **Sensor:**
   - Soil moisture sensor to monitor water needs in real-time.
2. **Actuator:**
   - Water pump to deliver water based on sensor data.
3. **Processing Unit:**
   - Controlled by an Arduino Uno R3 programmed in C++.
4. **User Interface:**
   - LCD display to allow users to set and monitor moisture thresholds and readings.
5. **PCB:**
   - Custom PCB for cleaner design and easier integration with mechanical component.
