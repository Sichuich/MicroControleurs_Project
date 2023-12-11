#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"
#include "Driver_UART.h"
#include "cap.h"
#include "main.h"
#include "gestion.h"







int main(void) {
	
    UsartInit();
	    
	  	
	  MoteurInit();
	  MoteurStart();
		initialisation();
    
    while (1) { 
   	  data();   
			controle_voile();
    }
}
