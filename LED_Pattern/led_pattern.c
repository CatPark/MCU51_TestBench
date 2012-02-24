#include <REGX51.H>
#include "lib_io.h"
#include "lib_timing.h"

void led_blinking(void)
{
 P0=ledout(0x88);
 delayms(100);

 P0=ledout(0x33);
 delayms(100);

 P0=ledout(0x44);
 delayms(100);
}
