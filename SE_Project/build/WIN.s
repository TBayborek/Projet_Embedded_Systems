
@{{BLOCK(WIN)

@=======================================================================
@
@	WIN, 256x48@8, 
@	+ palette 256 entries, not compressed
@	+ 26 tiles (t|f reduced) not compressed
@	+ regular map (flat), not compressed, 32x6 
@	Total size: 512 + 1664 + 384 = 2560
@
@	Time-stamp: 2018-01-02, 16:49:47
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global WINTiles		@ 1664 unsigned chars
WINTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x04040422,0x04040404,0x05050504,0x05050505,0x05050504,0x05050505,0x05050504,0x05050505
	.word 0x05050504,0x05050505,0x05050504,0x05050505,0x05050504,0x05050505,0x05050504,0x05050505
	.word 0x04040404,0x04040404,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x04040404,0x00220404,0x05050505,0x00040505,0x05050505,0x1D040505,0x05050505,0x1D040505
	.word 0x05050505,0x1D040505,0x05050505,0x1D040505,0x05050505,0x1D040505,0x05050505,0x1D040505

	.word 0x05050504,0x05050505,0x05050504,0x05050505,0x05050504,0x05050505,0x05050504,0x05050505
	.word 0x05050504,0x05050505,0x05050504,0x05050505,0x05050504,0x05050505,0x05050504,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x1D040505,0x05050505,0x1D040505,0x05050505,0x1D040505,0x05050505,0x1D040505
	.word 0x05050505,0x1D040505,0x05050505,0x1D040505,0x05050505,0x1D040505,0x05050505,0x1D040505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05054515,0x05050505,0x0505072A
	.word 0x05050505,0x05322105,0x05050505,0x16073A05,0x05050505,0x07290505,0x05050505,0x21050505

	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x10050505,0x05050505,0x07290505,0x07310505
	.word 0x16070905,0x0E071905,0x051A2105,0x05020605,0x0505070B,0x05240C05,0x05050F07,0x05332105
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05100D47,0x37050505,0x07070707,0x0705053C
	.word 0x132B0505,0x21050507,0x41050505,0x0C053F07,0x05050505,0x0C05352A,0x05050505,0x0C05464C
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05051005,0x05050524,0x05050727
	.word 0x05050524,0x05050727,0x05050524,0x05050727,0x05050524,0x05050727,0x05050524,0x05050727
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x26050505,0x05050505,0x071B0505,0x4F050505
	.word 0x07410505,0x06050542,0x06050505,0x07270525,0x29050505,0x324D051A,0x3A050505,0x2543051F

	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050510,0x05051005,0x05053E07,0x4D05074B
	.word 0x05051E07,0x1B053208,0x05051F14,0x1B053B2C,0x05440705,0x1B051807,0x4A252C05,0x1B050507
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x15050510,0x05050505,0x0C05051F,0x05050512
	.word 0x21050511,0x05054E07,0x21050511,0x05180707,0x0C050511,0x05304801,0x0C050511,0x3B073D24
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05053705,0x05050505,0x05050705,0x05050505
	.word 0x05050C05,0x05050505,0x05050C05,0x05050505,0x05050C05,0x05050505,0x05050C05,0x05050505
	.word 0x05050505,0x1B050505,0x05050505,0x1B050505,0x05050505,0x1B050505,0x05050505,0x1B050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505

	.word 0x05050511,0x053E0C05,0x05050511,0x05112A05,0x05050511,0x30072005,0x05050530,0x36200505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x0C05461C,0x09050505,0x21053E07,0x07490538,0x2905051A,0x2E070707,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050524,0x05050727,0x05050516,0x0505073A,0x39452F07,0x0505120C,0x07070734,0x05050512
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x18072307,0x05050505,0x05110A1C,0x05050505,0x05350740,0x05050505,0x05240727
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505

	.word 0x281A2D05,0x1B05051A,0x07072705,0x1B050516,0x07210505,0x1B050505,0x30170505,0x1B050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x0C050511,0x072D0524,0x0C050511,0x2C050524,0x0C050511,0x20050524,0x21050530,0x05050524
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05052123,0x05050505,0x05050707,0x05050505,0x05050707,0x05050505,0x0505071B,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050504,0x05050505,0x05050504,0x05050505,0x05050504,0x05050505,0x05050504,0x05050505
	.word 0x05050504,0x05050505,0x05050504,0x05050505,0x04040422,0x04040404,0x1D1D0000,0x1D1D1D1D

	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505,0x05050505
	.word 0x05050505,0x05050505,0x05050505,0x05050505,0x04040404,0x04040404,0x1D1D1D1D,0x1D1D1D1D
	.word 0x05050505,0x1D040505,0x05050505,0x1D040505,0x05050505,0x1D040505,0x05050505,0x1D040505
	.word 0x05050505,0x1D040505,0x05050505,0x1D040505,0x04040404,0x1D220404,0x1D1D1D1D,0x031D1D1D

	.section .rodata
	.align	2
	.global WINMap		@ 384 unsigned chars
WINMap:
	.hword 0x0001,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002
	.hword 0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002
	.hword 0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002
	.hword 0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0003
	.hword 0x0004,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005
	.hword 0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005
	.hword 0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005
	.hword 0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0006

	.hword 0x0004,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005
	.hword 0x0005,0x0005,0x0005,0x0005,0x0007,0x0008,0x0009,0x000A
	.hword 0x000B,0x000C,0x000D,0x000E,0x0005,0x0005,0x0005,0x0005
	.hword 0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0006
	.hword 0x0004,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005
	.hword 0x0005,0x0005,0x0005,0x0005,0x000F,0x0010,0x0011,0x0012
	.hword 0x0013,0x0014,0x0015,0x0016,0x0005,0x0005,0x0005,0x0005
	.hword 0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0006

	.hword 0x0004,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005
	.hword 0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005
	.hword 0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005
	.hword 0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0006
	.hword 0x0017,0x0018,0x0018,0x0018,0x0018,0x0018,0x0018,0x0018
	.hword 0x0018,0x0018,0x0018,0x0018,0x0018,0x0018,0x0018,0x0018
	.hword 0x0018,0x0018,0x0018,0x0018,0x0018,0x0018,0x0018,0x0018
	.hword 0x0018,0x0018,0x0018,0x0018,0x0018,0x0018,0x0018,0x0019

	.section .rodata
	.align	2
	.global WINPal		@ 512 unsigned chars
WINPal:
	.hword 0x0000,0x228B,0x21A6,0x2AB5,0x35AD,0x2732,0x18C9,0x18C6
	.hword 0x19AE,0x1E90,0x1906,0x1989,0x18C7,0x226D,0x2209,0x26AC
	.hword 0x26CF,0x1CE6,0x1D46,0x18E9,0x1A2D,0x22D0,0x266A,0x194C
	.hword 0x26ED,0x1A50,0x2186,0x1A0F,0x18EB,0x32F3,0x21C7,0x1CC6
	.hword 0x22D1,0x18C8,0x35CE,0x22AD,0x26AB,0x2649,0x26EF,0x1EB1
	.hword 0x19CD,0x198D,0x190B,0x22F1,0x18CA,0x19CE,0x21E9,0x224B
	.hword 0x1D06,0x1A0E,0x2146,0x268A,0x198B,0x21C6,0x1909,0x26D0
	.hword 0x26CE,0x1E6F,0x1E70,0x2628,0x26EE,0x1ED2,0x268B,0x2669

	.hword 0x19EE,0x22F2,0x26CC,0x18CB,0x2AED,0x26F0,0x21E7,0x226E
	.hword 0x18EA,0x1E2E,0x1E91,0x1A70,0x190C,0x19CF,0x2229,0x194D
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(WIN)
