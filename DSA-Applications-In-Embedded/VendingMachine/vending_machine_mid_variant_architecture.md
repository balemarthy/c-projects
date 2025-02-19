# 🏗️ Sugarcane Juice Vending Machine - Mid Variant - System Architecture

## **1. Introduction**
This document defines the **system architecture** for the **mid-complexity version** of the Sugarcane Juice Vending Machine. It provides an **overview of hardware, software structure, and key components**.

---

## **2. System Overview**
The mid-complexity version **upgrades the basic model** by adding:
- **User selection options** for quantity & flavors.
- **OLED display feedback** for user interaction.
- **Improved monitoring** (juice level tracking, basic logging).

The system is **event-driven** and follows a **state-machine approach**.

---

## **3. High-Level Architecture**
The system consists of **three main layers**:

### **🔹 1. Hardware Layer**
- **MCU** → ATmega2560 (Handles logic, I/O)
- **User Input** → Rotary Encoder + Buttons
- **Display** → 128x64 OLED (I2C)
- **Dispensing Control** → Solenoid Valves
- **Juice Monitoring** → Multiple Float Switches or Load Cells
- **Error Handling** → EEPROM for fault logs

### **🔹 2. Firmware Layer**
- **State Machine** → Manages system flow.
- **User Interface Control** → Handles **menu selection & display** updates.
- **Dispensing Logic** → Controls **valves based on user selection**.
- **Monitoring & Logging** → Tracks **juice levels, faults, and past issues**.

### **🔹 3. User Interaction Layer**
- **Rotary Encoder & Buttons** → Users select **flavors & quantity**.
- **OLED Display** → Shows **menu options, dispensing status**.
- **LED/Buzzer Feedback** → **Confirms selection, alerts on errors**.

---

## **4. Hardware Components**
| **Component** | **Purpose** |
|--------------|------------|
| **ATmega2560** | Main MCU controlling system logic |
| **Rotary Encoder** | User selection for quantity & flavors |
| **128x64 OLED** | Displays menu, selection, and status |
| **Push Buttons (3-5)** | Additional control inputs |
| **Solenoid Valves** | Dispensing mechanism |
| **Float Switches / Load Sensors** | Monitors juice availability |
| **EEPROM** | Stores logs of errors & past selections |

---

## **5. Software Architecture**
The firmware follows a **layered approach**:

### **🛠 Core Modules**
1. **State Machine Module**
   - Manages **system transitions**.
   - Handles **dispensing, menu selection, errors**.

2. **UI Control Module**
   - Handles **OLED updates**.
   - Reads **rotary encoder/button inputs**.

3. **Hardware Abstraction Layer (HAL)**
   - Controls **valves, LED, buzzer**.
   - Reads **float switches & sensors**.

4. **Logging & Monitoring Module**
   - Stores **error logs in EEPROM**.
   - Reads **juice levels & machine status**.

---

## **6. State Machine Overview**
| **State** | **Description** |
|-----------|----------------|
| **IDLE** | Machine ready, waiting for user input |
| **MENU_SELECTION** | User selects juice type & quantity |
| **CONFIRMATION** | User confirms selection, ready to dispense |
| **DISPENSING** | Juice is dispensed based on selection |
| **COMPLETION** | Process ends, machine resets |
| **ERROR** | Alerts user if an issue occurs |

---

## **7. Future Expansion Possibilities**
While **this version does not include advanced features**, the architecture is designed to **support future upgrades**:
- **WiFi/Bluetooth for remote monitoring**
- **QR-based payments**
- **Cloud-based inventory tracking**

---

🚀 **This document provides a structured approach to building a mid-complexity vending machine while keeping it cost-effective and user-friendly.** ✅

