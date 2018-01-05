
//{{BLOCK(RSP)

//======================================================================
//
//	RSP, 128x192@8, 
//	+ palette 256 entries, not compressed
//	+ 178 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 16x24 
//	Total size: 512 + 11392 + 768 = 12672
//
//	Time-stamp: 2018-01-05, 11:24:42
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_RSP_H
#define GRIT_RSP_H

#define RSPTilesLen 11392
extern const unsigned int RSPTiles[2848];

#define RSPMapLen 768
extern const unsigned short RSPMap[384];

#define RSPPalLen 512
extern const unsigned short RSPPal[256];

#endif // GRIT_RSP_H

//}}BLOCK(RSP)
