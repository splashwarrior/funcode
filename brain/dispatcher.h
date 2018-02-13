/*-----------------------------------------------------------------------------
 * Include Files
 * ------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * Enum: to define the type of header,
 * this is different from the header value. 
 * Add mode header types here.
 */
enum {
    MSG_TYPE_MOTOR,
    MSG_TYPE_DISPLAY,
    MSG_TYPE_INV,
} msg_type_t;

enum {
    NO_ERROR = 0,
    ERR_OOM,
    ERR_INV,
    ERR_GENERIC,
} error_type;

struct packet_data_t {
    uint8_t packet_id;
    uint8_t msg_type;
    uint16_t msg_len;
    uint8_t *msg_data;
};

#define DISPLAY_MSG_HEADER	0x34
#define MOTOR_MSG_HEADER	0x80

/* MOTOR data (fwd_back, left_right has to be 8 bytes) */
#define MOTOR_DATA_LEN	8

int display_message(struct packet_data_t *pdata);
int update_motor(struct packet_data_t *pdata);
int dispatcher(uint8_t *pkt); 

