
#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"
#include "main.h"

void girouette_init(){
	MyGPIO_Init(gir_I_GPIO,gir_I_Pin,In_PullDown);
	MyGPIO_Init(gir_A_GPIO,gir_A_Pin,In_PullDown);
	MyGPIO_Init(gir_B_GPIO,gir_B_Pin,In_PullDown);
	MyTimer_Base_Init(girouette_timer, 1439, 0);
	MyTimer_Encoder(girouette_timer);
	MyTimer_Base_Start(girouette_timer);	
}


int girouette_read(){
	return MyTimer_Read_CNT(girouette_timer)/4;
}

int girouette_zero(){ //Lit la valeur de I, si c'est 1 alors la girouette est à zéro
	return MyGPIO_Read(gir_I_GPIO,gir_I_Pin);
}

void girouette_reset() {
	MyTimer_Reset_CNT(girouette_timer);
}
