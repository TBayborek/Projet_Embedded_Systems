#include "Define.h"
#include "Shared.h"

#include "Init_Graphics.h"
#include "Init_Peripherals.h"
#include "Handle_Outcome.h"
#include "Pattern_Recognition.h"

status Old_Status;

int err_cnt;
int ticks;
int n_rock_streak;

int confirmation1;
int confirmation2;
int ticksConf1;
int ticksConf2;
int ticksPull;

typedef enum Messages_e {
	A,	//0x00
	B,	//0x01
	X,	//0x02
	Y	//0x03
}Message;

void Game_Update();

void Handle_Button();

void User_Move();
void Opponent_Move();

void Check_Results();

void printUserChoice();
void printOpponentChoice();

void sendConfirmation();
void receiveConfirmation();
void sendPlay1();
void receivePlay2();

void printMenu2();
void drawArea();
void drawAreaMulti();
void printLobby();
void printTimesUp();

void ISR_Timer0();

void Full_Rock();
