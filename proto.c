#include "proto.h"


/* setters prototypes */
void set_opcode(uint8_t);
void set_type(uint8_t);
void set_length(uint8_t);
void set_value(uint8_t *);
void set_chksum(uint16_t);

/* getters prototypes */
uint8_t get_opcode(void);
uint8_t get_type(void);
uint8_t get_length(void);
uint8_t *get_value(void);
uint16_t get_chksum(void);

// Temporarily silence the linker. The protocol files are supposed to get integrated with app file
int main(void) {

    return 0;

}
