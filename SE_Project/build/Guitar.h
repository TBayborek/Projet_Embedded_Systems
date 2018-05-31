
//{{BLOCK(Guitar)

//======================================================================
//
//	Guitar, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 144 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 9216 + 1536 = 11264
//
//	Time-stamp: 2018-05-31, 15:20:58
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GUITAR_H
#define GRIT_GUITAR_H

#define GuitarTilesLen 9216
extern const unsigned int GuitarTiles[2304];

#define GuitarMapLen 1536
extern const unsigned short GuitarMap[768];

#define GuitarPalLen 512
extern const unsigned short GuitarPal[256];

#endif // GRIT_GUITAR_H

//}}BLOCK(Guitar)
