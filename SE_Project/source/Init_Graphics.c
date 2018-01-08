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

	swiCopy(MenuDescriptionTiles, BG_TILE_RAM(0), MenuDescriptionTilesLen/2);
	swiCopy(MenuDescriptionMap, bg0Map, MenuDescriptionMapLen/2);
	swiCopy(MenuDescriptionPal, BG_PALETTE, MenuDescriptionPalLen/2);
}

void Init_Sub_Graphics(void){
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG; //Enable RAM memory bank for the sub engine

	REG_DISPCNT_SUB = MODE_3_2D | DISPLAY_BG0_ACTIVE; // Sub engine in mode 0, activate BG 0

	BGCTRL_SUB[0] = BG_MAP_BASE(15) | BG_TILE_BASE(0) | BG_32x32 | BG_COLOR_256;
	BGCTRL_SUB[3] = BG_MAP_BASE(17) | BG_BMP16_256x256 | BG_COLOR_256;

	bg0Map_SUB = BG_MAP_RAM_SUB(15);
	bg3Map_SUB = BG_MAP_RAM_SUB(17);

	BGCTRL_SUB[0] = (BGCTRL_SUB[0] & 0xFFFC) | 3; //Mask with all but the last two bits and initialize these last bits with 3
	BGCTRL_SUB[3] = (BGCTRL_SUB[3] & 0xFFFC) | 0;

    REG_BG3PA_SUB = 256;
    REG_BG3PB_SUB = 0;
    REG_BG3PC_SUB = 0;
    REG_BG3PD_SUB = 256;
    REG_BG3X_SUB = 0;
    REG_BG3Y_SUB = 256*36;

	//swiCopy(invisibleTiles, BG_TILE_RAM_SUB(0), invisibleTilesLen/2);
	//swiCopy(invisibleBitmap, bg3Map_SUB, invisibleBitmapLen/2);


	swiCopy(MenuTactileTiles, BG_TILE_RAM_SUB(0), MenuTactileTilesLen/2);
	swiCopy(MenuTactileMap, bg0Map_SUB, MenuTactileMapLen/2);
	swiCopy(MenuTactilePal, BG_PALETTE_SUB, MenuTactilePalLen/2);
	/*
	int row, col;
	for(row=0;row<256;row++)
		for (col=0;col<256;col++){
			bg3Map_SUB[row*256+col]=ARGB16(0,0,0,0);

		}
		*/


}
