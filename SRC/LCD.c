
/*
 * LCD.c
 *
 *  Created on: 22. jan. 2025
 *      Author: phill
 */
#include "LCD.h"

uint8_t* initalize_LCD(){
	lcd_init();
	uint8_t* LCD = (uint8_t*) malloc(512);
	LCDclrscrn(LCD, 0);


	return LCD;
}

void LCD_initgame(uint8_t* LCD){

	add_string(LCD, "<3 <3 <3", 0, 0);
	add_string(LCD, "Score: 0", 0, 1);
}


void LCD_score(uint8_t *LCD, uint32_t amount) {
    char printer[12];
    sprintf(printer, "%lu", amount);

    LCDclrline(LCD, 1) ;
    add_string(LCD, "Score: ", 0, 1);


    add_string(LCD, printer, 0x20, 1) ;
}

void hp(uint8_t* LCD, uint8_t amount){

	switch(amount){
	case 0:
		LCDclrline(LCD, 0) ;
		break;
	case 1:
		hp1(LCD);
		break;
	case 2:
		hp2(LCD);
		break;
	case 3:
		hp3(LCD);
		break;
	default:
		hp3(LCD);
	}
}

void hp1(uint8_t* LCD){
	LCDclrline(LCD, 0) ;
	add_string(LCD, "<3",0,0 );
}

void hp2(uint8_t* LCD){
	LCDclrline(LCD, 0) ;
	add_string(LCD, "<3 <3",0,0 );
}

void hp3(uint8_t* LCD){
	LCDclrline(LCD, 0) ;
	add_string(LCD, "<3 <3 <3",0,0 );
}

void add_string(uint8_t* LCD, char* text, uint8_t x, uint8_t y){

	uint8_t length = strlen(text);

	x = x%(128);
	y = y%4;

	uint16_t arr[ 20 ];
	memset(arr,0,10);


	for(int p = 0; p < length; p++){
		arr[p] = ((uint16_t) text[p] - 32);
	}

	for(int i = 0; i < length; i++){
		LCD[(i*5) + 0 + x + y*128] = character_data[ arr[i] ][0];
		LCD[(i*5) + 1 + x + y*128] = character_data[ arr[i] ][1];
		LCD[(i*5) + 2 + x + y*128] = character_data[ arr[i] ][2];
		LCD[(i*5) + 3 + x + y*128] = character_data[ arr[i] ][3];
		LCD[(i*5) + 4 + x + y*128] = character_data[ arr[i] ][4];
	}
	lcd_push_buffer(LCD);
}

void LCDclrline(uint8_t *LCD,uint8_t row){

	for(int i= 0; i < 128; i++){
		LCD[i+row*128] = 0;
	}

	lcd_push_buffer(LCD);
}

void LCDclrscrn(uint8_t *LCD,uint8_t fill){
	memset(LCD, fill, 512);
	lcd_push_buffer(LCD);
}
