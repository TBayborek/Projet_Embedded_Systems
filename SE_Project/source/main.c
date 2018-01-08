#include "main.h"

int main(){
	srand(time(NULL)); // Really random?

	// Initialize all the Graphics, Peripherals and Interruptions
	Initialization();

	Game_Status = STOP; // init Game_Status
	while(true){
		Game_Update(); // Update the game
		swiWaitForVBlank();
	}
	return 0;
}

void Initialization(){
	Init_Graphics();
	Init_Interruptions();
	Init_Sound();
}
