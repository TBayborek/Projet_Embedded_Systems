#include "Game_Update.h"

void Game_Update(){
	irqSet(IRQ_TIMER0, &ISR_Timer0);

	Handle_Button();

	if (n_rock_streak>=4) Full_Rock();

	switch(Game_Status){
	case STOP:
		Init_Graphics();
		scanKeys();
		key_released = true;
		// PRINT explanations about game and "choose mode"
		break;
	case START:
		// PRINT "press START to play"
		ticks = err_cnt = n_rock_streak = 0; times_up = pause =false;
		scoreHuman = scoreBot = 0;

		printMenu2();
		break;
	case USER_TURN:
		ticks=0;
		drawArea();
		user_move = Detect_Move();
		if(Game_Status != USER_TURN) break;
		if(user_move == ERROR){
			err_cnt++;
			if (err_cnt>2) {Loose_Round(1); err_cnt=0; break;}
			if(times_up){
				mmEffect(SFX_BUZZER);
				while(times_up){Handle_Button(); swiWaitForVBlank();}
				err_cnt = 0;
			}
			else mmEffect(SFX_WHIP);
		}
		else{
			switch(user_move){
			case ROCK: userPlayed(ROCK); break;
			case PAPER: userPlayed(PAPER); break;
			case SCISSORS: userPlayed(SCISSORS); break;
			case ERROR: break;
			}
			Game_Status = OPPONENT_TURN;
			delay_ds(30);
			err_cnt = 0;
			if (user_move == ROCK) n_rock_streak++;
			else if(user_move!= ERROR) n_rock_streak = 0;
		}
		break;
	case LOBBY:
		HasPlayed1=0;
		HasPlayed2=0;
		break;
	case MULTIPLAYER_TURN:
		err_cnt=0;
		user_move = ERROR;
		//reste dans cette boucle tant que Detect_move n'a rien detecte
		while(user_move==ERROR){
			if(user_move != ERROR) break;
			if (err_cnt>0) mmEffect(SFX_WHIP);
			if (err_cnt>2) {Loose_Round(1); break;}

			err_cnt++;
			ticks=0;

			drawAreaMulti();
			user_move = Detect_Move();

			if(times_up){
				//delay_ds(10);
				user_move = ERROR;
				times_up = false;
				err_cnt = 0;
			}
		}

		if(Game_Status == USER_TURN) Game_Status = OPPONENT_TURN;

			//tant que joueur 1 n'a pas jouö, on n'arrive pas lä
		switch(user_move){
			case ROCK:
				userPlayed(ROCK);
				HasPlayed1=1;
				break;
			case PAPER:
				userPlayed(PAPER);
				HasPlayed1=1;
				break;
			case SCISSORS:
				userPlayed(SCISSORS);
				HasPlayed1=1;
				break;
			case ERROR: break;
		}

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
	case PAUSE:
		break;
	}
}

