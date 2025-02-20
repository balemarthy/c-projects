# 🖥️ Sugarcane Juice Vending Machine - Mid Variant - Software Design

## **1. Introduction**
This document details the **software design** for the **mid-complexity version** of the Sugarcane Juice Vending Machine. It covers **module design, function responsibilities, data flow, and state transitions**.

---

## **2. Software Overview**
The software follows a **modular event-driven design** using a **state machine approach**. It consists of:
- **User Interface Module** (Handles rotary encoder, buttons, OLED display)
- **State Machine Module** (Manages transitions)
- **Hardware Control Module** (Controls solenoids, LEDs, buzzers)
- **Logging & Monitoring Module** (EEPROM data storage)

---

## **3. Software Architecture**
### **🔹 Core Modules**
| **Module** | **Responsibility** |
|------------|--------------------|
| **Main Control (`main.c`)** | Initializes system, runs state machine |
| **State Machine (`state_machine.c`)** | Handles system states & transitions |
| **User Interface (`ui_control.c`)** | Reads rotary encoder & buttons, updates OLED |
| **Hardware Control (`hardware.c`)** | Controls solenoids, LEDs, and buzzer |
| **Monitoring & Logging (`monitoring.c`)** | Tracks juice levels, stores error logs in EEPROM |

---

## **4. State Machine Design**
| **State** | **Description** |
|-----------|----------------|
| **IDLE** | Machine is ready, waiting for user input |
| **MENU_SELECTION** | User selects juice type & quantity |
| **CONFIRMATION** | User confirms selection, system prepares for dispensing |
| **DISPENSING** | Juice is dispensed based on selection |
| **COMPLETION** | Process ends, system resets |
| **ERROR** | System detects an issue (low juice, solenoid failure) |

---

## **5. Data Flow**
### **🔹 Input → Processing → Output**
1️⃣ **User Input (Rotary Encoder & Buttons)**  
   ⬇ Reads input  
2️⃣ **Menu Processing (State Machine)**  
   ⬇ Updates selection  
3️⃣ **Hardware Control (Solenoids & Sensors)**  
   ⬇ Dispenses juice  
4️⃣ **Logging & Alerts (EEPROM & Buzzer)**  
   ⬇ Stores errors  

---

## **6. Function Overview**
### **Main Control (`main.c`)**
- **`main()`** → Initializes system, enters main loop.
- **`ISR(INT0_vect)`** → Interrupt for button press.

### **State Machine (`state_machine.c`)**
- **`initStateMachine()`** → Initializes states.
- **`runStateMachine()`** → Handles transitions.
- **`handleError()`** → Manages faults.

### **User Interface (`ui_control.c`)**
- **`readRotaryEncoder()`** → Reads user selection.
- **`updateDisplay()`** → Updates OLED menu.

### **Hardware Control (`hardware.c`)**
- **`startDispensing()`** → Opens solenoid valve.
- **`stopDispensing()`** → Closes solenoid.
- **`updateLEDStatus()`** → Controls LEDs.
- **`playBuzzerSound()`** → Alerts user.

### **Monitoring & Logging (`monitoring.c`)**
- **`readJuiceLevel()`** → Checks juice level.
- **`logErrorToEEPROM()`** → Stores fault logs.

---

## **7. Error Handling**
| **Error Condition** | **System Response** |
|--------------------|---------------------|
| **Low Juice** | Stops dispensing, alerts user |
| **Overheat** | Buzzer warning, enters error state |
| **Solenoid Failure** | No juice dispensed, buzzer alert |
| **Invalid Selection** | OLED prompts user to retry |

---

## **8. Future Expansion Possibilities**
- **WiFi/Bluetooth logging**
- **QR-based payment integration**
- **Mobile app control**

---

🚀 **This document ensures structured software development while keeping code modular and expandable.** ✅

