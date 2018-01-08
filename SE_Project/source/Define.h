// File containing all the definitions and libraries and some basic functions that are needed in most of the files.
#ifndef Global
	#define Global

	#include <time.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <nds/arm9/sound.h>		// sound functions
	#include <maxmod9.h> //sound
	#include "soundbank.h"
	#include "soundbank_bin.h"
	#include <nds.h>

	#define n_elems(x) sizeof(x)/sizeof(x[0])
	#define TILE_PAL(n) ((n) << 12)

	#define PI 3.14159265

	#define RED ARGB16(1,31,0,0)
	#define GREEN ARGB16(1,0,31,0)
	#define BLUE ARGB16(1,0,0,31)
	#define WHITE ARGB16(1,31,31,31)
	#define BLACK ARGB16(1,0,0,0)

	typedef enum status{
		STOP=0,
		START=1,
		USER_TURN=2,
		OPPONENT_TURN=3,
		RESULTS=4,
		LOBBY=5,
		MULTIPLAYER_TURN=6,
		NEXT=7,
		PAUSE=8,
	}status;

	typedef enum move{
			ROCK,
			SCISSORS,
			PAPER,
			ERROR,
			LOSE,
	}move;

	typedef enum mode{
		SINGLE,
		MULTI,
	}mode;

#endif
