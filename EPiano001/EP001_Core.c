#include <STC89.H>

unsigned checkKey()
{
 unsigned a;
 unsigned b;

 P1 = 0xF0;
 P2 = 0x3C;

 a = ~P1;
 b = ~P3;

 a = a & 0xF0;
 b = b & 0x3C;

 if (b == 0x04) return (0);
 else if (b == 0x08) return (1);
 else if (b == 0x10) return (2);
 else if (b == 0x20) return (3);
 else if (a == 0x10) return (4);
 else if (a == 0x20) return (5);
 else if (a == 0x40) return (6);
 else if (a == 0x80) return (7);
 else return (33);
}

sbit BP = P3^6;

void main(void)
{
 unsigned int delay[]={10, 20, 30, 40, 50, 60, 70, 80};
 unsigned int d;
 unsigned char key;

 for (;;)
 {
  while ((key = checkKey()) > 7);

  for (d=0; d<delay[key]; d++);
  BP = ~BP;
  for (d=0; d<delay[key]; d++);
  BP = ~BP;
 }
}
