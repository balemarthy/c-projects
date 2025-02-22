/**
 * @file ui_control.h
 * @brief User Interface Module for Sugarcane Juice Vending Machine
 * @author 
 * @version 1.0
 * @date 2025
 *
 * @details
 * This module handles user input via a rotary encoder and buttons.
 * It also updates the OLED display for menu navigation.
 */

#ifndef UI_CONTROL_H
#define UI_CONTROL_H

#include <avr/io.h>

/** @defgroup UI Hardware Pins */
///@{
#define ROTARY_CLK     PC0 /**< Rotary Encoder Clock Pin */
#define ROTARY_DT      PC1 /**< Rotary Encoder Data Pin */
#define ROTARY_SW      PC2 /**< Rotary Encoder Button */
#define CONFIRM_BTN    PC3 /**< Confirmation Button */
///@}

/** @defgroup OLED Display Definitions */
///@{
#define OLED_WIDTH  128  /**< OLED display width */
#define OLED_HEIGHT 64   /**< OLED display height */
///@}

/** @defgroup UI States */
///@{
typedef enum {
    UI_IDLE,          /**< Default state */
    UI_MENU_SELECT,   /**< User selecting juice type */
    UI_VOLUME_SELECT, /**< User selecting quantity */
    UI_CONFIRMATION   /**< User confirms selection */
} UIState;
///@}

/** 
 * @brief Initializes the user interface components.
 *
 * Configures rotary encoder, buttons, and OLED display.
 */
void initUI(void);

/** 
 * @brief Reads user input from rotary encoder and buttons.
 *
 * Updates selection variables and detects confirmation.
 */
void readUserInput(void);

/** 
 * @brief Updates the OLED display with current menu selection.
 *
 * Shows juice type, quantity, and confirmation options.
 */
void updateDisplay(void);

#endif // UI_CONTROL_H
