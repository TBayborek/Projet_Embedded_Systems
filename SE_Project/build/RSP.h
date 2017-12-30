
//{{BLOCK(RSP)

//======================================================================
//
//	RSP, 128x192@8, 
//	+ palette 128 entries, not compressed
//	+ 178 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 16x24 
//	Total size: 256 + 11392 + 768 = 12416
//
//	Time-stamp: 2017-12-28, 17:57:03
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

#define RSPPalLen 256
extern const unsigned short RSPPal[128];

#endif // GRIT_RSP_H

//}}BLOCK(RSP)
