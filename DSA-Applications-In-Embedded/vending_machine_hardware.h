/**
 * @file hardware.h
 * @brief Hardware Abstraction Layer (HAL) for Sugarcane Juice Vending Machine
 * @author 
 * @version 1.0
 * @date 2025
 *
 * @details
 * This file contains the hardware-related definitions, macros, and function
 * prototypes required for interfacing with physical components such as buttons,
 * LEDs, solenoid valve, float switch, and buzzer.
 *
 * Target Microcontroller: ATmega2560
 */

#ifndef HARDWARE_H
#define HARDWARE_H

#include <avr/io.h>

/** @defgroup Hardware GPIO Pin Definitions */
///@{
#define BUTTON_PIN     PD2  /**< Button for juice dispensing */
#define FLOAT_SWITCH   PD3  /**< Float switch for juice level detection */
#define VALVE_CONTROL  PD4  /**< Solenoid valve control */
#define GREEN_LED      PD5  /**< Green LED for machine status */
#define ORANGE_LED     PD6  /**< Orange LED for low juice warning */
#define BUZZER         PD7  /**< Buzzer for audio alerts */
///@}

/** @defgroup Timing Macros */
///@{
#define DISPENSE_TIME_MS  3000  /**< Juice dispensing time in milliseconds */
#define COOLDOWN_TIME_MS  3000  /**< Cooldown time before next dispense */
#define BUZZER_WARNING_BEEP 50  /**< Short beep duration for warnings */
#define BUZZER_COMPLETE_BEEP 300 /**< Long beep duration for completion */
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

/** 
 * @brief Initializes all hardware components.
 *
 * Configures GPIO pins, enables pull-ups, and sets up external interrupts.
 */
void initHardware(void);

/** 
 * @brief Starts the juice dispensing process.
 *
 * Opens the solenoid valve and turns on the green LED.
 */
void startDispensing(void);

/** 
 * @brief Stops the juice dispensing process.
 *
 * Closes the solenoid valve and resets the green LED.
 */
void stopDispensing(void);

/** 
 * @brief Updates LED indicators based on machine state.
 */
void updateLEDStatus(void);

/** 
 * @brief Plays a buzzer sound based on the event type.
 * @param type Type of beep (1 = warning, 2 = completion).
 */
void playBuzzerSound(uint8_t type);

#endif // HARDWARE_H
