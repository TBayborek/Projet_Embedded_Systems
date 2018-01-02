
//{{BLOCK(Background)

//======================================================================
//
//	Background, 256x448@8, 
//	+ palette 256 entries, not compressed
//	+ 812 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x56 
//	Total size: 512 + 51968 + 3584 = 56064
//
//	Time-stamp: 2018-01-02, 15:54:19
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUND_H
#define GRIT_BACKGROUND_H

#define BackgroundTilesLen 51968
extern const unsigned int BackgroundTiles[12992];

#define BackgroundMapLen 3584
extern const unsigned short BackgroundMap[1792];

#define BackgroundPalLen 512
extern const unsigned short BackgroundPal[256];

#endif // GRIT_BACKGROUND_H

//}}BLOCK(Background)
