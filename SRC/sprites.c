#include "HEADER.h"
#include "stm32f30x_conf.h"  // STM32 config
#include "30010_io.h"         // Input/output library for this course
#include <stdint.h>           // For uint8_t
          // Miscellaneous functions
#include "ansi.h"             // ANSI escape sequences

#define SCREEN_WIDTH 180
#define SCREEN_HEIGHT 40
#define SPRITE_WIDTH 9
#define SPRITE_HEIGHT 4





#include "30010_io.h"
#include <stdint.h>
#include <stdio.h>
#include "ansi.h"


void draw_astroid_sprite(char buffer[180][40], uint8_t color_buffer[180][40], uint8_t x_pos, uint8_t y_pos);
void print_buffer(char buffer[180][40], uint8_t color_buffer[180][40], uint8_t width, uint8_t height);
void gotoxy(uint8_t x, uint8_t y);


void draw_astroid_sprite(char buffer[SCREEN_WIDTH][SCREEN_HEIGHT], uint8_t color_buffer[SCREEN_WIDTH][SCREEN_HEIGHT], uint8_t x_pos, uint8_t y_pos) {
    uint8_t astroid_color[][SPRITE_WIDTH] = {
        {0, 7, 8, 7, 7, 0, 0, 11, 11},
        {8, 7, 7, 8, 7, 7, 7, 11, 11},
        {7, 8, 7, 7, 7, 7, 0, 11, 11},
        {8, 7, 7, 7, 8, 8, 0, 11, 11},
    };

    uint8_t astroid_char[][SPRITE_WIDTH] = {
        {220, 220, 219, 219, 220, 0, 0, 42, 42},
        {220, 219, 219, 219, 219, 219, 220, 42, 42},
        {219, 219, 219, 219, 219, 223, 0, 42, 42},
        {223, 219, 219, 219, 223, 223, 223, 42, 42},
    };

    for (uint8_t current_row = 0; current_row < SPRITE_HEIGHT; current_row++) {
        for (uint8_t current_column = 0; current_column < SPRITE_WIDTH; current_column++) {
            if (y_pos + current_row < SCREEN_HEIGHT && x_pos + current_column < SCREEN_WIDTH) {
                buffer[y_pos + current_row][x_pos + current_column] = astroid_char[current_row][current_column];
                color_buffer[y_pos + current_row][x_pos + current_column] = astroid_color[current_row][current_column]; // Set color
            }
        }
    }
}

void print_buffer(char buffer[SCREEN_WIDTH][SCREEN_HEIGHT], uint8_t color_buffer[SCREEN_WIDTH][SCREEN_HEIGHT], uint8_t width, uint8_t height) {
    for (uint8_t row = 0; row < height; row++) {
        gotoxy(0, row);
        for (uint8_t col = 0; col < width; col++) {
            if (buffer[row][col] == 0) {
                fgcolor(0);
                printf(" ");
            } else {
                fgcolor(color_buffer[row][col]);
                printf("%c", buffer[row][col]);
            }
        }
    }
}


void clear_sprite(uint8_t x_pos, uint8_t y_pos) {
    for (uint8_t current_row = 0; current_row < 4; current_row++) {
        for (uint8_t current_column = 0; current_column < 9; current_column++) {
            gotoxy(x_pos + current_column, y_pos + current_row);
            printf(" "); // Overwrite with spaces to clear the sprite
        }
    }
}
