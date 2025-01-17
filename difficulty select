#include "stm32f30x_conf.h"  // STM32 config
#include "30010_io.h"         // Input/output library for this course
#include <stdio.h>
#include <stdint.h> // For uint8_t
#include <string.h> // For strlen

// Function to clear the screen
void clrscr() {
    printf("\033[2J"); // ANSI escape sequence to clear the screen
    printf("\033[H");  // Move cursor to home position (top-left corner).
}

// Function to move the cursor to a specific position (x, y)
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x); // ANSI escape sequence to move the cursor
}

// Function to change text color
void textcolor(int color) {
    if (color >= 0 && color <= 7) {
        printf("\033[3%dm", color); // ANSI escape sequence for text color (0-7)
    }
}

// Function to change background color
void set_bgcolor(int color) { // Renamed to avoid conflict
    if (color >= 0 && color <= 7) {
        printf("\033[4%dm", color); // ANSI escape sequence for background color (0-7)
    }
}

// Function to reset text attributes
void resettext() {
    printf("\033[0m"); // Reset text attributes
}

// Function to draw a window in the terminal
void window(int x1, int y1, int x2, int y2, const char *title, int style) {
    int width = x2 - x1 + 1;
    int height = y2 - y1 + 1;
    int title_length = strlen(title);

    // Top border
    gotoxy(x1, y1);
    printf("+");
    for (int i = 0; i < width - 2; i++) printf("-");
    printf("+");

    // Title in the top border
    gotoxy(x1 + (width - title_length) / 2, y1);
    printf("%s", title);

    // Side borders
    for (int i = 1; i < height - 1; i++) {
        gotoxy(x1, y1 + i);
        printf("|");
        gotoxy(x2, y1 + i);
        printf("|");
    }

    // Bottom border
    gotoxy(x1, y2);
    printf("+");
    for (int i = 0; i < width - 2; i++) printf("-");
    printf("+");
}

// Main function for creating a mockup GUI with one window
void drawdifficulty() {

    // Clear the screen
    clrscr();

    // Set text and background colors
    textcolor(5);  // Red text
    set_bgcolor(0);    // Blue background (Renamed function used here)


    // Draw the first window (Main window)
      window(52, 20, 80, 24, "-", 1);
      gotoxy(64, 22); // Text inside the first window
      printf("EASY");

      // Draw the second window (Window 1)
      window(84, 20, 112, 24, "-", 1);
      gotoxy(95, 22); // Text inside the second window
      printf("MEDIUM");

      // Draw the third window (Window 2)
      window(116, 20, 144, 24, "-", 1);
      gotoxy(128, 22); // Text inside the third window
      printf("HARD");


      // Draw the third window (Window 2)
      window(84, 3, 112, 7, "-", 1);
      gotoxy(90, 5); // Text inside the third window
      printf("SELECT DIFFICULTY");

        // Reset text attributes
        resettext();

    }
