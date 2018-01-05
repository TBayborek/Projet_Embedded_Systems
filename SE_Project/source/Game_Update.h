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

//void delay_ds(int);
