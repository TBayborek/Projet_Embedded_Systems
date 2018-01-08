#include "Handle_Outcome.h"

// User won
void Win_Round(){
	handleScore(1); // Increment his score
	mmEffect(SFX_WINSOUND); //sound

	//print "you win"
	int row, col;
	int rowEnd=6;
	for(row=0;row<5;row++){
		for(col=0;col<32;col++){
			bg0Map_SUB[(row+25-rowEnd)*32+col] = bg0Map_SUB[(row+24)*32+col];
		}
	}
	Game_Status = NEXT;
}

// User lost, reason is an integer indicating why the user lost.
void Lose_Round(int reason){
	mmEffect(SFX_LOSINGHORN); //sound

	if(reason==0){ //if "reason" = 0, then the player lost the round
		handleScore(0); // Increase score of opponent

		//print "you lose" panel
		int row, col;
		int rowEnd=6; //nb of rows in the WIN picture

		for(row=0;row<6;row++){
			for(col=0;col<32;col++){
				bg0Map_SUB[(row+26-rowEnd)*32+col] = bg0Map_SUB[(row+30)*32+col];
			}
		}
	}
	else if (reason==1) { //if reason = 1, then the player made too many drawing mistakes
		printBadDraw();
		handleScore(0); // Increment opponent score
		user_move = LOSE;
	}
	Game_Status = NEXT;
}

// It's a draw, nobody won
void Draw_Round(){
	mmEffect(SFX_BOING_X); //sound

	//printing of "it's a draw" panel
	int row, col;
	int rowEnd=6; //nb of rows in the WIN picture

	for(row=0;row<6;row++){
		for(col=0;col<32;col++){
			bg0Map_SUB[(row+26-rowEnd)*32+col] = bg0Map_SUB[(row+35)*32+col];
		}
	}
	Game_Status = NEXT;
}

// function that prints the score given as input on the main screen, at a specifically given location
void printScore(int number, int posx, int posy){
	int row, col;

	// Extract digit from number
	int digit_unit = number%10; // the digit of the units
	int digit_deca = ((number-digit_unit)%100)/10; // the digit of the decade

	// Required offset to print correctly
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

// Increments the score and calls function to print the score
void handleScore(int winner){
	if(winner==1) scoreHuman++;
	else if(winner==0) scoreBot++;

	printScore(scoreHuman,12,0);
	printScore(scoreBot,21,0);
}

// Print image to indicate the user made too many bad draws
void printBadDraw(){
	int row, col;
	int rowEnd=(256-192)/8; //nb of rows of tile in the WIN picture

	for(row=0;row<8;row++){
		for(col=0;col<32;col++){
			bg0Map_SUB[(row+24-rowEnd)*32+col] = bg0Map_SUB[(row+32)*32+col];
		}
	}
}
