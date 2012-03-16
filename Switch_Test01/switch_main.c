#include <STC89.H>

void switch01_init(void);
void switch01_loop(void);

void main()
{
 switch01_init();

 for (;;)
 {
  switch01_loop();
 }
}