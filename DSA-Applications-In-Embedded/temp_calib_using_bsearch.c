/**
 * @file main.c
 * @brief Temperature Sensor Calibration Using Binary Search on ATmega2560
 *
 * This project demonstrates how to use a lookup table and binary search to
 * calibrate sensor data efficiently on an ATmega2560. The code reads raw ADC
 * values from a temperature sensor, finds the corresponding calibrated value
 * using binary search, and outputs the results via UART.
 *
 * @details
 * Compilation and Flashing Commands:
 * - Compile: `avr-gcc -mmcu=atmega2560 -DF_CPU=16000000UL -O2 main.c -o main.elf`
 * - Convert to HEX: `avr-objcopy -O ihex main.elf main.hex`
 * - Flash to Microcontroller: `avrdude -c wiring -p m2560 -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex`
 *
 * Doxygen Documentation:
 * - Generate Doxygen Config File: `doxygen -g`
 * - Run Doxygen: `doxygen Doxyfile`
 *
 * @author [Your Name]
 * @date [Date]
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>

/**
 * @brief Structure to define a calibration point.
 *
 * The structure contains an ADC value and its corresponding calibrated temperature.
 */
typedef struct {
    uint16_t adc_value; ///< Raw ADC value
    int8_t temperature; ///< Temperature in Celsius
} CalibrationPoint;

/**
 * @brief Lookup table for calibration stored in program memory (PROGMEM).
 */
const CalibrationPoint calibration_table[] PROGMEM = {
    {0, 0}, {50, 10}, {100, 20}, {150, 30}, {200, 40},
    {250, 50}, {300, 60}, {350, 70}, {400, 80}, {450, 90}, {500, 100}
};
#define TABLE_SIZE (sizeof(calibration_table) / sizeof(CalibrationPoint))

/**
 * @brief Comparison function for binary search.
 *
 * This function compares a given key (ADC value) with an element in the
 * calibration table. It is used by the bsearch function.
 *
 * @param key Pointer to the ADC value to search for.
 * @param element Pointer to the calibration table element.
 * @return Negative if key < element, 0 if equal, positive if key > element.
 */
int compare_adc(const void *key, const void *element) {
    uint16_t key_value = *(uint16_t *)key;
    CalibrationPoint cp;
    memcpy_P(&cp, element, sizeof(CalibrationPoint));
    return (key_value - cp.adc_value);
}

/**
 * @brief Initialize the ADC.
 *
 * Configures the ADC to use AVcc as the reference voltage and sets the
 * prescaler to 128 for optimal accuracy at 16 MHz.
 */
void init_adc() {
    ADMUX = (1 << REFS0); // Use AVcc as reference
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC, prescaler = 128
}

/**
 * @brief Read ADC value from a specific channel.
 *
 * This function reads a 10-bit ADC value from the specified channel.
 *
 * @param channel The ADC channel to read from (0-7).
 * @return The 10-bit ADC value (0-1023).
 */
uint16_t read_adc(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F); // Select ADC channel
    ADCSRA |= (1 << ADSC);                     // Start conversion
    while (ADCSRA & (1 << ADSC));              // Wait for conversion to complete
    return ADC;
}

/**
 * @brief Transmit a single character over UART.
 *
 * @param data The character to transmit.
 */
void uart_transmit(char data) {
    while (!(UCSR0A & (1 << UDRE0))); // Wait for buffer to be empty
    UDR0 = data;
}

/**
 * @brief Print a string over UART.
 *
 * Transmits a null-terminated string over UART.
 *
 * @param str Pointer to the string to transmit.
 */
void uart_print(const char *str) {
    while (*str) {
        uart_transmit(*str++);
    }
}

/**
 * @brief Main function.
 *
 * This function initializes the ADC and UART, reads ADC values, finds the
 * closest calibration point using binary search, and outputs the result over UART.
 *
 * @return This function does not return.
 */
int main() {
    uint16_t adc_value; ///< Variable to store the raw ADC value
    CalibrationPoint *result; ///< Pointer to the matching calibration point
    int8_t temperature; ///< Variable to store the calibrated temperature

    init_adc(); // Initialize ADC

    // UART configuration for debugging
    UBRR0H = 0;
    UBRR0L = 103; // 9600 baud rate
    UCSR0B = (1 << TXEN0); // Enable UART transmitter
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data

    while (1) {
        adc_value = read_adc(0); // Read ADC value from channel 0

        // Find the closest calibration point
        result = (CalibrationPoint *)bsearch(&adc_value, calibration_table, TABLE_SIZE, sizeof(CalibrationPoint), compare_adc);

        if (result) {
            memcpy_P(&temperature, &result->temperature, sizeof(int8_t));
            char buffer[32];
            sprintf(buffer, "ADC: %u, Temp: %d\u00B0C\n", adc_value, temperature);
            uart_print(buffer); // Print result via UART
        } else {
            uart_print("Value out of range\n");
        }

        _delay_ms(1000); // Delay for 1 second
    }

    return 0;
}
