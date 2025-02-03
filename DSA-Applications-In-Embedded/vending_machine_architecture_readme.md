# Recreate the Markdown file after execution state reset

# Create a new Markdown file for the System Architecture Document

markdown_content = """# 🏗️ Intelligent Sugarcane Juice Vending Machine - System Architecture Document (MVP)

## 📌 1. Introduction

This document outlines the **architecture** for the **minimum viable product (MVP)** version of the **Intelligent Sugarcane Juice Vending Machine**. 

The machine is designed to **dispense sugarcane juice** with a **single button press** while ensuring **ingredient availability and machine status indication** using **LEDs and a buzzer**. The system operates using an **ATmega2560 microcontroller** and a **battery-powered 12V system**.

---

## 🔹 2. High-Level System Architecture

The system follows a **layered architecture**, ensuring modularity, scalability, and separation of concerns.


### **2.1 Application Layer (Business Logic)**
- Implements **State Machine** for juice selection & dispensing.
- Handles **LED & buzzer indications**.
- Ensures **debounced button press recognition**.
- Implements a **3-second cooldown period** after dispensing.

### **2.2 Hardware Abstraction Layer (HAL)**
- Reads **float switch status** (for juice level detection).
- Controls **solenoid valve** (volume-based dispensing).
- Manages **LED indicators & buzzer feedback**.
- Ensures **hardware changes do not affect the business logic**.

### **2.3 User Interface Layer**
- **Button input** (debounced for stable operation).
- **LED signals** to indicate machine states.
- **Buzzer alerts** for different machine events.

---

## 🏗️ 3. Component Selection

### **3.1 Microcontroller (MCU)**
| **Component**  | **Selection** |
|---------------|--------------|
| **Microcontroller** | ATmega2560 |
| **Reason** | Supports multiple GPIOs for LED, Buzzer, Float Switch, and Valve |

### **3.2 Sensors & Actuators**
| **Component**  | **Selection** |
|---------------|--------------|
| **Juice Level Sensor** | Float Switch (Single Level) |
| **Valve Control** | Solenoid Valve |
| **Button Type** | Mechanical Push Button (Debounced) |
| **LED Indicators** | Green & Orange LEDs |
| **Buzzer** | Passive Buzzer |

---

## 🔄 4. System Workflow (State Machine)

The system operates as a **state machine**, ensuring smooth and structured processing.


| **State** | **Description** |
|-----------|----------------|
| **IDLE** | Machine is ready, Green LED ON |
| **BUTTON PRESSED** | User selects a juice variant, button registered once (debounced) |
| **CHECK JUICE LEVEL** | Float switch checks if juice is available |
| **DISPENSING** | Solenoid valve opens, Green LED blinks |
| **COMPLETION** | Dispensing stops, buzzer sounds, button disabled for 3s |

---

## 🔊 5. LED & Buzzer Feedback Mechanism

The system uses **LED indicators** and a **buzzer** to provide real-time status updates.

| **Event** | **LED Indication** | **Buzzer Sound** |
|-----------|-----------------|------------------|
| **Machine Ready** | Green LED ON | No Sound |
| **Button Pressed** | Green LED Blinks | Short Beep (100ms) |
| **Dispensing in Progress** | Green LED Blinks | Continuous Beeps (100ms ON, 100ms OFF) |
| **Juice Low (No Dispensing Allowed)** | Orange LED Blinking | Fast Beeps (50ms ON, 50ms OFF) |
| **Temperature Too High** | Red LED ON | Long Beeps (500ms ON, 500ms OFF) |
| **Dispensing Complete** | Green LED ON | Single Long Beep (300ms) |

---

## 🔌 6. Hardware Circuit Design

The **ATmega2560** will interface with:
- **Button (Debounced Input)**
- **Float Switch (Juice Level Detection)**
- **Solenoid Valve (Dispensing Control via Relay)**
- **LEDs for Indications**
- **Buzzer for Audio Alerts**


---

## 🔄 7. Error Handling Mechanisms

| **Error Scenario** | **System Response** |
|-------------------|----------------------|
| **No Juice Available** | Orange LED Blinks + Buzzer Alert (Fast Beeps) |
| **Button Press Ignored** | If juice level is low, no action taken |
| **Temperature Too High** | Red LED ON + Long Beeps |
| **Solenoid Valve Failure** | Auto-stop dispensing, buzzer alert |

---

## 🔮 8. Future Scalability

| **Feature** | **Current Implementation** | **Future Upgrade** |
|------------|-----------------|----------------|
| **User Interface** | Button + LED | Touchscreen, Mobile App |
| **Connectivity** | None | Wi-Fi, Bluetooth |
| **Payment System** | None | QR Code, UPI, NFC Payments |
| **Data Logging** | None | SD Card Storage |
| **AI Integration** | None | Smart Recommendations |

---

## 📜 9. Summary

This **MVP architecture** provides a **simple yet effective vending machine system** with:
- **One-button juice dispensing**
- **Float switch monitoring for juice levels**
- **LED & Buzzer feedback for user awareness**
- **ATmega2560 as the core controller**

This is a **first version** of the **architecture**. We can **refine it further** based on feedback!

---

## 📢 Contributing
If you're interested in contributing, feel free to:
- Fork the repo
- Submit improvements via pull requests
- Report issues or request features

---

## 📄 License
This project is open-source and available under the **MIT License**.

