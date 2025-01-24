#include "HEADER.h"

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
	gotoxy(30, 45);
	printf("Press 'Space' to continue work");
}

void boss_key_function(int key) {
    if (key == 7) {
        clear_terminal();
        draw_boss_key();
        while (1) {
            int key = readkey();
            if (key == 5) {
                clear_terminal();
                gamewindow();
                return;
            }
        }
    }
}
