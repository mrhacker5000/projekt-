/*
 * player.h
 *
 *  Created on: 20. jan. 2025
 *      Author: phill
 */

#ifndef PLAYER_H_
#define PLAYER_H_

typedef struct {
	int x;
	int y;
	int health;
	int score;
	int powerup;
} player;

void init_player(player *p1) ;
void drawplayer(player p1) ;
void updateplayer(player *p1, int input) ;
void clearplayer(player p1) ;

#endif /* PLAYER_H_ */
