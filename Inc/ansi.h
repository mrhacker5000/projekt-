/*
 * ansi.h
 *
 *  Created on: 7. jan. 2025
 *      Author: phill
 */

#ifndef ANSI_H_
#define ANSI_H_

/* Includes --------------------------------------------*/
#include "stdint.h"
#include "stdio.h"
/* Exported types --------------------------------------*/
/* Exported constants ----------------------------------*/
/* Exported macro --------------------------------------*/
/* Exported functions ----------------------------------*/

typedef struct {
		int8_t x ;
		int8_t vx ;
		int8_t y ;
		int8_t vy ;
		int hits ;
	} Ball;


void fgcolor (uint8_t foreground) ;
void bgcolor (uint8_t background) ;
void color (uint8_t foreground, uint8_t background) ;
void underline (uint8_t on) ;
void gotoxy(uint8_t y, uint8_t x) ;
void blink(uint8_t on) ;
void inverse(uint8_t on) ;
void clrscr() ;
void clreol() ;
void clear() ;
void window(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, const char *title, uint8_t style) ;
void drawball(int8_t x, int8_t y) ;
void updatepos(int8_t *x, int8_t *y, int8_t vx, int8_t vy) ;
void graphic() ;
void check_collision(Ball *ball) ;
void clearball(int8_t prev_y, int8_t prev_x) ;
void drawTitle() ;
void hidecursor() ;
void gamewindow() ;

#define start1 180
#define start2 185
#define end1 195
#define end2 204
#define vert1 179
#define vert2 186
#define hor1 196
#define hor2 205
#define nw1 218
#define nw2 201
#define ne1 191
#define ne2 187
#define sw1 192
#define sw2 200
#define se1 217
#define se2 188

#endif /* ANSI_H_ */
