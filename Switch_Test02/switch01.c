#include <REGX52.H>

void switch03_init(void)
{
	P0=0xFF;
	P1=0xFF;
}
void switch03_loop(void)
{
	unsigned char port_in,key;

	port_in=P1;

	port_in=~port_in;

	key=port_in&0x80; 


if((port_in&0xF0)!=0)
{
		 if((port_in&0x80)!=0)
 		{
 			P0=0x3F;
		}
		if((port_in&0x40)!=0)
		{
			P0=0xCF;
		}
		if((port_in&0x20)!=0)
		{	  
			P0=0xFC;
		}
		if((port_in&0x10)!=0)
		{
			P0=0xF3;
		}
}
			
else
{
	P0=0xFF;
}	

}