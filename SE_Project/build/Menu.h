
//{{BLOCK(Menu)

//======================================================================
//
//	Menu, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 262 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 16768 + 1536 = 18816
//
//	Time-stamp: 2018-01-01, 14:37:53
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MENU_H
#define GRIT_MENU_H

#define MenuTilesLen 16768
extern const unsigned int MenuTiles[4192];

#define MenuMapLen 1536
extern const unsigned short MenuMap[768];

#define MenuPalLen 512
extern const unsigned short MenuPal[256];

#endif // GRIT_MENU_H

//}}BLOCK(Menu)
