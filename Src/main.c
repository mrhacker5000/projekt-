#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h"       // Input/output library for this course
#include "ansi.h"
#include "excellut.h"
#include "GPIO.h"

int main(void) {
    uart_init(9600);
    clrscr();
    clear();

    graphic() ;

    while (1) ;
}
