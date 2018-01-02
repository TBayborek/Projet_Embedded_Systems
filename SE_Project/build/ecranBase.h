
//{{BLOCK(ecranBase)

//======================================================================
//
//	ecranBase, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 163 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 512 + 10432 + 2048 = 12992
//
//	Time-stamp: 2018-01-02, 15:53:27
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ECRANBASE_H
#define GRIT_ECRANBASE_H

#define ecranBaseTilesLen 10432
extern const unsigned int ecranBaseTiles[2608];

#define ecranBaseMapLen 2048
extern const unsigned short ecranBaseMap[1024];

#define ecranBasePalLen 512
extern const unsigned short ecranBasePal[256];

#endif // GRIT_ECRANBASE_H

//}}BLOCK(ecranBase)
