# 📜 Intelligent Sugarcane Juice Vending Machine - Requirements Document

## 1. Introduction

The **Intelligent Sugarcane Juice Vending Machine** will be a **low-cost, durable, and configurable** vending solution. It will provide **preset juice combinations** (e.g., sugarcane juice with lemon, ginger, or pepper) and allow users to make a selection via a **simple button interface** (with future extensibility for **touchscreens or mobile apps**).

The vending machine will operate based on a **state machine architecture**, with an **application layer** that is **decoupled from the hardware interaction layer**, ensuring portability across different **microcontrollers**.

Additionally, the system should monitor:

- **Ingredient levels** (sugarcane, lemon, ginger, etc.)
- **Transaction history** (to track sales and inventory)
- **System health** and **maintenance needs**

---

## 2. System Requirements

### 2.1 Functional Requirements

#### 2.1.1 Juice Dispensing Logic
- The machine should have **preset dispensing options**, selectable via **physical buttons**.
- Each preset should control different **valves** to release specific ingredients.
- Juice dispensing should be controlled via a **state machine**, ensuring a **structured process**.
- The system should allow **future expansion** to support additional beverage options.

#### 2.1.2 User Interface (UI)
- **Initial Version:** Physical **buttons** for preset selection.
- **Future Expansion:** Option to integrate a **touchscreen** or **mobile app**.
- **Feedback** via **LED indicators** or a **small display** for status updates.

#### 2.1.3 Ingredient Level Monitoring
- **Liquid sensors** or **weight sensors** should detect ingredient levels.
- If an **ingredient is low**, the system should **display a warning**.
- Option to send **notifications** *(future expansion).*

#### 2.1.4 Payment Integration *(Future Scope)*
- Initially, the machine will **dispense juice without payments**.
- In **future versions**, support for **coin, card, UPI, or QR-code payments** can be added.

#### 2.1.5 Connectivity & Remote Monitoring *(Future Scope)*
- The machine should **log transactions** and provide an **interface for future cloud integration**.
- **Wi-Fi** or **Bluetooth** connectivity can be added later to sync data with a **mobile app or server**.

---

### 2.2 Non-Functional Requirements
- **💰 Low Cost:** Components should be affordable while ensuring **durability**.
- **🔌 Modularity:** Business logic should be **independent of hardware**.
- **📈 Scalability:** Future versions should support **touchscreens, mobile apps, or new ingredients**.
- **🚀 Portability:** Code should be **microcontroller-agnostic**, enabling **migration to different MCUs** in the future.
- **🔐 Security:** Prevent **unauthorized access** to firmware and data.

---

### 📌 Contributing
- Fork the repo and make improvements.
- Create a **pull request (PR)** for review.
- Report bugs or request features via **GitHub Issues**.

---

### 📄 License
This project is open-source and available under the **MIT License**.

---

### 📩 Contact
For questions or suggestions, feel free to **open an issue** or contact the **maintainer**.
