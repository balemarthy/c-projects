/**
 * @file event_logger.h
 * @brief Circular buffer and logging function declarations.
 */

#ifndef EVENT_LOGGER_H
#define EVENT_LOGGER_H

#include <stdint.h>

/**
 * @brief Initializes the logger (resets buffers, etc.).
 */
void loggerInit(void);

/**
 * @brief Logs an event if the category is enabled.
 *
 * @param category A bitmask representing the event category.
 * @param data     A 16-bit data value (sensor reading, error code, etc.).
 */
void logEvent(uint8_t category, uint16_t data);

/**
 * @brief Flushes all logged events (prints/saves them).
 */
void flushLog(void);

/**
 * @brief Enables logging for a specific category bit.
 */
void enableCategory(uint8_t category);

/**
 * @brief Disables logging for a specific category bit.
 */
void disableCategory(uint8_t category);

#endif /* EVENT_LOGGER_H */
