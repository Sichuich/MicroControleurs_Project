#include "stm32f10x.h"
#include "Driver_GPIO.h"
int main(void) 
{
	
	RouteurInit();
	RouteurSet(50);
	RouteurStart();
	while(1);

}
