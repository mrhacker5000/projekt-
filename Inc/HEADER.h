#ifndef HEADER_H_
#define HEADER_H_


// Constants for difficulty levels
#define MAX_ENEMY 3
#define MAX_BULLETS 10
#define INITIAL_SCORE 0
#define INITIAL_HEALTH 3
#define ENEMY_WIDTH 7
#define ENEMY_HEIGHT 5


#include "menu.h"
#include "stdint.h"
#include "stdio.h"
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ansi.h"
#include <time.h>
#include "charset.h"
#include "LCD.h"



// STRUCTS

typedef struct {
    int x;
    int y;
    int active;
    char direction;
} Bullet;


typedef struct {
    int x;
    int y;
    int active;
} Astroidbullets;


typedef struct {
	int x;
	int y;
	int health;
	int score;
	int powerup;
	char direction;
} player;


typedef struct {
    int x;
    int y;
    int active;
    int health;
    int maxspawn;
} Enemy;


typedef struct {
	int x;
	int y;
	int active;
	int health;
} Astroid;


typedef struct {
	int enemypace;
	int max;
} Difficulty;


// FUNKTIONER //
void start();
int readkey();
void boss_key_function(int key);


// GAME
#define DELAY 50000
void setup_game(player *p1, Astroid *astroid, Enemy *enemy, int maxspawn);
void handle_difficulty_selection(char selection, Difficulty *diff);
void game_loop(player *p1, Astroid *astroid, Enemy *enemy, Difficulty diff);
void game();


// MENU
void draw_title();
void draw_menu();
void draw_difficulty();
void draw_arrows();
void draw_gameover();
void clear_terminal();
void hide_cursor();
void set_terminal_size(int rows, int cols);
int selection();


// BULLETS
void clrscr();
uint8_t space_press();
void gotoxyz(int x, int y);
void bullet(uint8_t space_press());
void init_bullets();
void shoot_bullet(player *player);
void update_bullets(player *player);
void draw_bullets();
void clear_bullets();
void delay(int iterations);
void collision_bullet(Enemy enemy[], int maxspawn);


// PLAYER
void init_player(player *p1) ;
void drawplayer(player p1) ;
void updateplayer(player *p1, int input, int key) ;
void clearplayer(player p1) ;



// GPIO
int8_t readjoystick() ;
void setled() ;


// ENEMY
void init_enemy(Enemy enemy[], int maxspawn);
void start_enemy(Enemy enemy[], int maxspawn);
void update_enemy(Enemy enemy[], int maxspawn, player *player);
void draw_enemy(Enemy enemy[], int maxspawn);
void clear_enemy(Enemy enemy[], int maxspawn);
void collision_enemy(Enemy enemy[], int maxspawn, player *player);


// ASTROID
void start_astroid(Astroid astroid[]);
void init_astroid(Astroid astroid[]);
void draw_astroid(Astroid astroid[]);
void init_astroidbullets();
void shoot_astroidbullet(Astroid astroid[]);
void update_astroidbullets();
void draw_astroidbullets();
void clear_astroidbullets();
void collision_abullet(player *player);



// RANDOM
uint8_t Randoms(int min, int max);
void timer(void (*function)(Astroid[]), int time, Astroid astroid[]);



#endif /* HEADER_H_ */
