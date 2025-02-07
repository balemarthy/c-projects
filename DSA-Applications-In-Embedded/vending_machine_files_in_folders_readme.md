# 📁 Intelligent Sugarcane Juice Vending Machine - Project Files Overview

This document provides an overview of the **files and directories** required for the **Intelligent Sugarcane Juice Vending Machine Project**. The project is structured into **documentation, firmware, hardware, testing, and contribution files** to ensure clarity and modularity.

---

## 📌 1. Project Structure Overview

```
/Sugarcane-Vending-Machine/
│── /docs/                 # Documentation files
│── /hardware/             # Hardware design & components
│── /firmware/             # Embedded software for ATmega2560
│── /software/             # Optional PC/Mobile Interface
│── /tests/                # Testing & validation files
│── LICENSE                # License file (MIT, GPL, etc.)
│── CONTRIBUTING.md        # Guidelines for contributors
│── .gitignore             # Files to ignore in version control
│── CHANGELOG.md           # Version tracking
│── README.md              # Project overview
```

---

## 📜 2. Description of Files & Directories

### **📂 /docs/** (Documentation)
| **File Name** | **Purpose** |
|--------------|------------|
| `Architecture.md` | System Architecture Document |
| `Design.md` | Minimum Design Document (MVP) |
| `Specifications.md` | Detailed system specifications |
| `Flowchart.pdf` | Flowchart diagram of the system logic |
| `State_Machine.pdf` | Diagram of the state machine logic |
| `Hardware_Selection.md` | Rationale for selecting components |

### **📂 /hardware/** (Physical Design & Components)
| **File Name** | **Purpose** |
|--------------|------------|
| `Circuit_Diagram.pdf` | Circuit design for ATmega2560 |
| `Wiring_Schematic.png` | Wiring diagram for component connections |
| `Component_List.txt` | List of components and specifications |
| `PCB_Layout.pdf` | PCB design layout (if applicable) |

### **📂 /firmware/** (Embedded Software)
| **File Name** | **Purpose** |
|--------------|------------|
| `main.c` | Main firmware file that runs on ATmega2560 |
| `state_machine.c` | Implements the vending machine's state machine logic |
| `state_machine.h` | Header file defining state transitions |
| `hardware.h` | Header file containing pin definitions & hardware functions |
| `debounce.c` | Handles button debounce logic |
| `sensor_readings.c` | Handles float switch sensor data |
| `valve_control.c` | Controls solenoid valve operations |
| `led_buzzer_control.c` | Controls LED indicators and buzzer feedback |
| `Makefile` | Build automation file for compiling firmware |

### **📂 /software/** (Optional PC/Mobile Interface)
| **File Name** | **Purpose** |
|--------------|------------|
| `app.py` | Python script for interfacing with the vending machine |
| `gui.py` | Basic GUI for monitoring (if required) |
| `mobile_api.md` | API specifications for mobile integration (future scope) |

### **📂 /tests/** (Testing & Debugging)
| **File Name** | **Purpose** |
|--------------|------------|
| `test_hardware.md` | Test procedures for buttons, valves, and sensors |
| `test_logs.txt` | Log of test results and debugging notes |
| `test_state_machine.md` | State machine validation testing |
| `error_handling_tests.md` | List of error conditions and expected responses |

### **📂 Root Files**
| **File Name** | **Purpose** |
|--------------|------------|
| `README.md` | Main project overview, setup, and usage |
| `LICENSE` | Open-source license file (MIT, GPL, etc.) |
| `CONTRIBUTING.md` | Guidelines for contributors |
| `.gitignore` | Specifies files to be ignored by Git |
| `CHANGELOG.md` | Keeps track of changes in different project versions |

---

## 🔄 3. How to Use This Repository

1. **For Documentation**: Refer to `/docs/` for architecture and design details.
2. **For Hardware Setup**: Review `/hardware/` for circuit diagrams and components.
3. **For Firmware Development**: Navigate to `/firmware/` to modify embedded software.
4. **For PC/Mobile Interface**: Use `/software/` (if applicable) for monitoring.
5. **For Testing**: Follow `/tests/` for validation and debugging.

---

## 📢 Contributing

We welcome contributions! Please refer to `CONTRIBUTING.md` before making changes.

---

## 📄 License

This project is open-source and available under the **MIT License**.

🚀 Happy Building! Let me know if any refinements are needed! 🎯
