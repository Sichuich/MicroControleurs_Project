#ifndef CAP_H
#define CAP_H

#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"

void UsartInit(void);

void MoteurInit(void);

void MoteurSet(int i);

void MoteurStart(void);

void data(void);

#endif
