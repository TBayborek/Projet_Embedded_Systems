#include "Init_Graphics.h"
#define TILE_PAL(n) ((n) << 12) //macro permettant de changer de palette

void Init_Graphics(void){
	Init_Main_Graphics();	// Init Main Graphics
	Init_Sub_Graphics();	// Init Sub Graphics
}


void Init_Main_Graphics(void){
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG; //Enable RAM memory bank for the main engine
	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG1_ACTIVE; // Main engine in mode 0, activate BG 0 and 1

	BGCTRL[0] = BG_MAP_BASE(26) | BG_TILE_BASE(0) | BG_32x32 | BG_COLOR_256;
	BGCTRL[1] = BG_MAP_BASE(29) | BG_TILE_BASE(4) | BG_32x32 | BG_COLOR_256;


	swiCopy(BackgroundTiles, BG_TILE_RAM(4), BackgroundTilesLen/2);
	swiCopy(BackgroundPal, BG_PALETTE, BackgroundPalLen/2);

	//for (i=0;i<RSPPalLen/2;i++){
	//	BG_PALETTE[128+i]=BG_PALETTE[i]; //sauvegarde de la palette (il y a surement une meilleure facon)
	//}
	/*
	u16* bg1Map = (u16*)BG_MAP_RAM(29);

	for(i=0;i<(RSPMapLen/2);i++){
		bg1Map[i]= RSPMap[i] | TILE_PAL(8); //utilisation de la palette sauvegardee
	}
	*/
	swiCopy(MenuTiles, BG_TILE_RAM(0), MenuTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
	swiCopy(MenuMap, BG_MAP_RAM(26), MenuMapLen/2); // store in the 26th slot => #25
	swiCopy(MenuPal, BG_PALETTE, MenuPalLen/2);



}

void Init_Sub_Graphics(void){
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG; //Enable RAM memory bank for the sub engine
	REG_DISPCNT_SUB = MODE_0_2D |
			DISPLAY_BG0_ACTIVE |
			DISPLAY_BG1_ACTIVE; // Sub engine in mode 0, activate BG 0

	BGCTRL_SUB[0] = BG_MAP_BASE(25) | BG_TILE_BASE(0) | BG_32x32 | BG_COLOR_256;
	BGCTRL_SUB[1] = BG_MAP_BASE(26) | BG_TILE_BASE(4) | BG_32x32 | BG_COLOR_256;

	swiCopy(MenuInstructionTiles, BG_TILE_RAM_SUB(0), MenuInstructionTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
	swiCopy(MenuInstructionMap, BG_MAP_RAM_SUB(25), MenuInstructionMapLen/2); // store in the 26th slot => #25
	swiCopy(MenuInstructionPal, BG_PALETTE_SUB, MenuInstructionPalLen/2);

	/*
	swiCopy(AssemblageTiles, BG_TILE_RAM_SUB(0), BackgroundTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
	swiCopy(AssemblageMap, BG_MAP_RAM_SUB(25), BackgroundMapLen/2); // store in the 26th slot => #25
	swiCopy(AssemblagePal, BG_PALETTE_SUB, BackgroundPalLen/2);
	*/


}
