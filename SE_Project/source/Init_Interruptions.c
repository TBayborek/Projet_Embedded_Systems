#include "Init_Interruptions.h"

void Init_Interruptions(){
	Init_Timer();	// Init Timer
	Init_Keys();	// Init Button
}

void Init_Timer(){
	TIMER0_CR = TIMER_ENABLE | TIMER_DIV_64 | TIMER_IRQ_REQ;
	TIMER0_DATA = TIMER_FREQ_64(100); // Set the interruption with 100Hz

	irqEnable(IRQ_TIMER0);
}

void Init_Keys(){
	//REG_KEYCNT = (1<<14) | KEY_START | KEY_A;
	//irqEnable(IRQ_KEYS);
}
