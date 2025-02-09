/**
 * @file main.c
 * @brief Sugarcane Juice Vending Machine (MVP) - Main Control File
 * @author Open Source Contributor
 * @version 1.1
 * @date 2024
 * 
 * @details
 * This firmware controls a simple vending machine that dispenses sugarcane juice. 
 * It follows a state machine model and interacts with hardware components via `hardware.h`.
 *
 * Target Microcontroller: ATmega2560
 */

#include "hardware.h"
#include <util/delay.h>
#include <avr/interrupt.h>

/** Global variable to track the machine's state */
volatile State currentState = IDLE;

/** Global flag to track button press event */
volatile uint8_t buttonPressed = 0;

/**
 * @brief Interrupt Service Routine for Button Press
 * @details Debounces the button press and sets the event flag.
 */
ISR(INT0_vect) {
    _delay_ms(50); // Simple debounce delay
    if (!(PIND & (1 << BUTTON_PIN))) {
        buttonPressed = 1;
    }
}

/**
 * @brief Main function implementing the state machine loop.
 */
int main(void) {
    initHardware();  // Initialize hardware components

    while (1) {
        switch (currentState) {
            case IDLE:
                updateLEDStatus();
                if (buttonPressed) {
                    currentState = CHECK_JUICE_LEVEL;
                    buttonPressed = 0;
                }
                break;

            case CHECK_JUICE_LEVEL:
                if (PIND & (1 << FLOAT_SWITCH)) {  // Check if juice is available
                    currentState = DISPENSING;
                    startDispensing();
                } else {
                    PORTD |= (1 << ORANGE_LED);  // Indicate low juice warning
                    playBuzzerSound(1); // Fast beeps for low juice warning
                    currentState = IDLE;
                }
                break;

            case DISPENSING:
                _delay_ms(DISPENSE_TIME_MS); // Simulate dispensing time
                stopDispensing();
                playBuzzerSound(2); // Single long beep for completion
                currentState = COMPLETION;
                break;

            case COMPLETION:
                _delay_ms(COOLDOWN_TIME_MS); // Cooldown before allowing next dispense
                currentState = IDLE;
                break;
        }
    }
}
