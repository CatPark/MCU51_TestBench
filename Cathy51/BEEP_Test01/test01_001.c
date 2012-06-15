#include <REGX52.H>

sbit BEEP=P3^6;
sbit L00=P0^0;
 void delayst(unsigned int i)
 {
 	unsigned int j;

	for(;i>0;i--)
 	for(j=0;j<31;j++)

 	{;}
 }

 void delay(unsigned int i)
 {
 	unsigned int j;

 	for(;i>0;i--)
 	for (j=0;j<125;j++)

 	{;}
 }

void main()
{
	unsigned int j;
	while(1)
	{
		L00=0;
		for(j=1000;j>0;j--)
		{
			BEEP=~BEEP;
			delayst(2);
		}
		L00=1;
		BEEP=1;
		delay(500);
	}
}