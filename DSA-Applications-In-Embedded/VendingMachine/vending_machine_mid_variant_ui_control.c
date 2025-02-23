/**
 * @file ui_control.c
 * @brief Implementation of User Interface for Sugarcane Juice Vending Machine
 * @author 
 * @version 1.0
 * @date 2025
 *
 * @details
 * This module handles user input from a rotary encoder and buttons.
 * It also updates the OLED display for menu navigation and user feedback.
 */

#include "ui_control.h"
#include <util/delay.h>

/** Global variable to track UI state */
static UIState currentUIState = UI_IDLE;

/** Global variables to track user selection */
static uint8_t juiceType = 0;  /**< Selected juice type index */
static uint8_t volume = 1;     /**< Selected volume: 1=Small, 2=Medium, 3=Large */

/**
 * @brief Initializes the user interface components.
 *
 * Configures rotary encoder, buttons, and OLED display.
 */
void initUI(void) {
    // Set pin directions
    DDRC &= ~(1 << ROTARY_CLK);  // Rotary encoder CLK as input
    DDRC &= ~(1 << ROTARY_DT);   // Rotary encoder DT as input
    DDRC &= ~(1 << ROTARY_SW);   // Rotary encoder button as input
    DDRC &= ~(1 << CONFIRM_BTN); // Confirmation button as input

    // Enable internal pull-up resistors
    PORTC |= (1 << ROTARY_CLK) | (1 << ROTARY_DT) | (1 << ROTARY_SW) | (1 << CONFIRM_BTN);

    // Initialize OLED display (placeholder function)
    updateDisplay();
}

/**
 * @brief Reads user input from rotary encoder and buttons.
 *
 * Updates selection variables and detects confirmation.
 */
void readUserInput(void) {
    static uint8_t lastRotaryState = 0;

    uint8_t rotaryState = PINC & (1 << ROTARY_CLK);
    if (rotaryState != lastRotaryState) {
        if (PINC & (1 << ROTARY_DT)) {
            juiceType = (juiceType + 1) % 3;  // Cycle through juice options
        } else {
            if (juiceType > 0) juiceType--;  // Cycle backwards
        }
        updateDisplay();  // Update OLED with new selection
    }
    lastRotaryState = rotaryState;

    // Check rotary encoder button press
    if (!(PINC & (1 << ROTARY_SW))) {
        volume = (volume % 3) + 1;  // Cycle through volume options
        updateDisplay();
        _delay_ms(200);  // Debounce delay
    }

    // Check confirmation button press
    if (!(PINC & (1 << CONFIRM_BTN))) {
        currentUIState = UI_CONFIRMATION;
        updateDisplay();
        _delay_ms(200);  // Debounce delay
    }
}

/**
 * @brief Updates the OLED display with current menu selection.
 *
 * Shows juice type, quantity, and confirmation options.
 */
void updateDisplay(void) {
    // Placeholder function to update OLED display
    // In actual implementation, use I2C/SPI commands to send text to OLED
}

