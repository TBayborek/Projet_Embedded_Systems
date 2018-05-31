
//{{BLOCK(MenuDescription)

//======================================================================
//
//	MenuDescription, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 405 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 25920 + 1536 = 27968
//
//	Time-stamp: 2018-05-31, 15:20:59
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MENUDESCRIPTION_H
#define GRIT_MENUDESCRIPTION_H

#define MenuDescriptionTilesLen 25920
extern const unsigned int MenuDescriptionTiles[6480];

#define MenuDescriptionMapLen 1536
extern const unsigned short MenuDescriptionMap[768];

#define MenuDescriptionPalLen 512
extern const unsigned short MenuDescriptionPal[256];

#endif // GRIT_MENUDESCRIPTION_H

//}}BLOCK(MenuDescription)
