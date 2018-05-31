
//{{BLOCK(Pause)

//======================================================================
//
//	Pause, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 103 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 6592 + 1536 = 8640
//
//	Time-stamp: 2018-05-31, 15:21:00
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PAUSE_H
#define GRIT_PAUSE_H

#define PauseTilesLen 6592
extern const unsigned int PauseTiles[1648];

#define PauseMapLen 1536
extern const unsigned short PauseMap[768];

#define PausePalLen 512
extern const unsigned short PausePal[256];

#endif // GRIT_PAUSE_H

//}}BLOCK(Pause)
