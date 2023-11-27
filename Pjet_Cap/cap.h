#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"

void RouteurInit(void);

void RouteurSet(int8_t i);

void RouteurStart(void);

void Receive(void);

uint8_t get_data(void);
