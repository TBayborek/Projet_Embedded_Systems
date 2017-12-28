#include "Define.h"
#include "Shared.h"
#include "Game_Update.h"
#include "Initialization.h"

int main(){
	srand(time(NULL)); // Really random?

	Initialization();
	consoleDemoInit();

	while(true){
		Game_Update();
		swiWaitForVBlank();
	}
	return 0;
}
