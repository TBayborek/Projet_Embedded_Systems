#include "Game_Update.h"

void Game_Update(){
	irqSet(IRQ_TIMER0, &ISR_Timer0);

	scanKeys();
	keys = keysHeld();
	Handle_Button(keys);

	switch(Game_Status){
	case STOP:
		// PRINT "press START to play"
		break;
	case START:
		// PRINT explanations about game and "choose mode"
		ticks = 0; times_up = false;

		HasPlayed1=0; //in case of multi game
		HasPlayed2=0;
		/*
		int mode=0; //mode=0 for solo, =1 for multi
		if (mode==0) Game_Status = USER_TURN;
		else if(mode==1) Game_Status = MULTIPLAYER_TURN;
*/
		printMenu2();
		break;
	case USER_TURN:
		err_cnt=0;
		user_move = ERROR;
		while(user_move==ERROR){
			if(user_move != ERROR) break;
			if (err_cnt>0)mmEffect(SFX_BUZZER);
			if (err_cnt>2){Loose_Round(0); break;}

			err_cnt++;
			ticks=0;

			drawArea();
			user_move = Detect_Move();

			if(times_up){
				delay_ds(10);
				user_move = ERROR;
				times_up = false;
				err_cnt = 0;
			}
		}

		if(Game_Status == USER_TURN) Game_Status = OPPONENT_TURN;

		switch(user_move){
			case ROCK: userPlayed(ROCK); break;
			case PAPER: userPlayed(PAPER); break;
			case SCISSORS: userPlayed(SCISSORS); break;
			case ERROR: break;
		}
		break;
	case MULTIPLAYER_TURN:
		drawArea(); //modifier "bot" par player 2 en cröant drawAreaMult()
		user_move = Detect_Move();
		HasPlayed1=1;
		checkIfThe2HavePlayed();
		break;
	case OPPONENT_TURN:
		Opponent_Move();
		Game_Status = RESULTS;
		break;
	case RESULTS:
		Check_Results(user_move, opponent_move);
		break;
	case NEXT:
		delay_ds(20);
		Game_Status = USER_TURN;
		break;
	}
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

/*
	if((Game_Status == NEXT) && (keys & KEY_A)){
		Game_Status = STOP;
		Init_Graphics();
	}
*/
	if ((keys & KEY_TOUCH) && (Game_Status==START)) {
		touchRead(&touch);
		int posx = touch.px;
		int posy = touch.py;

		if((posx>27 & posx<=228) && (posy>=50 & posy<80)){
			Game_Status = USER_TURN;


		}



	}

}

void Opponent_Move(){
	int choice = rand()%3;

	int row_sel;
	switch(choice){
		case 0: opponent_move = ROCK; row_sel = 0; break;
		case 1: opponent_move = SCISSORS; row_sel = 10; break;
		case 2: opponent_move = PAPER; row_sel = 20; break;
	}

	//print the corresponding bot's choice (taken from the bottom of Background.png)
	int row, col;
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

void printMenu2(){
	swiCopy(MenuDescriptionTiles, BG_TILE_RAM(0), MenuDescriptionTilesLen/2);
	swiCopy(MenuDescriptionMap, bg0Map, MenuDescriptionMapLen/2);
	swiCopy(MenuDescriptionPal, BG_PALETTE, MenuDescriptionPalLen/2);

	swiCopy(MenuTactileTiles, BG_TILE_RAM_SUB(0), MenuTactileTilesLen/2);
	swiCopy(MenuTactileMap, bg0Map_SUB, MenuTactileMapLen/2);
	swiCopy(MenuTactilePal, BG_PALETTE_SUB, MenuTactilePalLen/2);
}

void drawArea(){
	//print bottom screen ("please draw here")
	swiCopy(ecranBaseTiles, BG_TILE_RAM_SUB(0), ecranBaseTilesLen/2);
	swiCopy(ecranBaseMap, bg0Map_SUB, ecranBaseMapLen/2);
	swiCopy(ecranBasePal, BG_PALETTE_SUB, ecranBasePalLen/2);

	//print top screen (comic style)
	//we use two times "Background" in order to have two layers. This will be
	//useful when printing computer choices
	swiCopy(BackgroundTiles, BG_TILE_RAM(0), BackgroundTilesLen/2);
	swiCopy(BackgroundMap, bg0Map, BackgroundMapLen/2);
	swiCopy(BackgroundPal, BG_PALETTE, BackgroundPalLen/2);

	swiCopy(BackgroundTiles, BG_TILE_RAM(4), BackgroundTilesLen/2);
	swiCopy(BackgroundMap, bg1Map, BackgroundMapLen/2);
	swiCopy(BackgroundPal, BG_PALETTE, BackgroundPalLen/2);

	//draw the interrogation point (taken from below the the Background.png)
	int row, col;
	for(row=0;row<9;row++){
		for(col=0;col<10;col++){
			bg0Map[(row+8)*32+(col+12)] = BackgroundMap[(row+25+30)*32+col+12];
		}
	}

	//utile pour affichage du 0-0
	printScore(scoreHuman,12,0);
	printScore(scoreBot,21,0);
}


void userPlayed(move user_play){
	switch(user_play){
		case ROCK:
			//print player's choice
			swiCopy(RockTiles, BG_TILE_RAM_SUB(0), RockTilesLen/2);
			swiCopy(RockMap, bg0Map_SUB, RockMapLen/2);
			swiCopy(RockPal, BG_PALETTE_SUB, RockPalLen/2);
			break;
		case PAPER:
			//print player's choice
			swiCopy(PaperTiles, BG_TILE_RAM_SUB(0), PaperTilesLen/2);
			swiCopy(PaperMap, bg0Map_SUB, PaperMapLen/2);
			swiCopy(PaperPal, BG_PALETTE_SUB, PaperPalLen/2);
			break;
		case SCISSORS:
			//print player's choice
			swiCopy(ScissorTiles, BG_TILE_RAM_SUB(0), ScissorTilesLen/2);
			swiCopy(ScissorMap, bg0Map_SUB, ScissorMapLen/2);
			swiCopy(ScissorPal, BG_PALETTE_SUB, ScissorPalLen/2);
			break;
		case ERROR: break;
	}
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
			row_sel = 20;
			break;
		case 2:
			opponent_move=SCISSORS;
			row_sel = 10;
			break;
		}
		HasPlayed2=1;
	}

	if(HasPlayed1==1 && HasPlayed2==1){
		//print the corresponding player 2's choice (taken from the bottom of Background.png)
		int row, col;
		for(row=0;row<9;row++){
			for(col=0;col<10;col++){
				bg0Map[(row+8)*32+(col+12)] = BackgroundMap[(row+25+row_sel)*32+col+12];
			}
		}
		Game_Status=RESULTS;
	}
}


void delay_ds(int ds){
	delay_ticks = 0;
	while(1){
		if(delay_ticks>=ds*10)break;
	}
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
		if (ticks>=400) {
			Loose_Round(1);
			times_up = true;
		}
	}
	delay_ticks++;
}
// ------- END OF ISR ------------
