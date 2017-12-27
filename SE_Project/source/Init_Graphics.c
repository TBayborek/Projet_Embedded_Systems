#include "Init_Graphics.h"

void Init_Graphics(void){
	Init_Main_Graphics();	// Init Main Graphics
	Init_Sub_Graphics();	// Init Sub Graphics
}


void Init_Main_Graphics(void){
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG; //Enable RAM memory bank for the main engine
	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG1_ACTIVE; // Main engine in mode 0, activate BG 0 and 1

	BGCTRL[0] = BG_MAP_BASE(25) | BG_TILE_BASE(0) | BG_32x32 | BG_COLOR_256;
	BGCTRL[1] = BG_MAP_BASE(26) | BG_TILE_BASE(4) | BG_32x32 | BG_COLOR_256;

	swiCopy(BackgroundTiles, BG_TILE_RAM(0), BackgroundTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
	swiCopy(BackgroundMap, BG_MAP_RAM(25), BackgroundMapLen/2); // store in the 26th slot => #25
	swiCopy(BackgroundPal, BG_PALETTE, BackgroundPalLen/2);

	swiCopy(RSPTiles, BG_TILE_RAM(4), RSPTilesLen/2);
	swiCopy(RSPPal, BG_PALETTE, RSPPalLen/2);
}

void Init_Sub_Graphics(void){
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG; //Enable RAM memory bank for the sub engine
	REG_DISPCNT_SUB = MODE_0_2D |
			DISPLAY_BG0_ACTIVE |
			DISPLAY_BG1_ACTIVE; // Sub engine in mode 0, activate BG 0

	BGCTRL_SUB[0] = BG_MAP_BASE(25) | BG_TILE_BASE(0) | BG_32x32 | BG_COLOR_256;
	BGCTRL_SUB[1] = BG_MAP_BASE(26) | BG_TILE_BASE(4) | BG_32x32 | BG_COLOR_256;

	swiCopy(BackgroundTiles, BG_TILE_RAM_SUB(0), BackgroundTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
	swiCopy(BackgroundMap, BG_MAP_RAM_SUB(25), BackgroundMapLen/2); // store in the 26th slot => #25
	swiCopy(BackgroundPal, BG_PALETTE_SUB, BackgroundPalLen/2);

	swiCopy(RSPTiles, BG_TILE_RAM_SUB(4), RSPTilesLen/2);
	swiCopy(RSPPal, BG_PALETTE_SUB, RSPPalLen/2);

	int row, col;
	int i=0;
	for(row=0;row<24;row++){
		for(col=16;col<32;col++){
			BG_MAP_RAM_SUB(26)[row*32+col] = RSPMap[i];
			BG_MAP_RAM_SUB(25)[row*32+col] = 0;
			i++;
		}
	}

}
