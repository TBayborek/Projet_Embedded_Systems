
//{{BLOCK(Paper)

//======================================================================
//
//	Paper, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 113 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 7232 + 1536 = 9280
//
//	Time-stamp: 2018-01-01, 16:00:49
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PAPER_H
#define GRIT_PAPER_H

#define PaperTilesLen 7232
extern const unsigned int PaperTiles[1808];

#define PaperMapLen 1536
extern const unsigned short PaperMap[768];

#define PaperPalLen 512
extern const unsigned short PaperPal[256];

#endif // GRIT_PAPER_H

//}}BLOCK(Paper)
