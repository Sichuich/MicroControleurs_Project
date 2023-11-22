#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"

void Voile_Init(){
	MyTimer_Base_Init(TIM2,1439,999);
	MyTimer_PWM(TIM2,2);
	MyTimer_SetDutyCycle(TIM2,2,75);     //100 = Voile rabattue, 50 = Voile ouverte
	MyTimer_Base_Start(TIM2);
}



int main(void){
	Voile_Init();
	MyTimer_SetDutyCycle(TIM2,2,100);
	do{
	}while(1);
		
}
