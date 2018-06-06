#include "Init_Graphics.h"

void Init_Graphics(void){
	Init_Main_Graphics();	// Init Main Graphics
	Init_Sub_Graphics();	// Init Sub Graphics
}

void Init_Main_Graphics(void){
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG; //Enable RAM memory bank for the main engine
	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG1_ACTIVE; // Main engine in mode 0, activate BG 0 and 1

	BGCTRL[0] = BG_MAP_BASE(27) | BG_TILE_BASE(0) | BG_32x32 | BG_COLOR_256; // Both BG as tiled mode
	BGCTRL[1] = BG_MAP_BASE(29) | BG_TILE_BASE(4) | BG_32x32 | BG_COLOR_256;

	// Define global variables containing the BG map RAM
	bg0Map = BG_MAP_RAM(27);
	bg1Map = BG_MAP_RAM(29);

	// Display Menu Screen
	swiCopy(MenuDescriptionTiles, BG_TILE_RAM(0), MenuDescriptionTilesLen/2);
	swiCopy(MenuDescriptionMap, bg0Map, MenuDescriptionMapLen/2);
	swiCopy(MenuDescriptionPal, BG_PALETTE, MenuDescriptionPalLen/2);
}

void Init_Sub_Graphics(void){
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG; //Enable RAM memory bank for the sub engine

	REG_DISPCNT_SUB = MODE_3_2D | DISPLAY_BG0_ACTIVE; // Sub engine in mode 3, activate BG 0, BG3 will be activated in the pattern recognition

	BGCTRL_SUB[0] = BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_32x32 | BG_COLOR_256; // Tiled mode
	BGCTRL_SUB[3] = BG_MAP_BASE(17) | BG_BMP16_256x256 | BG_COLOR_256; // Rotoscale emulating FB mode


    //Affine Marix Transformation
    REG_BG3PA_SUB = 256;
    REG_BG3PC_SUB = 0;
    REG_BG3PB_SUB = 0;
    REG_BG3PD_SUB = 256;

	// Define global variables containing the BG map RAM
	bg0Map_SUB = BG_MAP_RAM_SUB(0);
	bg3Map_SUB = BG_MAP_RAM_SUB(17);

	// Change priorities of the BG, swap BG 0 and 3
	BGCTRL_SUB[0] = (BGCTRL_SUB[0] & 0xFFFC) | 3; //Mask with all but the last two bits and initialize these last bits with 3
	BGCTRL_SUB[3] = (BGCTRL_SUB[3] & 0xFFFC) | 0;

	// Affine transformation of the BG3 to set it correctly
    REG_BG3PA_SUB = 256;
    REG_BG3PB_SUB = 0;
    REG_BG3PC_SUB = 0;
    REG_BG3PD_SUB = 256;
    REG_BG3X_SUB = 0;
    REG_BG3Y_SUB = 256*36;

    // Display the Menu for the Sub screen
	swiCopy(MenuTactileTiles, BG_TILE_RAM_SUB(1), MenuTactileTilesLen/2);
	swiCopy(MenuTactileMap, bg0Map_SUB, MenuTactileMapLen/2);
	swiCopy(MenuTactilePal, BG_PALETTE_SUB, MenuTactilePalLen/2);
}
