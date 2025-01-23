#include "menu.h"

void initialize_menu() {
	set_terminal_size(41, 120);
	clear_terminal();
	draw_title();
	gotoxy(35, 48);
	printf("Press SPACE to continue!");
	title_screen_controls();

}

void help_screen() {
	clear_terminal();
	gotoxy(20, 50);
	printf("Help menu goes here!");
	gotoxy(35, 51);
	printf("Press B to go back");
	help_controls();

}

void difficulty_screen() {
	clear_terminal();
	draw_difficulty();
	gotoxy(35, 51);
	printf("Press B to go back");
	difficulty_controls();

}

void menu_screen() {
	clear_terminal();
	draw_menu();
	menu_controls();

}
