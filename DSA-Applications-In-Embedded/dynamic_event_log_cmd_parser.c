/**
 * @file command_parser.c
 * @brief Parses commands like "ENABLE SENSOR", "DISABLE ERROR", "FLUSH", etc.
 */

#include "command_parser.h"
#include "event_logger.h"
#include "uart.h"

#include <string.h> // For string functions
#include <stdio.h>  // For sprintf, etc.

void checkAndHandleCommands(void)
{
    // Example approach: check if there's a line ready from UART
    // This is just dummy logic, real code may differ.

    static char cmdBuffer[32];
    // Suppose we have a function that returns 1 if a line was read
    // from UART, storing it in cmdBuffer:
    if (uartLineAvailable(cmdBuffer, sizeof(cmdBuffer))) {
        if (strncmp(cmdBuffer, "ENABLE ", 7) == 0) {
            // parse which category
            // enableCategory(EVENT_SENSOR); // example
            uartPrint("Enabled something...\r\n");
        }
        else if (strncmp(cmdBuffer, "DISABLE ", 8) == 0) {
            // parse category
            // disableCategory(EVENT_SENSOR);
            uartPrint("Disabled something...\r\n");
        }
        else if (strcmp(cmdBuffer, "FLUSH") == 0) {
            flushLog();
        }
        else if (strcmp(cmdBuffer, "STATUS") == 0) {
            // print current categories or buffer stats
            uartPrint("STATUS: ...\r\n");
        }
        else {
            uartPrint("Unknown command\r\n");
        }
    }
}
