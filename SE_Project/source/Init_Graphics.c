#include "Init_Graphics.h"

void Init_Graphics(void){
	Init_Main_Graphics();	// Init Main Graphics
	Init_Sub_Graphics();	// Init Sub Graphics
}

void Init_Main_Graphics(void){
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG; //Enable RAM memory bank for the main engine
	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG1_ACTIVE; // Main engine in mode 0, activate BG 0 and 1

	//The offset of 26 for the BG0 map has been chosen because of the size of Background.png.
	//It was 25, and that was just not enough (interrogation point was weird).
	//The offset of 29 for BG1 hasn't been optimized.

	BGCTRL[0] = BG_MAP_BASE(26) | BG_TILE_BASE(0) | BG_32x32 | BG_COLOR_256;
	BGCTRL[1] = BG_MAP_BASE(29) | BG_TILE_BASE(4) | BG_32x32 | BG_COLOR_256;

	bg0Map = BG_MAP_RAM(26);
	bg1Map = BG_MAP_RAM(29);

	swiCopy(MenuTiles, BG_TILE_RAM(0), MenuTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
	swiCopy(MenuMap, bg0Map, MenuMapLen/2); // store in the 26th slot => #25 (was finally chosen to be 26)
	swiCopy(MenuPal, BG_PALETTE, MenuPalLen/2);
}

void Init_Sub_Graphics(void){
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG; //Enable RAM memory bank for the sub engine
	REG_DISPCNT_SUB = MODE_3_2D |
			DISPLAY_BG0_ACTIVE |
			DISPLAY_BG3_ACTIVE; // Sub engine in mode 0, activate BG 0

	BGCTRL_SUB[0] = BG_MAP_BASE(25) | BG_TILE_BASE(0) | BG_32x32 | BG_COLOR_256;
	BGCTRL_SUB[3] = BG_MAP_BASE(26) | BgSize_B8_256x256 | BG_COLOR_256;

	bg0Map_SUB = BG_MAP_RAM_SUB(25);
	bg3Map_SUB = BG_MAP_RAM_SUB(26);

	swiCopy(MenuInstructionTiles, BG_TILE_RAM_SUB(0), MenuInstructionTilesLen/2); // approx. 50KB of Tiles, 25x2KB slots used
	swiCopy(MenuInstructionMap, bg0Map_SUB, MenuInstructionMapLen/2); // store in the 26th slot => #25
	swiCopy(MenuInstructionPal, BG_PALETTE_SUB, MenuInstructionPalLen/2);
}
