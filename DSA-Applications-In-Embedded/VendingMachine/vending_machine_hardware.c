/**
 * @file hardware.c
 * @brief Implementation of hardware control functions for Sugarcane Juice Vending Machine
 * @author 
 * @version 1.0
 * @date 2025
 *
 * @details
 * This file implements the functions declared in `hardware.h`.
 * It provides control for the solenoid valve, LEDs, buzzer, and button debounce logic.
 */

#include "hardware.h"
#include <util/delay.h>

/**
 * @brief Initializes all hardware components.
 *
 * Configures GPIO pins, enables pull-ups, and sets up external interrupts.
 */
void initHardware(void) {
    // Set pin modes
    DDRD &= ~(1 << BUTTON_PIN);      // Button as input
    DDRD &= ~(1 << FLOAT_SWITCH);    // Float switch as input
    DDRD |= (1 << VALVE_CONTROL);    // Valve as output
    DDRD |= (1 << GREEN_LED);        // Green LED as output
    DDRD |= (1 << ORANGE_LED);       // Orange LED as output
    DDRD |= (1 << BUZZER);           // Buzzer as output

    // Enable pull-up resistor on button
    PORTD |= (1 << BUTTON_PIN);

    // Enable External Interrupt for button press (Falling Edge Trigger)
    EICRA |= (1 << ISC01); // Falling edge INT0
    EIMSK |= (1 << INT0);  // Enable INT0

    sei(); // Enable global interrupts
}

/**
 * @brief Starts the juice dispensing process.
 *
 * Opens the solenoid valve and turns on the green LED.
 */
void startDispensing(void) {
    PORTD |= (1 << VALVE_CONTROL);  // Open valve
    PORTD |= (1 << GREEN_LED);      // Indicate dispensing
}

/**
 * @brief Stops the juice dispensing process.
 *
 * Closes the solenoid valve and resets the green LED.
 */
void stopDispensing(void) {
    PORTD &= ~(1 << VALVE_CONTROL);  // Close valve
    PORTD &= ~(1 << GREEN_LED);      // Stop indicating dispensing
}

/**
 * @brief Updates LED indicators based on machine state.
 */
void updateLEDStatus(void) {
    PORTD |= (1 << GREEN_LED); // Machine is ready
    PORTD &= ~(1 << ORANGE_LED); // Reset warning LED
}

/**
 * @brief Plays a buzzer sound based on the event type.
 * @param type Type of beep (1 = warning, 2 = completion).
 */
void playBuzzerSound(uint8_t type) {
    switch (type) {
        case 1: // Low Juice Warning (Fast Beeps)
            for (int i = 0; i < 5; i++) {
                PORTD |= (1 << BUZZER);
                _delay_ms(BUZZER_WARNING_BEEP);
                PORTD &= ~(1 << BUZZER);
                _delay_ms(BUZZER_WARNING_BEEP);
            }
            break;
        case 2: // Dispensing Complete (Single Long Beep)
            PORTD |= (1 << BUZZER);
            _delay_ms(BUZZER_COMPLETE_BEEP);
            PORTD &= ~(1 << BUZZER);
            break;
    }
}
