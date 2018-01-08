#include "Game_Update.h"

void Game_Update(){
	irqSet(IRQ_TIMER0, &ISR_Timer0);

	Handle_Button();

	if (n_rock_streak>=4) Full_Rock();

	switch(Game_Status){
	case STOP:
		// PRINT explanations about game and "choose mode"
		Init_Graphics();
		break;
	case START:
		ticks = err_cnt = n_rock_streak = 0; times_up = false;
		scoreHuman = scoreBot = 0;

		// For multiplayer
		confirmation1 = confirmation2 = 0;

		// PRINT Rules, "press START to play"
		printMenu2();
		break;
	case USER_TURN:
		ticks=0;
		drawArea();
		User_Move();
		if (user_move != ERROR && user_move != LOSE) Game_Status = OPPONENT_TURN;
		printUserChoice();
		break;
	case LOBBY:
		HasPlayed1 = HasPlayed2 = 0;


		Init_WiFi();

		//creer une image explicative ("en attente de connexion" en haut, "Quand vous pensez etre connectö avec joueur 2, appuyez sur a simultanement (sinon, attendre 3 secondes)" en bas)
		sendConfirmation();
		receiveConfirmation();

		if((confirmation1==1) && (confirmation2==1)) Game_Status = MULTIPLAYER_TURN;
		break;
	case MULTIPLAYER_TURN:
		ticks=0; // >>>> On pourrait ajouter tres facilement le times_up <<<<<<
		drawAreaMulti();
		User_Move();
		if (user_move !=ERROR){
			sendPlay1();
			Game_Status = OPPONENT_TURN;
			printUserChoice();
		}
		break;
	case OPPONENT_TURN:
		if (game_mode == SINGLE){
			Opponent_Move();
			Game_Status = RESULTS;
		}
		if ((game_mode == MULTI) && (HasPlayed2==1)){
			Game_Status = RESULTS;
		}
		break;
	case RESULTS:
		printOpponentChoice();
		Check_Results(user_move, opponent_move);
		break;
	case NEXT:
		user_move = opponent_move = ERROR;
		HasPlayed1 = HasPlayed2 = 0;
		delay_ds(20);

		if (game_mode==SINGLE) Game_Status = USER_TURN;
		if (game_mode==MULTI) Game_Status = MULTIPLAYER_TURN;
		break;
	case PAUSE:

		swiCopy(pauseTiles, BG_TILE_RAM(0), pauseTilesLen/2);
		swiCopy(pauseMap, bg0Map, pauseMapLen/2);
		swiCopy(pausePal, BG_PALETTE, pausePalLen/2);

		break;
	}
}

void Handle_Button(){
	scanKeys();
	unsigned keys = keysDown();

	if ((keys & KEY_TOUCH) && (Game_Status==STOP)){
		touchRead(&touch);
		int posx = touch.px;
		int posy = touch.py;

		if((posx>27) && (posx<=228)){
			if((posy>=50) && (posy<80)){game_mode = SINGLE; Game_Status = START;}
			if((posy>=90) && (posy<120)){game_mode = MULTI; Game_Status = START;}
		}
	}

	if(Game_Status == PAUSE){
			if(keys & KEY_A) Game_Status = Old_Status;
			if(keys & KEY_START) Game_Status = STOP;
	}

	if((Game_Status == USER_TURN)  && (keys & KEY_START)){
		Old_Status = Game_Status;
		Game_Status = PAUSE;
	}

	if((Game_Status == START) && (keys & KEY_START)){
		if(game_mode == SINGLE) Game_Status = USER_TURN;
		if(game_mode == MULTI) {printLobby(); Game_Status = LOBBY;}
	}

	if((times_up == true) && (keys & KEY_A) && !(keys & KEY_TOUCH)){times_up = false;}
}

void User_Move(){
	user_move = Detect_Move();
	if((Game_Status != USER_TURN) && (Game_Status!= MULTIPLAYER_TURN)) return;
	if(user_move == ERROR){
		err_cnt++;
		if(times_up){
			mmEffect(SFX_BUZZER);
			while(times_up){Handle_Button(); swiWaitForVBlank();}
			err_cnt = 0;
		}
		else if (err_cnt>2) {Loose_Round(1); err_cnt=0; return;}
		else mmEffect(SFX_WHIP);
	}
	else{
		err_cnt = 0;
		if (user_move == ROCK) n_rock_streak++;
		else n_rock_streak = 0;
	}
}

