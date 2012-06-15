#include <STC89.H>

void switch01_init(void);
void switch01_loop(void);

void switch02_init(void);
void switch02_loop(void);

void main()
{
 switch02_init();

 for (;;)
 {
  switch02_loop();
 }
}