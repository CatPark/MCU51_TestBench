#include <STC89.H>

/*******************************************
   Set conditional compiling as below:
   RICHMCU - for RichMCU Development Board
   XT100   - for XT100   Development Board
********************************************/
#define		RICHMCU

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
	char sw;
	char n;
	char lut[4][2]={{SW1, PTN1}, {SW2, PTN2}, {SW3, PTN3}, {SW4, PTN4}};
			
 	PORT_SW=0xFF;
	for(;;)
	{
	 	sw=PORT_SW;
		sw=sw & PORT_MSK;

		for (n=0; n< 3; n++)
		{
		 if (sw == lut[n][0]) 
		 {
		 	PORT_LED=led(lut[n][1]);
		 }
		 else PORT_LED=led(0);
		}
	}
}  