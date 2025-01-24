#include "HEADER.h"


uint8_t Randoms(int min, int max) {

	int rd_num = rand() % (max - min + 1) + min;

	return rd_num;
}

