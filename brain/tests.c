#include "dispatcher.h"

/* Test inputs */
uint8_t display_packet[] = {0x1, 0x34, 0x05, 0x00, 0x48, 0x65, 0x6c, 0x6c,
    0x6f};
uint8_t motor_packet[] = {0x2, 0x80, 0x08, 0x0, 0x0, 0x0, 0x80, 0x3f, 0x0,
    0x0, 0x0, 0xbf};
uint8_t error_packet[] = {0x3, 0x45, 0x07, 0x0, 0x0, 0x0, 0x80, 0x3f, 0x0,
    0x0, 0x0, 0xbf};

int main() {
    printf("motor ret=%d\n", dispatcher(motor_packet));
    printf("display ret=%d\n", dispatcher(display_packet));
    printf("error  ret=%d\n", dispatcher(error_packet));

    return 0;
}
