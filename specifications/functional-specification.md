# Functional Specifications

## Table of Contents

<details>
<summary>Table of content</summary>

- [Functional Specifications](#functional-specifications)
  - [Table of Contents](#table-of-contents)
  - [1. Introduction](#1-introduction)
    - [1.1 Overview](#11-overview)
    - [1.2 Purpose](#12-purpose)
    - [1.3 Personas](#13-personas)
    - [1.4 Use cases](#14-use-cases)
  - [2. How SportShield works](#2-how-sportshield-works)
  - [3. Functionalities](#3-functionalities)
    - [3.1 Battery management](#31-battery-management)
    - [3.2 Motion detection](#32-motion-detection)
    - [3.3 Unlock](#33-unlock)
    - [3.4 Alarm](#34-alarm)
    - [3.5 Notifications](#35-notifications)
    - [3.6 GPS positioning](#36-gps-positioning)
    - [3.7 NFC](#37-nfc)
    - [3.8 Alarm management](#38-alarm-management)
    - [3.9 Security](#39-security)
  - [4. Risks and assumptions](#4-risks-and-assumptions)
    - [4.1 Risks](#41-risks)
    - [4.2 Budget consideration](#42-budget-consideration)
  - [Glossary](#glossary)
  
</details>

## 1. Introduction

This document describes the functional specifications of SportShield. The team is composed of:

| Name | Role |
| ---- | ---- |
| Manech Laguens | Project Manager |
| Malo Archimbaud | Program Manager |
| Mattéo Lefin | Technical Lead |
| Léo Chartier | Software Engineer |
| Mathis Kakal | QA |
| Laurent Bouquin | Technical Writer |

### 1.1 Overview

SportShield is a device that is designed to prevent ski equipment from being stolen. It is a small device that can be attached to the ski equipment and can be controlled using a mobile application. The device is designed to be small and lightweight so that it can be easily attached to the ski equipment without adding any extra weight to the equipment. The device is also designed to be durable and weatherproof so that it can withstand the harsh weather conditions that are common in ski resorts.

### 1.2 Purpose

We have been entrusted with this project by Coris Innovation.
The purpose of our team is to improve the existing solution and to add new functionalities to the device. The existing solution has some limitations that need to be addressed, like the battery life of the device. The full solution is also composed of a mobile application and a server. The mobile application and the server are outside the scope of our team. Our team is only responsible for the improvement of the device.

### 1.3 Personas

The following personas are the main users of the SportShield:

- **Ski equipment owner**: The ski equipment owner is the primary target of SportShield. The owner would like to take breaks without having to worry about the safety of his equipment. He would also like to be notified if the device detects any motion.

- **Ski equipment renter**: The ski equipment renter is another target of SportShield. The renter would like to be able to rent the equipment without having to worry about the safety of the equipment, to avoid paying the deposit. He would also like to be notified if the device detects any motion.

### 1.4 Use cases

- **Locking skis**: A user wants to stop for a break at a restaurant. He locks his skis with SportShield by wrapping the cable around the skis and locking it. The user then goes to the restaurant. The device will go into sleep mode and emit sounds only if a motion is detected. After his meal, the user unlocks the skis using the mobile app and the Bluetooth connection on the device. The user then goes back to the slopes.
- **Retrieving skis**: A user has lost his skis. He uses the mobile app to locate the skis, thanks to the device sending the GPS coordinates. The user then goes to the location and can retrieve his skis

## 2. How SportShield works

As of now, the device is equipped with a battery, a motion sensor, a buzzer, a Bluetooth module, a GNSS module, an electromagnet and a GMS module. The device is also equipped with a cable that can be wrapped around the ski equipment to lock it.
The device has two modes of operation:

- **Sleep mode**: In this mode, the device is in a low-power state to save battery. The device sends GPS and battery information every 15 minutes, and this is the only time the device is active. The device enters Active mode if a motion is detected.
- **Active mode**: The device awakens when a motion is detected. It goes back into Sleep mode after 5 minutes of inactivity.

To unlock the device, the user has to use the mobile application, which contacts the device via Bluetooth.
The device detects two types of motion, normal and strong shock. Depending on the type of shock, the device produces either 3 light beeps or 5 long beeps. The device sends a notification to the mobile app only if a strong shock is detected.

## 3. Functionalities

The following functionalities are what our team is responsible for. The functionalities are ordered by priority

### 3.1 Battery management

The primary goal of the solution is to improve the battery life of the device. As of now, the battery can only last for three days, at a rate of 2 hours a day. Our goal is to increase the battery life to at least 7 days at a rate of 6 hours a day.
The device is equipped with a battery that can be recharged via a USB-C cable. A notification should be sent to the users when the battery reaches 25%, 20%, 15%, 10% and 5% of its capacity. As soon as the user receives one of these notifications, he would have to unlock the device to prevent the device from staying in lock mode. If the battery reaches 0%, the device will be locked and the user will have to recharge it to unlock it.
To ensure that the battery can last long enough, the battery should never be charged over 80% and should never be discharged under 20%.

### 3.2 Motion detection

The device is equipped with a motion sensor that can detect translations and rotation around three axes. This feature is the most critical feature of the device. Our goal is to ensure that the device can detect any motion, whether it is a linear movement or a rotation. Two types of shocks have to be detected:

- **Shocks**: In this case, the device should only produce a small sound
- **Strong shocks**: In this case, the device should produce a loud sound and send a notification to the mobile application

The shock detection should be accurate enough to not be activated by the harsh weather conditions that can occur in mountainous conditions, but only by a real attempt to steal the equipment. The normal shock produces a sound that prevents the thief from continuing, and the strong shock produces a louder sound and sends a notification to the user to alert him of the situation.

### 3.3 Unlock

The device can be locked by a cable that can be wrapped around ski equipment. Our goal is to ensure that the device can be unlocked at any time using the mobile application. This cable is locked thanks to the electromagnet. When the user asks for the cable to unlock, the electromagnet should be on only for 2 seconds. This short amount of time is enough to pull the cable out and it also saves battery.

### 3.4 Alarm

The device is equipped with a buzzer that can produce sound. The device should only produce sound when a motion is detected. Our goal is to ensure that the alarm can be heard and that the device can produce different kinds of alarms depending on the situation.
The device should produce 3 light beeps when a normal shock is detected, and 5 long beeps when a strong shock is detected. The device produces the sound thanks to the buzzer. The buzzer can output a sound up to 100 dB.

### 3.5 Notifications

The device should be able to send notifications to the mobile application when a motion is detected. The notification should be sent within 5 seconds of the strong shock being detected.
These are the types of notifications:

- **Battery notifications**: The device should send a notification to the mobile application when the battery reaches 25%, 20%, 15%, 10% and 5% of its capacity
- **Motion notifications**: The device should send a notification to the mobile application when a strong shock is detected

### 3.6 GPS positioning

The device should be able to send its position to the mobile application. Our goal is to ensure that the device can send its position at any time.
To communicate the GPS position, the device uses a GNSS module and a GSM module. The current GSM module only supports 2G networks. 2G networks are being phased out in some countries, so the GSM is only temporary. For the final product, at least a 3G module should be considered.
The GPS coordinates should be sent to the server every 15 minutes and when a strong shock is detected in this format:
  
  ```json
  {
    "latitude": 48.8584,
    "longitude": 2.2945
  }
  ```

### 3.7 NFC

The device should be able to communicate with the mobile application using NFC. Our goal is to add this NFC feature to the device.
The NFC feature will ease the use of the device by the user. As of now, the user has to open the mobile application and unlock the device using the mobile application. With the NFC feature, the user will only have to tap the device with the mobile application open to unlock it.

### 3.8 Alarm management

The user should be able to stop the alarm before the end of a cycle. Our goal is to add this feature to the device. The user would be able to stop the alarm in case of a false alarm.
Also, the device has to be able to send the GPS coordinates or notification while the alarm is on. Both should be executed at the same time. This will allow the user to be notified immediately in the case of a theft and to locate the device at the same time.

### 3.9 Security

The device should be secure enough to prevent malicious people from unlocking the device. Our goal is to ensure that the device is secure enough to prevent any unauthorized access. For example, extra layers of authentication could be added to the device.

- **Bluetooth**: We need to ensure that only the phone that is paired with the device can unlock it. To achieve this, we will check if the right password has been sent to the device. The locking and unlocking should happen if and only if the password is the correct one.
- **NFC**: The NFC feature should be secure enough to prevent any unauthorized access. The NFC feature should only work with the mobile application that is paired with the device.

## 4. Risks and assumptions

### 4.1 Risks

| Risk | Impact | Mitigation |
| ---- | ------ | ---------- |
| Battery Lifetime | High | To ensure that the battery lasts long enough, tests in real conditions are being envisaged |
| Privacy | Moderate | Malicious people could try to unlock the device. To ensure that it is not possible, extra layers of security will be added |

### 4.2 Budget consideration

As the device is already provided to us with some components, there should not be any expenses for the project. However, more components could be needed to ensure the functionalities of the device. We reserve the right to recommend specific components if we feel it is necessary.

## Glossary

- **Coris Innovation**: Coris Innovation is a company based in France and Switzerland that focuses on system engineering and process engineering. For more information, visit [Coris Innovation](https://www.corisinnovation.com/coris-innovation).
- **Mountainous condition**: Mountainous condition refers to the weather conditions in mountainous areas. This includes snow, wind and low temperatures.
- **GNSS**: Global Navigation Satellite System. It is the standard generic term for satellite navigation systems that provide autonomous geo-spatial positioning with global coverage.
- **GSM**: Global System for Mobile Communications. It is a standard developed by the European Telecommunications Standards Institute to describe the protocols for second-generation digital cellular networks used by mobile devices such as mobile phones and tablets.
- **NFC**: Near Field Communication. It is a set of communication protocols that enable two electronic devices, one of which is usually a portable device such as a smartphone, to establish communication by bringing them within 4 cm of each other.
