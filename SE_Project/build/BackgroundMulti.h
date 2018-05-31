
//{{BLOCK(BackgroundMulti)

//======================================================================
//
//	BackgroundMulti, 256x512@8, 
//	+ palette 256 entries, not compressed
//	+ 840 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x64 
//	Total size: 512 + 53760 + 4096 = 58368
//
//	Time-stamp: 2018-05-31, 15:20:57
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUNDMULTI_H
#define GRIT_BACKGROUNDMULTI_H

#define BackgroundMultiTilesLen 53760
extern const unsigned int BackgroundMultiTiles[13440];

#define BackgroundMultiMapLen 4096
extern const unsigned short BackgroundMultiMap[2048];

#define BackgroundMultiPalLen 512
extern const unsigned short BackgroundMultiPal[256];

#endif // GRIT_BACKGROUNDMULTI_H

//}}BLOCK(BackgroundMulti)
