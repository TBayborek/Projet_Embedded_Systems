#include "Handle_Outcome.h"
#define TILE_PAL(n) ((n) << 12)

void Win_Round(){

	//sound
	mmEffect(SFX_WINSOUND);

	//print "you win"
	int row, col;
	u16* bg1Map = (u16*)BG_MAP_RAM_SUB(25);
	int rowEnd=(WINMapLen/2)/32; //nb of rows in the WIN picture



	for(row=0;row<6;row++){
		for(col=0;col<32;col++){
			bg1Map[(row+25-rowEnd)*32+col] = bg1Map[(row+24)*32+col];


		}
	}






	Game_Status = NEXT;
}

void Loose_Round(int raison){

	//sound
	mmEffect(SFX_BUZZER);

	//if "raison" is equal to 0, then the player lost the round
	if(raison==0){

		//print "you lose" panel
		int row, col;
		u16* bg1Map = (u16*)BG_MAP_RAM_SUB(25);
		int rowEnd=(WINMapLen/2)/32; //nb of rows in the WIN picture


		for(row=0;row<6;row++){
			for(col=0;col<32;col++){
				bg1Map[(row+25-rowEnd)*32+col] = bg1Map[(row+30)*32+col];


			}
		}
	}

	//if raison = 1, then the player didn t play in time
	else if (raison==1) {
		printTimesUp();

	}



	Game_Status = NEXT;
}

void Draw_Round(){


	//sound
	mmEffect(SFX_BOING_X);


	//printing of "it's a draw" panel
	int row, col;
	u16* bg1Map = (u16*)BG_MAP_RAM_SUB(25);
	int rowEnd=(WINMapLen/2)/32; //nb of rows in the WIN picture

	for(row=0;row<6;row++){
		for(col=0;col<32;col++){
			bg1Map[(row+25-rowEnd)*32+col] = bg1Map[(row+36)*32+col];


		}
	}

	Game_Status = NEXT;
}


void printTimesUp(){

	int row, col;
	u16* bg1Map = (u16*)BG_MAP_RAM_SUB(25);
	int rowEnd=(256-192)/8; //nb of rows of tile in the WIN picture


	for(row=0;row<8;row++){
		for(col=0;col<32;col++){
			bg1Map[(row+24-rowEnd)*32+col] = bg1Map[(row+24)*32+col];


		}
	}


}
