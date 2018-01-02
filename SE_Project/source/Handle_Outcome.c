#include "Handle_Outcome.h"

void Win_Round(){
	/*
	int c;
	for (c=0;c<256;c++){
		BG_PALETTE_SUB[c] = GREEN;
	}
	*/
	Game_Status = NEXT;
}

void Loose_Round(){

	/*
	int c;
	for (c=0;c<256;c++){
		BG_PALETTE_SUB[c] = RED;
	}
	*/
	Game_Status = NEXT;
}

void Draw_Round(){
	/*
	int c;
	for (c=0;c<256;c++){
		BG_PALETTE_SUB[c] = ORANGE;
	}
	*/
	Game_Status = NEXT;
}

