#define ESC 0x1B
#include "ansi.h"

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

void updatepos(*x, *y, int8_t vx, int8_t vy) {
	*x += vx ;
	*y += vy ;
}

void drawball(int8_t x, int8_t y) {
	gotoxy(y,x) ;
	printf("o") ;
}

void window(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, char *title, uint8_t style) {

	clrscr() ;
	resetbgcolor() ;

	char start = "0";
	char end = "0";
	char vert = "0";
	char hor = "0";
	char nw = "0";
	char ne = "0";
	char sw = "0";
	char se = "0";

	if (style == 1) {
		start = start1 ;
		end = end1 ;
		vert = vert1 ;
		hor = hor1 ;
		nw = nw1 ;
		ne = ne1 ;
		sw = sw1 ;
		se = se1 ;
	}
		else {
			start = start2 ;
			end = end2 ;
			vert = vert2 ;
			hor = hor2 ;
			nw = nw2 ;
			ne = ne2 ;
			sw = sw2 ;
			se = se2 ;
	}

	gotoxy(y1, x1) ;
	printf("%c", nw) ;
	printf("%c", start) ;

	inverse(07) ;
	printf(" ") ;

	int len = 0 ;
	while (title[len] != '\0') {
			printf("%c", title[len]) ;
			len++ ;
	} ;

	printf(" ") ;
	inverse(27) ;

	printf("%c", end) ;

	int x = 0 ;

	uint8_t length = strlen(title) ;

	while (x < (x2 - length - 2 - 4)) {
		printf("%c", hor);
		x++ ;
	} ;

	printf("%c", ne);

	int y = 2 ;

	while (y < y2) {
		gotoxy(y, x1) ;
		printf("%c", vert) ;
		y++ ;
	}

	gotoxy(y2, x1) ;

	printf("%c", sw) ;

	int z = 0;
	while (z < x2 -1) {
		printf("%c", hor) ;
		z++ ;
	}
	int k = 2;
		while (k < (y2 - 3)) {
			gotoxy(k, x2) ;
			printf("%c", vert) ;
			k++ ;
		}

	gotoxy(y2, x2) ;
	printf("%c", se) ;

}

void graphic() {
	clrscr() ;
	clear() ;

	typedef struct {
		int8_t x ;
		int8_t vx ;
		int8_t y ;
		int8_t vy ;
	} Ball;

	printf("%c", nw2) ;

	int i = 2 ;
	while (i <= 60) {
		printf("%c", hor2) ;
		i++ ;
	}

	printf("%c", ne2) ;

	int y = 2;

	while (y <= 20) {
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

	gotoxy(10,27) ;

	int hits = 0 ;

	printf("Hits: %d", hits) ;

	gotoxy(9,26) ;

	printf("%c", nw1) ;

	int i1 = 0 ;

	while (i1 <= 6) {
		printf("%c", hor1) ;
		i1++ ;
	}

	printf("%c", ne1) ;

	gotoxy(10,26) ;
	printf("%c", vert1) ;
	gotoxy(10,34) ;
	printf("%c", vert1) ;

	gotoxy(11,26) ;

	printf("%c", sw1) ;

	int i2 = 0;

	while (i2 <= 6) {
			printf("%c", hor1) ;
			i2++ ;
		}

	printf("%c", se1) ;

	Ball ball ;
		ball.x = 2 ;
		ball.y = 2 ;
		ball.vx = 1 ;
		ball.vy = 1 ;


}
