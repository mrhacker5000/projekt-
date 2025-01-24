/*
 * GPIO.c
 *
 *  Created on: 14. jan. 2025
 *      Author: phill
 */
#include "GPIO.h"

int8_t readjoystick() {
	int8_t val = 0 ;

	// Enable clocks for GPIOA, GPIOB, and GPIOC
	    RCC->AHBENR |= RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC;

	    // Configure PC0 (Right) as input with pull-down
	    GPIOC->MODER &= ~(0x00000003 << (0 * 2));  // Clear mode register
	    GPIOC->PUPDR &= ~(0x00000003 << (0 * 2));  // Clear pull-up/pull-down register
	    GPIOC->PUPDR |= (0x00000002 << (0 * 2));   // Set pull-down

	    // Configure PA4 (Up) as input with pull-down
	    GPIOA->MODER &= ~(0x00000003 << (4 * 2));
	    GPIOA->PUPDR &= ~(0x00000003 << (4 * 2));
	    GPIOA->PUPDR |= (0x00000002 << (4 * 2));

	    // Configure PB5 (Center) as input with pull-down
	    GPIOB->MODER &= ~(0x00000003 << (5 * 2));
	    GPIOB->PUPDR &= ~(0x00000003 << (5 * 2));
	    GPIOB->PUPDR |= (0x00000002 << (5 * 2));

	    // Configure PC1 (Left) as input with pull-down
	    GPIOC->MODER &= ~(0x00000003 << (1 * 2));
	    GPIOC->PUPDR &= ~(0x00000003 << (1 * 2));
	    GPIOC->PUPDR |= (0x00000002 << (1 * 2));

	    // Configure PB0 (Down) as input with pull-down
	    GPIOB->MODER &= ~(0x00000003 << (0 * 2));
	    GPIOB->PUPDR &= ~(0x00000003 << (0 * 2));
	    GPIOB->PUPDR |= (0x00000002 << (0 * 2));

	    // Read joystick inputs
	    uint16_t right = GPIOC->IDR & (0x0001 << 0);  // Read PC0
	    uint16_t up = GPIOA->IDR & (0x0001 << 4);     // Read PA4
	    uint16_t center = GPIOB->IDR & (0x0001 << 5); // Read PB5
	    uint16_t left = GPIOC->IDR & (0x0001 << 1);   // Read PC1
	    uint16_t down = GPIOB->IDR & (0x0001 << 0);   // Read PB0

	    if (right) {
	           val = 0x08;
	       } else if (left) {
	    	   val = 0x04;
	       } else if (center) {
	           val = 0x10;
	       } else if (up) {
	           val = 0x01;
	       } else if (down) {
	           val = 0x02;
	       }

	       return val; // Return the value corresponding to the joystick input
	   }

void setled(player p1) {
    // Enable the clock
	RCC->AHBENR |= RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC;

    // Configure PA9 (Blue) as output
    GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2)); // Clear speed register
    GPIOA->OSPEEDR |= (0x00000002 << (9 * 2)); // Set speed to 2 MHz
    GPIOA->OTYPER &= ~(0x0001 << 9);           // Set output type to push-pull
    GPIOA->MODER &= ~(0x00000003 << (9 * 2));  // Clear mode register
    GPIOA->MODER |= (0x00000001 << (9 * 2));   // Set PA9 as output

    // Configure PC7 (Green) as output
    GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2)); // Clear speed register
    GPIOC->OSPEEDR |= (0x00000002 << (7 * 2)); // Set speed to 2 MHz
    GPIOC->OTYPER &= ~(0x0001 << 7);           // Set output type to push-pull
    GPIOC->MODER &= ~(0x00000003 << (7 * 2));  // Clear mode register
    GPIOC->MODER |= (0x00000001 << (7 * 2));   // Set PC7 as output

    // Configure PB4 (Red) as output
    GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2)); // Clear speed register
    GPIOB->OSPEEDR |= (0x00000002 << (4 * 2)); // Set speed to 2 MHz
    GPIOB->OTYPER &= ~(0x0001 << 4);           // Set output type to push-pull
    GPIOB->MODER &= ~(0x00000003 << (4 * 2));  // Clear mode register
    GPIOB->MODER |= (0x00000001 << (4 * 2));   // Set PB49 as output

    // Control the LED on PA9 based on joystick input
    if (p1.health == 3) {
    	GPIOA->ODR |= (0x0001 << 9);
    	GPIOB->ODR |= (0x0001 << 4);
    	GPIOC->ODR |= (0x0001 << 7);

        GPIOC->ODR &= ~(0x0001 << 7);  // Turn on LED (Set PA9 high)
    }
    else if (p1.health == 2) {
    	GPIOA->ODR |= (0x0001 << 9);
    	GPIOB->ODR |= (0x0001 << 4);
    	GPIOC->ODR |= (0x0001 << 7);

    	GPIOC->ODR &= ~(0x0001 << 7);
    	GPIOB->ODR &= ~(0x0001 << 4);
    }
    else if (p1.health == 1) {
    	GPIOA->ODR |= (0x0001 << 9);
    	GPIOB->ODR |= (0x0001 << 4);
    	GPIOC->ODR |= (0x0001 << 7);

    	GPIOB->ODR &= ~(0x0001 << 4);
    }
    else {
    	GPIOA->ODR |= (0x0001 << 9);
    	GPIOB->ODR |= (0x0001 << 4);
    	GPIOC->ODR |= (0x0001 << 7);
    }
}




