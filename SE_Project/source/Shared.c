#include "Shared.h"

status Game_Status = STOP;
int scoreHuman=0;
int scoreBot=0;
int HasPlayed1=0;
int HasPlayed2=0;


void Test(int color){
	int i;
	for (i=0;i<100;i++) BG_PALETTE_SUB[i] = RGB15(color,0,0);
}
