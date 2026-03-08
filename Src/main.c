#include "hal/reg.h"
#include "hal/common.h"
#include <stdio.h>



void setup  (void);
void loop   (void);

int main(void)
{
	setup();
	loop();
	
	return 0;
}


void setup(void)
{
	printf("Hello World!\n");
}


void loop(void)
{
	while (1)
	{
		
	}
}
