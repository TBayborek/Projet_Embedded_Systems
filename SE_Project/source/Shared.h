#include "Define.h"

extern status Game_Status;

extern move user_move;
extern move opponent_move;

extern int scoreHuman;
extern int scoreBot;

extern int HasPlayed1;
extern int HasPlayed2;

extern mode game_mode; // mode=SINGLE/MULTI

extern u16* bg0Map;
extern u16* bg1Map;
extern u16* bg0Map_SUB;
extern u16* bg3Map_SUB;

extern int delay_ticks;
extern bool times_up;

extern void delay_ds(int);
