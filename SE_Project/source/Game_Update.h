#include "Define.h"
#include "Shared.h"

#include "Init_Graphics.h"
#include "Handle_Outcome.h"
#include "Init_Peripherals.h"

#include "Pattern_Recognition.h"

unsigned keys;
int err_cnt;
int ticks;
bool times_up;

move user_move;
move opponent_move;

int confirmation1;
int confirmation2;
int ticksConf1;
int ticksConf2;
int ticksPull;
int flag2Play;

typedef enum Messages_e {
	A,	//0x00
	B,	//0x01
	X,	//0x02
	Y	//0x03
}Message;

int row_sel;


void Game_Update();

void Handle_Button(unsigned);

void Opponent_Move();
void Check_Results(move,move);


void printMenu2();
void drawArea();
void drawAreaMulti();
void userPlayed(move);
void printTimesUp();
void checkIfThe2HavePlayed();
void sendPlay(move);

//void ISR_Keys();
void ISR_Timer0();
void lobby();
void sendConfirmation();
void receiveConfirmation();
void printLobby();
void sendPlay1();
void receivePlay2();
void printOpponentChoice();


//void delay_ds(int);
