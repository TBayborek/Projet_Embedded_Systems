#include "Handle_Outcome.h"

void Win_Round(){
	handleScore(1);
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
		handleScore(0);

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


void printScore(int number, int posx, int posy){


	int row, col;
	u16* bg0Map = (u16*)BG_MAP_RAM(26);

	//if(number>9){
		int deci=number/10;
		int offDeci = deci*3;
		number=number-(10*deci);

		for(row=0;row<3;row++){
			for(col=0;col<2;col++){
				bg0Map[(row+posy)*32+(col+posx-2)] = BackgroundMap[(row+25+offDeci)*32+col];
			}
		}

	//}

	int offNumber=number*3;


	for(row=0;row<3;row++){
		for(col=0;col<2;col++){
			bg0Map[(row+posy)*32+(col+posx)] = BackgroundMap[(row+25+offNumber)*32+col];
		}
	}

}

void handleScore(int winner){


	if(winner==1){
		scoreHuman=scoreHuman+1;


		printScore(scoreHuman,12,0);
		printScore(scoreBot,21,0);
	}
	else if(winner==0){
		scoreBot=scoreBot+1;


		printScore(scoreHuman,12,0);
		printScore(scoreBot,21,0);
	}

}
