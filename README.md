# Anti-Accident Device

## Overview
The **Anti-Accident Device** is a safety system designed to prevent collisions by using an ultrasonic sensor to detect obstacles and control the movement of a vehicle. The system dynamically adjusts speed, activates warning signals, and stops the vehicle if necessary.

## Components Used
- **Arduino Uno** – Microcontroller for processing sensor data.
- **Motor Driver (Adafruit Motor Shield)** – Controls the movement of DC motors.
- **Ultrasonic Sensor (HC-SR04)** – Measures the distance to obstacles.
- **Buzzer** – Provides an audible warning.
- **LED** – Indicates proximity warnings.
- **DC Motors** – Drive the vehicle.

## Working Principle
1. The ultrasonic sensor continuously measures the distance to obstacles.
2. The system adjusts the motor speed based on the detected distance:
   - **Safe Distance (> 50 cm)**: Vehicle moves forward at normal speed.
   - **Caution (40-50 cm)**: Speed reduces slightly.
   - **Warning (30-40 cm)**: Further speed reduction, LED and buzzer activate.
   - **Critical (< 30 cm)**: Vehicle stops, LED blinks faster, and buzzer sounds continuously.
3. The buzzer and LED provide visual and auditory alerts for safety.

## Circuit Diagram
Ensure proper wiring as follows:
- **Trig Pin (A0)** → Ultrasonic sensor **Trig**
- **Echo Pin (A2)** → Ultrasonic sensor **Echo**
- **Buzzer (Pin 7)** → Arduino **Digital Pin 7**
- **LED (Pin 9)** → Arduino **Digital Pin 9**
- **Motor Shield Pins** → Connected to four DC motors

## Code Explanation
- The code initializes all components in the `setup()` function.
- In `loop()`, the ultrasonic sensor calculates distance.
- Based on the measured distance, appropriate actions are taken:
  - Motor speed is adjusted.
  - The buzzer and LED are triggered as necessary.
  - The vehicle stops in critical situations.

## Installation & Usage
1. Connect all components as per the circuit diagram.
2. Upload the provided **Arduino code** to the **Arduino Uno** using the **Arduino IDE**.
3. Power the Arduino and observe how the system responds to nearby obstacles.

## Future Improvements
- Implementing **automatic braking** using relays.
- Integrating **Bluetooth** for remote control.
- Using **AI-based obstacle detection** for better accuracy.

## Author
Ritvik Rai




