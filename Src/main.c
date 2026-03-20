#include "../hal/core/core.h"



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
	HAL_Init();

	printf("Hello World!\n");
}


void loop(void)
{
	while (1)
	{
		
	}
}
