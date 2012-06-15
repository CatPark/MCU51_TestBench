#include <STC89.H>

void delay(unsigned int t);
void led_On(void);
void led_Off(void);

void main(void)
{	
	char a;
	P1 = 0xFF;
	P0 = 0xFF;

	for(;;)
	{
	 	a = P1;	 
		a = a & 0xF0;

		if(a == 0x70) led_On();
		if(a == 0x70) led_Off();

/*		if(a == 0x70) 
		{
			led_On();
			led_Off();
		} */
	}
}

void delay(unsigned int t)
{
 	unsigned int x;
 	for(x=0;x<t;x++);
}

void led_On(void)
{			
	unsigned int t=30000;

	P0=0x7F;
 	delay(t);
}
void led_Off(void)
{			
	unsigned int t=30000;
	P0=0xFF;
	delay(t);

}
