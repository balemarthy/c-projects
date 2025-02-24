/**
 * @file state_machine.c
 * @brief Implementation of State Machine for Sugarcane Juice Vending Machine
 * @author 
 * @version 1.0
 * @date 2025
 *
 * @details
 * This file implements the logic for state transitions in the vending machine.
 * It ensures smooth operation from user input to dispensing and completion.
 */

#include "state_machine.h"
#include <util/delay.h>

/** Global variable to track the machine's state */
static State currentState = IDLE;

/** Global flag to track button press event */
volatile uint8_t buttonPressed = 0;

/**
 * @brief Initializes the state machine.
 *
 * Sets the system to IDLE state and ensures hardware is ready.
 */
void initStateMachine(void) {
    currentState = IDLE;
    updateLEDStatus();
}

/**
 * @brief Runs the state machine loop.
 *
 * Handles transitions between different states.
 */
void runStateMachine(void) {
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
