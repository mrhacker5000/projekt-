#include "HEADER.h"

int main(void) {
	uart_init(115200);
	set_terminal_size(41, 120);
	game();

	while (1){}
}
