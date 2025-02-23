/**
 * @file debounce.h
 * @brief Button Debounce Header for Sugarcane Juice Vending Machine
 * @author 
 * @version 1.0
 * @date 2025
 *
 * @details
 * This file provides the function prototype for debouncing button inputs.
 */

#ifndef DEBOUNCE_H
#define DEBOUNCE_H

#include "hardware.h"

/**
 * @brief Debounces the button press.
 *
 * Ensures that only valid button presses are registered by checking stability over time.
 */
void debounceButton(void);

#endif // DEBOUNCE_H
