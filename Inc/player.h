#include "stdint.h"
#include "stdio.h"
#include "30010_io.h"
#include "stm32f30x_conf.h"


struct player  {
  char * name;
  uint32_t score;
  uint8_t life;
}
