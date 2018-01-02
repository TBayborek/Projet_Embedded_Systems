
//{{BLOCK(Scissor)

//======================================================================
//
//	Scissor, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 114 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 7296 + 1536 = 9344
//
//	Time-stamp: 2018-01-01, 16:00:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SCISSOR_H
#define GRIT_SCISSOR_H

#define ScissorTilesLen 7296
extern const unsigned int ScissorTiles[1824];

#define ScissorMapLen 1536
extern const unsigned short ScissorMap[768];

#define ScissorPalLen 512
extern const unsigned short ScissorPal[256];

#endif // GRIT_SCISSOR_H

//}}BLOCK(Scissor)
