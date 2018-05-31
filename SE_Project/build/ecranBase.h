
//{{BLOCK(ecranBase)

//======================================================================
//
//	ecranBase, 256x320@8, 
//	+ palette 256 entries, not compressed
//	+ 268 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x40 
//	Total size: 512 + 17152 + 2560 = 20224
//
//	Time-stamp: 2018-05-31, 15:20:58
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ECRANBASE_H
#define GRIT_ECRANBASE_H

#define ecranBaseTilesLen 17152
extern const unsigned int ecranBaseTiles[4288];

#define ecranBaseMapLen 2560
extern const unsigned short ecranBaseMap[1280];

#define ecranBasePalLen 512
extern const unsigned short ecranBasePal[256];

#endif // GRIT_ECRANBASE_H

//}}BLOCK(ecranBase)
