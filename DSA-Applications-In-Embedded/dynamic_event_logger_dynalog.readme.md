# DynaLog: A Dynamic Event Logger for Embedded Systems

DynaLog is a minimal embedded logging framework that captures different categories of events (errors, sensor readings, info messages, and more) and stores them in a circular buffer. With simple **UART commands**, you can **enable** or **disable** specific event categories, as well as **flush** all queued events to an output. This approach lets you perform detailed debugging or telemetry in real-time, while preserving memory on constrained microcontrollers.

---

## Table of Contents
- [Overview](#overview)
- [Key Features](#key-features)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)
- [Usage](#usage)
  - [1. Build & Flash](#1-build--flash)
  - [2. Initialize in `main.c`](#2-initialize-in-mainc)
  - [3. Logging Events](#3-logging-events)
  - [4. Sending Commands](#4-sending-commands)
  - [5. Flushing the Buffer](#5-flushing-the-buffer)
- [Configuration](#configuration)
- [Future Extensions](#future-extensions)
- [License](#license)

---

## Overview

DynaLog addresses the need for **flexible, on-demand logging** in embedded systems. Many existing loggers either:
- Log everything, overwhelming the system with unnecessary data, **or**
- Use fixed logic, requiring recompilation to change what gets logged.

With DynaLog, you can toggle specific categories at runtime, making it easier to **trace issues in real-time** without flooding your logs.

---

## Key Features

1. **Dynamic Enable/Disable**  
   Turn on or off specific event categories (e.g., `EVENT_ERROR`, `EVENT_SENSOR`, `EVENT_INFO`) with simple UART commands (`ENABLE`, `DISABLE`).

2. **Circular Buffer**  
   Stores events in a fixed-size ring buffer to avoid heap usage. If the buffer fills up, you can opt to discard the newest or oldest data (depending on your preference).

3. **Command-Driven**  
   An optional command parser listens for commands (`FLUSH`, `STATUS`, etc.) via UART. Perfect for real-time debugging, live configuration, or runtime toggling of log verbosity.

4. **Minimal Footprint**  
   Designed for small MCUs (AVR, ARM Cortex-M, etc.). It avoids dynamic memory (like `malloc`) and relies on straightforward data structures.

5. **Timestamp Support (Optional)**  
   Integrate a simple millisecond or real-time clock to tag log entries, helping you track when events occurred.

---

## Project Structure

A suggested file breakdown might look like this:


- **`main.c`**: Initializes hardware, runs the main loop, and demonstrates logging usage.  
- **`event_logger.c/.h`**: Implements the circular buffer, logging functions, and category bitmask.  
- **`command_parser.c/.h`**: Parses incoming UART commands (e.g., `ENABLE SENSOR`), calls logger functions.  
- **`uart.c/.h`**: UART initialization and TX/RX routines.  
- **`timestamp.c/.h`** (optional): Provides a function to get the current time for log events.  
- **`categories.h`** (optional): Defines event categories (e.g., `EVENT_ERROR`, `EVENT_SENSOR`, etc.).

---

## How It Works

1. **Event Categories**  
   You define constants for each type of event (errors, sensor readings, etc.). For instance, `#define EVENT_ERROR (1 << 0)`, `#define EVENT_SENSOR (1 << 1)`, etc.

2. **Log Function**  
   When you call `logEvent(category, data)`, the system checks if `category` is enabled. If yes, the event is placed in the circular buffer.

3. **Circular Buffer**  
   A ring buffer that stores each log entry (e.g., `LogEvent` struct with category, data, and optional timestamp). As new events arrive, they go to `head`, and reading or flushing removes them from `tail`.

4. **Flush**  
   On command (`FLUSH`), threshold, or time interval, the system reads each event from the buffer and sends it over UART (or stores it to external memory like an SD card).

5. **Commands**  
   Through a serial terminal, you can issue commands like `ENABLE SENSOR`, `DISABLE ERROR`, `FLUSH`, and `STATUS`. The command parser updates internal flags or triggers buffer actions accordingly.

---

## Usage

### 1. Build & Flash

Use your favorite AVR or ARM toolchain. For example, on AVR:

```bash
avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os *.c -o main.elf
avr-objcopy -O ihex main.elf main.hex
avrdude -c <programmer> -p m328p -U flash:w:main.hex
