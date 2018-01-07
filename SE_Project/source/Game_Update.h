#include "Define.h"
#include "Shared.h"

#include "Init_Graphics.h"
#include "Handle_Outcome.h"
#include "Init_Peripherals.h"

#include "Pattern_Recognition.h"

int err_cnt;
int ticks;
int n_rock_streak;
bool pause;
bool key_released;

move user_move;
move opponent_move;

status Old_Status;

void Game_Update();

void Handle_Button();

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

void Full_Rock();
