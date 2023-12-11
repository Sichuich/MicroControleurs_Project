#ifndef MYUART_H
#define MYUART_H

#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "MyTimer.h"

void Uart_init(USART_TypeDef * Uart,unsigned int baudrate);

void Send(USART_TypeDef * Uart, char data);

void Receive_Interruption(USART_TypeDef * usart, char priority,  void (*function) (void));

int Uart_Get(USART_TypeDef * usart);

#endif
