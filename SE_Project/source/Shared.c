#include "Shared.h"

status Game_Status = STOP;

void Test(int color){
	int i;
	for (i=0;i<100;i++) BG_PALETTE_SUB[i] = RGB15(color,0,0);
}
