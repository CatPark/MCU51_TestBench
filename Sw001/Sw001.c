#include <STC89.H>

char led( char a);

void main(void)

{
	unsigned int x;
			
 	P1=0xFF;
	for(;;)
	{
	 	x=P1;
		x=x & 0xF0;

		if  (x==0x70) P0=led(0xC0);
		else if(x==0xB0) P0=led(0x30);
		else if(x==0xD0) P0=led(0x0C);
		else if(x==0xE0) P0=led(0x03);
		else P0=led(0x00);
	}

}
char led( char a)
{
	return ~a;	
}



		  