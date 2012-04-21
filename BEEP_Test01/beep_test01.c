#include <REGX52.H>

sbit BEEP=P3^6;
sbit L00=P0^0;

int beepcount=0;			// Global variable

void delayst(unsigned int i)
 {
  	unsigned int j;
	for(;i>0;i--)
 	for(j=0;j<31;j++);
	{;}
 }

void delay(unsigned int i)
 {
  	unsigned int j;
	for(;i>0;i--)
 	for(j=0;j<125;j++);
	{;}
 }

void beep01(void)
{
	unsigned int j;
		// L00=0;
		for(j=1000;j>0;j--)
		{
			BEEP=~BEEP;
			delayst(2);
		}
		// L00=1;
		BEEP=1;
		delay(500);

}

void InitTimer0(void)
{
	TR0  = 0;			// Stop Timer
	TF0	 = 0;			// Reset Overflow
    TMOD = 0x01; 		// Set Timer0 to Mode 1 (1 shot)
    TH0 = 0xA0; 		// Delay time counter delay
    TL0 = 0x00;
    EA = 1;				// Enable Interrupt
    ET0 = 1;			// Enable Timer0 Interrupt
    TR0 = 1;	  		// Start Timer
} /* InitTimer0() */

void ISR_Timer0(void) interrupt 1 using 2	// Timer Interrupt Service Routine
{
   TR0 = 0;				// Stop Timer - Protection: NO MORE INTERRUPT

   TH0 = 0xA0;	   		// Rest timer delay time	
   TL0 = 0x00;

   //P0  = ~P0;
   
   if (beepcount > 999) P0 = 0x00;
   else P0 =0xFF;

   TR0 = 1;				// Start Timer - Enable Interrupt again before quit
} /* ISR_Timer0() */

void main()
{
  P0 = 0x00;
  InitTimer0();			// Start Timer

  for(;;beepcount++) 
  {
   beep01();
   if (beepcount > 1000) beepcount = 0;
  }
}

