/**
 * @file debounce.c
 * @brief Button Debounce Logic for Sugarcane Juice Vending Machine
 * @author 
 * @version 1.0
 * @date 2025
 *
 * @details
 * This file implements a debounce algorithm to ensure stable button press detection.
 * The state-tracking method is used to avoid false triggers due to button bouncing.
 */

#include "hardware.h"
#include <util/delay.h>

/** @defgroup Debounce Configuration */
///@{
#define DEBOUNCE_DELAY_MS  20  /**< Debounce time in milliseconds */
///@}

/** Global variable to track stable button state */
static uint8_t previousButtonState = 1;

/** Global variable to track button press event */
extern volatile uint8_t buttonPressed;

/**
 * @brief Debounces the button press.
 *
 * Ensures that only valid button presses are registered by checking stability over time.
 */
void debounceButton(void) {
    uint8_t stableState = 1; // Assume button is not pressed

    for (uint8_t i = 0; i < 5; i++) { // Check stability for 5 cycles (~20ms total)
        if (!(PIND & (1 << BUTTON_PIN))) { // Button is pressed (Active LOW)
            stableState = 0;
        }
        _delay_ms(DEBOUNCE_DELAY_MS / 5); // Small delay for sampling
    }

    if (stableState == 0 && previousButtonState == 1) { // Detect valid press
        buttonPressed = 1;  // Register button press event
    }

    previousButtonState = stableState; // Store last button state
}
