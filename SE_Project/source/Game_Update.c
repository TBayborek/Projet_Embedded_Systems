#include "Game_Update.h"
#define TILE_PAL(n) ((n) << 12)

void Game_Update(){
	irqSet(IRQ_TIMER0, &ISR_Timer0);

	Handle_Input();

	int gs_test;

	switch(Game_Status){
	case STOP:
		// PRINT "press START to play"
		gs_test = 0;
		break;
	case START:
		// PRINT explanations about game and "press A when ready"
		gs_test = 1;
		ticks = 0;
		Game_Status = USER_TURN; //skip definitivement?
		//printMenu2();
		break;
	case USER_TURN:
		gs_test = 2;
		drawArea();
		break;
	case OPPONENT_TURN:

		Opponent_Move();
		Game_Status = RESULTS;
		gs_test = 3;
		break;
	case RESULTS:
			Check_Results(user_move, opponent_move);
			gs_test = 4;
			break;
	case NEXT:
		// Press A to continue
		gs_test = 5;
		break;
	}

	printf("%u\n",gs_test);
	printf("%u\n",ticks);
}


void Handle_Input(){
	//irqSet(IRQ_KEYS, &ISR_Keys);

	scanKeys();
	keys = keysHeld();

	printf("%u ",KEY_TOUCH);
	printf("%u \n",keys);

	Handle_Button(keys);
	if(keys & KEY_TOUCH) Handle_Touchscreen();
}

void Handle_Button(unsigned keys){
	if((Game_Status == STOP) && (keys & KEY_START)){
		Game_Status = START;
	}

	if((Game_Status == START) && (keys & KEY_A)){
		Game_Status = USER_TURN;
		ticks = 0;
	}

	if((Game_Status == NEXT) && (keys & KEY_A)){
		Game_Status = STOP;
		Init_Graphics();

		//consoleDemoInit(); // TO DELETE, JUST FOR TESTING
	}
}

void Handle_Touchscreen(){

	touchRead(&touch);

	posx = touch.px;
	posy = touch.py;

	if (Game_Status == USER_TURN){
		if ((posx>125 && posx<256) && (posy>=0 && posy<192)){
			if(posy>=0 && posy<64) {

				userPlayRock();


				user_move = ROCK;
			}
			if(posy>=64 && posy<128){
				userPlayScissor();

				user_move = SCISSORS;
			}
			if(posy>=128 && posy<192){
				userPlayPaper();

				user_move = PAPER;
			}
			Game_Status = OPPONENT_TURN;
		}
	}
}


void Opponent_Move(){
	choice = rand()%3;

	int row_sel;
	switch(choice){
		case 0: opponent_move = ROCK; row_sel = 0; break;
		case 1: opponent_move = SCISSORS; row_sel = 10; break;
		case 2: opponent_move = PAPER; row_sel = 20; break;
	}

	int row, col;
	u16* bg0Map = (u16*)BG_MAP_RAM(26);




	for(row=0;row<9;row++){
		for(col=0;col<10;col++){
			bg0Map[(row+8)*32+(col+12)] = BackgroundMap[(row+25+row_sel)*32+col+12];
		}
	}



}

void Check_Results(move user_move, move opponent_move){
	if((user_move == ROCK && opponent_move == SCISSORS) ||
			(user_move == SCISSORS && opponent_move == PAPER) ||
			(user_move == PAPER && opponent_move == ROCK)){
		Win_Round(); //ä modifier!!!
	}

	if((user_move == ROCK && opponent_move == PAPER) ||
			(user_move == SCISSORS && opponent_move == ROCK) ||
			(user_move == PAPER && opponent_move == SCISSORS)){
		Loose_Round(0); //ä modifier!!!
	}

	if(user_move == opponent_move) Draw_Round();

}


