#include "HEADER.h"

#define MAX_ASTROID 3
#define ASTROID_HEIGHT 5 // Height of the asteroid sprite
#define ASTROID_WIDTH 7  // Width of the asteroid sprite

const char *ASTROID_SPRITE[ASTROID_HEIGHT] = {
    "  xxxx ", // Top of the hexagon
    " xxx   ", // Upper middle
    "xxxxxxx",  // Middle
    " xxx   ", // Lower middle
    "  xxxx "  // Bottom of the hexagon
};

Astroid astroid[MAX_ASTROID];

void init_astroid(Astroid astroid[]) {
    for (int i = 0; i < MAX_ASTROID; i++) {
        astroid[i].active = 0;
    }
}

void start_astroid(Astroid astroid[]) {
    for (int i = 0; i < MAX_ASTROID; i++) {
        if (!astroid[i].active) {
            astroid[i].x = 110;
            if (i == 0) {
                astroid[i].y = 10;
            } else if (i == 1) {
                astroid[i].y = 20;
            } else if (i == 2) {
                astroid[i].y = 30;
            }

            astroid[i].health = 2;
            astroid[i].active = 1;
            break;
        }
    }
}

void draw_astroid(Astroid astroid[]) {
    for (int i = 0; i < MAX_ASTROID; i++) {
        if (astroid[i].active) {
            for (int row = 0; row < ASTROID_HEIGHT; row++) {
                gotoxyz(astroid[i].x, astroid[i].y + row);
                printf("%s", ASTROID_SPRITE[row]);
            }
        }
    }
}

void astroid_shoot(Astroid astroid[]) {
    for (int i = 0; i < MAX_ASTROID; i++) {
        if (astroid[i].active) {
            // Shooting logic to be implemented
        }
    }
}
