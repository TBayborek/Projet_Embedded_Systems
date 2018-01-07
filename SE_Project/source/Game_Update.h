#include "Define.h"
#include "Shared.h"

#include "Init_Graphics.h"
#include "Handle_Outcome.h"
#include "Init_Peripherals.h"

#include "Pattern_Recognition.h"

unsigned keys;
int err_cnt;
int ticks;
<<<<<<< HEAD
int n_rock_streak;
bool pause;
bool key_released;
int row_sel;
=======
bool times_up;
>>>>>>> b2b954f20d949036764dfc9e13851467f4d94d21

move user_move;
move opponent_move;

<<<<<<< HEAD
=======
<<<<<<< HEAD

>>>>>>> b2b954f20d949036764dfc9e13851467f4d94d21
status Old_Status;

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

<<<<<<< HEAD
=======
int row_sel;

=======
>>>>>>> parent of 69b1087... Update
>>>>>>> b2b954f20d949036764dfc9e13851467f4d94d21
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

<<<<<<< HEAD
void Full_Rock();
=======
//void ISR_Keys();
void ISR_Timer0();

<<<<<<< HEAD
void Full_Rock();
=======
//void delay_ds(int);
>>>>>>> parent of 69b1087... Update
>>>>>>> b2b954f20d949036764dfc9e13851467f4d94d21
