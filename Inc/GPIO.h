/*
 * GPIO.h
 *
 *  Created on: 14. jan. 2025
 *      Author: phill
 */

#ifndef GPIO_H_
#define GPIO_H_

// Includes :
#include "ansi.h"
#include "stdint.h"
#include "stdio.h"
#include "30010_io.h"
#include "player.h"

int8_t readjoystick() ;
void setled(player p1) ;

#endif /* GPIO_H_ */
