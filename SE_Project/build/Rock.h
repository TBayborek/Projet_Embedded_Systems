
//{{BLOCK(Rock)

//======================================================================
//
//	Rock, 256x320@8, 
//	+ palette 256 entries, not compressed
//	+ 165 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x40 
//	Total size: 512 + 10560 + 2560 = 13632
//
//	Time-stamp: 2018-05-31, 15:21:00
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ROCK_H
#define GRIT_ROCK_H

#define RockTilesLen 10560
extern const unsigned int RockTiles[2640];

#define RockMapLen 2560
extern const unsigned short RockMap[1280];

#define RockPalLen 512
extern const unsigned short RockPal[256];

#endif // GRIT_ROCK_H

//}}BLOCK(Rock)
