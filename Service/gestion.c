#include "stm32f10x.h"
#include "voile.h"
#include "girouette.h"


int angle_girouette;
void initialisation(){
	Voile_Init();
	girouette_init();
	while (girouette_zero()==0) {
		
	}
	girouette_reset();
	
}

void controle_voile(){
	angle_girouette = girouette_read();
	Voile_Set(angle_girouette);
}
