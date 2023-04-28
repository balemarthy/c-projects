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

/* Helper functions */
uint8_t create_msg();
uint8_t calculate_chksum();

/* APIs */
uint8_t frame_packet();
uint8_t parse_packet();

// Temporarily silence the linker. The protocol files are supposed to get integrated with app file
int main(void) {

    return 0;

}

uint8_t create_msg() {
    if(NULL == msg) {
        msg = (msg_fmt *)malloc(sizeof(msg_fmt));   
        return (1);
    } else {
        // msg already created - singleton pattern
        return (0);
    }
}

uint8_t frame_packet(struct msg_fields *msg_fields) {
    if(NULL == msg_fields) {
        return -1;
    } else {
        if(create_msg()) {
            set_opcode(msg_fields->opcode);
            set_type(msg_fields->type);
            set_length(msg_fields->length);
            set_value(msg_fields->value);
            
            if(calculate_chksum()) {
                set_chksum();
            } else {
                set_chksum(DEF_CHKSUM);
            }
        }   
    }
}
