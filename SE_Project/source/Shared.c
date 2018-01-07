#include "Shared.h"

status Game_Status = STOP;

int scoreHuman=0;
int scoreBot=0;

int HasPlayed1=0;
int HasPlayed2=0;

int mode;

u16* bg0Map;
u16* bg1Map;
u16* bg0Map_SUB;
u16* bg3Map_SUB;

bool times_up;

int delay_ticks;
void delay_ds(int ds){
	delay_ticks = 0;
	while(1){
		if(delay_ticks>=ds*10)break;
		swiWaitForVBlank();
	}
}

int mode=0;
