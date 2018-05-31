
//{{BLOCK(MenuInstruction)

//======================================================================
//
//	MenuInstruction, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 221 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 14144 + 1536 = 16192
//
//	Time-stamp: 2018-05-31, 15:20:59
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MENUINSTRUCTION_H
#define GRIT_MENUINSTRUCTION_H

#define MenuInstructionTilesLen 14144
extern const unsigned int MenuInstructionTiles[3536];

#define MenuInstructionMapLen 1536
extern const unsigned short MenuInstructionMap[768];

#define MenuInstructionPalLen 512
extern const unsigned short MenuInstructionPal[256];

#endif // GRIT_MENUINSTRUCTION_H

//}}BLOCK(MenuInstruction)
