#include <REGX52.H>

void switch03_init(void);
void switch03_loop(void);

void main()
{
   switch03_init();
	for(;;)
	{
  	 switch03_loop();
	}
}