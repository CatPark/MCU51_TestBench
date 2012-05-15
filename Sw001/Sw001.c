#include <STC89.H>

/*******************************************
   Set conditional compiling as below:
   RICHMCU - for RichMCU Development Board
   XT100   - for XT100   Development Board
********************************************/
#define		XT100

#ifdef		RICHMCU
#define		PORT_LED	P0
#define		PORT_SW		P1
#define		PORT_MSK	0xF0
#define		SW1			0x70
#define		SW2			0xB0
#define		SW3	  		0xD0
#define		SW4			0xE0
#define		PTN1		0xC0
#define		PTN2		0x30
#define		PTN3		0x0C
#define		PTN4		0x03
#endif

#ifdef		XT100
#define		PORT_LED	P0
#define		PORT_SW		P2
#define		PORT_MSK	0x0F
#define		SW1			0x0E
#define		SW2			0x0D
#define		SW3	    	0x0B
#define		SW4			0x07
#define		PTN1		0x03
#define		PTN2		0x0C
#define		PTN3		0x30
#define		PTN4		0xC0
#endif

char led(char a)
{
	return ~a;	
}

void main(void)
{
	unsigned int x;
			
 	PORT_SW=0xFF;
	for(;;)
	{
	 	x=PORT_SW;
		x=x & PORT_MSK;

		if (x==SW1) PORT_LED=led(PTN1);
		else if(x==SW2) PORT_LED=led(PTN2);
		else if(x==SW3) PORT_LED=led(PTN3);
		else if(x==SW4) PORT_LED=led(PTN4);
		else PORT_LED=led(0x00);
	}
}  