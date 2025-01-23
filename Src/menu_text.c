#include "menu.h"

void draw_title() { // Prints title with alien heads
	hide_cursor();
    gotoxy(15, 1);
    printf("    .-\"\"\"\"-.                                                                                                .-\"\"\"\"-.");
    gotoxy(16, 1);
    printf("   /        \\     _____   _____     ___     _____   ______      _______   _   _______   _   _   _______    /        \\ ");
    gotoxy(17, 1);
    printf("  /_        _\\   / ____| |  __ \\   / _ \\   / ____| |  ____|    |  _____| | | |  _____| | | | | |__   __|  /_        _\\ ");
    gotoxy(18, 1);
    printf(" // \\      / \\\\ | (___   | |__) | / /_\\ \\ | |      | |__       | |___    | | | |  __   | |_| |    | |    // \\      / \\\\");
    gotoxy(19, 1);
    printf(" |\\__\\    /__/|  \\___ \\  |  ___/  |  _  | | |      |  __|      |  ___|   | | | | |_ \\  |  _  |    | |    |\\__\\    /__/|");
    gotoxy(20, 1);
    printf("  \\    ||    /   ____) | | |      | | | | | |____  | |____     | |       | | | |___| | | | | |    | |     \\    ||    / ");
    gotoxy(21, 1);
    printf("   \\        /   |_____/  |_|      |_| |_|  \\_____| |______|    |_|       |_|  \\______| |_| |_|    |_|      \\        / ");
    gotoxy(22, 1);
    printf("    \\  __  /                                                                                                \\  __  / ");
    gotoxy(23, 1);
    printf("     '.__.'                                                                                                  '.__.'");
}

void draw_menu() { // Prints menu with "START", "HELP" and "EXIT"
	hide_cursor();
    gotoxy(10, 37);
    printf("  _____   _______    ___     _____    _______");
    gotoxy(11, 37);
    printf(" / ____| |__   __|  / _ \\   |  __ \\  |__   __|");
    gotoxy(12, 37);
    printf("| (___      | |    / /_\\ \\  | |__) |    | |");
    gotoxy(13, 37);
    printf(" \\___ \\     | |    |  _  |  |  _  /     | |");
    gotoxy(14, 37);
    printf(" ____) |    | |    | | | |  | | \\ \\     | |");
    gotoxy(15, 37);
    printf("|_____/     |_|    |_| |_|  |_|  \\_\\    |_|");

    gotoxy(17, 43);
    printf(" _   _    ______   _        _____  ");
    gotoxy(18, 43);
    printf("| | | |  |  ____| | |      |  __ \\ ");
    gotoxy(19, 43);
    printf("| |_| |  | |__    | |      | |__) |");
    gotoxy(20, 43);
    printf("|  _  |  |  __|   | |      |  ___/ ");
    gotoxy(21, 43);
    printf("| | | |  | |____  | |____  | |     ");
    gotoxy(22, 43);
    printf("|_| |_|  |______| |______| |_|     ");

    gotoxy(24, 43);
    printf(" ______  __   __  _____   _______ ");
    gotoxy(25, 43);
    printf("|  ____| \\ \\ / / |_   _| |__   __|");
    gotoxy(26, 43);
    printf("| |__     \\ V /    | |      | |   ");
    gotoxy(27, 43);
    printf("|  __|     > <     | |      | |   ");
    gotoxy(28, 43);
    printf("| |____   / . \\   _| |_     | |   ");
    gotoxy(29, 43);
    printf("|______| /_/ \\_\\ |_____|    |_|   ");
}

void draw_difficulty() { // Prints difficulty selection screen with "EASY", "MEDIUM" and "HARD"
	hide_cursor();
	gotoxy(10, 43);
	printf(" ______    ___      _____  __   __ ");
	gotoxy(11, 43);
	printf("|  ____|  / _ \\    / ____| \\ \\ / / ");
	gotoxy(12, 43);
	printf("| |__    / /_\\ \\  | (___    \\ V /  ");
	gotoxy(13, 43);
	printf("|  __|   |  _  |   \\___ \\    > <   ");
	gotoxy(14, 43);
	printf("| |____  | | | |   ____) |   | |   ");
	gotoxy(15, 43);
	printf("|______| |_| |_|  |_____/    |_|   ");

	gotoxy(17, 34);
	printf(" __  __   ______   _____    _____   _    _   __  __ ");
	gotoxy(18, 34);
	printf("|  \\/  | |  ____| |  __ \\  |_   _| | |  | | |  \\/  | ");
	gotoxy(19, 34);
	printf("| \\  / | | |__    | |  | |   | |   | |  | | | \\  / | ");
	gotoxy(20, 34);
	printf("| |\\/| | |  __|   | |  | |   | |   | |  | | | |\\/| |");
	gotoxy(21, 34);
	printf("| |  | | | |____  | |__| |  _| |_  | |__| | | |  | |");
	gotoxy(22, 34);
	printf("|_|  |_| |______| |_____/  |_____|  \\____/  |_|  |_|");

	gotoxy(24, 43);
	printf(" _   _    ___     _____    _____  ");
	gotoxy(25, 43);
    printf("| | | |  / _ \\   |  __ \\  |  __ \\ ");
    gotoxy(26, 43);
    printf("| |_| | / /_\\ \\  | |__) | | |  | |");
    gotoxy(27, 43);
    printf("|  _  | |  _  |  |  _  /  | |  | |");
    gotoxy(28, 43);
    printf("| | | | | | | |  | | \\ \\  | |__| |");
    gotoxy(29, 43);
    printf("|_| |_| |_| |_|  |_|  \\_\\ |_____/ ");

}

