/**
 * @file state_machine.h
 * @brief State Machine for Sugarcane Juice Vending Machine
 * @author 
 * @version 1.0
 * @date 2025
 *
 * @details
 * This file defines the state machine transitions for the vending machine.
 * It ensures a structured process for handling user input, checking juice levels,
 * controlling dispensing, and managing completion.
 */

#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "hardware.h"

/** 
 * @brief Initializes the state machine.
 *
 * Sets up the initial state and prepares the system for operation.
 */
void initStateMachine(void);

/** 
 * @brief Runs the state machine loop.
 *
 * This function should be called in the main loop to handle state transitions.
 */
void runStateMachine(void);

#endif // STATE_MACHINE_H
