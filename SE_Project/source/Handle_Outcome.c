#include "Handle_Outcome.h"
#define TILE_PAL(n) ((n) << 12)

void Win_Round(){
	/*
	int c;
	for (c=0;c<256;c++){
		BG_PALETTE_SUB[c] = GREEN;
	}
	*/
	int row, col;
	u16* bg1Map = (u16*)BG_MAP_RAM_SUB(25);
	int rowEnd=(WINMapLen/2)/32; //nb of rows in the WIN picture


	//swiCopy(PaperTiles,BG_TILE_RAM_SUB(0),PaperTilesLen/2);
	//swiCopy(PaperPal,BG_PALETTE_SUB,PaperPalLen/2);
/*
	//inversed loop to draw the picture at the end
	for(row=23;row>=rowEnd;row--){
		for(col=31;col>=0;col--){
			bg1Map[row*32+col] = WINMap[(row-(24-rowEnd))*32+col];


		}
	}
	*/
	for(row=0;row<6;row++){
		for(col=0;col<32;col++){
			bg1Map[(row+25-rowEnd)*32+col] = bg1Map[(row+24)*32+col];


		}
	}






	Game_Status = NEXT;
}

void Loose_Round(int raison){
	if(raison==0){
		int row, col;
		u16* bg1Map = (u16*)BG_MAP_RAM_SUB(25);
		int rowEnd=(WINMapLen/2)/32; //nb of rows in the WIN picture

		/*
		int c;
		for (c=0;c<256;c++){
			BG_PALETTE_SUB[c] = RED;
		}
		*/
		for(row=0;row<6;row++){
			for(col=0;col<32;col++){
				bg1Map[(row+25-rowEnd)*32+col] = bg1Map[(row+30)*32+col];


			}
		}
	}



	Game_Status = NEXT;
}

void Draw_Round(){
	int row, col;
	u16* bg1Map = (u16*)BG_MAP_RAM_SUB(25);
	int rowEnd=(WINMapLen/2)/32; //nb of rows in the WIN picture
	/*
	int c;
	for (c=0;c<256;c++){
		BG_PALETTE_SUB[c] = ORANGE;
	}
	*/
	for(row=0;row<6;row++){
		for(col=0;col<32;col++){
			bg1Map[(row+25-rowEnd)*32+col] = bg1Map[(row+36)*32+col];


		}
	}

	Game_Status = NEXT;
}

