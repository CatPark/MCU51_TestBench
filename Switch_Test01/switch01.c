#include <STC89.H>

main()
{
 unsigned char port_in, key;

 P0=0xFF;		/* Turn off all P0 LEDs */

 P1=0xF0;		/* Prepare to get standalone switches K5 to K8 */

 for (;;)
 {
  port_in = P1;					/* Read P1 to detect switch status */

  key = ~P1 & 0x80;				/* Check K8 status (check bit7 of Port1) */

  if (key != 0) P0=0xFF;		/* K8 pressed, turn LEDs on  */
  else P0=0;					/* K8 not pressed,   LED off */	
 }
}
