// =====================================================================
//
//	Exported by Cearn's excellut v1.0
//	(comments, kudos, flames to daytshen@hotmail.com)
//
// =====================================================================

#ifndef EXCELLUT_H
#define EXCELLUT_H
#include "stdint.h"
#include "stdio.h"
#include "30010_io.h"
#include "stm32f30x_conf.h"

typedef struct vector_t vector_t ;

int32_t expand(int32_t i) ;
void printfix(int32_t i) ;
int32_t sinsin(int32_t x) ;
int32_t coscos(int32_t x) ;
void initvector(vector_t *v) ;
void rotatevector(int32_t x, int32_t y, int32_t degree) ;

// === LUT SIZES ===
#define SIN_SIZE 512

// === LUT DECLARATIONS ===
extern const signed short SIN[512];

#endif	// EXCELLUT_H
