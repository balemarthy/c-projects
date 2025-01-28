/**
 * @file event_logger.c
 * @brief Implements circular buffer and logging features.
 */

#include "event_logger.h"
#include "uart.h"         // For printing logs via UART
//#include "timestamp.h"   // If using timestamps
//#include "categories.h"  // If you have a separate file for categories

// Example ring buffer size
#define BUFFER_SIZE 16

// Example categories (if not using categories.h)
#define EVENT_ERROR  (1 << 0)
#define EVENT_SENSOR (1 << 1)
#define EVENT_INFO   (1 << 2)

/**
 * @brief Structure for a single log event.
 */
typedef struct {
    uint8_t  category;
    uint16_t data;
    // uint32_t timestamp; // if using timestamps
} LogEvent;

/**
 * @brief Circular buffer data.
 */
static LogEvent logBuffer[BUFFER_SIZE];
static uint8_t head = 0;
static uint8_t tail = 0;
static uint8_t count = 0;

// Track which categories are enabled
static uint8_t enabledCategories = (EVENT_ERROR | EVENT_SENSOR);

void loggerInit(void)
{
    head = tail = count = 0;
    // Enable some default categories here if desired
    enabledCategories = (EVENT_ERROR | EVENT_SENSOR);
}

void logEvent(uint8_t category, uint16_t data)
{
    // Check if the category is enabled
    if (!(enabledCategories & category)) {
        return;
    }

    // Prepare the event
    LogEvent newEvent;
    newEvent.category = category;
    newEvent.data = data;
    // newEvent.timestamp = getTimestamp(); // if using a time function

    // Enqueue if space
    if (count < BUFFER_SIZE) {
        logBuffer[head] = newEvent;
        head = (head + 1) % BUFFER_SIZE;
        count++;
    } else {
        // Buffer full -> decide to drop or overwrite
    }
}

void flushLog(void)
{
    // Dequeue and print
    while (count > 0) {
        LogEvent e = logBuffer[tail];
        tail = (tail + 1) % BUFFER_SIZE;
        count--;

        // Print or save
        // For simplicity, print over UART
        // Format: "Cat: X, Data: Y\n"
        uartPrint("Cat:");
        uartTransmit('0' + e.category); // naive single-digit print
        uartPrint(", Data:");
        // convert e.data to string here if desired
        uartPrint("??\r\n");
    }
}

void enableCategory(uint8_t category)
{
    enabledCategories |= category;
}

void disableCategory(uint8_t category)
{
    enabledCategories &= ~category;
}
