#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "MyTimer.h"

void (*USART1_Handler)(void);
void (*USART2_Handler)(void);
void (*USART3_Handler)(void);


void Uart_init(USART_TypeDef * Uart, unsigned int baudrate){
	int fPCLK;
	if (Uart == USART1){
		RCC -> APB2ENR |= RCC_APB2ENR_USART1EN;
	} else if (Uart == USART2){
		RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;
	} else if (Uart == USART3){
		RCC -> APB1ENR |= RCC_APB1ENR_USART3EN;
	} /*else if (Uart == UART4) {
    RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
  } else if (Uart == UART5) {
    RCC->APB1ENR |= RCC_APB1ENR_UART5EN;
  }*/
	
	Uart -> CR1 |= USART_CR1_UE;
	Uart -> CR1 &= ~USART_CR1_M;
	Uart -> CR2 &= ~USART_CR2_STOP;
	//DMA 
	//Uart-> CR3 |= USART_CR3_DMAT;
	//bandrate Tx/Rx band = fCK/(16*USARTDIV)
	//Uart -> BRR 
		
	if (Uart == USART1){
		fPCLK = 72000000;
	} else {
	  fPCLK = 36000000;
	}

	Uart->BRR = fPCLK / ( baudrate);
	Uart-> CR1 |= (USART_CR1_RE | USART_CR1_TE);	
}

void Send(USART_TypeDef * Uart, char data){
	while((Uart->SR & USART_SR_TXE)==0);
	Uart->DR = data;
	
}

void Receive_Interruption(USART_TypeDef * usart, char priority,  void (*function) (void)){
	  if (usart == USART1) {
        NVIC_EnableIRQ(USART1_IRQn);
        NVIC_SetPriority(USART1_IRQn, priority);
        USART1_Handler = function;
    } else if (usart == USART2) {
        NVIC_EnableIRQ(USART2_IRQn);
        NVIC_SetPriority(USART2_IRQn, priority);
        USART2_Handler = function;
    } else if (usart == USART3) {
        NVIC_EnableIRQ(USART3_IRQn);
        NVIC_SetPriority(USART3_IRQn, priority);
        USART3_Handler = function;
    }
    usart->CR1 |= (USART_CR1_RXNEIE | USART_CR1_PEIE);
}

char Uart_Get(USART_TypeDef * usart){
	return usart -> DR;
}


void USART1_IRQHandler(void) {
    
  	USART1->SR &= ~USART_SR_RXNE;
    (*USART1_Handler)();	
}

void USART2_IRQHandler(void) {
    
    USART2->SR &= ~USART_SR_RXNE;
	  (*USART2_Handler)();
}

void USART3_IRQHandler(void) {
    
    USART3->SR &= ~USART_SR_RXNE;
	  (*USART3_Handler)();
}
