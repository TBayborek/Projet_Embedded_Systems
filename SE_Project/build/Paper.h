
//{{BLOCK(Paper)

//======================================================================
//
//	Paper, 256x336@8, 
//	+ palette 256 entries, not compressed
//	+ 191 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x42 
//	Total size: 512 + 12224 + 2688 = 15424
//
//	Time-stamp: 2018-01-04, 21:53:46
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PAPER_H
#define GRIT_PAPER_H

#define PaperTilesLen 12224
extern const unsigned int PaperTiles[3056];

#define PaperMapLen 2688
extern const unsigned short PaperMap[1344];

#define PaperPalLen 512
extern const unsigned short PaperPal[256];

#endif // GRIT_PAPER_H

//}}BLOCK(Paper)
