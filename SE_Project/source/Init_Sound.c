#include "Init_Sound.h"

void Init_Sound() {

	mmInitDefaultMem((mm_addr)soundbank_bin);


	mmLoadEffect(SFX_WINSOUND);
	mmLoadEffect(SFX_BUZZER);
	mmLoadEffect(SFX_LOSINGHORNSOUNDEFFECT);
	mmLoadEffect(SFX_BOING_X);




}
