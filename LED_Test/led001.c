#include <REGX51.H>

main()
{
 unsigned char p, q;

 q=5;
 p=10;

 for (;;)
 {
  P1=p++; 	// Try this out...
  p+=q;

  q++;		// add one more line...
  
  p+=q;
  P1=p++;
 }
}
