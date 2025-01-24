#include "HEADER.h"

int readkey() {
    uint8_t ch = uart_get_char();

    switch (ch) {
        case 'w':
            return 1;
        case 's':
            return 2;
        case 'a':
            return 3;
        case 'd':
            return 4;
        case ' ':
        	return 5;
        case 'r':
        	return 6;
        case 0x1B:
        	return 7;
        default:
            return 0;
    }
}
