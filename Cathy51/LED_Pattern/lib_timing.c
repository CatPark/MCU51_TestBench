/*
	This is a library all about timing control
*/

void delay(int t)
{
 int n;

 for (n=0; n<t; n++); 
}

// Delay unit: ms (mini-sec)
void delayms(int t)
{
 int n;

 for (n=0; n<t; n++) delay(90);
}


// Delay unit: sec
void delaysec(int t)
{
 int n;

 for (n=0; n<t; n++) delayms(1000);
}
