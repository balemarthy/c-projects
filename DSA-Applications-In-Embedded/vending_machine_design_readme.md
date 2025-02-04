# 🏗️ Intelligent Sugarcane Juice Vending Machine - Minimum Design Document (MVP)

## 📌 1. Introduction

This document describes the **design specifications** for the **minimum viable version** of the **Intelligent Sugarcane Juice Vending Machine**. 

The machine is designed to:
- **Dispense sugarcane juice** with a **button press**.
- **Ensure juice availability** using a **float switch sensor**.
- **Indicate machine status** using **LEDs and a buzzer**.
- **Use an ATmega2560 microcontroller** for control.

---

## 🔹 2. System Overview

### **2.1 Functional Requirements**
| **Feature** | **Description** |
|------------|----------------|
| **Juice Dispensing** | Dispenses juice when the button is pressed |
| **Float Switch Monitoring** | Prevents dispensing if juice is insufficient |
| **LED Indicators** | Shows machine status (Ready, Dispensing, Error) |
| **Buzzer Alerts** | Provides audio feedback for events |
| **Debounced Button** | Ensures only valid button presses are registered |
| **Cooldown Timer** | Prevents repeated presses during dispensing |

### **2.2 System Constraints**
- **No touchscreen or complex UI** (Only buttons, LEDs, and buzzer).
- **No logging or memory storage** (Real-time operation only).
- **Manually maintained cooling system** (No temperature monitoring).
- **Fixed volume-based dispensing** (No flow sensors).

---

## 🏗 3. Hardware Design

### **3.1 Hardware Components**
| **Component** | **Type** | **Purpose** |
|--------------|---------|------------|
| **MCU** | ATmega2560 | Main controller |
| **Button** | Mechanical Push Button | User input for dispensing |
| **Float Switch** | Liquid Level Sensor | Detects juice availability |
| **Solenoid Valve** | Normally Closed Valve | Controls juice flow |
| **LEDs** | Green, Orange, Red | Provides machine status |
| **Buzzer** | Passive Buzzer | Audio alerts |

### **3.2 Circuit Design**
```
+---------------------------+
|       ATmega2560          |
|---------------------------|
| Button Input -> GPIO 2    |
| Float Switch -> GPIO 3    |
| Solenoid Valve -> GPIO 4  |
| Green LED -> GPIO 5       |
| Orange LED -> GPIO 6      |
| Buzzer -> GPIO 7          |
+---------------------------+
```
- **Button** is connected to a **debounced GPIO pin**.
- **Float switch** detects low juice levels.
- **Solenoid valve** controls juice flow.
- **LEDs and buzzer** provide real-time feedback.

---

## ⚙ 4. Software Design

### **4.1 System Workflow (State Machine)**
```
[IDLE] → [BUTTON PRESSED] → [CHECK JUICE LEVEL] → [DISPENSING] → [COMPLETION] → [IDLE]
```

| **State** | **Description** |
|-----------|----------------|
| **IDLE** | Machine is ready, Green LED ON |
| **BUTTON PRESSED** | User presses the button, debounce logic applied |
| **CHECK JUICE LEVEL** | Float switch verifies juice availability |
| **DISPENSING** | Solenoid valve opens, Green LED blinks |
| **COMPLETION** | Dispensing stops, buzzer sounds, button disabled for 3s |

### **4.2 LED & Buzzer Indications**
| **Event** | **LED Indication** | **Buzzer Sound** |
|-----------|-----------------|------------------|
| **Machine Ready** | Green LED ON | No Sound |
| **Button Pressed** | Green LED Blinks | Short Beep (100ms) |
| **Dispensing in Progress** | Green LED Blinks | Continuous Beeps |
| **Juice Low (No Dispensing Allowed)** | Orange LED Blinking | Fast Beeps |
| **Dispensing Complete** | Green LED ON | Single Long Beep |

### **4.3 Error Handling**
| **Error** | **Response** |
|----------|------------|
| No Juice | Orange LED Blinks + Buzzer Warning |
| Solenoid Failure | Auto-stop + Error Indication |
| Button Spamming | Button disabled during dispensing |

---

## 📜 5. Summary

This **MVP design** defines a **simple, reliable, and cost-effective** vending system. It ensures:
- **Basic juice dispensing**
- **Ingredient monitoring**
- **User feedback with LEDs & buzzer**
- **Minimal hardware and power consumption**

This is the **first version** of the design. **Further refinements** can be made based on testing and feedback.

---

## 📢 Contributing

If you're interested in contributing, feel free to:
- Fork the repo
- Submit improvements via pull requests
- Report issues or request features

---

## 📄 License

This project is open-source and available under the **MIT License**.

---

### **Next Steps**
1. **Review & finalize this design document**.
2. **Create a prototype on ATmega2560**.
3. **Test button, valve, and LED logic**.
4. **Optimize debounce timing & power consumption**.


