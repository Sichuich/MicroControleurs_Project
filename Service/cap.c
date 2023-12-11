#include "stm32f10x.h"
#include "cap.h"
#include "Driver_UART.h"

int received_data;

void Receive(void){
	received_data = Uart_Get(USART1);
	Send(USART1, received_data);
}


void UsartInit(void){
	Uart_init(USART1,9600);
		MyGPIO_Init(GPIOA,9,AltOut_Ppull);//tx
	MyGPIO_Init(GPIOA,10,In_Floating);//rx
	  
	  //MyGPIO_Init(GPIOA, 5, Out_Ppull);// 
	
	 
	 Receive_Interruption(USART1,8,Receive);	
}

void MoteurInit(void){		
	  
	  MyGPIO_Init(GPIOA, 5, Out_Ppull);//
	   MyTimer_Base_Init(TIM3, 3599, 1);	
    MyTimer_PWM(TIM3, 1);
 
	
	
	 //Receive_Interruption(USART2,1,Receive);	
}



void MoteurSet(int i){		
	if (i < 128) {
     MyGPIO_Reset(GPIOA, 5);
		 //i = -i ; 
	} else {
     MyGPIO_Set(GPIOA, 5);
			i ^= 255;
  }					
    MyTimer_SetDutyCycle(TIM3, 1, i*10);
}
void MoteurStart(void){
	 MyTimer_Base_Start(TIM3);
}

void data(void){
	MoteurSet(received_data);
}

