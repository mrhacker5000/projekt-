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



void drawplayer(player p1, int input) {
	gotoxy(p1.y, p1.x) ;
	char arrow;
	char *p = &arrow;
	if(input == 0x02) {
		*p -> "v" ;
		}
	else if (input == 0x01) {
		*p -> "^" ;
		}
	else if(input == 0x04) {
		*p -> "<" ;
		}
	else if (input == 0x08) {
		*p -> ">" ;
		}
	printf("%c", arrow);
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
