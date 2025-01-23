#include "menu.h"

void title_screen_controls() {
	while (1) {
	    char key = uart_get_char();
	    if (key == ' ') {
	    	menu_screen();
            break; // Exit loop when SPACE is pressed
        }
	}
}


void menu_controls() {
	draw_arrows(0);
	int choice = 0;
	while(1) {
		char key = uart_get_char();
		if ((key == 'w' || key == 'W') && (choice > 0)) {
		clear_arrows(choice);
		choice--;
		draw_arrows(choice);
		}
		else if ((key == 's' || key == 'S') && (choice < 2)) {
		clear_arrows(choice);
		choice++;
		draw_arrows(choice);
		}
		else if (key == ' ') {
			if (choice == 0) {
				difficulty_screen();
				break;
			}
			if (choice == 1) {
				 help_screen();
				 break;
			}
			if (choice == 2) {
				initialize_menu();
				break;
			}
		}
	}
}

int difficulty_controls() {
	draw_arrows(0);
	int choice = 0;
	while(1) {
		char key = uart_get_char();
		if ((key == 'w' || key == 'W') && (choice > 0)) {
		clear_arrows(choice);
		choice--;
		draw_arrows(choice);
		}
		else if ((key == 's' || key == 'S') && (choice < 2)) {
		clear_arrows(choice);
		choice++;
		draw_arrows(choice);
		}
		else if (key == 'b' || key == 'B') {
		menu_screen();
		break;
		}
		else if (key == ' ') {
			if (choice == 0) {
				clear_terminal();
				// TEMPORARY TEST:
				gotoxy(20, 60);
				printf("Easy difficulty");
				// INSERT START EASY DIFFICULTY
				return 1;
			}
			if (choice == 1) {
				clear_terminal();
				// TEMPORARY TEST:
				gotoxy(20, 60);
				printf("Medium difficulty");
				// INSERT START MEDIUM DIFFICULTY
				return 2;
			}
			if (choice == 2) {
				clear_terminal();
				// TEMPORARY TEST:
				gotoxy(20, 60);
				printf("Hard difficulty");
				// INSERT START HARD DIFFICULTY
				return 3;
			}
		}
	}
	return 0; // Default return value if 'b' is pressed
}

void help_controls() {
	while(1) {
		char key = uart_get_char();
		if (key == 'b' || key == 'B') {
			menu_screen();
			break;
		}
	}
}


