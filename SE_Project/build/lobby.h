
//{{BLOCK(lobby)

//======================================================================
//
//	lobby, 256x240@8, 
//	+ palette 256 entries, not compressed
//	+ 409 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x30 
//	Total size: 512 + 26176 + 1920 = 28608
//
//	Time-stamp: 2018-05-31, 15:20:59
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LOBBY_H
#define GRIT_LOBBY_H

#define lobbyTilesLen 26176
extern const unsigned int lobbyTiles[6544];

#define lobbyMapLen 1920
extern const unsigned short lobbyMap[960];

#define lobbyPalLen 512
extern const unsigned short lobbyPal[256];

#endif // GRIT_LOBBY_H

//}}BLOCK(lobby)
