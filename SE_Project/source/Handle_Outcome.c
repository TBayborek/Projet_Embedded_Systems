#include "Handle_Outcome.h"

void Win_Round(){
	handleScore(1);
	mmEffect(SFX_WINSOUND); //sound

	//print "you win"
	int row, col;
	int rowEnd=6;
	for(row=0;row<6;row++){
		for(col=0;col<32;col++){
			bg0Map_SUB[(row+25-rowEnd)*32+col] = bg0Map_SUB[(row+24)*32+col];
		}
	}
	Game_Status = NEXT;
}

void Loose_Round(int raison){
	mmEffect(SFX_LOSINGHORN); //sound

	if(raison==0){ //if "raison" is equal to 0, then the player lost the round
		handleScore(0);

		//print "you lose" panel
		int row, col;
		int rowEnd=(WINMapLen/2)/32; //nb of rows in the WIN picture

		for(row=0;row<6;row++){
			for(col=0;col<32;col++){
				bg0Map_SUB[(row+25-rowEnd)*32+col] = bg0Map_SUB[(row+30)*32+col];
			}
		}
	}
	else if (raison==1) { //if raison = 1, then the player made 3 drawing mistakes
		printBadDraw();
		handleScore(0);
		user_move = LOSE;
	}
	Game_Status = NEXT;
}

void Draw_Round(){
	mmEffect(SFX_BOING_X); //sound

	//printing of "it's a draw" panel
	int row, col;
	int rowEnd=(WINMapLen/2)/32; //nb of rows in the WIN picture

	for(row=0;row<6;row++){
		for(col=0;col<32;col++){
			bg0Map_SUB[(row+25-rowEnd)*32+col] = bg0Map_SUB[(row+36)*32+col];
		}
	}
	Game_Status = NEXT;
}

void printScore(int number, int posx, int posy){
	int row, col;

	int digit_unit = number%10;
	int digit_deca = ((number-digit_unit)%100)/10;

	int offUnit = digit_unit*3;
	int offDeca = digit_deca*3;

	// Print the decade digit
	for(row=0;row<3;row++){
		for(col=0;col<2;col++){
			bg0Map[(row+posy)*32+(col+posx-2)] = bg0Map[(row+25+offDeca)*32+col];
		}
	}

	// Print the unit digit
	for(row=0;row<3;row++){
		for(col=0;col<2;col++){
			bg0Map[(row+posy)*32+(col+posx)] = bg0Map[(row+25+offUnit)*32+col];
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

void printBadDraw(){
	int row, col;
	int rowEnd=(256-192)/8; //nb of rows of tile in the WIN picture

	for(row=0;row<8;row++){
		for(col=0;col<32;col++){
			bg0Map_SUB[(row+24-rowEnd)*32+col] = bg0Map_SUB[(row+32)*32+col];
		}
	}
}