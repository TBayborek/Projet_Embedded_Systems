#include "Shared.h"
#include "Define.h"

#include "Init_Graphics.h"
#include "Handle_Outcome.h"

unsigned keys;
touchPosition touch;
u16 posx, posy;
int choice;

move user_move;
move opponent_move;

void Game_Update();

void Handle_Input();

void Handle_Button(unsigned);
void Handle_Touchscreen();

void Opponent_Move();
void Check_Results(move,move);

//void ISR_Keys();
void ISR_Timer0();
