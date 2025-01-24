#include "HEADER.h"

void init_player(player *p1) {
	p1->health = 3 ;
	p1->x = 5 ;
	p1->y = 20 ;
	p1->score = 0 ;
	p1->powerup = 0 ;
	p1->direction = '>' ;
}



void drawplayer(player p1) {
	gotoxy(p1.y, p1.x) ;
	printf("%c", p1.direction);
}

void updateplayer(player *p1, int input, int key) {

//	Player movement
	if(input == 0x02 || key == 2) {
		p1->y++ ;
		p1->direction = 'v';
	}
	if(input == 0x01 || key == 1) {
		p1->y-- ;
		p1->direction = '^';
	}
	if(input == 0x04 || key == 3) {
		p1->x-- ;
		p1->direction = '<';
	}
	if(input == 0x08 || key == 4) {
		p1->x++ ;
		p1->direction = '>';
	}

//	Checks if moving out of bounds
	if (p1->y >= 41 ) {
		p1->y = 40 ;
	}
	if (p1->y <= 2) {
		p1->y = 2 ;
	}
	if (p1->x >= 119) {
		p1->x = 119 ;
	}
	if (p1->x <= 2) {
		p1->x = 2 ;
	}
}

void clearplayer(player p1) {
	gotoxy(p1.y, p1.x) ;
	printf(" ") ;
}
