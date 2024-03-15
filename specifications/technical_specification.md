# <u>Technical Specification</u>

---

## Version

|Version|Reviewver|Date|modification description|
|-------|---------|----|------------------------|
|   1   |Mattéo LEFIN| 14/03/2024 | Added Table of content and introduction. Added Project goals and scopes|
|2|Mattéo LEFIN| 15/03/2024|Finish Project Organisation|

---

<details open>

<summary>Table of content</summary>

## Table of contents:

- [***I. Introduction***](#i-introduction)
  - [1. Definition of a technical specification](#1-definition-of-a-technical-specification)
  - [2. Project Overview](#2-Project-Overview)
  - [3. Glossary](#3-Glossary)
- [***II. Project goals and scopes***](#ii-project-goals-and-scopes)
  - [1. Objectives](#1-objectives)
  - [2. Project scope](#2-project-scope)
  - [3. ]()
  - []()
- [***III. Project organisation***](#iii-project-organisation)
  - [1. Work environnement](#1-work-environnement)
  - [2. Naming convention](#2-naming-convention)
  - [3. File list](#3-file-list)
  - [4. File sorting](#4-file-sorting)
- [***IV. Project risks***](#iv-project-risks)
- ***V Technical specifications***
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
Our part in this project is mainly maintenance of the battery and making the system work with an NFC system

### 3. Glossary

|Word|Definition|
|----|----------|
|    |          |

</details>

---

<details open>

<summary>project goals and scopes</summary>

## II. Project goals and scopes

### 1. Objectives

The Objective of our participation in this project is to develop the software so it will detect unusual movement when the device is activated.
we also have to find a way to make the battery last as much as possible and make the program compatible with NFC system.

### 2. Project Scope

||||
|----|----|----|
|    |    |    |
</details>

---

<details open>

<summary>Project organisation</summary>

## III. Project organisation

### 1. Work environnement

- Operating System: We are using Lenovo Thinkbook for Windows and we are using a Macbook Air for the IOS system.

- For programming, we are developing C++/C using the Arduino IDE. 

- We are using imposed libraries for C++.

- Prototype : 

|Piece name|description|Image|
|----------|-----------|-----|
|Xiao BLE Sense nrf52840|||
|GNSS PA1010D|||
|GSM/2G SIM800L Module|||
|Arduino card, model SIM800L|||
|Electromagnet|||
|Lithium-Polymer battery | Stocking energy for the system to work||
|NFC antenna |||
|Piezoelectric buzzer|||


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
    |   └-- LICENSE

</details>


---

<details open>

<summary>Project risks</summary>

## IV. Project risks

### 1. Communication risks

### 2. Potential risks

### 3. Dealing with risks


</details>

---

<details open>

<summary>Technical specification</summary>

## V. Technical specification

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