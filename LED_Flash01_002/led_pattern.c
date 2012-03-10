#include <REGX52.H>

#include "lib_timing.h"

void led()
{		
		P0=0xfe;
		delay();
		P0=0xfd;
		delay();
		P0=0xfb;
		delay();
		P0=0xf7;
		delay();

		P0=0xef;
		delay();
		P0=0xdf;
		delay();
		P0=0xbf;
		delay();
		P0=0x7f;
		delay();
		P0=0xff;
		delay();

		P1=0x7f;
		delay();
		P1=0xbf;
		delay();
		P1=0xdf;
		delay();
		P1=0xef;
		delay();

		P1=0xf7;
		delay();
		P1=0xfb;
		delay();
		P1=0xfd;
		delay();
		P1=0xfe;
		delay();
		P1=0xff;
		delay();
}
