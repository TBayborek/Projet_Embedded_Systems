
@{{BLOCK(YourChoice)

@=======================================================================
@
@	YourChoice, 256x32@8, 
@	+ palette 256 entries, not compressed
@	+ 22 tiles (t|f reduced) not compressed
@	+ regular map (flat), not compressed, 32x4 
@	Total size: 512 + 1408 + 256 = 2176
@
@	Time-stamp: 2018-01-05, 11:24:42
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global YourChoiceTiles		@ 1408 unsigned chars
YourChoiceTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D
	.word 0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D
	.word 0x2D2D2D2D,0x002D2D2D,0x2D2D2D2D,0x002D2D2D,0x2D2D2D2D,0x002D2D2D,0x2D2D2D2D,0x002D2D2D
	.word 0x2D2D2D2D,0x002D2D2D,0x2D2D2D2D,0x002D2D2D,0x2D2D2D2D,0x002D2D2D,0x2D2D2D2D,0x002D2D2D
	.word 0x2D2D2D2D,0x832D2D2D,0x2D2D2D2D,0x5C2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D
	.word 0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D

	.word 0x2D2D430B,0x43105E2D,0x2D2D4403,0x2D6E6971,0x2D8E6057,0x2D491A21,0x22585F2D,0x132D8703
	.word 0x03031E2D,0x034D2D72,0x12482D2D,0x2F112D2E,0x56612D2D,0x5A6C2D43,0x567D2D2D,0x15862D43
	.word 0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D545033,0x2D823C2D,0x45033503,0x431A112D
	.word 0x036A2D62,0x435B3A62,0x652D2D2E,0x435B3A28,0x5F2D2D49,0x43566C28,0x033F2D8B,0x4B0D6862
	.word 0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x3C6D4A2D,0x2D6B333E,0x3A42012D,0x30600303
	.word 0x684F392D,0x2D703703,0x3A4F7B2D,0x2D2D2E1A,0x3A4F392D,0x2D2D435B,0x3A260674,0x2D2D435B
	.word 0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D3E7C8D,0x242D2D2D,0x02251503
	.word 0x2F762D2D,0x26212D7F,0x427B2D2D,0x2D2D2D2D,0x6E732D2D,0x291F2D2D,0x60312D2D,0x6E652D4B

	.word 0x2D2D8C64,0x2D2D2D2D,0x2D2E1A11,0x2D2D2D2D,0x500F566C,0x2D2D2D84,0x03030368,0x132D8103
	.word 0x2D022568,0x034D0A8F,0x2D437E3A,0x2F637E61,0x2D435B3A,0x5A5C567D,0x2D435B3A,0x150C567D
	.word 0x2D2D2D2D,0x2D29642D,0x2D2D2D2D,0x2E1A112D,0x2D545033,0x2D534A2D,0x45033503,0x2E1A112D
	.word 0x036A2D62,0x0C5B3A62,0x652D2D2E,0x5C5B3A28,0x5F2D2D49,0x5C5B3A28,0x033F2D8B,0x465B3A62
	.word 0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x84501C2D,0x232D2D2D,0x0335031B,0x030E2D17
	.word 0x312D7515,0x492F2B2F,0x2D2D7F05,0x1D03612D,0x2D2D0960,0x19522778,0x382D072C,0x4B60085A
	.word 0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D3E40,0x2D2D6D79,0x2D8A034E,0x2D2D423D
	.word 0x2E5B762D,0x2D2D531C,0x3225471D,0x2D2D2D2D,0x2E4C1434,0x2D2D2D2D,0x492F3B2D,0x2D2D5918

	.word 0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x89802D2D,0x412D2D43,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x67030303,0x037A2D2D,0x2D432A2D,0x702D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x3A6F1603,0x2D2D437E,0x2D2D2D55,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x662D2D2D,0x88360303,0x2D2D2D2D,0x2D2D703C,0x2D2D2D2D,0x2D2D2D2D,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x2D437E3A,0x41435676,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x67030303,0x437E3A2D,0x2D432A2D,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x25031577,0x03852D20,0x43702D2D,0x3C2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x2D516003,0x2D2D045D,0x2D2D2D70,0x2D2D2D2D,0x2D2D2D2D,0x2D2D2D2D,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x2D2D2D2D,0x002D2D2D,0x2D2D2D2D,0x002D2D2D,0x2D2D2D2D,0x002D2D2D,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global YourChoiceMap		@ 256 unsigned chars
YourChoiceMap:
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0003,0x0004,0x0005,0x0006,0x0007
	.hword 0x0008,0x0009,0x000A,0x000B,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002
	.hword 0x000C,0x000C,0x000C,0x000C,0x000C,0x000C,0x000C,0x000C
	.hword 0x000C,0x000C,0x000C,0x000C,0x000D,0x000E,0x000F,0x0010
	.hword 0x0011,0x0012,0x0013,0x0014,0x000C,0x000C,0x000C,0x000C
	.hword 0x000C,0x000C,0x000C,0x000C,0x000C,0x000C,0x000C,0x0015

	.section .rodata
	.align	2
	.global YourChoicePal		@ 512 unsigned chars
YourChoicePal:
	.hword 0x0000,0x1A39,0x7B96,0x18C6,0x6626,0x30C6,0x18CE,0x6ED0
	.hword 0x4319,0x7FFA,0x61C6,0x6B17,0x63BE,0x24C6,0x1973,0x77DD
	.hword 0x66F6,0x473E,0x4506,0x2E38,0x675B,0x18C8,0x25CE,0x6AAE
	.hword 0x5B1B,0x739B,0x44C6,0x3299,0x73BE,0x2529,0x577E,0x679E
	.hword 0x7734,0x19D6,0x4B3B,0x6B7C,0x1931,0x20C6,0x6649,0x2657
	.hword 0x7731,0x6F38,0x7BBE,0x3AB8,0x18C9,0x7FFF,0x7FFD,0x40C6
	.hword 0x7FDA,0x431D,0x7FD8,0x6F9E,0x6F7B,0x1906,0x4126,0x7775
	.hword 0x32BA,0x265A,0x4B5E,0x2218,0x7BDF,0x18D2,0x7FDD,0x471B

	.hword 0x6F59,0x4F1C,0x6606,0x7FFE,0x72F0,0x622B,0x67DE,0x1909
	.hword 0x2238,0x7FFC,0x77DF,0x7B98,0x6718,0x5FBF,0x1908,0x6628
	.hword 0x6B3A,0x7B76,0x4926,0x7BBC,0x779B,0x7FDE,0x4D06,0x2639
	.hword 0x5E06,0x7758,0x38C6,0x48C6,0x4B3D,0x1975,0x677D,0x18D0
	.hword 0x2CC6,0x2E7A,0x7B75,0x473C,0x6FBF,0x1912,0x3238,0x6EF1
	.hword 0x4F5E,0x18CB,0x5B7E,0x777B,0x4B3E,0x7BDD,0x6206,0x664B
	.hword 0x7BDE,0x67DF,0x6EAE,0x2259,0x67BF,0x7754,0x32BB,0x533D
	.hword 0x6719,0x77BE,0x1993,0x2659,0x6F5A,0x267A,0x4906,0x7FFB

	.hword 0x2E9A,0x7310,0x7BBD,0x5F1B,0x7B9B,0x3258,0x63BF,0x7F96
	.hword 0x7FDB,0x4D26,0x7755,0x6EF0,0x6F17,0x6F7C,0x7FD9,0x2239
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

@}}BLOCK(YourChoice)
