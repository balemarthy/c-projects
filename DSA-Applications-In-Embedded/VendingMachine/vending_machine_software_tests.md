# 💻 Sugarcane Juice Vending Machine - Software Test Plan

This document outlines the **software-level test cases** to verify the correct execution of **state machine logic, debounce function, and firmware behavior**.

---

## 📌 1. State Machine Tests

| **Test ID** | **Test Case** | **Expected Result** |
|------------|--------------|----------------------|
| **ST-01** | System starts in IDLE state | Green LED is ON, No dispensing |
| **ST-02** | Transition from IDLE to CHECK_JUICE_LEVEL | Button press moves system to CHECK_JUICE_LEVEL |
| **ST-03** | Transition from CHECK_JUICE_LEVEL to DISPENSING | If juice is available, dispensing starts |
| **ST-04** | Transition from CHECK_JUICE_LEVEL to IDLE (No Juice) | If juice is low, system returns to IDLE |
| **ST-05** | Transition from DISPENSING to COMPLETION | After 3s, system completes dispensing |
| **ST-06** | Transition from COMPLETION to IDLE | After 3s cooldown, system is ready for next cycle |

---

## ⏳ 2. Button & Debounce Tests

| **Test ID** | **Test Case** | **Expected Result** |
|------------|--------------|----------------------|
| **BT-01** | Button pressed once | Only one dispensing cycle starts |
| **BT-02** | Button bouncing simulation | No multiple presses registered |
| **BT-03** | Button held down during DISPENSING | No additional dispensing occurs |
| **BT-04** | Button pressed during error condition | No action, Buzzer alert |

---

## ⚠️ 3. Error Handling Tests

| **Test ID** | **Test Case** | **Expected Result** |
|------------|--------------|----------------------|
| **EH-01** | Juice Level Low | System prevents dispensing, shows warning |
| **EH-02** | Solenoid Valve Failure | No dispensing, buzzer alert |
| **EH-03** | Overheat Condition | System enters error mode, Red LED ON |
| **EH-04** | Reset After Overheat | System recovers after cooldown |
| **EH-05** | Unexpected Power Loss | System starts in IDLE state after restart |

---

## 🚀 4. How to Run Tests

1. **State Machine Tests**: Step through states and observe LED & buzzer feedback.
2. **Button Tests**: Simulate button presses & ensure proper debounce behavior.
3. **Error Handling**: Simulate fault conditions (disconnect valve, overheat scenario).

---

## 📢 Notes
- Use **debugging tools** like `printf` (UART) if needed.
- Test cases should be **logged** with results.

---

🛠️ **Document test outcomes for validation.** ✅

