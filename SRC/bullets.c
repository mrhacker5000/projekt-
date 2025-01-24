#include "HEADER.h"

#define BULLET_CHAR '*'
#define MAX_BULLETS 10
#define MAX_ASTROIDBULLETS 10
#define MAX_ASTROID 3

// Arrays til at holde styr på kugler og asteroider
Bullet bullets[MAX_BULLETS];
Astroidbullets Abullets[MAX_ASTROIDBULLETS];
Astroid astroid[MAX_ASTROID];

// Flyt terminalcursor til en bestemt position
void gotoxyz(int x, int y) {
    printf("\x1B[%d;%dH", y, x);
}

// Initialiser spillerens kugler (deaktiver dem alle)
void init_bullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].active = 0;
    }
}

// Skyder en kugle fra spillerens position
void shoot_bullet(player *player) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bullets[i].active) {
            bullets[i].x = player->x;
            bullets[i].y = player->y;
            bullets[i].direction = player->direction;
            bullets[i].active = 1;
            break;
        }
    }
}

// Opdater positionen af spillerens kugler
void update_bullets(player *player) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            if (bullets[i].direction == '^') {
                bullets[i].y--;
            } else if (bullets[i].direction == 'v') {
                bullets[i].y++;
            } else if (bullets[i].direction == '<') {
                bullets[i].x--;
            } else {
                bullets[i].x++;
            }


            if (bullets[i].x > 119 || bullets[i].x <= 2 || bullets[i].y <= 2 || bullets[i].y >= 40) {
                bullets[i].active = 0;
            }
        }
    }
}

// Tegn spillerens kugler på skærmen
void draw_bullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            gotoxyz(bullets[i].x, bullets[i].y);
            putchar(BULLET_CHAR);
        }
    }
}

// Fjern spillerens kugler fra skærmen
void clear_bullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            gotoxyz(bullets[i].x, bullets[i].y);
            putchar(' ');
        }
    }
}

// Kollisionsdetektion mellem spillerens kugler og fjender
void collision_bullet(Enemy enemy[], int maxspawn) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            for (int j = 0; j < maxspawn; j++) {
                if (enemy[j].active) {
                    if (bullets[i].x == enemy[j].x && bullets[i].y >= enemy[j].y && bullets[i].y <= enemy[j].y + ENEMY_HEIGHT - 1) {
                        bullets[i].active = 0; // Kuglen deaktiveres
                        enemy[j].health--;    // Fjenden tager skade
                        break;
                    }
                }
            }
        }
    }
}

// Simpel forsinkelse til tidsstyring
void delay(int iterations) {
    for (volatile int i = 0; i < iterations; i++) {
    }
}

// Initialiser asteroidekugler (deaktiver dem alle)
void init_astroidbullets() {
    for (int i = 0; i < MAX_ASTROIDBULLETS; i++) {
        Abullets[i].active = 0;
    }
}

// Asteroider skyder kugler
void shoot_astroidbullet(Astroid astroid[]) {
    for (int j = 0; j < MAX_ASTROID; j++) {
        for (int i = 0; i < MAX_ASTROIDBULLETS; i++) {
            if (!Abullets[i].active) {
                Abullets[i].x = astroid[j].x;
                Abullets[i].y = astroid[j].y;
                Abullets[i].active = 1;
                break;
            }
        }
    }
}

// Opdater positionen af asteroidekugler
void update_astroidbullets() {
    for (int i = 0; i < MAX_ASTROIDBULLETS; i++) {
        if (Abullets[i].active) {
            Abullets[i].x--; // Kugler bevæger sig til venstre
        }

        // Deaktiver kuglen, hvis den er uden for området
        if (Abullets[i].x > 119 || Abullets[i].x <= 2 || Abullets[i].y <= 2 || Abullets[i].y >= 40) {
            Abullets[i].active = 0;
        }
    }
}

// Tegn asteroidekugler på skærmen
void draw_astroidbullets() {
    for (int i = 0; i < MAX_ASTROIDBULLETS; i++) {
        if (Abullets[i].active) {
            gotoxyz(Abullets[i].x, Abullets[i].y);
            putchar(BULLET_CHAR);
        }
    }
}

// Fjern asteroidekugler fra skærmen
void clear_astroidbullets() {
    for (int i = 0; i < MAX_ASTROIDBULLETS; i++) {
        if (Abullets[i].active) {
            gotoxyz(Abullets[i].x, Abullets[i].y);
            putchar(' ');
        }
    }
}

// Kollisionsdetektion mellem asteroidekugler og spilleren
void collision_abullet(player *player) {
    for (int i = 0; i < MAX_ASTROIDBULLETS; i++) {
        if (Abullets[i].active) {
            if (Abullets[i].x == player->x && Abullets[i].y == player->y) {
                player->health--;     // Spilleren tager skade
                Abullets[i].active = 0; // Kuglen deaktiveres
                break;
            }
        }
    }
}
