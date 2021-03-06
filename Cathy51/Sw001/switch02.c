#include <STC89.H>

#define	DEBUG
#undef	DEBUG

void switch02_init(void)
{
 P0=0xFF;		/* Turn off all P0 LEDs */
 P1=0xFF;		/* Prepare to get standalone switches K5 to K8 */
}

void switch02_loop(void)
{
 unsigned char port_in, key;

  port_in = P1;					/* Read P1 to detect switch status */

  /* Key on is to set port pin level to 0
     P1 = 1111 xxxx => No key pressed
  	 P1 = 0xxx xxxx => K8
  	 P1 = x0xx xxxx => K7
     P1 = xx0x xxxx => K6
     P1 = xxx0 xxxx => K5
  */

  port_in = ~port_in;						/* Bit reverse P1 for checking key status */
  /* P1 = 0000 xxxx => No key pressed
     P1 = 1xxx xxxx => K8 (& 0x80 --> 1000 0000)
     P1 = x1xx xxxx => K7 (& 0x40 --> 0100 0000)
     P1 = xx1x xxxx => K6 (& 0x20 --> 0010 0000)
     P1 = xxx1 xxxx => K5 (& 0x10 --> 0001 0000)
  */

  key = port_in & 0x80;				/* Check K8 status (check bit7 of Port1) */
  /* P1 = 0000 0000 => No key pressed
     P1 = 1000 0000 => K8
     P1 = 0100 0000 => K7
     P1 = 0010 0000 => K6
     P1 = 0001 0000 => K5
  */

#ifdef DEBUG
  P0 = key;	 					/* Debug only */
#else
  if ((port_in & 0xF0) != 0)		/* Any K5 - K8 is pressed 1111 xxxx */
  {
	  if ((port_in & 0x80) != 0)	/* K8 is pressed */
	  {
	   P0=0x3F;						/* 0011 1111 */						
	  }
	  
	  if ((port_in & 0x40) != 0)	/* K7 is pressed */
	  {
	   P0=0xCF;			 			/* 1100 1111 */
	  }
	  
	  if ((port_in & 0x20) != 0)	/* K6 is pressed */
	  {
	   P0=0xF3;				  		/* 1111 0011 */
	  }
	  
	  if ((port_in & 0x10) != 0)	/* K5 is pressed */
	  {
	   P0=0xFC;					   	/* 1111 1100 */
	  }
  }
  else
  {
   P0=0xFF;
  }
#endif
}
