/**
 * @file timestamp.c
 * @brief Provides a millisecond timer interrupt or other time base.
 */

#include "timestamp.h"
#include <avr/interrupt.h>

// Example: a simple millisecond counter using Timer0
static volatile uint32_t msCounter = 0;

void initTimestamp(void)
{
    // Configure Timer0 for ~1ms interrupts (on AVR at 16MHz, for instance)
    // This is just an example, adjust prescalers, etc. as needed.
    TCCR0A = (1 << WGM01);  // CTC mode
    OCR0A  = 249;           // 1ms at 16MHz with prescaler=64
    TCCR0B = (1 << CS01) | (1 << CS00); // prescaler=64
    TIMSK0 = (1 << OCIE0A); // enable compare match interrupt
}

uint32_t getTimestamp(void)
{
    uint32_t temp;
    // To avoid partial reads of volatile 32-bit variable
    cli();
    temp = msCounter;
    sei();
    return temp;
}

ISR(TIMER0_COMPA_vect)
{
    msCounter++;
}
