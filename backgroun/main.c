#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "background.h"
#include <unistd.h>


int main(void)
{
	uart_init(115200);


		//fjern cursor
	    printf("\033[?25l");

	srand(1234);
	    initializeStars();

	    while (1) {
	        clearScreen();
	        drawBackground();
	        updateStars();
	        delay(200);
	    }
}