void Opponent_Move(){
	int choice = rand()%3;

	switch(choice){
		case 0: opponent_move = ROCK; break;
		case 1: opponent_move = SCISSORS; break;
		case 2: opponent_move = PAPER; break;
	}
}

void printUserChoice(){
	switch(user_move){
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
		case LOSE: break;
	}
	if(user_move != ERROR && user_move != LOSE) delay_ds(30);
}


//print opponent choice
void printOpponentChoice(){
	int row_sel;
	switch(opponent_move){
		case ROCK: {row_sel = 0; break;}
		case SCISSORS:{row_sel = 10; break;}
		case PAPER: {row_sel = 20; break;}
		case ERROR: break;
		case LOSE: {row_sel = 30; break;}
	}
	//print the corresponding bot's choice (taken from the bottom of BackgroundMulti.png)
	int row, col;
	for(row=0;row<9;row++){
		for(col=0;col<10;col++){
			bg0Map[(row+8)*32+(col+12)] = bg0Map[(row+25+row_sel)*32+col+12];
		}
	}
}

void Check_Results(){
	if((user_move == ROCK && opponent_move == SCISSORS) ||
			(user_move == SCISSORS && opponent_move == PAPER) ||
			(user_move == PAPER && opponent_move == ROCK) || (opponent_move==LOSE)){
		Win_Round();
	}

	if((user_move == ROCK && opponent_move == PAPER) ||
			(user_move == SCISSORS && opponent_move == ROCK) ||
			(user_move == PAPER && opponent_move == SCISSORS)){
		Loose_Round(0);
	}

	if(user_move == opponent_move) Draw_Round();

	if(user_move==LOSE) Game_Status=NEXT;

}


// --------MULTIPLAYER ---------

//send your confirmation from the lobby to the other player
void sendConfirmation(){
	//Poll the keypad
	//scanKeys();
	char msg[1];
	unsigned short keysLobby = keysDown();

	//Print and send a message if key pressed
	if (keysLobby == KEY_A){
		msg[0]=(char)A;
		sendData(msg, 1);

    	int row, col;
    	int rowEnd=6;
    	for(row=0;row<6;row++){
    		for(col=0;col<32;col++){
    			bg0Map[(row+25-rowEnd)*32+col] = bg0Map[(row+24)*32+col];
    		}
    	}
    	confirmation1=1;
	}
}

//get the confirmation of the other player
void receiveConfirmation(){
	char msg[1];

	//Listen for messages from others
	if(receiveData(msg,1)>0	){
		//If received, decode the key and print
		switch(msg[0]){
		case A:
			confirmation2 = 1;

			int row, col;
			int rowEnd=(WINMapLen/2)/32; //nb of rows in the WIN picture
			for(row=0;row<6;row++){
				for(col=0;col<32;col++){
					bg0Map[(row+25-rowEnd)*32+col] = bg0Map[(row+30)*32+col];
				}
			}
			break;
		}
	}
}

//function called once to send the move of the user
void sendPlay1(){
	char msg[1];

	switch(user_move){
	case ROCK: msg[0] = (char)ROCK; break;
	case SCISSORS: msg[0] = (char)SCISSORS; break;
	case PAPER: msg[0] = (char)PAPER; break;
	case ERROR: break;
	case LOSE: msg[0] = (char)LOSE; break;
	}
	sendData(msg, 1);
	HasPlayed1=1;
}

//function called every 0.5 seconds, to get the move of the other player
void receivePlay2(){
	char msg[1];

	//Listen for messages from others
	if(receiveData(msg,1)>0){
		//If received, decode the key and print
		switch(msg[0]){
		case ROCK: {opponent_move=ROCK; break;}
		case SCISSORS: {opponent_move=SCISSORS; break;}
		case PAPER: {opponent_move=PAPER; break;}
		case LOSE: {opponent_move=LOSE; break;}
		}
		HasPlayed2=1;
	}
}
// ------- End of Multiplayer -----------------

// ---------- Print Backgrounds ---------------