void Handle_Button(){
	scanKeys();
	unsigned keys = keysHeld();

	if ((keys & KEY_TOUCH) && (Game_Status==STOP) && (key_released == true)) {
		touchRead(&touch);
		int posx = touch.px;
		int posy = touch.py;

		if((posx>27) && (posx<=228)){
			if((posy>=50) && (posy<80)){mode = 0; Game_Status = START;}
			//if((posy>=90) && (posy<120)){mode = 1; Game_Status = START;}
		}
		key_released = false;
	}

	if((Game_Status == START) && (keys & KEY_START) && (key_released == true)){
		if(mode == 0) Game_Status = USER_TURN;
		if(mode == 1) Game_Status = LOBBY;
		key_released = false;
	}
	/*
	else if((Game_Status != START) && (Game_Status != STOP) && (keys & KEY_START) && (key_released == true)){
		Old_Status = Game_Status;
		Game_Status = PAUSE;
		key_released = false;
	}

	if(Game_Status == PAUSE && (key_released == true)){
		if(keys & KEY_A) Game_Status = Old_Status;
		if(keys & KEY_START) Game_Status = STOP;
		key_released = false;
	}
*/
	if((times_up == true) && (keys & KEY_A) && !(keys & KEY_TOUCH)){times_up = false; key_released = false;}

	key_released = true; //(keys==KEY_A || keys==KEY_START || keys == KEY_TOUCH);
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
    swiCopy(MenuTiles, BG_TILE_RAM(0), MenuTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
    swiCopy(MenuMap, bg0Map, MenuMapLen/2); // store in the 26th slot => #25 (was finally chosen to be 26)
    swiCopy(MenuPal, BG_PALETTE, MenuPalLen/2);

	swiCopy(MenuInstructionTiles, BG_TILE_RAM_SUB(0), MenuInstructionTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
	swiCopy(MenuInstructionMap, bg0Map_SUB, MenuInstructionMapLen/2); // store in the 26th slot => #25
	swiCopy(MenuInstructionPal, BG_PALETTE_SUB, MenuInstructionPalLen/2);
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



void drawAreaMulti(){
	//print bottom screen ("please draw here")
	swiCopy(ecranBaseTiles, BG_TILE_RAM_SUB(0), ecranBaseTilesLen/2);
	swiCopy(ecranBaseMap, bg0Map_SUB, ecranBaseMapLen/2);
	swiCopy(ecranBasePal, BG_PALETTE_SUB, ecranBasePalLen/2);

	//print top screen (comic style)
	//we use two times "Background" in order to have two layers. This will be
	//useful when printing computer choices
	swiCopy(BackgroundMultiTiles, BG_TILE_RAM(0), BackgroundMultiTilesLen/2);
	swiCopy(BackgroundMultiMap, bg0Map, BackgroundMultiMapLen/2);
	swiCopy(BackgroundMultiPal, BG_PALETTE, BackgroundMultiPalLen/2);

	swiCopy(BackgroundMultiTiles, BG_TILE_RAM(4), BackgroundMultiTilesLen/2);
	swiCopy(BackgroundMultiMap, bg1Map, BackgroundMultiMapLen/2);
	swiCopy(BackgroundMultiPal, BG_PALETTE, BackgroundMultiPalLen/2);

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
			mmEffect(SFX_GUITAR);
			break;
		case PAPER:
			//print player's choice
			swiCopy(PaperTiles, BG_TILE_RAM_SUB(0), PaperTilesLen/2);
			swiCopy(PaperMap, bg0Map_SUB, PaperMapLen/2);
			swiCopy(PaperPal, BG_PALETTE_SUB, PaperPalLen/2);
			mmEffect(SFX_PAPER);
			break;
		case SCISSORS:
			//print player's choice
			swiCopy(ScissorTiles, BG_TILE_RAM_SUB(0), ScissorTilesLen/2);
			swiCopy(ScissorMap, bg0Map_SUB, ScissorMapLen/2);
			swiCopy(ScissorPal, BG_PALETTE_SUB, ScissorPalLen/2);
			mmEffect(SFX_SHEARS);
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
		case 0:	{opponent_move=ROCK; row_sel = 0; break;}
		case 1: {opponent_move=PAPER; row_sel = 20; break;}
		case 2: {opponent_move=SCISSORS; row_sel = 10; break;}
		HasPlayed2=1;
		}
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
	delay_ticks++;
	if(Game_Status == USER_TURN){
		ticks++;
		if (ticks>=4000) {
			printTimesUp();
			times_up = true;
			ticks = 0;
		}
	}
}
// ------- END OF ISR ------------

void Full_Rock(){
	u8 fullTile[64] = {
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
	};
	mmEffect(SFX_NIRVANA);
	delay_ds(10);

	swiCopy(GuitarTiles, BG_TILE_RAM(0), GuitarTilesLen/2);
	swiCopy(GuitarMap, bg0Map, GuitarMapLen/2);
	swiCopy(GuitarPal, BG_PALETTE, GuitarPalLen/2);

	dmaCopy(fullTile,(u8*) BG_TILE_RAM(0), 64);
	memset(bg1Map,1,32*32*64);

	int cnt = 0;
	while(cnt<50){
		if (cnt%2){
			BG_PALETTE[1] = RED;
			memset(bg0Map_SUB,WHITE,256*256*2);
		}
		else{
			BG_PALETTE[1] = WHITE;
			memset(bg0Map_SUB, BLACK ,256*256*2);
		}
		if (cnt%4==3) REG_POWERCNT ^= BIT(15);
		delay_ds(5);
		swiWaitForVBlank();
		cnt++;
	}
	n_rock_streak = 0;
	Init_Graphics();
	memset(bg3Map_SUB, ARGB16(0,0,0,0),256*192*2);
	drawArea();
}
