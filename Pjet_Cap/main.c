#include "stm32f10x.h"
#include "cap.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"
#include "Driver_UART.h"


int main(void) 
{
	
	RouteurInit();
	RouteurSet(50);
	RouteurStart();
	while(1);
}
