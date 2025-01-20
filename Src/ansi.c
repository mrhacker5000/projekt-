#define ESC 0x1B
#include "ansi.h"
#include "string.h"

void fgcolor(uint8_t foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

void bgcolor(uint8_t background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
 	              way coming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

    Value      Color
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}

void color(uint8_t foreground, uint8_t background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);
}

void underline(uint8_t on) {
//	04 for underline, 24 for no-underline
	printf("%c[%dm", ESC, on) ;
}

void gotoxy(uint8_t y, uint8_t x) {
	printf("%c[%d;%df", ESC, y, x) ;
}

void blink(uint8_t on) {
//	05 for blink, 25 for no-blink
	printf("%c[%dm", ESC, on) ;
}

void inverse(uint8_t on) {
//	07 for inverse, 27 for no-inverse
	printf("%c[%dm", ESC, on) ;
}

void clrscr() {
	printf("%c[2J", ESC) ;
}

void clrseol() {
	printf("%c[2K", ESC) ;
}

void clear() {
	printf("%c[H", ESC) ;
}

void updatepos(int8_t *x, int8_t *y, int8_t vx, int8_t vy) {
	*x += vx ;
	*y += vy ;
}

void drawball(int8_t x, int8_t y) {
	gotoxy(y,x) ;
	printf("o") ;
}

void clearball(int8_t prev_y, int8_t prev_x) {
    gotoxy(prev_y, prev_x); // Move the cursor to the previous position
    printf(" ");            // Print a space to clear the old ball
}

void hidecursor() {
	printf("\e[?25l") ;
}

void check_collision(Ball *ball) {
	// Check collision with vertical walls (vert2)
	    if (ball->x <= 2 || ball->x >= 17) { // Assuming wall boundaries at x = 2 and x = 60
	        ball->vx = -ball->vx; // Invert horizontal velocity
	        ball->hits = ball->hits +1 ;
	    }

	    // Check collision with horizontal walls (hor2)
	    if (ball->y <= 2 || ball->y >= 60) { // Assuming wall boundaries at y = 2 and y = 20
	        ball->vy = -ball->vy; // Invert vertical velocity
	        ball->hits = ball->hits +1 ;
	    }
}

void updatehitbox(int hits) {
	gotoxy(10,26) ;
	printf("Hits: %d", hits) ;

		gotoxy(9,25) ;

		printf("%c", nw1) ;

		int i1 = 0 ;

		while (i1 <= 8) {
			printf("%c", hor1) ;
			i1++ ;
		}

		printf("%c", ne1) ;

		gotoxy(10,25) ;
		printf("%c", vert1) ;
		gotoxy(10,35) ;
		printf("%c", vert1) ;

		gotoxy(11,25) ;

		printf("%c", sw1) ;

		int i2 = 0;

		while (i2 <= 8) {
				printf("%c", hor1) ;
				i2++ ;
			}

		printf("%c", se1) ;
}

void window(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, const char *title, uint8_t style) {

	clrscr() ;
	resetbgcolor() ;

	char vert ;
	char hor ;
	char nw ;
	char ne ;
	char sw ;
	char se ;

	if (style == 1) {
		vert = vert1 ;
		hor = hor1 ;
		nw = nw1 ;
		ne = ne1 ;
		sw = sw1 ;
		se = se1 ;
	}
		else {
			vert = vert2 ;
			hor = hor2 ;
			nw = nw2 ;
			ne = ne2 ;
			sw = sw2 ;
			se = se2 ;
	}

	int width = x2 - x1 + 1;
	int height = y2 - y1 + 1;
	int title_length = strlen(title);

	    // Top border
	gotoxy(y1, x1);
	printf("%c", nw);
	for (int i = 0; i < width - 2; i++) printf("%c", hor);
	printf("%c", ne);

	    // Title in the top border
	gotoxy(y1, x1 + (width - title_length) / 2);
	printf("%s", title);

	    // Side borders
	for (int i = 1; i < height - 1; i++) {
		gotoxy(y1 + i, x1);
	    printf("%c", vert);
	    gotoxy(y1 + i, x2);
	    printf("%c", vert);
	    }

	    // Bottom border
	gotoxy(y2, x1);
	printf("%c",sw);
	for (int i = 0; i < width - 2; i++) printf("%c", hor);
	printf("%c",se);
	}

void graphic() {
	clrscr() ;
	clear() ;

	Ball ball ;
			ball.x = 3 ;
			ball.y = 3 ;
			ball.vx = 1 ;
			ball.vy = 1 ;
			ball.hits = 0 ;

	printf("%c", nw2) ;

	int i = 2 ;
	while (i <= 60) {
		printf("%c", hor2) ;
		i++ ;
	}

	printf("%c", ne2) ;

	int y = 2;

	while (y <= 17) {
		gotoxy(y, 1) ;
		printf("%c", vert2) ;
		y++ ;
	}

	gotoxy(y,1) ;

	printf("%c", sw2) ;

	int x = 2 ;

	while (x <= 60) {
		printf("%c", hor2) ;
		x++ ;
	}

	printf("%c", se2) ;

	int z = 2 ;

	while (z < 18) {
		gotoxy(z, 61) ;
		printf("%c", vert2) ;
		z++ ;
	}

	updatehitbox(ball.hits) ;

	while (1) {
		clearball(ball.x, ball.y) ;
		updatepos(&ball.x, &ball.y, ball.vx, ball.vy) ;
		check_collision(&ball) ;
		drawball(ball.y, ball.x) ;
		gotoxy(10,27);
		updatehitbox(ball.hits);
	}
}

void gamewindow() {
	window(1, 1, 120, 41, "", 2) ;
}
