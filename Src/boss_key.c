#include "menu.h"

void draw_boss_key() { // Prints boss key
	hide_cursor();
	gotoxy(15, 12);
	printf("                                                                                  .-\"\"\"\"\"\"-.");
	gotoxy(16, 12);
	printf(" _   _   ______   _______      ___       _______    ___    __  __   ______      .'          '.");
	gotoxy(17, 12);
	printf("| \\ | | |  __  | |__   __|    / _ \\     |  _____|  / _ \\  |  \\/  | |  ____|    /   O    -=-   \\");
	gotoxy(18, 12);
	printf("|  \\| | | |  | |    | |      / /_\\ \\    | |  __   / /_\\ \\ | \\  / | | |__      :                :");
	gotoxy(19, 12);
	printf("| . ` | | |  | |    | |      |  _  |    | | |_ \\  |  _  | | |\\/| | |  __|     |                |");
	gotoxy(20, 12);
	printf("| |\\  | | |__| |    | |      | | | |    | |___| | | | | | | |  | | | |____    : ',          ,' :");
	gotoxy(21, 12);
	printf("|_| \\_| |______|    |_|      |_| |_|     \\______| |_| |_| |_|  |_| |______|    \\  '-......-'  /");
	gotoxy(22, 12);
	printf("                                                                                '.          .'");
	gotoxy(23, 12);
	printf("                                                                                  '-......-'");
}

void boss_key_function() {
		while(1) {
	static int boss_key_count = 0;

	int boss_key_value = uart_get_char();

	if (boss_key_value == 0x1B) {
		boss_key_count++;

		if (boss_key_count == 1) {
			clear_terminal();
			draw_boss_key();

		} else if (boss_key_count == 2) {
			boss_key_count = 0;
			clear_terminal();
		}
	}
		}
}
