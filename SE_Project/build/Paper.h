
//{{BLOCK(Paper)

//======================================================================
//
//	Paper, 256x320@8, 
//	+ palette 256 entries, not compressed
//	+ 170 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x40 
//	Total size: 512 + 10880 + 2560 = 13952
//
//	Time-stamp: 2018-05-31, 15:21:00
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PAPER_H
#define GRIT_PAPER_H

#define PaperTilesLen 10880
extern const unsigned int PaperTiles[2720];

#define PaperMapLen 2560
extern const unsigned short PaperMap[1280];

#define PaperPalLen 512
extern const unsigned short PaperPal[256];

#endif // GRIT_PAPER_H

//}}BLOCK(Paper)
