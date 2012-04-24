#include <STC89.H>

#define	SPEAKER = P3.6








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
