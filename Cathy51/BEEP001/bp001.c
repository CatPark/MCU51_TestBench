#include <STC89.H>

void main(void)
{
	unsigned int t;
	for(;;)
	{
		P3=0x00;
		for(t=0;t<10;t++);
		P3=0x40;
		for(t=0;t<10;t++);
	}
}
