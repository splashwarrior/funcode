/*-----------------------------------------------------------------------------
 * Include Files
 * ------------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------------------------------------
 * Enums
 * ------------------------------------------------------------------------------*/
enum {
    NO_ERROR = 0,
    ERR_OOM,
    ERR_INV,
    ERR_GENERIC,
} error_type;

/*
 * ToDo: To optimize, aling/padd structure to 4/8 byte, 
 * making reads faster.
 */
struct packet_data_t {
    uint8_t packet_id;
    uint8_t msg_type;
    uint16_t msg_len;
    uint8_t *msg_data;
};

/*-----------------------------------------------------------------------------
 * Macros/Constants
 * ------------------------------------------------------------------------------*/
#define DISPLAY_MSG_HEADER	0x34
#define MOTOR_MSG_HEADER	0x80

/* MOTOR data (fwd_back, left_right has to be 8 bytes) */
#define MOTOR_DATA_LEN	8

/*-----------------------------------------------------------------------------
 * Function Prototypes 
 * ------------------------------------------------------------------------------*/
int display_message(struct packet_data_t *pdata);
int update_motor(struct packet_data_t *pdata);
int dispatcher(uint8_t *pkt); 
