#ifndef CAP_H
#define CAP_H

#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"

void RouteurInit(void);

void RouteurSet(int i);

void RouteurStart(void);

#endif
