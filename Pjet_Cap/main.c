#include "stm32f10x.h"
//#include "cap.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"
#include "Driver_UART.h"
#include "cap.h"


char received_data;

void Receive(void){
	received_data = Uart_Get(USART1);
	Send(USART1, received_data);
}


void USART_Init_Test(void) {

    Uart_init(USART1, 9600);
  

    MyGPIO_Init(GPIOA, 9, AltOut_Ppull); // Tx
    MyGPIO_Init(GPIOA, 10, In_Floating); // Rx
	  
	  
}


void USART_Test_Send(void) {
    Send(USART1, '0'); 
    Send(USART1, '1'); 	
	  Send(USART1, '2');
}




int main(void) {
	
    USART_Init_Test();
	  USART_Test_Send();
	Receive_Interruption(USART1,8,Receive);  
	  

	
	
	  RouteurInit();
	  RouteurStart();
    
    while (1) { 
   	  RouteurSet(50);   
    }
}

