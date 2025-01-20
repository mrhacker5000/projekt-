#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bullets.h"
#include "enemy.h"
#include "ansi.h"
#include "GPIO.h"
#include "player.h"


#define DELAY 50000



int main(void) {
	uart_init(115200);



    uint8_t ch;
    player p1 = {10, 20, 5, 0, 0}; // Initialize player position

    clrscr(); // Clear the screen
    init_bullets();
    gamewindow();

    while (1) {

    	readjoystick();
    	int joy = readjoystick();
    	setled();
    	clearplayer(p1);
    	updateplayer(&p1, joy);
    	drawplayer(p1, joy);


       // Simulate input for demonstration purposes
    	ch = uart_get_char(); // Get user input from standard input

        if (ch == ' ') {
            shoot_bullet(&p1); // Pass the player struct to shoot_bullet
        }

        clear_bullets(); // Clear previous bullet positions
        update_bullets(); // Update bullet positions
        draw_bullets(); // Draw bullets

        delay(DELAY); // Delay for a short time
    }

    return 0;
}
