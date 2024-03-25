# <u>Technical Specification</u>

---

## Version

|Version|Reviewver|Date|modification description|
|-------|---------|----|------------------------|
|   1   |Mattéo LEFIN| 14/03/2024 | Added Table of content and introduction. Added Project goals and scopes|
|2|Mattéo LEFIN| 15/03/2024|Finish Project Organisation|
|3|Mattéo LEFIN|21/03/2024|Added an hardware description, risks, project scope and started technical specification. |
|4|Mattéo LEFIN|25/03/2024|finish technical specification and add images|
---

<details open>

<summary>Table of content</summary>

## Table of contents:

- [***I. Introduction***](#i-introduction)
  - [1. Definition of a technical specification](#1-definition-of-a-technical-specification)
  - [2. Project Overview](#2-Project-Overview)
  - [3. Functional specification](#3-functional-specification)
  - [4. Glossary](#4-glossary)
- [***II. Project goals and scopes***](#ii-project-goals-and-scopes)
  - [1. Objectives](#1-objectives)
  - [2. Out of scope](#2-out-of-scope)
- [***III. Project organisation***](#iii-project-organisation)
  - [1. Work environnement](#1-work-environnement)
  - [2. Naming convention](#2-naming-convention)
  - [3. File list](#3-file-list)
  - [4. File sorting](#4-file-sorting)
- [***IV. Project risks***](#iv-project-risks)
  - [1. Communication risks](#1-communication-risks)
  - [2. Potential risks](#2-potential-risks)
  - [3. Dealing with risks](#3-dealing-with-risks)
- ***V Technical specifications***
  - [1. Upgrading battery](#1-upgrading-battery)
  - [2. Bluetooth communication](#2-bluetooth-communication)
  - [3. NFC communication](#3-nfc-communication)
  - [4. Sensor](#4-sensor)
  - [5. Electromagnet](#5-electromagnet)
  - [6. Test Plan](#6-test-plan)
- ***VI***
- ***Document approval***

(*For a better reading experience, a leaflet has been placed in each part of the document so you can close them when you are finished*)
</details>

---

<details Open>

<summary>Introduction</summary>

## I. Introduction

### 1. Definition of a technical specification

The objective of the Technical Specifications is to translate the Functional Requirements, which delineate the features, scope, and objectives of the project. This involves breaking down each requirement into explicit instructions with utmost clarity. The purpose is to provide precise guidance to both the development and quality assurance teams, ensuring the successful accomplishment of their mission.

### 2. Project Overview

This Project has for purpose of creating a security system for sports equipment such as snowboards and surfboards using an alarm system similar to car antithief protection, controlled with the owner's phone using an NFC system. 
Our part in this project is mainly maintenance of the battery and making the system work with an NFC system.

### 3. Functional specification

This document is a more detailed version of the functional specification, adding more explanations about our project! You can access this document right [here](https://github.com/algosup/2023-2024-project-4-sportshield-team-7/blob/main/specifications/functional_specification.md).
### 4. Glossary

|Word|Definition|
|----|----------|
| NFC system   |    NFC or Near Field Communication is a communication system with a high frequency but a short range, it's comonly used for contactless system like train contactless train cards    |
|GPS| GPS or Global Positioning System is a device that allow the user locate himself, a place or an object by satellite|

</details>

---

<details open>

<summary>project goals and scopes</summary>

## II. Project goals and scopes

### 1. Objectives

The Objective of our participation in this project is to develop the software so it will detect unusual movement when the device is activated.
we also have to find a way to make the battery last as much as possible and make the program compatible with the [**NFC system**](#3-glossary).

### 2. Out of scope

The method used to update the software is out of the scope of what our team is responsible for.
The mobile application and the server are out of the scope of what our team is responsible for.
The hardware security and integrity are out of the scope of what our team is responsible for.
The API to send and receive notifications is out of the scope of what our team is responsible for.
The hardware design is out of the scope of what our team is responsible for.

</details>

---

<details open>

<summary>Project organisation</summary>

## III. Project organisation

### 1. Work environnement

- Operating System: We are using Lenovo Thinkbook for Windows and we are using a Macbook Air for the IOS system.

- For programming, we are developing C++/C using the Arduino IDE. 

- We are using imposed libraries for C++.


|Piece name|description|Image|
|----------|-----------|-----|
|Xiao BLE Sense nrf52840|Microcontroller used for bluetooth applications|![Image of a Xiao BLE Sense nrf52840](/images/xiao_BLE.jpg)|
|GNSS PA1010D|A [**GPS**](#4-glossary) to locate where the device is.|![Image of a GNSS PA1010D](/images/GNSS.jpg)|
|GSM/2G SIM800L Module|Allow internet connection in 2G to the device|![Image of a GSM/2G SIM800L Module](/images/2g_Module.jpg)|
|Arduino card, model SIM800L|The mother Board of the device|![Image of a Arduino card, model SIM800L](/images/arduino_SIM800L.jpg)|
|Electromagnet|a soft metal core made into a magnet by the passage of electric current through a coil surrounding it.|![Image of a Electromagnet](/images/Magnet.jpg)|
|Lithium-Polymer battery | Stocking energy for the system to work|![Image of a Lithium-Polymer battery](/images/lithium_battery.jpg)|
|NFC antenna |An antenna that send short range signal to an NFC chip (here a componnent in a smartphone) allowing communication between two devices.|![Image of a NFC antenna](/images/NFC_Antenna.png)|
|Piezoelectric buzzer|An electronic device that can prouduce a 120 Db sound|![Image of a Piezoelectric buzzer](/images/Buzzer.jpg)|

*(List and definition of the project hardware given by the client)*

### 2. Naming convention

To better Organise our Project we decided to pick some naming conventions.

- Snake case (folders/file names and program commentary)
- kebab case(branch)
- camelCase(function and variables name)

### 3. File list
(*Folders are written in **bold***)

**`src/main`**

`main.ino` The core of the project, contains the main function.

`struct.h`

**`management`**

`RACI.md`

`weeklyreport.md` Report of ou progress each week


**`specifications`**

`README.md`

`.gitignore`

### 4. File sorting

    |-- 2023-2024-project-4-Sportshield-team-7 (root)
    |   └-- src/main
    |   |   └-- main.ino
    |   └-- specifications
    |   |   └--  functionalSpecifications.md
    |   |   |   └--technicalSpecifications.md
    |   └-- management
    |   |   └-- RACI.md
    |   |   └-- weeklyreport.md
    |   └-- .gitignore
    |   └-- README.md

</details>


---

<details open>

<summary>Project risks</summary>

## IV. Project risks

### 1. Communication risks

To ensure that there's no communication issue between our team and our stakeholders we send e-mails when we need information.

### 2. Potential risks

There's always a potential risk that could appear,

We had an issue with the hardware given by the client like the SIM module malfunctioning and a contact problem between the Arduino card and SIM module.

### 3. Dealing with risks

To deal with those risks we principally analyzed the potential risk and troubleshoot it before we had to firefight and create a mess in our schedules.

New hardware has been given by the client to solve the issues with the  SIM module.
</details>

---

<details open>

<summary>Technical specification</summary>

## V. Technical specification

### 1. Upgrading battery

we will find a way to upgrade the lifespan of a battery.
For this, we have to ensure that every component that isn't needed are deactivated to reduce the device's energy cost. We will program a system that shuts off any pieces of hardware that aren't in use and activate them when needed.

### 2. Bluetooth communication

We will develop the communication between the device and the application on the user's smartphone so the user can link and activate the device.

It's our main priority to ensure Bluetooth working by the end of the project.


### 3. NFC communication

we will allow NFC communication between the device and a card so the user can activate the anti-tief system.

However, it's our lowest priority, we are mostly focusing on Bluetooth and the other hardware adjustments.

### 4. Sensor

We will adjust the movement detection registered by the sensor to reduce the risk of false alarms. 
for that, we placed a scale where the sensor would not trigger it for anything and so, activate the buzzer.

### 5. Electromagnet

we will initialize the magnet so we can lock and unlock the cable.
For this, the user will press a button on the smartphone app that will send a Bluetooth signal to the device and unlock the cable

### 6. Test plan

we prepared a test strategy to find possible errors and reduce the risk of a firefight at the end of the project. For this, we are using a test plan that you can access right [here]().

</details>

---
<details open>

<summary>?</summary>

## VI. 

</details>

---

### Document Approval

|Reviewer|Date|Approval|
|--------|----|--------|
|Manech LAGUENS||
|Malo ARCHIMBAUD||
|Mattéo LEFIN|||
|Laurent BOUQUIN|||
|Léo CHARTIER|||
|Mathis KAKAL|||