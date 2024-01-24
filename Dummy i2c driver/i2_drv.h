
#ifndef DRV_H
#define DRV_H

#include <stdint.h>

// I2C Device Structure
struct I2CDevice {
    uint16_t control;     // Control register, offset 0x00
    uint16_t status;      // Status register, offset 0x02
    uint16_t data;        // Data register, offset 0x04
    uint16_t address;     // Address register, offset 0x06
};

// Control Register Bitmasks
#define I2C_ENABLE 0x0001
#define I2C_START 0x0002
#define I2C_STOP 0x0004
#define I2C_READ 0x0008
#define I2C_WRITE 0x0010
#define I2C_ACK 0x0020

// Hardware state tracking
typedef struct {
    struct I2CDevice* i2c;
    int is_initialized;
} I2CDriverState;

// Function Prototypes
void initialize_i2c(I2CDriverState* state);
void i2c_start(I2CDriverState* state);
void i2c_stop(I2CDriverState* state);
void i2c_write(I2CDriverState* state, uint8_t data);
uint8_t i2c_read(I2CDriverState* state, int ack);
void i2c_isr(void);  // Interrupt Service Routine

#endif // DRV_H
