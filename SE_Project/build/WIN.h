
//{{BLOCK(WIN)

//======================================================================
//
//	WIN, 256x48@8, 
//	+ palette 256 entries, not compressed
//	+ 26 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x6 
//	Total size: 512 + 1664 + 384 = 2560
//
//	Time-stamp: 2018-01-04, 10:51:39
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WIN_H
#define GRIT_WIN_H

#define WINTilesLen 1664
extern const unsigned int WINTiles[416];

#define WINMapLen 384
extern const unsigned short WINMap[192];

#define WINPalLen 512
extern const unsigned short WINPal[256];

#endif // GRIT_WIN_H

//}}BLOCK(WIN)
