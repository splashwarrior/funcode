/*-----------------------------------------------------------------------------
 * Include Files
 * ------------------------------------------------------------------------------*/
#include "dispatcher.h"

/*-----------------------------------------------------------------------------
 * Globals 
 * ------------------------------------------------------------------------------*/
/* Test inputs */
uint8_t display_packet[] = {0x1, 0x34, 0x05, 0x00, 0x48, 0x65, 0x6c, 0x6c,
    0x6f};
uint8_t motor_packet[] = {0x2, 0x80, 0x08, 0x0, 0x0, 0x0, 0x80, 0x3f, 0x0,
    0x0, 0x0, 0xbf};
uint8_t error_packet[] = {0x3, 0x45, 0x07, 0x0, 0x0, 0x0, 0x80, 0x3f, 0x0,
    0x0, 0x0, 0xbf};
uint8_t null_packet[] = {};

/*
 * This is a test case that core dumps, the problem is we dont do any
 * bound checks. Solution is to read the size of the incoming buffer
 * and check this with the msg_len inputed. 
 * Ideally define, a #define MAX_LEN_DISPLAY_SIZE to gauard against,
 * error input.
 *
 uint8_t bus_error[] = {0x4, 0x34, 0x05, 0xff, 0x00};
 */

uint8_t *tests[] = {display_packet,
                    motor_packet,
                    error_packet,
                    null_packet,
                    NULL};
/*-----------------------------------------------------------------------------
 * Functions 
 * ------------------------------------------------------------------------------*/
int main() {
    uint8_t size = sizeof(tests)/sizeof(tests[0]);
    uint8_t i = 0;

    for (i = 0; i < size; i++) {
        printf("\n%s: Test case %d\n", __func__, i);
        printf("%s: Result = %d\n", __func__, dispatcher(tests[i]));
    }
    return 0;
}
