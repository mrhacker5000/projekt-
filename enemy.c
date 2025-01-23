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
