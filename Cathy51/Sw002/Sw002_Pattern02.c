#include <REGX52.H>

void delay(unsigned int t);
void led_loop(void);

void main(void)
{	
	char a;
	P1 = 0xFF;
	P0 = 0xFF;

	for(;;)
	{
	 	a = P1;	 
		a = a & 0xF0;

		if(a == 0x70) led_loop();
	}
}

void delay(unsigned int t)
{
 	unsigned int x;
 	for(x=0;x<t;x++);
}

void led_loop(void)
{			
	unsigned int t=10000;

	P0=0x7F;
 	delay(t);
	P0=0xBF;
	delay(t);

}

