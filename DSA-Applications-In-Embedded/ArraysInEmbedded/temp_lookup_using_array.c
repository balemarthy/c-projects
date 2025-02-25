/**
 * @file main.c
 * @brief ADC-to-Temperature Conversion using a Lookup Table on ATmega328P
 *
 * This program demonstrates the use of an array-based lookup table to convert 
 * raw ADC values into temperature readings. The approach is optimized for 
 * low-memory embedded systems and includes UART debugging for result display.
 *
 * @details
 * - Precomputes temperature values for a 10-bit ADC range (0-1023).
 * - Uses UART to transmit ADC and temperature readings for debugging.
 * - Ideal for low-power and low-memory embedded applications.
 *
 * @author Vamsi
 * @version 1.0
 * @date 2025-01-18
 *
 * ### Compilation Commands:
 * ```bash
 * avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -O2 main.c -o main.elf
 * avr-objcopy -O ihex main.elf main.hex
 * ```
 *
 * ### Flashing Command:
 * ```bash
 * avrdude -c arduino -p m328p -P /dev/ttyUSB0 -b 115200 -U flash:w:main.hex
 * ```
 *
 * ### Doxygen Command:
 * ```bash
 * doxygen -g
 * doxygen Doxyfile
 * ```
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

// Define constants
#define ADC_MAX 1024  /**< Maximum ADC value (10-bit ADC) */
#define UART_BAUD 9600 /**< UART baud rate */

/**
 * @brief Lookup table for ADC-to-temperature mapping.
 *
 * This array stores precomputed temperature values based on a linear relationship:
 * Temperature (°C) = ADC_Value / 10.
 */
uint8_t temp_lookup_table[ADC_MAX];

/**
 * @brief Populate the lookup table with precomputed values.
 *
 * This function calculates temperature values for all possible ADC readings
 * and stores them in a global array.
 */
void populate_lookup_table() {
    for (int i = 0; i < ADC_MAX; i++) {
        temp_lookup_table[i] = i / 10; // Example: Linear relationship
    }
}

/**
 * @brief Initialize the ADC for reading analog values.
 *
 * Configures the ADC with AVcc as the reference voltage and a prescaler of 128
 * for accurate readings.
 */
void init_adc() {
    ADMUX = (1 << REFS0); // Use AVcc as reference
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC, prescaler = 128
}

/**
 * @brief Read an ADC value from channel 0.
 *
 * @return uint16_t ADC reading (10-bit value).
 */
uint16_t read_adc() {
    ADMUX = (ADMUX & 0xF0);        // Clear channel selection
    ADCSRA |= (1 << ADSC);         // Start ADC conversion
    while (ADCSRA & (1 << ADSC));  // Wait for conversion to complete
    return ADC;
}

/**
 * @brief Initialize UART for serial communication.
 *
 * Configures UART for transmitting data at the specified baud rate (9600 bps).
 */
void init_uart() {
    UBRR0H = 0;
    UBRR0L = F_CPU / (16 * UART_BAUD) - 1; // Baud rate calculation
    UCSR0B = (1 << TXEN0); // Enable UART transmitter
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Frame format: 8 data bits, 1 stop bit
}

/**
 * @brief Transmit a single character over UART.
 *
 * @param data Character to transmit.
 */
void uart_transmit(char data) {
    while (!(UCSR0A & (1 << UDRE0))); // Wait until the transmit buffer is empty
    UDR0 = data; // Load data into the UART Data Register
}

/**
 * @brief Transmit a string over UART.
 *
 * @param str Null-terminated string to transmit.
 */
void uart_print(const char *str) {
    while (*str) {
        uart_transmit(*str++);
    }
}

/**
 * @brief Main function of the program.
 *
 * - Initializes the ADC, UART, and lookup table.
 * - Reads ADC values, retrieves corresponding temperatures, and sends the results over UART.
 */
int main() {
    uint16_t adc_value;
    uint8_t temperature;

    populate_lookup_table(); // Precompute temperature values
    init_adc();              // Initialize ADC
    init_uart();             // Initialize UART

    while (1) {
        adc_value = read_adc(); // Get ADC reading
        temperature = temp_lookup_table[adc_value]; // Lookup temperature

        // Format and send the result via UART
        char buffer[32];
        sprintf(buffer, "ADC: %u, Temp: %d°C\n", adc_value, temperature);
        uart_print(buffer);

        _delay_ms(1000); // Delay for 1 second
    }

    return 0;
}
