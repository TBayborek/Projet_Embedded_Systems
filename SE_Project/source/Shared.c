// File that contains all the global variable or global functions which are needed in most of the files.
#include "Shared.h"

status Game_Status = STOP;

move user_move;
move opponent_move;

int scoreHuman=0;
int scoreBot=0;
int numPlay=0;
int lastRoundsPlay[5]={0,0,0,0,0};
int lastRoundScore=0;

int HasPlayed1=0;
int HasPlayed2=0;

mode game_mode;

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
