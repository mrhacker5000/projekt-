/*
 * LCD.h
 *
 *  Created on: 22. jan. 2025
 *      Author: phill
 */

#ifndef LCD_H_
#define LCD_H_

#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "charset.h"

uint8_t* initalize_LCD() ;

void LCD_initgame(uint8_t* LCD) ;

void add_string(uint8_t* LCD, char* text, uint8_t x, uint8_t y) ;

void set_score(uint8_t* LCD,  uint8_t amount) ;

void hp(uint8_t* LCD, uint8_t amount) ;

void hp1(uint8_t* LCD) ;
void hp2(uint8_t* LCD) ;
void hp3(uint8_t* LCD) ;

void LCDclrline(uint8_t *LCD,uint8_t line_y) ;

void LCDclrscrn(uint8_t *LCD,uint8_t fill) ;

#endif /* LCD_H_ */
