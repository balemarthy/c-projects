/**
 * @file uart.h
 * @brief UART initialization and I/O functions.
 */

#ifndef UART_H
#define UART_H

#include <stdint.h>

/**
 * @brief Initializes UART with chosen baud rate etc.
 */
void uartInit(void);

/**
 * @brief Transmits a single byte over UART.
 */
void uartTransmit(uint8_t data);

/**
 * @brief Transmits a null-terminated string over UART.
 */
void uartPrint(const char *str);

/**
 * @brief Example function to check if a full line is available.
 *        (Implementation can vary: ring buffer, polling, etc.)
 * @param buffer Where to store the read line.
 * @param bufferSize The max size for the line.
 * @return 1 if a line was read, 0 otherwise.
 */
uint8_t uartLineAvailable(char *buffer, uint8_t bufferSize);

#endif /* UART_H */
