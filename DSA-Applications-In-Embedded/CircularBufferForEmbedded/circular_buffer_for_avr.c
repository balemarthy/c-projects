/**
 * @file circular_queue.c
 * @brief Demonstrates a circular (ring) buffer for AVR real-time data streaming using UART.
 *
 * This file sets up a UART interrupt for receiving bytes and stores them in a circular queue.
 * The main loop echoes received bytes and toggles an LED to show activity. It can be extended
 * for sensor/ADC data as well.
 *
 * @author
 *   Vamsi (Adjust or add your name/organization here)
 *
 * @copyright
 *   MIT License or any license of your preference
 */

/* ---------------- Includes ---------------- */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/* ---------------- Configuration ---------------- */
#ifndef F_CPU
#define F_CPU 16000000UL /**< CPU Frequency (Adjust if different) */
#endif

#define BAUD_RATE 9600   /**< UART Baud Rate */
#define UBRR_VALUE ((F_CPU / (16UL * BAUD_RATE)) - 1)

/**
 * @def BUFFER_SIZE
 * @brief Size of the circular queue buffer in bytes.
 */
#define BUFFER_SIZE 32

/* ---------------- Type Definitions ---------------- */
/**
 * @struct CircularQueue
 * @brief Structure representing the circular buffer.
 */
typedef struct {
    uint8_t buffer[BUFFER_SIZE];   /**< Storage for queue data */
    volatile uint8_t head;         /**< Index for enqueue (insertion) */
    volatile uint8_t tail;         /**< Index for dequeue (removal) */
    volatile uint8_t count;        /**< Number of elements currently in the queue */
} CircularQueue;

/* ---------------- Global Variables ---------------- */
/**
 * @var rxQueue
 * @brief Global instance of the circular queue to hold UART RX data.
 */
CircularQueue rxQueue;

/* ---------------- Function Prototypes ---------------- */
/**
 * @brief Initializes the circular queue to empty.
 *
 * @param q Pointer to the CircularQueue to initialize.
 */
void queueInit(CircularQueue *q);

/**
 * @brief Checks if the queue is empty.
 *
 * @param q Pointer to the CircularQueue.
 * @return 1 if empty, 0 otherwise.
 */
uint8_t queueIsEmpty(CircularQueue *q);

/**
 * @brief Checks if the queue is full.
 *
 * @param q Pointer to the CircularQueue.
 * @return 1 if full, 0 otherwise.
 */
uint8_t queueIsFull(CircularQueue *q);

/**
 * @brief Enqueues one byte of data.
 *
 * @param q Pointer to the CircularQueue.
 * @param data Byte to be inserted.
 * @return 1 on success, 0 if the queue is full.
 */
uint8_t enqueue(CircularQueue *q, uint8_t data);

/**
 * @brief Dequeues one byte of data.
 *
 * @param q Pointer to the CircularQueue.
 * @param data Pointer to variable where the dequeued byte will be stored.
 * @return 1 on success, 0 if the queue is empty.
 */
uint8_t dequeue(CircularQueue *q, uint8_t *data);

/**
 * @brief Initializes UART at the specified BAUD rate and enables RX interrupt.
 */
void uartInit(void);

/**
 * @brief Transmits a single byte via UART.
 *
 * @param data Byte to transmit.
 */
void uartTransmit(uint8_t data);

/* ---------------- Implementation ---------------- */

void queueInit(CircularQueue *q) {
    q->head  = 0;
    q->tail  = 0;
    q->count = 0;
}

uint8_t queueIsEmpty(CircularQueue *q) {
    return (q->count == 0);
}

uint8_t queueIsFull(CircularQueue *q) {
    return (q->count == BUFFER_SIZE);
}

uint8_t enqueue(CircularQueue *q, uint8_t data) {
    if (queueIsFull(q)) {
        // Buffer is full, can't enqueue
        return 0;
    }
    q->buffer[q->head] = data;
    q->head = (q->head + 1) % BUFFER_SIZE;
    q->count++;
    return 1;
}

uint8_t dequeue(CircularQueue *q, uint8_t *data) {
    if (queueIsEmpty(q)) {
        // Buffer is empty, can't dequeue
        return 0;
    }
    *data = q->buffer[q->tail];
    q->tail = (q->tail + 1) % BUFFER_SIZE;
    q->count--;
    return 1;
}

void uartInit(void) {
    // Set baud rate
    UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
    UBRR0L = (uint8_t)UBRR_VALUE;

    // Enable RX, TX, and RX interrupt
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);

    // 8-bit data, 1 stop bit, no parity
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uartTransmit(uint8_t data) {
    // Wait until the UART Data Register is empty
    while (!(UCSR0A & (1 << UDRE0))) {
        // Spin until ready
    }
    UDR0 = data;
}

/**
 * @brief ISR for UART Receive. Automatically called on receiving a byte.
 *
 * Reads from UDR0 and enqueues the received byte.
 */
ISR(USART_RX_vect) {
    uint8_t receivedByte = UDR0;
    enqueue(&rxQueue, receivedByte);
}

/**
 * @brief Main function demonstrating usage of the circular queue.
 *
 * Initializes queue, UART, and an LED on PD6. 
 * Repeatedly dequeues and echoes bytes, toggling an LED for visual feedback.
 */
int main(void) {
    // Initialize the queue
    queueInit(&rxQueue);

    // Initialize UART
    uartInit();

    // Example LED indicator: PD6 as output
    DDRD |= (1 << PD6);

    // Enable global interrupts
    sei();

    while (1) {
        if (!queueIsEmpty(&rxQueue)) {
            uint8_t data;
            if (dequeue(&rxQueue, &data)) {
                // Echo data back
                uartTransmit(data);
                // Toggle LED to indicate activity
                PORTD ^= (1 << PD6);
            }
        }
        // Small delay to avoid overly busy loop
        _delay_ms(100);
    }

    return 0;
}
