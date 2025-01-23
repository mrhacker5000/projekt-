#ifndef MISC_H
#define MISC_H

#include <stdint.h>

#define NUM_BULLETS 10

typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t active;
} Bullet;

void draw_ship(uint8_t x, uint8_t y);
void clear_ship(uint8_t x, uint8_t y);
void draw_bullet(uint8_t x, uint8_t y);
void clear_bullet(uint8_t x, uint8_t y);
void move_bullets(Bullet bullets[], uint8_t screen_height);
void gotoxy(uint8_t x, uint8_t y);
void clrscr();

#endif // MISC_H
