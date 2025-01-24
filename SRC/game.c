#include "HEADER.h"



void game() {
    Astroid astroid[3];
    Enemy enemy[15];

    while (1) {
    		initialize_menu();
    		difficulty_screen();
    		uint8_t selection = difficulty_controls();

            Difficulty diff;
            handle_difficulty_selection(selection, &diff);

            player p1 = {10, 20, INITIAL_HEALTH, INITIAL_SCORE, 0};
            setup_game(&p1, astroid, enemy, diff.max);
            game_loop(&p1, astroid, enemy, diff);
    }
}



void handle_difficulty_selection(char selection, Difficulty *diff) {
    switch (selection) {
        case 1:
            *diff = (Difficulty){40, 5};
            break;
        case 2:
            *diff = (Difficulty){20, 7};
            break;
        case 3:
            *diff = (Difficulty){5, 12};
            break;
        default:
            *diff = (Difficulty){20, 7};
    }
}


void setup_game(player *p1, Astroid *astroid, Enemy *enemy, int maxspawn) {
    clrscr();
    init_bullets();
    init_enemy(enemy, maxspawn);
    init_astroid(astroid);
    init_astroidbullets();
    gamewindow();
}


void game_loop(player *p1, Astroid *astroid, Enemy *enemy, Difficulty diff) {

    int t = 0;

    uint8_t* LCD = initalize_LCD();
    LCD_initgame(LCD);


    while (1) {
        readjoystick();
        int joy = readjoystick();
        int key = readkey();
        setled();
        clearplayer(*p1);
        updateplayer(p1, joy, key);
        drawplayer(*p1);

        collision_enemy(enemy, diff.max, p1);
        collision_bullet(enemy, diff.max);

        t++;
        if (t >= diff.enemypace) {
            start_enemy(enemy, diff.max);
            clear_enemy(enemy, diff.max);
            update_enemy(enemy, diff.max, p1);
            draw_enemy(enemy, diff.max);
            t = 0;
        }

        start_astroid(astroid);
        draw_astroid(astroid);

        setled(*p1);


        if (key == 5) {
            shoot_bullet(p1);
        }

        clear_bullets();
        update_bullets(p1);
        draw_bullets();


        timer(shoot_astroidbullet, 100, astroid);
        clear_astroidbullets();
        update_astroidbullets();
        draw_astroidbullets();
        collision_abullet(p1);


        uint32_t amountHP = p1->health;
        uint32_t amountScore = p1->score;
        hp(LCD, amountHP);

        boss_key_function(key);

        p1->score += 1;

        LCD_score(LCD, amountScore);

        if (p1->health == 0) {
            break;
        }
}

    clrscr();
    draw_gameover();
    gotoxy(30, 55);
    printf("Score: %d\n", p1->score);
    gotoxy(35, 45);
    printf("Press 'R' to restart the game!");

    // Game over loop
    while (1) {
    	int key = readkey();
        if (key == 6) {
            game();
            return;
        }
    }
}

