/*
 * misc.c
 *
 *  Created on: 17. jan. 2025
 *      Author: Bruger
 */


#include <stdio.h>
#include "misc.h"
#include "ansi.h"

void gotoxy(int x, int y) {
    // ANSI escape sequence to move the cursor
    printf("\033[%d;%dH", y, x);
}
void spawn_spaceship_sprite() {

// function for drawing spaceship-sprite

/*
 * array for the coloring of ASCII character
 * index[y][x] is the color of the character at terminal position -
 * (row : 22  + y, column : 3 + x)
 * */

uint16_t spaceship_sprite[3][10] = {
{11,0,0,0,1, 1,1,1,1,15}, /* row 1 */
{11,1,1,0,1, 1,0,0,0,0}, /* row 2 */
{11,1,1,1,7, 7,1,1,1,0}, /* row 3 */


};

uint8_t current_row = 0;
uint8_t current_column = 0;

/*
* drawing top half of sprite
*/

for (current_row = 0; current_row <=2; current_row++) {
for (current_column = 0; current_column < 10; current_column++) {
gotoxy(1 + current_column, 1 + current_row);
fgcolor(spaceship_sprite[current_row][current_column]);
printf("%c", 219);
}
}

/*
 * drawing bottom half of sprite by going through array in reverse
 */

for (current_row = 1; current_row >= 0 ; current_row--) {
    for (current_column = 0; current_column < 10; current_column++) {
        gotoxy(1 + current_column,  5 - current_row);
        fgcolor(spaceship_sprite[current_row][current_column]);
        printf("%c", 219);
}
}
}
