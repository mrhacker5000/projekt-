
#ifndef BULLETS_H_
#define BULLETS_H_

#include "ansi.h"
#include "player.h"

void clrscr();
uint8_t space_press();
void gotoxyz(int x, int y);
void bullet(uint8_t space_press());
void init_bullets();
void shoot_bullet(player *player);
void update_bullets();
void draw_bullets();
void clear_bullets();
void delay(int iterations);


typedef struct {
    int x;
    int y;
    int active;
} Bullet;



#endif /* BULLETS_H_ */
