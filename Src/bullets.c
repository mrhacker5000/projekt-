#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "system_stm32f30x.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "bullets.h"


#define MAX_BULLETS 10
#define BULLET_CHAR '*'
#define DELAY 10000

Bullet bullets[MAX_BULLETS];

void gotoxyz(int x, int y) {
    printf("\x1B[%d;%dH", y, x);
}



void init_bullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].active = 0;
    }
}

void shoot_bullet(player *player)  {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bullets[i].active) {
            bullets[i].x = player->x;
            bullets[i].y = player->y;
            bullets[i].active = 1;
            break;
        }
    }
}

void update_bullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            bullets[i].x++; //bevæg kugle til højre
            if (bullets[i].x > 119) {
                bullets[i].active = 0; // kugle er ude for området
            }
        }
    }
}

void draw_bullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            gotoxyz(bullets[i].x, bullets[i].y);
            putchar(BULLET_CHAR);
        }
    }
}

void clear_bullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            gotoxyz(bullets[i].x, bullets[i].y);
            putchar(' ');
        }
    }
}

void delay(int iterations) {
    for (volatile int i = 0; i < iterations; i++) {

    }
}
