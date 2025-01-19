
#ifndef BACKGROUND_H_
#define BACKGROUND_H_



typedef struct {
    int x;
    int y;
} Star;



void delay(int milliseconds);
void drawBackground();
void clearScreen();
void initializeStars();
void updateStars();


#endif /* BACKGROUND_H_ */