void printMenu2(){
    swiCopy(MenuTiles, BG_TILE_RAM(0), MenuTilesLen/2);
    swiCopy(MenuMap, bg0Map, MenuMapLen/2);
    swiCopy(MenuPal, BG_PALETTE, MenuPalLen/2);

	swiCopy(MenuInstructionTiles, BG_TILE_RAM_SUB(0), MenuInstructionTilesLen/2);
	swiCopy(MenuInstructionMap, bg0Map_SUB, MenuInstructionMapLen/2);
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
			bg0Map[(row+8)*32+(col+12)] = bg0Map[(row+25+30)*32+col+12];
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
			bg0Map[(row+8)*32+(col+12)] = bg0Map[(row+25+30)*32+col+12];
		}
	}
	//utile pour affichage du 0-0
	printScore(scoreHuman,12,0);
	printScore(scoreBot,21,0);
}

//print images for the lobby (in test phase: you win (also you lose for some reason) on sub means you re connected to wifi,
//you win on main means you send the confirmation, and you lose on main means you received a confirmation )
void printLobby(){
	swiCopy(lobbyMainTiles, BG_TILE_RAM(0), lobbyMainTilesLen/2);
	swiCopy(lobbyMainMap, bg0Map, lobbyMainMapLen/2);
	swiCopy(lobbyMainPal, BG_PALETTE, lobbyMainPalLen/2);

	swiCopy(lobbyTiles, BG_TILE_RAM_SUB(0), lobbyTilesLen/2);
	swiCopy(lobbyMap, bg0Map_SUB, lobbyMapLen/2);
	swiCopy(lobbyPal, BG_PALETTE_SUB, lobbyPalLen/2);
}

void printTimesUp(){
	int row, col;
	int rowEnd=(256-192)/8; //nb of rows of tile in the WIN picture

	for(row=0;row<8;row++){
		for(col=0;col<32;col++){
			bg0Map_SUB[(row+24-rowEnd)*32+col] = bg0Map_SUB[(row+24)*32+col];
		}
	}
}


// ---------- End of Print Backgrounds ---------

// ---------- ISR ----------------
void ISR_Timer0(void){
	delay_ticks++;
	if(Game_Status == USER_TURN){
		ticks++;
		if (ticks>=400) {
			printTimesUp();
			times_up = true;
			ticks = 0;
		}
	}

	//-------- Multiplayer --------
	if(game_mode==MULTI){
		//erase confirmation1 if the second one isn t confirmed after 1 sec
		if (Game_Status==LOBBY){
			if(confirmation1==1){
				ticksConf1++;
				if (ticksConf1>300){
					confirmation1=0;
					ticksConf1=0;
					printLobby();
				}
			}
			//erase confirmation2 if the first one isn t confirmed after 1 sec
			if(confirmation2==1){
				ticksConf2++;
				if (ticksConf2>300){
					confirmation2=0;
					ticksConf2=0;
					printLobby();
				}
			}
		}

		//call receivePlay2 every 0.5 sec
		if(Game_Status==OPPONENT_TURN){
			ticksPull++;
			if (ticksPull>10){
				receivePlay2();
				ticksPull=0;
			}
		}
	}
}
// ------- END OF ISR ------------

// -------- Easter Egg -----------
void Full_Rock(){ // Declare tile
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

	dmaCopy(fullTile,(u8*) BG_TILE_RAM(0), 128); // assign the fullTile to the tile RAM
	memset(bg1Map,1,32*32*64); // fill the map with that tile

	// Loop n_times*time base defined by the delay
	int cnt = 0;
	while(cnt<50){
		// Change color every tick
		if (cnt%2){
			BG_PALETTE[1] = RED;
			memset(bg0Map_SUB,WHITE,256*256*2);
		}
		else{
			BG_PALETTE[1] = WHITE;
			memset(bg0Map_SUB, BLACK ,256*256*2);
		}
		// Change the screens every 4 ticks
		if (cnt%4==3) REG_POWERCNT ^= BIT(15);
		delay_ds(5); // Time base for each loop
		swiWaitForVBlank();
		cnt++;
	}
	// End of Easter Egg Init all the parameters/Graphics
	n_rock_streak = 0;
	Init_Graphics();
	memset(bg3Map_SUB, ARGB16(0,0,0,0),256*192*2);
	printUserChoice();
}
