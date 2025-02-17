# 🛠️ Sugarcane Juice Vending Machine - Test Plan

This document outlines the **test cases** for verifying the correct functionality, hardware interactions, and error handling of the **Sugarcane Juice Vending Machine**.

---

## 📌 1. Functional Tests

| **Test ID** | **Test Case** | **Expected Result** |
|------------|--------------|----------------------|
| **TC-01** | Power On | Green LED turns ON (Machine Ready) |
| **TC-02** | Button Press (Valid) | Juice is dispensed, Green LED blinks |
| **TC-03** | Button Press (Debounce) | Only 1 press registered, ignores bounce |
| **TC-04** | Button Disabled During Dispensing | No multiple dispensing during active cycle |
| **TC-05** | Restart After Cooldown | System resets and allows normal operation |

---

## 🏗️ 2. Hardware Tests

| **Test ID** | **Test Case** | **Expected Result** |
|------------|--------------|----------------------|
| **TC-06** | Juice Level Low | Orange LED blinks, Buzzer fast beeps, No dispensing |
| **TC-07** | Solenoid Valve Operation | Valve opens when dispensing, closes after 3s |
| **TC-08** | Buzzer Feedback | Short beep on button press, long beep on completion |
| **TC-09** | LED Indicators | Green: Ready, Blinking: Dispensing, Orange: Low Juice |
| **TC-10** | Power Failure Recovery | System resumes from IDLE state on power restore |

---

## ⚠️ 3. Error Handling Tests

| **Test ID** | **Test Case** | **Expected Result** |
|------------|--------------|----------------------|
| **TC-11** | Juice Level Low | Orange LED blinks, No dispensing allowed |
| **TC-12** | Button Press During Low Juice | No action, Buzzer warning |
| **TC-13** | Overheat Condition | Red LED ON, Buzzer long beep |
| **TC-14** | Button Press During Overheat | No action taken, buzzer alert |
| **TC-15** | Solenoid Valve Failure | Buzzer alert, No dispensing |

---

## 🚀 4. How to Run Tests

1. **Power On Test**: Plug in the machine and observe LED behavior.
2. **Button Test**: Press the button and check for debounce, LED feedback, and valve activation.
3. **Juice Level Simulation**: Manually toggle the float switch to test low juice conditions.
4. **Error Handling**: Simulate valve failure by disconnecting it and observing error response.

---

## 📢 Notes
- If a test **fails**, check power, wiring, and component connections.
- Reset the system after testing **error handling cases**.

---

🛠️ **Test results should be documented to verify system stability.** ✅

