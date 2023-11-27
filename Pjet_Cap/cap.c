#include "stm32f10x.h"
#include "cap.h"
#include "Driver_UART.h"

uint8_t data;

void Receive(void){
	data = Uart_Get(USART1);
}

void RouteurInit(void){
		MyGPIO_Init(GPIOA,2,AltOut_Ppull);
	  MyGPIO_Init(GPIOA,3,In_Floating);
	  
	  MyGPIO_Init(GPIOA, 5, Out_Ppull);
    MyTimer_PWM(TIM3, 1);
    MyTimer_Base_Init(TIM3, 1000, 1);	
	
	  Uart_init(USART2,9600);
	  Receive_Interruption(USART2,1,Receive);	
}



void RouteurSet(int8_t i){		
	if (i < 0) {
     MyGPIO_Set(GPIOA, 6);
		 i = -i ; 
	} else {
     MyGPIO_Reset(GPIOA, 6);
  }					
    MyTimer_SetDutyCycle(TIM3, 1, i);
}
void RouteurStart(void){
	 MyTimer_Base_Start(TIM3);
}

uint8_t get_data(void){
	return data  ;
}
