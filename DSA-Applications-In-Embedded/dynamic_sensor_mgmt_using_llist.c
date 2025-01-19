
/**
 * @file main.c
 * @brief Dynamic Sensor Configuration Manager
 *
 * This program implements a dynamic sensor manager using a linked list.
 * Sensors can be added, removed, and displayed dynamically, with details 
 * sent to a serial terminal via UART.
 *
 * @details
 * - Uses structures to represent sensor data.
 * - Demonstrates dynamic memory allocation and linked list traversal.
 * - Ideal for early-career developers learning data structures in embedded systems.
 *
 * ### Compilation Commands:
 * 
 * avr-gcc -mmcu=atmega2560 -DF_CPU=16000000UL -O2 main.c -o main.elf
 * avr-objcopy -O ihex main.elf main.hex
 * 
 *
 * ### Flashing Command:
 * 
 * avrdude -c arduino -p m2560 -P /dev/ttyUSB0 -b 115200 -U flash:w:main.hex
 * 
 *
 * ### Doxygen Command:
 * 
 * doxygen -g
 * doxygen Doxyfile
 * 
 */

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

// Define the Sensor structure
/**
 * @brief Structure representing a sensor.
 */
typedef struct Sensor {
    uint8_t id;          /**< Sensor ID */
    char type[10];       /**< Sensor type (e.g., "Temp") */
    uint16_t config;     /**< Configuration value (e.g., threshold) */
    struct Sensor* next; /**< Pointer to the next sensor */
} Sensor;

// Head of the linked list
Sensor* sensor_list_head = NULL;

/**
 * @brief Initialize UART for serial communication.
 */
void init_uart() {
    UBRR0H = 0;
    UBRR0L = 103; // 9600 baud rate
    UCSR0B = (1 << TXEN0); // Enable transmitter
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8 data bits
}

/**
 * @brief Transmit a single character over UART.
 * @param data Character to transmit.
 */
void uart_transmit(char data) {
    while (!(UCSR0A & (1 << UDRE0))); // Wait for buffer
    UDR0 = data;
}

/**
 * @brief Transmit a string over UART.
 * @param str Null-terminated string to transmit.
 */
void uart_print(const char* str) {
    while (*str) {
        uart_transmit(*str++);
    }
}

/**
 * @brief Add a new sensor to the list.
 * @param id Sensor ID.
 * @param type Sensor type (e.g., "Temp").
 * @param config Sensor configuration value.
 */
void add_sensor(uint8_t id, const char* type, uint16_t config) {
    Sensor* new_sensor = (Sensor*)malloc(sizeof(Sensor));
    if (new_sensor == NULL) {
        uart_print("Memory allocation failed\n");
        return;
    }
    new_sensor->id = id;
    strcpy(new_sensor->type, type);
    new_sensor->config = config;
    new_sensor->next = sensor_list_head;
    sensor_list_head = new_sensor;
    uart_print("Sensor added successfully\n");
}

/**
 * @brief Remove a sensor from the list by ID.
 * @param id Sensor ID to remove.
 */
void remove_sensor(uint8_t id) {
    Sensor* current = sensor_list_head;
    Sensor* previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                sensor_list_head = current->next; // Remove head
            } else {
                previous->next = current->next; // Remove non-head
            }
            free(current);
            uart_print("Sensor removed successfully\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    uart_print("Sensor not found\n");
}

/**
 * @brief Display all sensors in the list.
 */
void display_sensors() {
    Sensor* current = sensor_list_head;

    if (current == NULL) {
        uart_print("No sensors to display\n");
        return;
    }

    while (current != NULL) {
        char buffer[64];
        sprintf(buffer, "ID: %d, Type: %s, Config: %d\n", current->id, current->type, current->config);
        uart_print(buffer);
        current = current->next;
    }
}

/**
 * @brief Main function to demonstrate sensor management.
 */
int main() {
    // Initialize UART
    init_uart();

    // Add sensors
    add_sensor(1, "Temp", 100);
    add_sensor(2, "Pressure", 200);

    // Display sensors
    uart_print("Sensor List:\n");
    display_sensors();

    // Remove a sensor
    remove_sensor(1);

    // Display sensors again
    uart_print("Updated Sensor List:\n");
    display_sensors();

    while (1) {
        // Main loop
        // Implement your application code here
    }

    return 0;
}
