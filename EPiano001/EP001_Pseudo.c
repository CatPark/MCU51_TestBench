#include <STC89.H>

unsigned char checkKey()
{
 if (keyon)
 {
  return (key on #);
 } 
 else return 99;
}

void main()
{
 int freq[]=1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000;

 unsigned char n;

 for (;;)
 {
  while ( (n = checkKey()) > 7);

  for (d=0; d < freq[n]; d++);
  SPEAKER = ~SPEAKER;
  for (d=0; d < freq[n]; d++);
  SPEAKER = ~SPEAKER;
 }
}
