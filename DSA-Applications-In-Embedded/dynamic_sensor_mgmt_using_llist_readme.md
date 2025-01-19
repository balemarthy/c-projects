# Dynamic Sensor Configuration Manager

## Overview
This project demonstrates the use of **structures** and **pointers to structures** to implement a **dynamic sensor configuration manager**. It is designed for early-career developers to learn how to manage data dynamically using **linked lists** in embedded systems.

## Features
- Add, remove, and display sensor configurations dynamically.
- Efficient management of multiple sensors using a linked list.
- UART integration for debugging and displaying the sensor list.

## Key Concepts
- **Structures**: Represent real-world entities (sensors) with attributes like ID, type, and configuration.
- **Pointers to Structures**: Build a linked list for dynamic memory management.
- **Linked Lists**: Enable flexible addition and removal of elements.
- **UART Debugging**: Display sensor details via serial communication.

## Hardware Requirements
- **Microcontroller**: ATmega2560 or similar.
- **UART Interface**: To connect with a serial terminal.

## Software Requirements
- **AVR-GCC**: To compile the code.
- **AVRDUDE**: To flash the code to the microcontroller.
- **Doxygen**: To generate documentation.

## How to Use
### Hardware Setup
1. Connect the UART pins of the ATmega2560 to a serial interface (e.g., USB-to-serial converter).
2. Use a terminal application (e.g., PuTTY) to view the output at 9600 baud.


