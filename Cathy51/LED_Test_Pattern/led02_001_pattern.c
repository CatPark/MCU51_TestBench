#include <REGX52.H>

#include "led02_001_io.h"
#include "led02_001_timing.h"

void led_blinking()	  
{
	int n,d;

	d=10000;
	n=0;

	for(;;)
	{
		P0=P1=led(n++);
		delay(d);
	}		
	
}
