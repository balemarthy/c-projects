# Temperature Sensor Calibration on ATmega2560  

## Overview  
This project demonstrates how to perform **sensor calibration using a lookup table** on an Arduino Mega (ATmega2560). It uses the **binary search algorithm** to efficiently map raw ADC values to calibrated temperature readings. The project is optimized for memory-constrained embedded systems and leverages the AVR toolchain.

## Features  
- **Binary Search with bsearch**: Efficient lookup of calibration points.  
- **PROGMEM Optimization**: Stores lookup table in program memory to conserve SRAM.  
- **ADC Configuration**: Reads temperature data with 10-bit precision.  
- **UART Debugging**: Outputs ADC readings and calibrated temperature via UART.  

## Components  
- **Microcontroller**: Arduino Mega (ATmega2560).  
- **Sensor**: LM35 temperature sensor (or equivalent).  
- **Software Toolchain**: AVR-GCC, avrdude.  

## How It Works  
1. **ADC Reading**: The system reads raw ADC values from the sensor.  
2. **Lookup Table**: Precomputed calibration points map ADC values to temperatures.  
3. **Binary Search**: The `bsearch` function locates the closest calibration point.  
4. **Result Output**: The calibrated temperature is sent over UART for debugging.  

## Calibration Table  
The calibration table contains ADC values mapped to temperatures (in Celsius):  
| ADC Value | Temperature (°C) |  
|-----------|-------------------|  
| 0         | 0                |  
| 50        | 10               |  
| 100       | 20               |  
| ...       | ...              |  
| 500       | 100              |  

## Circuit Diagram  
1. Connect the **LM35 sensor** output to **ADC0 (A0)**.  
2. Use the Arduino Mega's **UART0** for serial output to a terminal.  

## Usage Instructions  
### Hardware Setup  
1. Connect the LM35 sensor's output pin to **A0** on the Arduino Mega.  
2. Ensure the sensor's Vcc and GND are connected to the board.  

### Software Setup  
1. You can use this code free of cost and at your own risk. 
