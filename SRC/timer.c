#include "HEADER.h"




void timer(void (*function)(Astroid[]), int time, Astroid astroid[]){
	static int i = 0;

	i++;
	if (i >= time){
		function(astroid);
		i = 0;
	}
}
