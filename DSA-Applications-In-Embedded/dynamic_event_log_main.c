/**
 * @file main.c
 * @brief Application entry point.
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "event_logger.h"
#include "command_parser.h"
#include "uart.h"
// #include "timestamp.h"     // if using timestamps
// #include "categories.h"   // if using a separate file for event categories

int main(void)
{
    // Initialize system components
    uartInit();
    loggerInit();
    // initTimestamp(); // if you have a timestamp module

    // Enable global interrupts (if your UART is interrupt-driven)
    sei();

    while (1)
    {
        // Example usage: check for incoming commands
        checkAndHandleCommands();

        // Example logging call:
        // logEvent(EVENT_SENSOR, readFakeSensor());

        // Add your main application logic here
    }

    return 0;
}
