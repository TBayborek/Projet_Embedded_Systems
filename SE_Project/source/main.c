#include "Define.h"
#include "Shared.h"
#include "Game_Update.h"
#include "Initialization.h"

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
