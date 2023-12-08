#ifndef GIROUETTE_H
#define GIROUETTE_H

#include "stm32f10x.h"

void girouette_init();
int girouette_read();
int girouette_zero();
void girouette_reset();
	
#endif