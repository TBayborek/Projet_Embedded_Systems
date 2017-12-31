
//{{BLOCK(ecranBase)

//======================================================================
//
//	ecranBase, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 70 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 4480 + 1536 = 6528
//
//	Time-stamp: 2017-12-31, 14:26:07
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ECRANBASE_H
#define GRIT_ECRANBASE_H

#define ecranBaseTilesLen 4480
extern const unsigned int ecranBaseTiles[1120];

#define ecranBaseMapLen 1536
extern const unsigned short ecranBaseMap[768];

#define ecranBasePalLen 512
extern const unsigned short ecranBasePal[256];

#endif // GRIT_ECRANBASE_H

//}}BLOCK(ecranBase)
