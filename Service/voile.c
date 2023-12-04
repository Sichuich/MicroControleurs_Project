#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"
#include "voile.h"
#include "main.h"

void Voile_Init(){
	MyTimer_Base_Init(Voile_timer,1439,999);
	MyTimer_PWM(Voile_timer,Voile_channel);
	MyTimer_SetDutyCycle(Voile_timer,Voile_channel,75);     //100 = Voile rabattue, 50 = Voile ouverte
	MyTimer_Base_Start(Voile_timer);
}


void Voile_Set(int angle){
	
	int pwm;
	
	if (angle<=180) {
		pwm = 100 - ((50*angle)/180);
	}else if (angle <=360){
		pwm = (50*angle)/180;
	}
	
	
	MyTimer_SetDutyCycle(Voile_timer,Voile_channel,pwm);
	
}
/*

int main(void){
	Voile_Init();
	MyTimer_SetDutyCycle(TIM2,2,100);
	do{
	}while(1);
		
}*/
