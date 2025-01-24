#include "menu.h"

void initialize_menu() { // Starter titelskærmen 
	set_terminal_size(41, 120);
	clear_terminal();
	draw_title(); // Tegner grafikken for titelskærmen
	gotoxy(35, 48);
	printf("Press SPACE to continue!");
	title_screen_controls(); // Starter titelskærmens controls

}

void help_screen() { // Viser help menuen
	clear_terminal();
	gotoxy(14, 23);
	printf("Use WASD or the joystick on the microcontroller to control the player ship");
	gotoxy(16, 51);
	printf("Use SPACE to shoot");
	gotoxy(18, 36);
	printf("Earn score by surviving and destroying asteroids");
	gotoxy(20, 36);
	printf("Dodge the enemy bullets and shoot the asteroids!");
	gotoxy(35, 51);
	printf("Press B to go back");
	help_controls(); // Starter help menuens controls

}

void difficulty_screen() { // Viser difficulty select menuen
	clear_terminal();
	draw_difficulty(); // Tegner grafikken for menuen
	gotoxy(35, 51);
	printf("Press B to go back");
	difficulty_controls(); // Starter difficulty select menuens controls

}

void menu_screen() { // Viser start menuen
	clear_terminal();
	draw_menu(); // Tegner grafikken for menuen
	menu_controls(); // Starter menuens controls

}
