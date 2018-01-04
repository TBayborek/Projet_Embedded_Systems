
//{{BLOCK(MenuInstruction)

//======================================================================
//
//	MenuInstruction, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 220 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 14080 + 1536 = 16128
//
//	Time-stamp: 2018-01-04, 21:53:45
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MENUINSTRUCTION_H
#define GRIT_MENUINSTRUCTION_H

#define MenuInstructionTilesLen 14080
extern const unsigned int MenuInstructionTiles[3520];

#define MenuInstructionMapLen 1536
extern const unsigned short MenuInstructionMap[768];

#define MenuInstructionPalLen 512
extern const unsigned short MenuInstructionPal[256];

#endif // GRIT_MENUINSTRUCTION_H

//}}BLOCK(MenuInstruction)
