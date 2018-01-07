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
			if (err_cnt>2){Loose_Round(1); break;}

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
<<<<<<< HEAD
	case LOBBY:

			 //* ça menerait ä une fonction lobby
			 //* qui activerait le wifi et attendrait le ping de l'autre ds
			 //* au moment ou on recoit le ping (inclure double veref -> pas plus de 1 sec de döcalage)
			 //* on passe ä fonction MULTIPLAYER_TURN
			 //* modifier le handle outcome
			//Game_Status = MULTIPLAYER_TURN;
		HasPlayed1=0;
		HasPlayed2=0;
		confirmation1=0;
		confirmation2=0;
		printLobby();
		lobby();
		break;
=======


>>>>>>> parent of 69b1087... Update
	case MULTIPLAYER_TURN:
		err_cnt=0;
		user_move = ERROR;
		//reste dans cette boucle tant que Detect_move n'a rien detecte
		while(user_move==ERROR){
			if(user_move != ERROR) break;
<<<<<<< HEAD

			if (err_cnt>0)mmEffect(SFX_BUZZER);
			if (err_cnt>2){Loose_Round(1); user_move=LOSE; break;}
=======
			if (err_cnt>0)mmEffect(SFX_BUZZER);
			if (err_cnt>2){Loose_Round(1); break;}
>>>>>>> parent of 69b1087... Update

			err_cnt++;
			ticks=0;

			drawAreaMulti();
			user_move = Detect_Move();
			if(times_up){

				delay_ds(10);
				user_move = ERROR;
				times_up = false;
				err_cnt = 0;
			}
		}

		//if(Game_Status == USER_TURN) Game_Status = OPPONENT_TURN;

			//tant que joueur 1 n'a pas jouö, on n'arrive pas lä
		switch(user_move){
			case ROCK:
				userPlayed(ROCK);

				break;
			case PAPER:
				userPlayed(PAPER);

				break;
			case SCISSORS:
				userPlayed(SCISSORS);

				break;
			case ERROR:
				break;
			case LOSE:
				break;
		}

		sendPlay1(user_move);

		while (!flag2Play){
			checkIfThe2HavePlayed();
			swiWaitForVBlank();
		}

<<<<<<< HEAD
=======


		checkIfThe2HavePlayed();
>>>>>>> parent of 69b1087... Update
		break;
	case OPPONENT_TURN:
		Opponent_Move();
		Game_Status = RESULTS;
		break;
	case RESULTS:

		if(mode==1){
			printOpponentChoice();
		}

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

<<<<<<< HEAD
		if((posx>27) && (posx<=228)){
			if((posy>=50) && (posy<80)){mode = 0; Game_Status = START;}
			if((posy>=90) && (posy<120)){mode = 1; Game_Status = START;}
=======
		if((posx>27 & posx<=228) && (posy>=50 & posy<80)){
			Game_Status = USER_TURN;
>>>>>>> parent of 69b1087... Update
		}

<<<<<<< HEAD
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
=======


>>>>>>> parent of 69b1087... Update
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
			bg0Map[(row+8)*32+(col+12)] = bg0Map[(row+25+row_sel)*32+col+12];
		}
	}
}

void Check_Results(move user_move, move opponent_move){
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

<<<<<<< HEAD
=======
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
>>>>>>> parent of 69b1087... Update

/*
void delay_ds(int ds){
	delay_ticks = 0;
	while(1){
		if(delay_ticks>=ds*10)break;
	}
}
*/
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
			printTimesUp();
			//Loose_Round(1);
			times_up = true;
		}
	}
<<<<<<< HEAD

	//-------- Multiplayer --------
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
	if(Game_Status==MULTIPLAYER_TURN){
		ticksPull++;
		if (ticksPull>50){
			receivePlay2();
			ticksPull=0;
		}
	}
	delay_ticks++;
}
// ------- END OF ISR ------------


// --------MULTIPLAYER ---------

// manages everything in the lobby
void lobby(){

	int test=0;

	if (test==0){
	test=Init_WiFi();
	}


	//cröer une image explicative ("en attente de connexion" en haut, "Quand vous pensez etre connectö avec joueur 2, appuyez sur a simultanement (sinon, attendre 3 secondes)" en bas)


	sendConfirmation();
	receiveConfirmation();

	if((confirmation1==1) && (confirmation2==1)){
		Game_Status=MULTIPLAYER_TURN;
		drawAreaMulti();

	}


}

//send your confirmation from the lobby to the other player
void sendConfirmation()
{
	char msg[1];

	//Poll the keypad
	//scanKeys();
	unsigned short keysLobby = keysDown();

	//Print and send a message if key pressed
	switch(keysLobby)
	{
	case KEY_A:

		msg[0] = (char)A;
		sendData(msg, 1);

    	int row, col;
    	//int rowEnd=(WINMapLen/2)/32; //nb of rows in the WIN picture
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
void receiveConfirmation()
{
	char msg[1];


	//Listen for messages from others
	if(receiveData(msg,1)>0	)
	{
		//If received, decode the key and print
		switch(msg[0])
		{
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

//check if the two players have played
void checkIfThe2HavePlayed(){




	if(HasPlayed1==1 && HasPlayed2==1){
		//print the corresponding player 2's choice (taken from the bottom of Background.png)
		int row, col;
		for(row=0;row<9;row++){
			for(col=0;col<10;col++){
				bg0Map[(row+8)*32+(col+12)] = bg0Map[(row+25+row_sel)*32+col+12];
			}
		}
		flag2Play=1;
		Game_Status=RESULTS;
	}
}


//function called once to send the move of the user
void sendPlay1(){
	char msg[1];


	switch(user_move)
	{
	case ROCK:
		msg[0] = (char)ROCK;
		sendData(msg, 1);
		break;
	case SCISSORS:
		msg[0] = (char)SCISSORS;
		sendData(msg, 1);
		break;
	case PAPER:
		msg[0] = (char)PAPER;
		sendData(msg, 1);
		break;
	case LOSE:
		msg[0] = (char)LOSE;
		sendData(msg, 1);
		break;
	}

}


//function called every 0.5 seconds, to get the move of the other player
void receivePlay2(){

	char msg[1];

	//Listen for messages from others
	if(receiveData(msg,1)>0	)
	{
		//If received, decode the key and print
		switch(msg[0])
		{
		case ROCK:
			opponent_move=ROCK;
			row_sel = 0;
			break;
		case PAPER:
			opponent_move=PAPER;
			row_sel = 20;
			break;
		case SCISSORS:
			opponent_move=SCISSORS;
			row_sel = 10;
			break;
		case LOSE:
			opponent_move=LOSE;
			row_sel = 30;
			break;
		}
		HasPlayed2=1;
	}


}

//print opponent choice
void printOpponentChoice(){

	int row_sel;
	switch(opponent_move){
		case ROCK: row_sel = 0; break;
		case SCISSORS:row_sel = 10; break;
		case PAPER:row_sel = 20; break;
	}

	//print the corresponding bot's choice (taken from the bottom of BackgroundMulti.png)
	int row, col;
	for(row=0;row<9;row++){
		for(col=0;col<10;col++){
			bg0Map[(row+8)*32+(col+12)] = bg0Map[(row+25+row_sel)*32+col+12];
		}
	}
}



// --------------------- EXTRAS ------------------

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
=======
	delay_ticks++;
}
// ------- END OF ISR ------------
>>>>>>> parent of 69b1087... Update
