#ifndef MENU_H_
#define MENU_H_


// ANSI FUNCTIONS

void clear_terminal();
void hide_cursor();
void set_terminal_size(int rows, int cols);

// DRAW MENU

void draw_title();
void draw_menu();
void draw_difficulty();
void draw_arrows(int y_axis);
void clear_arrows(int y_axis);
void draw_gameover();

// MENU CONTROLS

void title_screen_controls();
void menu_controls();
int difficulty_controls();
void help_controls();

// MENU

void initialize_menu();
void help_screen();
void difficulty_screen();
void menu_screen();

// BOSS KEY

void draw_boss_key();
void boss_key_function();

#endif /* MENU_H_ */
