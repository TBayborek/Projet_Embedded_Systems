#include "Game_Update.h"

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
		// PRINT explanations about game and "choose mode"
		gs_test = 1;
		ticks = 0;

		HasPlayed1=0; //in case of multi game
		HasPlayed2=0;

		int mode=0; //mode=0 for solo, =1 for multi

		if (mode==0)
			Game_Status = USER_TURN;
		else if(mode==1)
			Game_Status = MULTIPLAYER_TURN;



		//printMenu2();
		break;
	case USER_TURN:
		gs_test = 2;
		drawArea();
		break;
	case MULTIPLAYER_TURN:
		gs_test=2;
		drawArea(); //modifier "bot" par player 2 en cröant drawAreaMult()
		checkIfThe2HavePlayed();
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
	/*
	if((Game_Status == START) && (keys & KEY_A)){
		Game_Status = USER_TURN;
		ticks = 0;

	}
	*/

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
/*
	if(Game_Status == START){
		if ((posx>27 & posx<=228) && (posy>=50 & posy<80)){
			mode=0;
			Game_Status = USER_TURN;
		}
		/*
		if ((posx>27 && posx<=228) && (posy>=90 && posy<120)){
			mode=1;
			Game_Status = MULTIPLAYER_TURN;
		}

	}
*/


	if (Game_Status == USER_TURN){
		user_move = detect_move();
		Game_Status = OPPONENT_TURN;
		/*
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
		*/
	}

	if (Game_Status == MULTIPLAYER_TURN){
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
			HasPlayed1=1; //player 1 has played


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

	//print the corresponding bot's choice (taken from the bottom of Background.png)
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
		Win_Round();
	}

	if((user_move == ROCK && opponent_move == PAPER) ||
			(user_move == SCISSORS && opponent_move == ROCK) ||
			(user_move == PAPER && opponent_move == SCISSORS)){
		Loose_Round(0);
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
			Loose_Round(1);

		}
	}
}

// ------- END OF ISR ------------


void printMenu2(){
	swiCopy(MenuDescriptionTiles, BG_TILE_RAM(0), MenuDescriptionTilesLen/2);
	swiCopy(MenuDescriptionMap, BG_MAP_RAM(26), MenuDescriptionMapLen/2);
	swiCopy(MenuDescriptionPal, BG_PALETTE, MenuDescriptionPalLen/2);

	swiCopy(MenuTactileTiles, BG_TILE_RAM_SUB(0), MenuTactileTilesLen/2);
	swiCopy(MenuTactileMap, BG_MAP_RAM_SUB(25), MenuTactileMapLen/2);
	swiCopy(MenuTactilePal, BG_PALETTE_SUB, MenuTactilePalLen/2);

}

void drawArea(){

	//print bottom screen ("please draw here")
	swiCopy(ecranBaseTiles, BG_TILE_RAM_SUB(0), ecranBaseTilesLen/2);
	swiCopy(ecranBaseMap, BG_MAP_RAM_SUB(25), ecranBaseMapLen/2);
	swiCopy(ecranBasePal, BG_PALETTE_SUB, ecranBasePalLen/2);

	//print top screen (comic style)
	//we use two times "Background" in order to have two layers. This will be
	//useful when printing computer choices
	swiCopy(BackgroundTiles, BG_TILE_RAM(0), BackgroundTilesLen/2);
	swiCopy(BackgroundMap, BG_MAP_RAM(26), BackgroundMapLen/2);
	swiCopy(BackgroundPal, BG_PALETTE, BackgroundPalLen/2);

	swiCopy(BackgroundMap, BG_MAP_RAM(29), BackgroundMapLen/2);
	swiCopy(BackgroundTiles, BG_TILE_RAM(4), BackgroundTilesLen/2);
	swiCopy(BackgroundPal, BG_PALETTE, BackgroundPalLen/2);

	//draw the interrogation point (taken from below the the Background.png)
	int row, col;
	u16* bg0Map = (u16*)BG_MAP_RAM(26);

	for(row=0;row<9;row++){
		for(col=0;col<10;col++){
			bg0Map[(row+8)*32+(col+12)] = BackgroundMap[(row+25+30)*32+col+12];
		}
	}

	//utile pour affichage du 0-0
	printScore(scoreHuman,12,0);
	printScore(scoreBot,21,0);


}


void userPlayScissor(){
	//print player's choice
	swiCopy(ScissorTiles, BG_TILE_RAM_SUB(0), ScissorTilesLen/2);
	swiCopy(ScissorMap, BG_MAP_RAM_SUB(25), ScissorMapLen/2);
	swiCopy(ScissorPal, BG_PALETTE_SUB, ScissorPalLen/2);
}

void userPlayRock(){
	//print player's choice
	swiCopy(RockTiles, BG_TILE_RAM_SUB(0), RockTilesLen/2);
	swiCopy(RockMap, BG_MAP_RAM_SUB(25), RockMapLen/2);
	swiCopy(RockPal, BG_PALETTE_SUB, RockPalLen/2);

}

void userPlayPaper(){
	//print player's choice
	swiCopy(PaperTiles, BG_TILE_RAM_SUB(0), PaperTilesLen/2);
	swiCopy(PaperMap, BG_MAP_RAM_SUB(25), PaperMapLen/2);
	swiCopy(PaperPal, BG_PALETTE_SUB, PaperPalLen/2);

}

void checkIfThe2HavePlayed(){
	int row_sel;
	char msg[1];

	//Listen for messages from others
	if(receiveData(msg,1)>0	)
	{
		//If received, decode the key and print
		switch(msg[0])
		{
		case 0:
			opponent_move=ROCK;
			row_sel = 0;
			break;
		case 1:
			opponent_move=PAPER;
			row_sel = 10;
			break;
		case 2:
			opponent_move=SCISSORS;
			row_sel = 20;
			break;
		}
		HasPlayed2=1;

	}

	if(HasPlayed1==1 && HasPlayed2==1){

		//print the corresponding player 2's choice (taken from the bottom of Background.png)
		int row, col;
		u16* bg0Map = (u16*)BG_MAP_RAM(26);
		for(row=0;row<9;row++){
			for(col=0;col<10;col++){
				bg0Map[(row+8)*32+(col+12)] = BackgroundMap[(row+25+row_sel)*32+col+12];
			}
		}


		Game_Status=RESULTS;

	}
}

