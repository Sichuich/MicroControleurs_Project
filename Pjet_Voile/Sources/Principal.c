#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "main.h"
#include "gestion.h"



	/* reglage voile*/
/*#include "MyTimer.h"
#include "voile.h"

int valpwm;*/
int main(void) 
{
	
	/* reglage voile
	Voile_Init();
	while(1)
	{
	MyTimer_SetDutyCycle(Voile_timer,Voile_channel,valpwm);
	}
	*/
	
	
	
	initialisation();
	do
	{
		controle_voile();
		
	}while(1);

}
