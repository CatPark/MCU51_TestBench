#include <STC89.H>

unsigned int checkkey()
{
 unsigned  int a;
 unsigned  int b;

 P1=0xFF;
 P3=0xFF;

 a = ~P1;
 b = ~P3;

a = a & 0xF0;
b = b & 0x3C;

if( b == 0x04) return(0);
else if( b == 0x08) return(1);
else if( b == 0x10) return(2);
else if( b == 0x20) return(3);
else if( a == 0x10) return(4);
else if( a == 0x20) return(5);
else if( a == 0x40) return(6);
else if( a == 0x80) return(7);
else return(33);
}
sbit Beep=P3^6;	
sbit L00=P0^0;

void main(void)
{
 unsigned int freq[]={20,30,40,50,60,70,80,90};
 unsigned int d;
 unsigned char key;

 for(;;)
 	{
		while((key=checkkey())>7);
		L00=0;
		for (d=0;d<freq[key];d++);
		Beep=~Beep;
		L00=1;
		for (d=0;d<freq[key];d++);
		Beep=~Beep;
	}
}
