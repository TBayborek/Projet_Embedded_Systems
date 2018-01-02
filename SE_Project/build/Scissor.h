
//{{BLOCK(Scissor)

//======================================================================
//
//	Scissor, 256x328@8, 
//	+ palette 256 entries, not compressed
//	+ 200 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x41 
//	Total size: 512 + 12800 + 2624 = 15936
//
//	Time-stamp: 2018-01-02, 18:08:16
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SCISSOR_H
#define GRIT_SCISSOR_H

#define ScissorTilesLen 12800
extern const unsigned int ScissorTiles[3200];

#define ScissorMapLen 2624
extern const unsigned short ScissorMap[1312];

#define ScissorPalLen 512
extern const unsigned short ScissorPal[256];

#endif // GRIT_SCISSOR_H

//}}BLOCK(Scissor)