// ---------- ISR ----------------
/*
void ISR_Keys(){
	uint32 keys = ~(REG_KEYINPUT);
	if((Game_Status == STOP) && (keys & KEY_START)){
		Game_Status = START;
	}

	if((Game_Status == START) && (keys & KEY_A)){
		Game_Status = USER_TURN;
		ticks = 0;
	}

	if((Game_Status == NEXT) && (keys & KEY_A)){
		Game_Status = STOP;
		Init_Graphics();
	}

}
*/


void ISR_Timer0(void){
	if(Game_Status == USER_TURN){
		ticks++;
		if (ticks>=300) {
			printTimesUp();
			Loose_Round(1);

		}
	}
}

// ------- END OF ISR ------------


void printMenu2(){
	swiCopy(MenuInstructionTiles, BG_TILE_RAM_SUB(0), MenuInstructionTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
	swiCopy(MenuInstructionMap, BG_MAP_RAM_SUB(26), MenuInstructionMapLen/2); // store in the 26th slot => #25
	swiCopy(MenuInstructionPal, BG_PALETTE_SUB, MenuInstructionPalLen/2);

}

void drawArea(){
	swiCopy(ecranBaseTiles, BG_TILE_RAM_SUB(0), ecranBaseTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
	swiCopy(ecranBaseMap, BG_MAP_RAM_SUB(25), ecranBaseMapLen/2); // store in the 26th slot => #25
	swiCopy(ecranBasePal, BG_PALETTE_SUB, ecranBasePalLen/2);


	//we use two times "Background" in order to have two layers. This will be useful when printing computer choices
	swiCopy(BackgroundTiles, BG_TILE_RAM(0), BackgroundTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
	swiCopy(BackgroundMap, BG_MAP_RAM(26), BackgroundMapLen/2); // store in the 26th slot => #25
	swiCopy(BackgroundPal, BG_PALETTE, BackgroundPalLen/2);
	swiCopy(BackgroundMap, BG_MAP_RAM(29), BackgroundMapLen/2);
	swiCopy(BackgroundTiles, BG_TILE_RAM(4), BackgroundTilesLen/2);
	swiCopy(BackgroundPal, BG_PALETTE, BackgroundPalLen/2);

	//draw the interrogation point
	int row, col;
	u16* bg0Map = (u16*)BG_MAP_RAM(26);

	for(row=0;row<9;row++){
		for(col=0;col<10;col++){
			bg0Map[(row+8)*32+(col+12)] = BackgroundMap[(row+25+30)*32+col+12];
		}
	}


}


void userPlayScissor(){
	swiCopy(ScissorTiles, BG_TILE_RAM_SUB(0), ScissorTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
	swiCopy(ScissorMap, BG_MAP_RAM_SUB(25), ScissorMapLen/2); // store in the 26th slot => #25
	swiCopy(ScissorPal, BG_PALETTE_SUB, ScissorPalLen/2);
}

void userPlayRock(){
	swiCopy(RockTiles, BG_TILE_RAM_SUB(0), RockTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
	swiCopy(RockMap, BG_MAP_RAM_SUB(25), RockMapLen/2); // store in the 26th slot => #25
	swiCopy(RockPal, BG_PALETTE_SUB, RockPalLen/2);

}

void userPlayPaper(){
	swiCopy(PaperTiles, BG_TILE_RAM_SUB(0), PaperTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
	swiCopy(PaperMap, BG_MAP_RAM_SUB(25), PaperMapLen/2); // store in the 26th slot => #25
	swiCopy(PaperPal, BG_PALETTE_SUB, PaperPalLen/2);

}


void printTimesUp(){
	int row, col;
	u16* bg1Map = (u16*)BG_MAP_RAM_SUB(25);
	int rowEnd=(256-192)/8; //nb of rows of tile in the WIN picture

	/*
	int c;
	for (c=0;c<256;c++){
		BG_PALETTE_SUB[c] = RED;
	}
	*/
	for(row=0;row<8;row++){
		for(col=0;col<32;col++){
			bg1Map[(row+24-rowEnd)*32+col] = bg1Map[(row+24)*32+col];


		}
	}


}
