#include <REGX52.H>

void delay(int t);
void led_loop(void);
char led(unsigned int n);

void main(void)
{	
	P1 = 0xFF;
	P0 = 0xFF;

	for(;;)
	{
	 	int a;
		a = P1;	 
		a = a & 0xF0;

		if(a == 0x70) led_loop();
	}
}

char led(unsigned int n)
{
 return n;
}

void delay(int t)
{
 	int x;
 	for(x=0;x<t;x++);
}

void led_loop(void)
{			
		int t=10000;

		P0=led(0x7F);
 		delay(t);
		P0=led(0xBF);
		delay(t);
		P0=led(0xDF);
		delay(t);
		P0=led(0xF7);
		delay(t);
		P0=led(0xFB);
		delay(t);
		P0=led(0xFD);
		delay(t);
		P0=led(0xFE);
		delay(t);
		P0=led(0xFF);
		delay(t);
}

