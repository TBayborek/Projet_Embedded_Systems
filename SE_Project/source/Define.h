#ifndef Global
	#define Global

	#include <time.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <nds/arm9/sound.h>		// sound functions
	#include <nds.h>

	#define n_elems(x) sizeof(x)/sizeof(x[0])

	#define PI 3.14159265

	#define RED ARGB16(1,31,0,0)
	#define GREEN ARGB16(1,0,31,0)
	#define BLUE ARGB16(1,0,0,31)
	#define YELLOW ARGB16(1,31,31,0)
	#define ORANGE ARGB16(1,31,15,0)
	#define CYAN ARGB16(1,0,31,31)

	int ticks;

	typedef enum status{
		STOP,
		START,
		USER_TURN,
		OPPONENT_TURN,
		RESULTS,
		NEXT,
	}status;

	typedef enum move{
			ROCK,
			SCISSORS,
			PAPER,
			ERROR,
	}move;

#endif
