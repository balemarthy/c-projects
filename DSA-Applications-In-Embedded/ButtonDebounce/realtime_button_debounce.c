
/**
 * @file main.c
 * @brief Real-Time Button Debounce Manager
 *
 * This program dynamically manages multiple buttons with debounce handling
 * and triggers callback functions when a button press is detected. Each button
 * is represented as a structure stored in a linked list.
 *
 * @details
 * - Dynamically adds and removes buttons at runtime.
 * - Implements debouncing to avoid false triggers.
 * - Demonstrates event-driven programming using callback functions.
 *
 * ### Compilation Commands:
 * ```bash
 * avr-gcc -mmcu=atmega2560 -DF_CPU=16000000UL -O2 main.c -o main.elf
 * avr-objcopy -O ihex main.elf main.hex
 * ```
 *
 * ### Flashing Command:
 * ```bash
 * avrdude -c arduino -p m2560 -P /dev/ttyUSB0 -b 115200 -U flash:w:main.hex
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
#include <stdlib.h>

// Define the Button structure
/**
 * @brief Structure representing a button.
 */
typedef struct Button {
    uint8_t pin;                 /**< GPIO pin connected to the button */
    uint8_t state;               /**< Current state of the button (pressed/released) */
    uint16_t debounce_time;      /**< Debounce interval in milliseconds */
    void (*callback)(void);      /**< Callback function on button press */
    struct Button* next;         /**< Pointer to the next button in the list */
} Button;

// Head of the linked list
Button* button_list_head = NULL;

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
 * @brief Add a button to the debounce manager.
 * @param pin GPIO pin connected to the button.
 * @param debounce_time Debounce interval in milliseconds.
 * @param callback Function to call on button press.
 */
void add_button(uint8_t pin, uint16_t debounce_time, void (*callback)(void)) {
    Button* new_button = (Button*)malloc(sizeof(Button));
    if (new_button == NULL) {
        // Memory allocation failed
        return;
    }
    new_button->pin = pin;
    new_button->state = 0; // Initial state is "not pressed"
    new_button->debounce_time = debounce_time;
    new_button->callback = callback;
    new_button->next = button_list_head;
    button_list_head = new_button; // Add to the front of the list

    // Set the pin as input
    DDRD &= ~(1 << pin); // Set pin as input
    PORTD |= (1 << pin); // Enable pull-up resistor
}

/**
 * @brief Remove a button from the debounce manager by its pin.
 * @param pin GPIO pin connected to the button.
 */
void remove_button(uint8_t pin) {
    Button* current = button_list_head;
    Button* previous = NULL;

    while (current != NULL) {
        if (current->pin == pin) {
            if (previous == NULL) {
                button_list_head = current->next; // Remove head
            } else {
                previous->next = current->next; // Remove non-head
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

/**
 * @brief Debounce all buttons in the list.
 */
void debounce_buttons() {
    Button* current = button_list_head;

    while (current != NULL) {
        uint8_t current_state = !(PIND & (1 << current->pin)); // Active low
        if (current_state != current->state) {
            _delay_ms(current->debounce_time); // Debounce delay
            if (current_state == !(PIND & (1 << current->pin))) {
                current->state = current_state;
                if (current_state) {
                    current->callback(); // Trigger callback on press
                }
            }
        }
        current = current->next;
    }
}

// Example callback functions
void button1_pressed() {
    PORTB ^= (1 << PB0); // Toggle LED on PB0
}

void button2_pressed() {
    PORTB ^= (1 << PB1); // Toggle LED on PB1
}

int main() {
    // Initialize UART (optional debugging)
    init_uart();

    // Configure LEDs as outputs
    DDRB |= (1 << PB0) | (1 << PB1); // LEDs on PB0 and PB1

    // Add buttons to the debounce manager
    add_button(2, 50, button1_pressed); // Button on PD2
    add_button(3, 50, button2_pressed); // Button on PD3

    while (1) {
        debounce_buttons(); // Monitor and debounce buttons
    }

    return 0;
}
