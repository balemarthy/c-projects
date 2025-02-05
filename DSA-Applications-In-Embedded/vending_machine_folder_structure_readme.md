# 📁 Intelligent Sugarcane Juice Vending Machine - Project Structure

This project follows a **structured file organization** to maintain clarity and modularity. Below is an overview of the **files and directories** needed for this project.

---

## 📌 1. Project Structure Overview

```
/Sugarcane-Vending-Machine/
│── /docs/                 # Documentation files
│   ├── Architecture.md    # System Architecture Document
│   ├── Design.md          # Minimum Design Document
│── /hardware/             # Hardware-related files
│   ├── Circuit_Diagram.pdf # Circuit design for ATmega2560
│   ├── Component_List.txt  # List of components used
│── /firmware/             # Embedded software for ATmega2560
│   ├── main.c             # Main firmware code (C language)
│   ├── state_machine.c    # Implementation of the vending state machine
│   ├── debounce.c         # Debounce logic for buttons
│   ├── hardware.h         # Header file for hardware abstraction
│── /software/             # PC software (if any, for monitoring, logging)
│   ├── app.py            # Python script (if needed for interfacing)
│── /tests/                # Test scripts and validation logs
│   ├── test_hardware.md   # Test procedures for buttons, valves, sensors
│── README.md              # Project overview and how to use it
│── LICENSE                # License file (MIT, GPL, etc.)
│── CONTRIBUTING.md        # Guidelines for contributors
│── .gitignore             # Files to ignore in version control
```

---

## 📜 2. Description of Files & Directories

### **📂 /docs/** (Documentation)
| **File** | **Description** |
|----------|----------------|
| `Architecture.md` | Contains the System Architecture Document |
| `Design.md` | Contains the Minimum Design Document |

### **📂 /hardware/** (Physical Design & Components)
| **File** | **Description** |
|----------|----------------|
| `Circuit_Diagram.pdf` | PDF containing the circuit design |
| `Component_List.txt` | List of components and specifications |

### **📂 /firmware/** (Embedded Software)
| **File** | **Description** |
|----------|----------------|
| `main.c` | Main firmware file that runs on ATmega2560 |
| `state_machine.c` | Implements the vending machine's state machine logic |
| `debounce.c` | Handles button debounce logic |
| `hardware.h` | Header file containing pin definitions & hardware functions |

### **📂 /software/** (Optional PC/Mobile Interface)
| **File** | **Description** |
|----------|----------------|
| `app.py` | Python script for interfacing with the vending machine (if needed) |

### **📂 /tests/** (Testing & Validation)
| **File** | **Description** |
|----------|----------------|
| `test_hardware.md` | Documents test procedures for buttons, valves, and sensors |

### **Root Files**
| **File** | **Description** |
|----------|----------------|
| `README.md` | Main project overview, setup, and usage |
| `LICENSE` | Open-source license file (MIT, GPL, etc.) |
| `CONTRIBUTING.md` | Guidelines for contributing to the project |
| `.gitignore` | Specifies files to be ignored by Git |

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
