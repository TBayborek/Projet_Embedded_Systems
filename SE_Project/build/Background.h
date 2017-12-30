
//{{BLOCK(Background)

//======================================================================
//
//	Background, 256x192@8, 
//	+ palette 128 entries, not compressed
//	+ 768 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 256 + 49152 + 1536 = 50944
//
//	Time-stamp: 2017-12-28, 17:57:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUND_H
#define GRIT_BACKGROUND_H

#define BackgroundTilesLen 49152
extern const unsigned int BackgroundTiles[12288];

#define BackgroundMapLen 1536
extern const unsigned short BackgroundMap[768];

#define BackgroundPalLen 256
extern const unsigned short BackgroundPal[128];

#endif // GRIT_BACKGROUND_H

//}}BLOCK(Background)
