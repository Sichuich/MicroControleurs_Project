#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"
#include "Driver_UART.h"
#include "cap.h"
#include "main.h"
#include "gestion.h"



char received_data;

void Receive(void){
	received_data = Uart_Get(USART1);
	Send(USART1, received_data);
}




int main(void) {
	
    RouteurInit1();
	  Receive_Interruption(USART1,8,Receive);  
	  	
	  RouteurInit2();
	  RouteurStart();
		initialisation();
    
    while (1) { 
   	  RouteurSet(received_data);   
			controle_voile();
    }
}
