# AI Smart Waste Segregation Dustbin

## Overview
This project is an AI-based Smart Waste Segregation Dustbin that automatically classifies waste into Reusable and Non-Reusable categories using an ESP32-CAM and an Edge Impulse machine learning model. Based on the prediction, an Arduino Uno controls a servo motor to direct the waste into the appropriate bin.

## Features
- AI-powered waste classification
- ESP32-CAM image capture
- Edge Impulse image classification
- Ultrasonic object detection
- Automatic servo motor control
- Real-time classification
- Low-cost embedded system

## Hardware Used
- ESP32-CAM (AI Thinker)
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- Jumper Wires
- Breadboard
- 5V Power Supply

## Software Used
- Arduino IDE
- Edge Impulse
- C++
- ESP32 Board Package

## Working
1. Ultrasonic sensor detects an object.
2. ESP32-CAM captures an image.
3. Edge Impulse classifies the waste as Reusable or Non-Reusable.
4. ESP32-CAM sends `R` or `N` to the Arduino Uno.
5. Arduino rotates the servo motor to the correct bin.
6. Servo returns to the default position after a short delay.

## Project Structure
