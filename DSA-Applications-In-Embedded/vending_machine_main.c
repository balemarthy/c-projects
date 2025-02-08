/**
 * @file main.c
 * @brief Sugarcane Juice Vending Machine (MVP)
 * @author Open Source Contributor
 * @version 1.0
 * @date 2024
 * 
 * @details
 * This firmware controls a simple vending machine that dispenses sugarcane juice. 
 * It follows a state machine model and interacts with hardware components such as 
 * a button, float switch, solenoid valve, LEDs, and a buzzer.
 *
 * Target Microcontroller: ATmega2560
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/** @defgroup Hardware GPIO Pin Definitions */
///@{
#define BUTTON_PIN     PD2  /**< Button for juice dispensing */
#define FLOAT_SWITCH   PD3  /**< Float switch for juice level detection */
#define VALVE_CONTROL  PD4  /**< Solenoid valve control */
#define GREEN_LED      PD5  /**< Green LED for machine status */
#define ORANGE_LED     PD6  /**< Orange LED for low juice warning */
#define BUZZER         PD7  /**< Buzzer for audio alerts */
///@}

/** @defgroup State Machine States */
///@{
typedef enum {
    IDLE,             /**< Machine is idle and ready for user input */
    CHECK_JUICE_LEVEL,/**< Checks if juice is available */
    DISPENSING,       /**< Dispensing process in progress */
    COMPLETION        /**< Juice has been dispensed successfully */
} State;
///@}

/** Global variable to track the machine's state */
volatile State currentState = IDLE;

/** Global flag to track button press event */
volatile uint8_t buttonPressed = 0;

/** 
 * @brief Initializes hardware components 
 * 
 * Configures GPIO pins, enables pull-ups, and sets up external interrupts.
 */
void initHardware(void);

/** 
 * @brief Handles button press debounce logic 
 * 
 * Ensures only valid button presses are registered.
 */
void debounceButton(void);

/** 
 * @brief Starts the dispensing process 
 * 
 * Opens the solenoid valve and updates LED status.
 */
void startDispensing(void);

/** 
 * @brief Stops the dispensing process 
 * 
 * Closes the solenoid valve and resets LED status.
 */
void stopDispensing(void);

/** 
 * @brief Updates LED indicators based on machine state 
 */
void updateLEDStatus(void);

/** 
 * @brief Plays a buzzer sound based on the event type 
 * @param type Type of beep (1 = warning, 2 = completion)
 */
void playBuzzerSound(uint8_t type);

/**
 * @brief Interrupt Service Routine for Button Press
 * @details Debounces the button press and sets the event flag.
 */
ISR(INT0_vect) {
    debounceButton();
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
                _delay_ms(3000); // Simulate dispensing time
                stopDispensing();
                playBuzzerSound(2); // Single long beep for completion
                currentState = COMPLETION;
                break;

            case COMPLETION:
                _delay_ms(3000); // 3s cooldown before allowing next dispensing
                currentState = IDLE;
                break;
        }
    }
}

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

void debounceButton(void) {
    _delay_ms(50); // Simple debounce delay
    if (!(PIND & (1 << BUTTON_PIN))) {
        buttonPressed = 1;
    }
}

void startDispensing(void) {
    PORTD |= (1 << VALVE_CONTROL);  // Open valve
    PORTD |= (1 << GREEN_LED);      // Indicate dispensing
}

void stopDispensing(void) {
    PORTD &= ~(1 << VALVE_CONTROL);  // Close valve
    PORTD &= ~(1 << GREEN_LED);      // Stop indicating dispensing
}

void updateLEDStatus(void) {
    PORTD |= (1 << GREEN_LED); // Machine is ready
    PORTD &= ~(1 << ORANGE_LED); // Reset warning LED
}

void playBuzzerSound(uint8_t type) {
    switch (type) {
        case 1: // Low Juice Warning (Fast Beeps)
            for (int i = 0; i < 5; i++) {
                PORTD |= (1 << BUZZER);
                _delay_ms(50);
                PORTD &= ~(1 << BUZZER);
                _delay_ms(50);
            }
            break;
        case 2: // Dispensing Complete (Single Long Beep)
            PORTD |= (1 << BUZZER);
            _delay_ms(300);
            PORTD &= ~(1 << BUZZER);
            break;
    }
}
