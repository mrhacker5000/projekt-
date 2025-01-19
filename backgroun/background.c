#include "stm32f30x_conf.h"
#include "30010_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "background.h"

#define WIDTH 80
#define HEIGHT 30
#define NUM_STARS 100
#define ESC 27

Star stars[NUM_STARS];

void clearScreen() {
    printf("\033[H\033[J");
}

void initializeStars() {
    for (int i = 0; i < NUM_STARS; i++) {
        stars[i].x = rand() % WIDTH;
        stars[i].y = rand() % (HEIGHT - 1);
    }
}

void drawBackground() {
    printf("\033[%d;1H", HEIGHT);
    for (int x = 0; x < WIDTH; x++) {
        printf(" ");
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int isStar = 0;
            for (int i = 0; i < NUM_STARS; i++) {
                if (stars[i].x == x && stars[i].y == y) {
                    printf("\033[%d;%dH*", y + 1, x + 1);
                    isStar = 1;
                    break;
                }
            }
            if (!isStar) {
                if (y == HEIGHT - 1) {
                    printf("\033[%d;%dH_", y + 1, x + 1);
                }
            }
        }
    }
}

void updateStars() {
    for (int i = 0; i < NUM_STARS; i++) {
        stars[i].x--;
        if (stars[i].x < 0) {
            stars[i].x = WIDTH - 1;
            stars[i].y = rand() % (HEIGHT - 1);
        }
    }
}

void delay(int milliseconds) {
    volatile int count;
    for (int i = 0; i < milliseconds * 1000; i++) {
        count++;
    }
}


