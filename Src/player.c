/*
 * player.c
 *
 *  Created on: 20. jan. 2025
 *      Author: phill
 */
/*
 * player.c
 *
 *  Created on: 12 Jan 2024
 *      Author: oscar
 */

#include "player.h"
#include "ansi.h"
#include <stdio.h>


void init_player(player *p1) {
	p1->health = 5 ;
	p1->x = 5 ;
	p1->y = 20 ;
	p1->score = 0 ;
	p1->powerup = 0 ;
}



void drawplayer(player p1) {
	gotoxy(p1.y, p1.x) ;
	printf(">") ;
}

void updateplayer(player *p1, int input) {

//	Player movement
	if(input == 0x02) {
		p1->y++ ;
	}
	if(input == 0x01) {
		p1->y-- ;
	}
	if(input == 0x04) {
		p1->x-- ;
	}
	if(input == 0x08) {
		p1->x++ ;
	}

//	Checks if moving out of bounds
	if (p1->y >= 41 ) {
		p1->y = 40 ;
	}
	if (p1->y <= 2) {
		p1->y = 2 ;
	}
	if (p1->x + 40 >= 120) {
		p1->x = 80 ;
	}
	if (p1->x <= 2) {
		p1->x = 2 ;
	}
}

void clearplayer(player p1) {
	gotoxy(p1.y, p1.x) ;
	printf(" ") ;
}
---------------------------------------------------------------------------------------------------------------------------
	#include "HEADER.h"

#define PLAYER_HEIGHT 8 // Height of the player's sprite
#define PLAYER_WIDTH 9  // Width of the player's sprite

// Sprites for different directions
const char *PLAYER_SPRITE_LEFT[PLAYER_HEIGHT] = {
    "    x x x x  ",
    "  x x x      ",
    "x x x x x x x",
    "  x x x      ",
    "    x x x x  "
};

const char *PLAYER_SPRITE_RIGHT[PLAYER_HEIGHT] = {
    "  x x x x    ",
    "      x x x  ",
    "x x x x x x x",
    "      x x x  ",
    "  x x x x    "
};

const char *PLAYER_SPRITE_DOWN[PLAYER_HEIGHT] = {
    "    x    ",
    "  x x x  ",
    "x x x x x",
    "x x x x x",
    "x   x   x",
    "x   x   x",
    "    x   ",

};

const char *PLAYER_SPRITE_UP[PLAYER_HEIGHT] = {
    "    x    ",
    "x   x   x",
    "x   x   x",
    "x x x x x",
    "x x x x x",
    "  x x x  ",
    "    x    "
};
void init_player(player *p1) {
    p1->health = 3;
    p1->x = 5;
    p1->y = 20;
    p1->score = 0;
    p1->powerup = 0;
    p1->direction = '>';
}
// Draw the player sprite
void drawplayer(player p1) {
    const char **sprite = NULL;

    // Choose the correct sprite based on direction
    switch (p1.direction) {
        case '<':
            sprite = PLAYER_SPRITE_LEFT;
            break;
        case '>':
            sprite = PLAYER_SPRITE_RIGHT;
            break;
        case 'v':
            sprite = PLAYER_SPRITE_DOWN;
            break;
        case '^':
            sprite = PLAYER_SPRITE_UP;
            break;
        default:
            return; // Invalid direction
    }

    // Draw the selected sprite
    for (int i = 0; i < PLAYER_HEIGHT; i++) {
        gotoxy(p1.y + i, p1.x); // Move to the correct line
        printf("%s", sprite[i]); // Print the sprite's row
    }
}

// Clear the player's sprite
void clearplayer(player p1) {
    for (int i = 0; i < PLAYER_HEIGHT; i++) {
        gotoxy(p1.y + i, p1.x); // Move to the correct line
        for (int j = 0; j < PLAYER_WIDTH; j++) {
            printf(" "); // Print spaces to clear the area
        }
    }
}

// Update the player's position and direction
void updateplayer(player *p1, int input) {
    // Clear the current sprite before updating the position
    clearplayer(*p1);

    // Update position and direction based on input
    if (input == 0x02) { // Move down
        p1->y++;
        p1->direction = 'v';
    }
    if (input == 0x01) { // Move up
        p1->y--;
        p1->direction = '^';
    }
    if (input == 0x04) { // Move left
        p1->x--;
        p1->direction = '<';
    }
    if (input == 0x08) { // Move right
        p1->x++;
        p1->direction = '>';
    }

    // Check bounds (adjust for the height and width of the sprite)
    if (p1->y + PLAYER_HEIGHT > 41) {
        p1->y = 41 - PLAYER_HEIGHT;
    }
    if (p1->y < 2) {
        p1->y = 2;
    }
    if (p1->x + PLAYER_WIDTH > 119) {
        p1->x = 119 - PLAYER_WIDTH;
    }
    if (p1->x < 2) {
        p1->x = 2;
    }

    // Draw the sprite at the new position
    drawplayer(*p1);
}
