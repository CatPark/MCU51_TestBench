#include <REGX52.H>

sbit BEEP=P3^6;
sbit L00=P0^0;

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
    TH0 = 0x00; 		// Delay time counter delay about 65536us=66ms
    TL0 = 0x01;
    EA = 1;
    ET0 = 1;
    TR0 = 1;	  		// Start Timer
}

void ISR_Timer0(void) interrupt 1 using 2	// Timer Interrupt Service Routine
{
   P0 = ~P0;
   InitTimer0();	   // Reste Timer
}

void main()
{
  P0 = 0x00;
  InitTimer0();			// Start Timer

  for(;;) beep01();
}
