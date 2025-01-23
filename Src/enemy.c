#include "misc.h"
#include "30010_io.h"
#include <stdint.h>
#include "ansi.h"
#include <stdio.h>

#define SHIP_WIDTH 7
#define SHIP_HEIGHT 3

void draw_ship(uint8_t x, uint8_t y) {
    gotoxy(x, y);
    printf("  /\\  ");
    gotoxy(x, y + 1);
    printf(" /__\\ ");
    gotoxy(x, y + 2);
    printf("/____\\");
}

void clear_ship(uint8_t x, uint8_t y) {
    for (uint8_t i = 0; i < SHIP_HEIGHT; i++) {
        gotoxy(x, y + i);
        printf("       ");
    }
}

void draw_bullet(uint8_t x, uint8_t y) {
    gotoxy(x, y);
    printf("|");
}

void clear_bullet(uint8_t x, uint8_t y) {
    gotoxy(x, y);
    printf(" ");
}

void move_bullets(Bullet bullets[], uint8_t screen_height) {
    for (uint8_t i = 0; i < NUM_BULLETS; i++) {
        if (bullets[i].active) {
            clear_bullet(bullets[i].x, bullets[i].y);
            bullets[i].y++;
            if (bullets[i].y >= screen_height) {
                bullets[i].active = 0;
            } else {
                draw_bullet(bullets[i].x, bullets[i].y);
            }
        }
    }
}

void gotoxy(uint8_t x, uint8_t y) {
    printf("\033[%d;%dH", y + 1, x + 1);
}

void clrscr() {
    printf("\033[2J\033[H"); // Clear screen and move cursor to home
}
-----------------------------------------------------------------
    main.c
    #include "stm32f30x_conf.h"  // STM32 config
#include "30010_io.h"        // Input/output library for this course
#include <stdint.h>          // For uint8_t
#include "ansi.h"            // ANSI escape sequences
#include "misc.h"            // Miscellaneous functions

#define SCREEN_WIDTH 180
#define SCREEN_HEIGHT 40
#define NUM_ENEMY_SHIPS 5
#define SHIP_WIDTH 7
#define SHIP_HEIGHT 3
int main() {
    uart_init(115200);
    clrscr();
    hide_cursor();
    printf("Program started\n"); // Debug print

    // Enemy ship positions
    uint8_t enemy_x[NUM_ENEMY_SHIPS];
    uint8_t enemy_y[NUM_ENEMY_SHIPS];

    // Bullets
    Bullet bullets[NUM_BULLETS];

    // Initialize enemy ships
    for (uint8_t i = 0; i < NUM_ENEMY_SHIPS; i++) {
        enemy_x[i] = SCREEN_WIDTH - (i * 25) - 10;
        enemy_y[i] = 5 + (i * 6);
    }
    printf("Ships initialized\n"); // Debug print

    // Initialize bullets
    for (uint8_t i = 0; i < NUM_BULLETS; i++) {
        bullets[i].active = 0;
    }
    printf("Bullets initialized\n"); // Debug print

    // Animation loop
    while (1) {
        printf("Animation loop iteration\n"); // Debug print

        // Clear enemy ships from their old positions
        for (uint8_t i = 0; i < NUM_ENEMY_SHIPS; i++) {
            clear_ship(enemy_x[i], enemy_y[i]);
        }

        // Move enemy ships
        for (uint8_t i = 0; i < NUM_ENEMY_SHIPS; i++) {
            enemy_x[i]--;
            if (enemy_x[i] + SHIP_WIDTH == 0) {
                enemy_x[i] = SCREEN_WIDTH - 1;
            }
        }

        // Fire bullets randomly
        for (uint8_t i = 0; i < NUM_ENEMY_SHIPS; i++) {
            if (rand() % 50 == 0) {
                for (uint8_t j = 0; j < NUM_BULLETS; j++) {
                    if (!bullets[j].active) {
                        bullets[j].x = enemy_x[i] + SHIP_WIDTH / 2;
                        bullets[j].y = enemy_y[i] + SHIP_HEIGHT;
                        bullets[j].active = 1;
                        break;
                    }
                }
            }
        }

        // Move and draw bullets
        move_bullets(bullets, SCREEN_HEIGHT);

        // Draw enemy ships at their new positions
        for (uint8_t i = 0; i < NUM_ENEMY_SHIPS; i++) {
            draw_ship(enemy_x[i], enemy_y[i]);
        }

        // Add delay for smoother movement
        for (volatile int delay = 0; delay < 10000; delay++);
    }

    return 0;
}
