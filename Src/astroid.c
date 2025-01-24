#include "HEADER.h"

#define ENEMY_WIDTH 7  // Width of the hexagon sprite
#define ENEMY_HEIGHT 5 // Height of the hexagon sprite

const char *ENEMY_SPRITE[ENEMY_HEIGHT] = {
    "  /-\\  ", // Top of the hexagon
    " /   \\ ", // Upper middle
    "|     |", // Middle
    " \\   / ", // Lower middle
    "  \\-/  "  // Bottom of the hexagon
};

void draw_enemy(Enemy enemy[], int maxspawn) {
    for (int i = 0; i < maxspawn; i++) {
        if (enemy[i].active) {
            for (int row = 0; row < ENEMY_HEIGHT; row++) {
                gotoxyz(enemy[i].x, enemy[i].y + row); // Adjust position for each row
                printf("%s", ENEMY_SPRITE[row]);
            }
        }
    }
}

void clear_enemy(Enemy enemy[], int maxspawn) {
    for (int i = 0; i < maxspawn; i++) {
        if (enemy[i].active) {
            for (int row = 0; row < ENEMY_HEIGHT; row++) {
                gotoxyz(enemy[i].x, enemy[i].y + row); // Adjust position for each row
                for (int col = 0; col < ENEMY_WIDTH; col++) {
                    putchar(' '); // Clear each character in the sprite
                }
            }
        }
    }
}
void init_enemy(Enemy enemy[], int maxspawn) {
    for (int i = 0; i < maxspawn; i++) {
        enemy[i].active = 0;
    }
}


void start_enemy(Enemy enemy[], int maxspawn)  {
    for (int i = 0; i < maxspawn; i++) {
        if (!enemy[i].active) {
        	enemy[i].x = 118;
        	enemy[i].y = Randoms(2, 39);
        	enemy[i].health = 2;
        	enemy[i].active = 1;
            break;
        }
    }
}

void collision_enemy(Enemy enemy[], int maxspawn, player *player) {
    for (int i = 0; i < maxspawn; i++) {
        if (enemy[i].active) {

            if (enemy[i].x == player->x && enemy[i].y == player->y) {
            	player->health--;
                enemy[i].active = 0;

                break;
            }
        }
    }

}

void update_enemy(Enemy enemy[], int maxspawn, player *player) {
    for (int i = 0; i < maxspawn; i++) {
        if (enemy[i].active) {
        	enemy[i].x--;
            if (enemy[i].x <= 2) {
            	enemy[i].active = 0;
            }
        if (enemy[i].health == 0) {
        	player->score += 1000;
        	enemy[i].active = 0;
            }
            }
        }
    }


