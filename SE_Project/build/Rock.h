
//{{BLOCK(Rock)

//======================================================================
//
//	Rock, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 100 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 6400 + 1536 = 8448
//
//	Time-stamp: 2018-01-01, 16:00:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ROCK_H
#define GRIT_ROCK_H

#define RockTilesLen 6400
extern const unsigned int RockTiles[1600];

#define RockMapLen 1536
extern const unsigned short RockMap[768];

#define RockPalLen 512
extern const unsigned short RockPal[256];

#endif // GRIT_ROCK_H

//}}BLOCK(Rock)
