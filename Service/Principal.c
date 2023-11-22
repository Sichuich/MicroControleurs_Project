#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"
#include "Driver_UART.h"


void Callback(void) {
	MyGPIO_Toggle(GPIOA,6);
}

int main(void) {
	
	char data = '1';
	int cmpt = 0;
	
	MyGPIO_Init(GPIOA,6,Out_Ppull);
	MyGPIO_Init(GPIOA,2,Out_Ppull);
	MyGPIO_Init(GPIOA,3,Out_Ppull);
	

	
	MyTimer_Base_Init(TIM4,36000-1,1000-1);
	MyTimer_ActiveIT(TIM4,3, Callback);
	MyTimer_PWM(TIM4,1);
	MyTimer_SetDutyCycle(TIM4,1,25);
	MyTimer_Base_Start(TIM4);
	Uart_init(USART2,9600);
	
	
	while (cmpt < 10 )	{
	    Send(USART2,data+cmpt);
	    cmpt ++;
	}
		
	
	
	do{		
	}while(1);
}
