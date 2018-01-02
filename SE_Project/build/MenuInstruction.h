
//{{BLOCK(MenuInstruction)

//======================================================================
//
//	MenuInstruction, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 145 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 9280 + 1536 = 11328
//
//	Time-stamp: 2018-01-01, 14:37:52
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MENUINSTRUCTION_H
#define GRIT_MENUINSTRUCTION_H

#define MenuInstructionTilesLen 9280
extern const unsigned int MenuInstructionTiles[2320];

#define MenuInstructionMapLen 1536
extern const unsigned short MenuInstructionMap[768];

#define MenuInstructionPalLen 512
extern const unsigned short MenuInstructionPal[256];

#endif // GRIT_MENUINSTRUCTION_H

//}}BLOCK(MenuInstruction)
