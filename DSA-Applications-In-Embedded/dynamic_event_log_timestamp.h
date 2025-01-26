/**
 * @file timestamp.h
 * @brief Simple interface for obtaining a system timestamp.
 */

#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <stdint.h>

/**
 * @brief Initializes any timers or counters needed for timestamping.
 */
void initTimestamp(void);

/**
 * @brief Returns the current timestamp (e.g., milliseconds since startup).
 */
uint32_t getTimestamp(void);

#endif /* TIMESTAMP_H */
