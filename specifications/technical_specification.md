# <u>Technical Specification</u>

---

## Version

|Version|Reviewver|Date|modification description|
|-------|---------|----|------------------------|
|   1   |Mattéo LEFIN| 14/03/2024 | Added Table of content and introduction. Added Project goals and scopes.|
|2|Mattéo LEFIN| 15/03/2024|Finish Project Organisation.|
|3|Mattéo LEFIN|21/03/2024|Added an hardware description, risks, project scope and started technical specification. |
|4|Mattéo LEFIN|25/03/2024|finish technical specification and add images.|
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
  - [2. Out of scope](#2-in-and-out-of-scope)
- [***III. Project organisation***](#iii-project-organisation)
  - [1. Work environnement](#1-work-environment)
  - [2. Naming convention](#2-naming-convention)
  - [3. File list](#3-file-list)
  - [4. File sorting](#4-file-sorting)
- [***IV. Project risks***](#iv-projeéct-risks)
  - [1. Communication risks](#1-communication-risks)
  - [2. Potential risks](#2-potential-risks)
  - [3. Dealing with risks](#3-dealing-with-risks)
- [***V Technical specifications***](#v-technical-specification)
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

### 1. Definition of a Technical Specification

The objective of the Technical Specifications is to translate the Functional Requirements into deeper explanations and technicality, which delineate the features, scope, and objectives of the project. This involves breaking down each requirement into explicit instructions with utmost clarity. The purpose is to provide precise guidance to both the development and quality assurance teams, ensuring the successful accomplishment of their mission.

### 2. Project Overview

This Project has for purpose the creation of a security system for sports equipment such as skis and possibly snowboards and surfboards in the future using an alarm system similar to a car anti-theft protection, controlled with the owner's phone using an NFC system. 
Our part in this project is mainly the maintenance of the battery and making the system work with an NFC system.

![the device](/images/Device.png)

(*3D schema of the device*)

### 3. Functional Specification

A Technical Specifications document contains more actionable/[**low-level data**](#4-glossary) than the Functional Specifications, adding more explanations and a technical aspect of our project! You can access this document right [here](https://github.com/algosup/2023-2024-project-4-sportshield-team-7/blob/main/specifications/functional_specification.md).
### 4. Glossary

|Word|Definition|
|----|----------|
|low-level data|Low-level describes more specific individual components of a systematic operation, focusing on the details of rudimentary micro functions rather than macro, complex processes.|
|Bluetooth system| Bluetooth is a telecommunications industry specification that describes how mobile devices, computers and other devices can easily communicate with each other using a short-range wireless connection. |
| NFC system   |    NFC or Near Field Communication is a communication system with a high frequency but a short range, it's comonly used for contactless system like train contactless train cards.    |
|GPS| GPS or Global Positioning System is a device that allow the user locate himself, a place or an object by satellite.|
|IDE|A software application that helps programmers effectively develop software code.|


</details>

---

<details open>

<summary>Project goals and scopes</summary>

## II. Project goals and scopes

### 1. Objectives

Our objective in this project is to develop the software so it will detect unusual movement when the device is activated and to link the user's smartphone and device using the [**Bluetooth system**](#4-glossary).
we also have to find a way to make the battery last as long as possible and make the program compatible with the [**NFC system**](#4-glossary).

### 2. In and Out of scope

|In scope|Priority|
|--------|--------|
|Communication between user and the device.|critical|
|Upgrade battery lifespan.|High|
|Set the sensor correctly.|High|


|out of scope|Reason|
|------------|------|
|Method used to update the software.|Not responsible.|
|Mobile application and the server.|Not responsible.|
|Hardware security and integrity.|Not responsible.|
|API to send and receive notifications.|Not responsible.|
|Hardware design.|Not responsible.|

</details>

---

<details open>

<summary>Project organisation</summary>

## III. Project organisation

### 1. Work Environment

- Operating System: We are using Lenovo Thinkbook for Windows and we are using a Macbook Air for the IOS system.

- For programming, we are developing C++/C using the Arduino [**IDE**](#4-glossary). 

- We are using imposed libraries in C++ for the device to work perfectly: 
  - NRF52_MBED_TimerInterupt V1.4.1 (enable us to use interrupt for hardware).
  - ArduinoBLE V1.3.6 (enable Bluetooth).
  - Adafruit GPS Library V1.14.0 (enable us to use [**GPS**](#4-glossary)).
  - Seeed Arduino LSM6DS V2.0.3 (enable us to control the sensor).
  - OneWire V2.3.7 (enable us to control temperature sensor).


|Piece name|description|Image|Documentations|
|----------|-----------|-----|----|
|Xiao BLE Sense nrf52840|Microcontroller used for Bluetooth applications.|![Image of a Xiao BLE Sense nrf52840](/images/xiao_BLE.jpg)|[Xiao BLE documentation](/specifications/hardware_documentation/nRF52840_PS_v1.5.pdf) and [Xiao BLE build plan](/specifications/hardware_documentation/Seeed-Studio-XIAO-nRF52840-Sense-v1.1.pdf)|
|GNSS PA1010D|A GPS module to locate the device.|![Image of a GNSS PA1010D](/images/GNSS.jpg)|[GNSS documentation](/specifications/hardware_documentation/CD-PA1010D-Datasheet-v.02.pdf)|
|GSM/2G SIM800L Module|Allows internet connection of the device to 2G cellular networks.|![Image of a GSM/2G SIM800L Module](/images/2g_Module.jpg)|[SIM800L documentation](/specifications/hardware_documentation/SIM800L-SIMCom.pdf)|
|Arduino card, model SIM800L|The mother Board of the device.|![Image of a Arduino card, model SIM800L](/images/arduino_SIM800L.jpg)|[SIM800L documentation](/specifications/hardware_documentation/SIM800L-SIMCom.pdf)|
|Electromagnet Mini 2728 Small Solenoid Lock|A soft metal core made into a magnet by the passage of electric current through a coil surrounding it, in this project, we use it lock the device.|![Image of a Electromagnet](/images/Magnet.jpg)|[Electromagnet documentation]()|
|Lithium-Polymer battery | Energy storage for the system to work.|![Image of a Lithium-Polymer battery](/images/lithium_battery.jpg)|[Battery documentation](/specifications/hardware_documentation/Batterie_LP603449.pdf)|
|2G Antenna |An antenna that allows devices to receive information by 2G signals.|![Image of a 2g antenna](/images/2G_Antenna.png)|[2G antenna documentation](/specifications/hardware_documentation/SIM800L-SIMCom.pdf)|
|NFC antenna |This antenna allows contactless system and short range communication between two electronic devices.|![Image of a NFC antenna](/images/NFC.jpg)|[NFC antenna documentation](https://docs.rs-online.com/4b3f/0900766b816bd632.pdf)|
|Piezoelectric buzzer|An electronic device that can produce a 120 Db sound.|![Image of a Piezoelectric buzzer](/images/Buzzer.jpg)|[Buzzer documentation](https://www.cdiscount.com/bricolage/securite-domotique/yosoo-avertisseur-sonore-electronique-10pcs-buzzer/f-1662005-yos7034115523140.html)     *Only available in french*|

*List and definition of the project hardware given by the client.*

### 2. Naming convention

To better organize our Project we decided to adhere to naming conventions.

- snake_case (folders/file names and program commentary): `hello_world!`
- kebab-case(branch): `hello-world!`
- camelCase(function and variable names): `helloWorld!`

### 3. File list
(*This part is only a representation of our folders and files, only some of them are shown. Folders are written in **bold**.*)

**`src/main`**

`main.ino` The core of the project program, contains the main function.

`struct.ino/struct.h` Other files, essential for the program work.

**`management`**

`RACI.md` Managing documents.

`weekly_report.md` Report your progress each week.


**`specifications`**

`functional_specification` Document that specifies an aspect of the project.

`technical_specification` Document that details the Functional Specification.

**`test_plan`**

`test_plan.md` Document detailing the objectives, resources, and processes for a specific test session for a software or hardware product.

`README.md` Document presenting the project.

`.gitignore` Crucial file to ensure that certain files not tracked by Git remain untracked.

### 4. File sorting

*This part shows how we will sort the different needed program files and documents*

    |-- 2023-2024-project-4-Sportshield-team-7 (root)
    |   └-- src/main
    |   |   └-- buzzer.ino
    |   |   └-- buzzer.h
    |   |   └-- config.ino
    |   |   └-- config.h
    |   |   └-- constants.ino
    |   |   └-- constants.h
    |   |   └-- main.ino
    |   |   └-- motion.ino
    |   |   └-- motion.h
    |   |   └-- sim.ino
    |   |   └-- sim.h
    |   |   └-- utils.ino
    |   |   └-- utils.h
    |   └-- specifications
    |   |   └--  functional_specifications.md
    |   |   └--technical_specifications.md
    |   └-- user_manual
    |   |   └-- user_manual.md
    |   └-- management
    |   |   └-- RACI.md
    |   |   └-- risks_management.md
    |   |   └-- weekly_report.md
    |   |   └-- project_charter.md
    |   └-- test_plan
    |   |   └-- test_plan.md
    |   └-- .gitignore
    |   └-- README.md

</details>


---

<details open>

<summary>Project risks</summary>

## IV. Project risks

### 1. Communication risks

To ensure that there are no communication issues between our team and our stakeholders we send e-mails when we need information. Otherwise, it could create even more challenging issues among other issues that we have to troubleshoot and will raise the probability of having to firefight more 
often.

### 2. Potential risks

There's always a potential risk that could appear like communication issues as previously said, performance risks and technical risks.

We had an issue with the hardware given by the client like the SIM module malfunctioning and a contact problem between the Arduino card and SIM module.

We analyze the project multiple times to find potential risks and solve future issues or at least mitigate them before they become a problem.

### 3. Dealing with risks

We identified risks and planned action in the event of failure so we would pass less time to correct them and move on to the rest of the project.
Sending e-mails to clients is crucial for lowering some potential risks that could be avoided. So we frequently communicate any question or issue with the client.

New hardware has been given by the client to solve the issues with the SIM module.
</details>

---

<details open>

<summary>Technical specification</summary>

## V. Technical specification

### 1. Upgrading battery

We will find a way to upgrade the lifespan of a battery.
For this, we have to ensure that every component that isn't needed is deactivated to reduce the device's energy cost. We will program a system that shuts off any pieces of hardware that aren't in use and activate them when needed.

### 2. Bluetooth communication

We will develop the communication between the device and the application on the user's smartphone so the user can link and activate the device.
The linking functionality allows the user to know the location of the device, initialize notification for the battery or if the alarm activates.
It's our main priority to ensure Bluetooth working by the end of the project.


### 3. NFC communication

We will allow NFC communication between the device and a card so the user can activate the anti-theft system. 

However, it's our lowest priority, we are mostly focusing on Bluetooth and the other hardware adjustments.

### 4. Sensor

We will adjust the movement detection registered by the sensor to reduce the risk of false alarms. 
For that, we placed a scale where the sensor would not trigger it for anything and so, activate the buzzer.

### 5. Electromagnet

We will initialize the magnet so we can lock and unlock the cable.
For this, the user will press a button on the smartphone app that will send a Bluetooth signal to the device and unlock the cable. 

### 6. Test plan

We prepared a test strategy to find possible errors and reduce the risk of a firefight at the end of the project. For this, we laid out a plan that you can access right [here]().

</details>

---

## Document Approval

|Reviewer|Date|Approval|
|--------|----|--------|
|Manech LAGUENS||
|Malo ARCHIMBAUD||
|Mattéo LEFIN|26/03/2024|✅|
|Laurent BOUQUIN|||
|Léo CHARTIER|||
|Mathis KAKAL|||