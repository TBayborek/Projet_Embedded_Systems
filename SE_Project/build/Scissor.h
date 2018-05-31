
//{{BLOCK(Scissor)

//======================================================================
//
//	Scissor, 256x320@8, 
//	+ palette 256 entries, not compressed
//	+ 177 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x40 
//	Total size: 512 + 11328 + 2560 = 14400
//
//	Time-stamp: 2018-05-31, 15:21:00
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SCISSOR_H
#define GRIT_SCISSOR_H

#define ScissorTilesLen 11328
extern const unsigned int ScissorTiles[2832];

#define ScissorMapLen 2560
extern const unsigned short ScissorMap[1280];

#define ScissorPalLen 512
extern const unsigned short ScissorPal[256];

#endif // GRIT_SCISSOR_H

//}}BLOCK(Scissor)
