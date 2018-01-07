#include "main.h"

int main(){
	srand(time(NULL)); // Really random?

	Initialization();

	Game_Status = STOP;
	while(true){
		Game_Update();
		swiWaitForVBlank();
	}
	return 0;
}

void Initialization(){
	Init_Graphics();
	Init_Interruptions();
	Init_Sound();
}