void draw_arrows(int y_axis) { // Prints arrows used to show the selected element
	hide_cursor();
	gotoxy(11 + (y_axis * 7), 28);
	printf("__");
	gotoxy(12 + (y_axis * 7), 28);
	printf("\\ \\");
	gotoxy(13 + (y_axis * 7), 28);
	printf(" \\ \\");
	gotoxy(14 + (y_axis * 7), 28);
	printf(" / /");
	gotoxy(15 + (y_axis * 7), 28);
	printf("/_/");

	gotoxy(11 + (y_axis * 7), 88);
	printf("  __");
	gotoxy(12 + (y_axis * 7), 88);
	printf(" / /");
	gotoxy(13 + (y_axis * 7), 88);
	printf("/ /");
	gotoxy(14 + (y_axis * 7), 88);
	printf("\\ \\");
	gotoxy(15 + (y_axis * 7), 88);
	printf(" \\_\\");
}

void clear_arrows(int y_axis) { // Clears arrows at previous location
	hide_cursor();
	gotoxy(11 + (y_axis * 7), 28);
	printf("  ");
	gotoxy(12 + (y_axis * 7), 28);
	printf("     ");
	gotoxy(13 + (y_axis * 7), 28);
	printf("      ");
	gotoxy(14 + (y_axis * 7), 28);
	printf("    ");
	gotoxy(15 + (y_axis * 7), 28);
	printf("   ");

	gotoxy(11 + (y_axis * 7), 88);
	printf("    ");
	gotoxy(12 + (y_axis * 7), 88);
	printf("    ");
	gotoxy(13 + (y_axis * 7), 88);
	printf("   ");
	gotoxy(14 + (y_axis * 7), 88);
	printf("     ");
	gotoxy(15 + (y_axis * 7), 88);
	printf("      ");
}

void draw_gameover() { // Prints game over screen
	hide_cursor();
	gotoxy(13, 5);
	printf("     ______                                                						 ______");
	gotoxy(14, 5);
    printf("  .-\"      \"-.                                           					      .-\"      \"-.");
    gotoxy(15, 5);
    printf(" /            \\                                        					     /            \\");
    gotoxy(16, 5);
    printf("|              |   _______    ___    __  __   ______      ______  __      __  ______   _____    |              |");
    gotoxy(17, 5);
    printf("|,  .-.  .-.  ,|  |  _____|  / _ \\  |  \\/  | |  ____|    |  __  | \\ \\    / / |  ____| |  __ \\   |,  .-.  .-.  ,|");
    gotoxy(18, 5);
    printf("| )(__/  \\__)( |  | |  __   / /_\\ \\ | \\  / | | |__       | |  | |  \\ \\  / /  | |__    | |__) |  | )(__/  \\__)( |");
    gotoxy(19, 5);
    printf("|/     /\\     \\|  | | |_ \\  |  _  | | |\\/| | |  __|      | |  | |   \\ \\/ /   |  __|   |  _  /   |/     /\\     \\|");
    gotoxy(20, 5);
    printf("(_     ^^     _)  | |___| | | | | | | |  | | | |____     | |__| |    \\  /    | |____  | | \\ \\   (_     ^^     _)");
    gotoxy(21, 5);
    printf(" \\__|IIIIII|__/    \\______| |_| |_| |_|  |_| |______|    |______|     \\/     |______| |_|  \\_\\   \\__|IIIIII|__/");
    gotoxy(22, 5);
    printf("  | \\IIIIII/ |                                          					      | \\IIIIII/ |");
    gotoxy(23, 5);
    printf("  \\          /                                          					      \\          /");
    gotoxy(24, 5);
    printf("   `--------`                                           			  		       `--------`");
}
