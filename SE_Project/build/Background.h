
//{{BLOCK(Background)

//======================================================================
//
//	Background, 256x512@8, 
//	+ palette 256 entries, not compressed
//	+ 807 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x64 
//	Total size: 512 + 51648 + 4096 = 56256
//
//	Time-stamp: 2018-01-02, 16:49:45
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUND_H
#define GRIT_BACKGROUND_H

#define BackgroundTilesLen 51648
extern const unsigned int BackgroundTiles[12912];

#define BackgroundMapLen 4096
extern const unsigned short BackgroundMap[2048];

#define BackgroundPalLen 512
extern const unsigned short BackgroundPal[256];

#endif // GRIT_BACKGROUND_H

//}}BLOCK(Background)
