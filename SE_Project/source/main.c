#include "main.h"

int main(){
	srand(time(NULL)); // Really random?

	Initialization();
	//consoleDemoInit();

	//int scoreHuman=0;
	//int scoreBot=0;

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
