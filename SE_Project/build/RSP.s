
@{{BLOCK(RSP)

@=======================================================================
@
@	RSP, 128x192@8, 
@	+ palette 256 entries, not compressed
@	+ 178 tiles (t|f reduced) not compressed
@	+ regular map (flat), not compressed, 16x24 
@	Total size: 512 + 11392 + 768 = 12672
@
@	Time-stamp: 2018-01-03, 17:13:56
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global RSPTiles		@ 11392 unsigned chars
RSPTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x35111111,0x11111111,0x39811111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x8C411111,0x8C9C8C8C,0x0037C999,0x00000000,0x00000000,0x00000000

	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111141,0x00001111,0x8CB13F0F,0x00000011,0x03000000,0x00000098
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0xB99975A0,0x00000000,0x00000000,0x00000000,0x09094D7F,0x598D0000,0x0C0C0C46
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0xA01BA399,0x1111358C,0x00000000,0x81301900,0x00000056,0x00000000,0x5A7C460C,0x00000028
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x1111A53F,0x11111111,0x9CC90000,0x11111111

	.word 0x11111111,0x00391111,0x11111111,0x0000B411,0xA3111111,0x4E000039,0x00521111,0x0CCE0000
	.word 0x00771111,0x0C0C8300,0x00391111,0x0C0C4600,0x0000A311,0x0C0C0C7D,0x0000B411,0x0C0C0C59
	.word 0x00000000,0xA2A26053,0x0C580B00,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x00004D60,0x0000C200,0x8A460C0C,0xC100006A,0x0C0C0C0C,0x6500290C,0x0C0C0C0C,0x004A0C0C
	.word 0x0C0C0C0C,0x005A0C0C,0x0C0C0C0C,0x00000C0C,0x0C0C0C0C,0xA200470C,0x0C0C0C0C,0x0C00580C
	.word 0x0C0C0C6F,0x0C0C0C0C,0x58460C0C,0x0C0C5812,0x00004E6E,0x5A000000,0x5A7F0000,0x0C0C0C0C
	.word 0x0C0C6800,0x0C0C0C0C,0x0C0C0C5A,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C

	.word 0x0C0C0C0C,0x0078460C,0x0C0C0C0C,0x460C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x00000000,0x111111A3,0x00000083,0x1111B100,0x0000290C,0x11490000,0x008E0C0C,0x35A70000
	.word 0x8E0C0C0C,0x0F000000,0x0C0C0C0C,0x0000005A,0x0C0C0C0C,0x0000800C,0x0C0C0C0C,0x006A0C0C
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x1111119C,0x11111111,0x111111A9,0x11111111,0x11114900,0x11111111,0x1111A700,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x35111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.word 0x56003711,0x0C0C0C0C,0x0B001941,0x0C0C0C0C,0x86001941,0x0C0C0C0C,0x80001E41,0x0C0C0C0C
	.word 0x4E00B411,0x0C0C0C0C,0x00006C11,0x0C0C0C46,0x00009911,0x0C0C0C62,0x00000011,0x0C0C0C4D
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0CA2470C,0x0C0C0C0C,0x0C470C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x00270C0C,0x0C0C0C0C,0x6B0C0C0C,0x0C0C0C0C,0x7C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C

	.word 0x11B10000,0x11111111,0x11190000,0x11111111,0xAC000000,0x113591AC,0x00000083,0x970F0000
	.word 0x8300008E,0x00004E54,0x6B007F0C,0x00540C0C,0x4D00600C,0x8A0C0C0C,0x0000540C,0x0C0C0C0C
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111135,0x11111111
	.word 0x1111990F,0x11111111,0x11B30000,0x11111111,0x98000000,0x11111141,0xAD00004D,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0xA4111111,0x11111111,0x00111111
	.word 0x11111111,0x00411111,0x11111111,0x00A01111,0x11111111,0x002E1111,0x11111111,0x002E1111
	.word 0x00000011,0x0C0C1200,0x108A00A9,0x0C0C7F00,0x0C0CCF00,0x0C86005A,0x0C0C6E00,0x6E008D0C
	.word 0x0C0C0C00,0x005A0C0C,0x0C0C0C74,0x8E0C0C0C,0x0C0C0C80,0x0C0C0C0C,0x0C0C0C29,0x0C0C0C0C

	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C46,0x0C0C0C0C,0x0C0C0C4E,0x0C0C0C0C,0x0C0C8A59,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C6E580C,0x0C0C0C0C,0x6A000010,0x0C0C0C0C,0x00000012,0x0C0C0C0C,0x00000047
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C7C,0x0C0C0C0C,0x0C0C8E00,0x0C0C0C0C,0x0C680000,0x0C0C0C0C
	.word 0x0000590C,0x0C0C0C0C,0x007F0C0C,0x0C0C0C0C,0x00600C0C,0x0C0C0C0C,0x00680C0C,0x0C0C0C0C
	.word 0x00540C0C,0x0C0C0C0C,0x006E0C0C,0x0C0C0C0C,0x007C0C0C,0x0C0C0C0C,0x4D590C0C,0x0C0C0C0C

	.word 0x0000005A,0x1111118C,0x00000046,0x1111111B,0x0000530C,0x1111119F,0x0000600C,0x111111A7
	.word 0x0000780C,0x11114137,0x00008A0C,0x11114139,0x00008A0C,0x11114100,0x00008E0C,0x11114100
	.word 0x11111111,0x00871111,0x11111111,0x00111111,0x11111111,0x1E111111,0x11111111,0x91161111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x0C0C0C86,0x0C0C0C0C,0x0C0C0CCE,0x0C0C0C0C,0x0C0C0C44,0x0C0C0C0C,0x0C0C0C00,0x0C0C0C0C
	.word 0x0C0CCA00,0x0C0C0C0C,0x0C0CB8B9,0x0C0C0C0C,0x0C7C003A,0x0C0C0C0C,0x0C5300A3,0x0C0C0C0C
	.word 0x0C0C0C0C,0x00008A0C,0x0C0C0C0C,0x00540C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x47580C0C,0x0C0C0C0C,0x00005A0C,0x0C0C2783,0x00005A0C,0x8A4D0000

	.word 0x4E000000,0x0C0C0C46,0x00000000,0x0C0C8E00,0x00000060,0x0CA20000,0x004D100C,0x00000000
	.word 0x590C0C0C,0x0000006B,0x0C0C0C0C,0x4D8A0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C46,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C54,0x0C0C0C0C
	.word 0x0C7C5600,0x0C0C0C0C,0x4E000000,0x0C0C0C6E,0x004E8A47,0x0C120000,0x0C0C0C0C,0x0C8D866E
	.word 0x6B460C0C,0x0C0C0C0C,0x78470C0C,0x0C0C0C0C,0x8E470C0C,0x0C0C0C0C,0x0C470C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x00008E0C,0x11114100,0x00008A0C,0x11114139,0x00008A0C,0x11114119,0x0000780C,0x11111103
	.word 0x0000A20C,0x111111A9,0x00004E0C,0x11111136,0x0000560C,0x11114199,0x00000047,0x111111A0

	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x41111111,0x11111111,0x41111111
	.word 0x11111111,0x41111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x684E002F,0x0C0C0C0C,0x6B5400B0,0x0C0C0C8E,0x0C8600A3,0x0C0C586B,0x0C4E0075,0x0C59540C
	.word 0x0C0000A0,0x0C0C0C0C,0x58000011,0x0C0C0C0C,0x93003711,0x0C0C0C0C,0x00009F11,0x0C0C0C0C
	.word 0x00530C0C,0x00000000,0x830C0C0C,0x00000000,0x0C0C0C0C,0x00004E8E,0x0C0C0C0C,0x8E470C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C46580C,0x0C0C0C0C,0x0000004D,0x780B6056
	.word 0x47546000,0x0C0C0C0C,0x00000000,0x47587853,0x00000000,0x00000000,0x5360A278,0x53535353
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x29292929,0x4D6B8029

	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x5A68836A,0x0C0C0C10,0x534E4D4D,0x0C0C0C8D
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x470B270C,0x460C0C0C,0x0C7F0000,0x290C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x790C0C0C,0x0C0C0C0C,0x2C0C0C0C,0x0C0C0C8E,0x000C0C0C,0x0C0C0C58,0x00540C0C
	.word 0x19000058,0x1111118C,0x95000068,0x11111111,0xB900004E,0x11111111,0xB5000000,0x11111135
	.word 0x113F0000,0x11111135,0x41B10000,0x11111111,0x35B50000,0x11111111,0x1111C000,0x11111111
	.word 0x00005211,0x0C0C0C78,0x00394111,0x0C0C5900,0x00851111,0x0C0C4D00,0x9D111111,0x0C830000
	.word 0xA5111111,0x83000000,0x11111111,0x000000AE,0x11111111,0x00009F35,0x11111111,0x00AE1111

	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C6E6A,0x0C0C0C0C,0x58600000,0x0C0C0C0C,0x00000000,0x0C58786A
	.word 0x00000078,0x00000000,0x0000560C,0x00000000,0x004E0C0C,0x00000000,0x7C0C0C0C,0x0C47276E
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x00000000,0x00000000,0x00000000,0x0C8D5300,0x588AA256,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x4E12460C
	.word 0x0C0C6E83,0x7F460C0C,0x0C0C0C0C,0x0B530C0C,0x0C0C0C0C,0x59008D0C,0x0C0C0C0C,0x0C780012
	.word 0x540C0C0C,0x5A290000,0x00780C0C,0x00000000,0x00004D27,0x99A1BD43,0x980F0000,0x11111111

	.word 0x0C0C0C0C,0x00000C0C,0x0C0C0C0C,0x0000800C,0x0C0C0C0C,0x19000054,0x040C0C0C,0xA00F0000
	.word 0x00000B8A,0x418CA700,0x37000000,0x11111199,0x119C81A3,0x11111111,0x11111111,0x11111111
	.word 0x11418100,0x11111111,0x111111A4,0x11111111,0x11111122,0x11111111,0x11111141,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x52111611,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x00000377,0x00000000,0x90811111,0x00000000,0x35111111,0x0003A4B9,0x11111111,0xAF111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.word 0x7C8E294E,0x0C0C0C0C,0x00000000,0x534D0000,0x00000000,0x00000000,0x000000A7,0x00000000
	.word 0x99521111,0x373FC09F,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x0C0C0C0C,0x460C0C0C,0x534E6B53,0x00002453,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x190F0F39,0xC777C003,0x11111111,0x22221111,0x41411111,0x41414141,0x11111111,0x11111111
	.word 0xA28D8E7C,0x0000004D,0x00000000,0x19000000,0x00000000,0x22A3A700,0x9B030000,0x3541118C
	.word 0x11111107,0x11111111,0x1111118C,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x119C9600,0x11111111,0x1141118B,0x11111111,0x11111141,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x97979777,0x00371111,0x00000000,0x00009711,0x5927137F,0x89001911,0x0C0C0C0C
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0xAE979797,0x11113598,0x00000000,0x41A40000,0x004D8D58,0x19000000,0x580C0C0C,0x00000053
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111181,0x11111111,0x1111A900,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0xB9111111,0x11111111,0x39111111,0x11111111,0x00111111
	.word 0x11111111,0x00111111,0x11111111,0x00111111,0x11111111,0x00111111,0x11111111,0x00111111

	.word 0x0C8300B4,0x0C0C0C0C,0x0C7C0000,0x0C0C0C0C,0x0C0C6900,0x0C0C0C0C,0x0C0C7D00,0x0C0C0C0C
	.word 0x0C0CBC00,0x0C0C0C0C,0x0C0C1200,0x0C0C0C0C,0x0C0C9400,0x0C0C0C0C,0x0C0C4D00,0x0C0C0C0C
	.word 0x0C0C0C0C,0x005CCA0C,0x0C0C0C0C,0x130C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x850F0000,0x11111135,0x00000000,0x11119B39,0x0000A246,0x813F0000,0x6A580C0C,0x00000000
	.word 0x0C0C0C0C,0x00000068,0x0C0C0C0C,0x004D270C,0x0C0C0C0C,0x120C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x1111A5A9,0x11111111
	.word 0xA0A40000,0x11111111,0x00000000,0x41987739,0x0000006A,0x00000000,0x0060580C,0x00000000

	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0xAEA4C219,0xACAEAEAE,0x00000000,0x00000000
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x81A08C11,0x0F3733A4,0x00000000,0x00000000,0x6A000000
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0xB1B98B98,0xAEAEAEA8,0x00000000,0x00000000,0x680BA24E,0x86686868
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x8BB9B1AE,0x11111111,0x00000000,0x11119B0F,0x0000004E,0x980F0000

	.word 0x11111111,0xA4111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x0C580000,0x0C0C0C0C,0x0C6A0090,0x0C0C0C0C,0x4F000035,0x0C0C0C0C,0x00008511,0x0C0C174D
	.word 0x00A11111,0x0C5A0000,0x99111111,0x4D00000F,0x11111111,0x00007749,0x11111111,0xB4351111
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C58,0x0C0C0C0C,0x0C125300,0x0C0C0C0C,0x6A000000,0x0C0C327E
	.word 0x0C0C0C0C,0x0056808E,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C

	.word 0x00000000,0x7F000000,0x58271017,0x0C0C47AB,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x4E7C0C0C,0x0C0C0C0C,0x5300780C
	.word 0x1D8286D3,0x0C0C0C59,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x590C0C0C,0x0C0C0C46,0x58788610,0x0C0C0C47,0x0C0C6E00,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x867C0C0C,0x00000000,0x0C0C0C0C,0x00005B0C,0x0C0C0C0C,0x7F590C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x11111197,0x11111111,0x11117700,0x11111111,0x11A80000,0x11111111,0xB9000056,0x11111111
	.word 0x00000046,0x114111A5,0x0000580C,0x418B1A0F,0x00860C0C,0x0F000000,0x000C0C0C,0x00006A00

	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11114111,0x11111111,0x114141B9,0x11111111,0x1135B400,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x8C111111,0x99A53511,0x003977A8,0x00000FB1,0x00000000
	.word 0x00009598,0x68250000,0x758C1111,0x00003730,0x11111111,0xA3351111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x00000000,0x00000000,0x00000000,0x6A7F7F7F
	.word 0x0C0C0C27,0x0C0C0C0C,0x726B0000,0x0C0C0C0C,0x000039C4,0x5E294D00,0x81111111,0x000039C4
	.word 0x11111111,0x0FB71111,0xA0111111,0x53003930,0x00000000,0x0C27BE00,0x588D1418,0x0C0C0C0C

	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C580B00,0x0C0C0C0C
	.word 0x00008300,0x0C0C5A4E,0x7C0C0C7C,0x56004D29,0x0C0C0C0C,0x6E0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C53004E,0x4E0C0C0C,0x0C0C0000,0x00680C0C,0x0C0C2700,0x0000460C,0x0C0C0CA2
	.word 0x00008A0C,0x0C0C0C47,0x4D008329,0x0C0C0C0C,0x6000000B,0x0C0C0C0C,0x86000046,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x270C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C470C,0x0C0C0C0C,0x0C0C6B46
	.word 0x0C0C0C0C,0x0C0C000C,0x0C0C0C6B,0x0C59000C,0x0C0C0078,0x0C590012,0x0C00000C,0x0C0C0053

	.word 0x290C0C0C,0x577C6B00,0x0C0C0C0C,0x0C0C0000,0x0C0C0C0C,0x0C5400A2,0x0C0C0C0C,0x0C0B008E
	.word 0x0C0C0C0C,0x0C4D0047,0x0C0C0C0C,0x0C00000C,0x0C0C0C0C,0x0C004E0C,0x0C0C0C0C,0x0C000B0C
	.word 0x41480000,0x11111111,0x9700004D,0x11111111,0x0000000C,0x1111413D,0x0000580C,0x111111A9
	.word 0x004E0C0C,0x11118C00,0x00BC0C0C,0x1111B100,0x000C0C0C,0x11119500,0x530C0C0C,0x11411900
	.word 0x11111111,0x95111111,0x11111111,0x00971111,0x11111111,0x0000A311,0x11111111,0x00001911
	.word 0x11111111,0x00000035,0x11111111,0x00000035,0x11111111,0x0000A911,0x11111111,0x00009711
	.word 0x00000000,0x1F2712A2,0x4C780000,0x0C0C0C0C,0x0C0C2300,0x0C0C0C0C,0x0C0C0C6B,0x0C0C0C0C
	.word 0x0C0C0C27,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C

	.word 0x474A4747,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x5380540C
	.word 0x0B000047,0x0C0C0C0C,0x83000046,0x0C0C0C0C,0x4D006A0C,0x0C0C0C0C,0x00004E0C,0x0C0C0C47
	.word 0x0000680C,0x0C0C0C54,0x0000100C,0x0C0C0C53,0x004E0C0C,0x0C0C1200,0x0000566A,0x0C460000
	.word 0x4D006E0C,0x0C0C4E00,0x00560C0C,0x0C0C5400,0x00540C0C,0x0C0C0C6A,0x000C0C0C,0x0C0C0C53
	.word 0x6B0C0C0C,0x0C0C5900,0x540C0C0C,0x0C0C8A00,0x460C0C0C,0x0C0C6000,0x0C0C0C0C,0x0C0C7F00

	.word 0x0C0C0C0C,0x0C000B0C,0x0C0C0C0C,0x0C000B0C,0x0C0C0C0C,0x0C564E0C,0x0C0C0C0C,0x0CA2000C
	.word 0x0C0C0C0C,0x0C5A0046,0x0C0C0C0C,0x0C460012,0x0C0C0C0C,0x0C0C4D53,0x270C0C0C,0x0C0C6E00
	.word 0xBE0C0C0C,0x119C0000,0xC60C0C0C,0x113D0000,0x680C0C0C,0x412E0000,0x150C0C0C,0x351B0000
	.word 0x6B0C0C0C,0x35D20000,0x5D0C0C0C,0x112E0000,0x4D0C0C0C,0x11A50000,0x0F0C0C0C,0x118C0000
	.word 0x11111111,0x0000A411,0x11111111,0x0000A911,0x11111111,0x00904911,0x11111111,0x90A01111
	.word 0x11111111,0xA0111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x0C0C0C47,0x0C0C0C0C,0x0C0C0C8E,0x0C0C0C0C,0x0C0C0C74,0x0C0C0C0C,0x0C0C8A00,0x0C0C0C0C
	.word 0x47800000,0x0C0C0C0C,0x000000A9,0x2913704E,0x00000091,0x00000000,0xBD8B6611,0x0000A6A4

	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x866E470C,0x83318429,0x00000056,0x00000000,0x98A40300,0xA197A403,0x11111181
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0xD10C0C0C,0x0C0C0C0C,0x004D8A46,0x4E5A470C,0x39000000
	.word 0xA4030053,0x4152B997,0x11119103,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x448D0C0C,0x00000000,0x0000006B,0x7575AD00,0x66B30000,0x00611141,0x1111A036,0x00481111
	.word 0x11111111,0x00001111,0x11111111,0x00001111,0x11111111,0x00001111,0x11111111,0x00001111
	.word 0x126B0000,0x0C4D0000,0x0C0C5500,0x54000086,0x0C0C0C0A,0x00006A0C,0x0C0C0C8A,0x00008E0C
	.word 0x0C0C0C73,0x00560C0C,0x0C0C0C59,0x00540C0C,0x0C0C0C59,0x000C0C0C,0x0C0C0C64,0x8E0C0C0C

	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C86,0x0C0C0C0C
	.word 0x0C0C4600,0x0C0C0C0C,0x0C0C0B00,0x0C0C0C0C,0x0C580000,0x0C0C0C0C,0x7C000000,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C47006A,0x0C0C0C0C,0x0C7C004D,0x0C0C0C0C,0x0C270056,0x0C0C0C0C,0x0C7C0000
	.word 0x460C0C0C,0x0C460000,0x680C0C0C,0x0C0C6A00,0x000C0C0C,0x0C0C8600,0x004D0C0C,0x0C0C8A00
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x120C0C0C,0x0C0C0C0C,0x460C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x530C0C0C,0x0C0C0C56,0x00120C0C,0x0C0C0C7C,0x8A00460C,0x0C0C0C0C,0x0C86530C,0x0C0C0C0C
	.word 0x0C0C6880,0x0C0C0C0C,0x0C0C0C8E,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C

	.word 0x00470C0C,0x11353900,0x00260C0C,0x1111B400,0x00860C0C,0x11119900,0x00530C0C,0x1111A500
	.word 0x00000C0C,0x11113500,0x0000580C,0x111111A4,0x0000780C,0x11111175,0x00006A0C,0x1111118C
	.word 0x11111111,0x49491111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x00371111,0x11111111,0x00A01111,0x11111111,0xA9111111,0x11111111,0x97111111
	.word 0x11111111,0x66111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x0C0C0C68,0x0C0C0C0C,0x0C0C0C6A,0x0C0C0C0C,0x0C0C1200,0x0C0C0C0C,0x0C0C6A00,0x0C0C0C0C
	.word 0x0C0B0037,0x0C0C0C0C,0x800000A0,0x0C0C0C0C,0x0000B411,0x0C0C0C83,0x00963511,0x0C290000

	.word 0x0000006B,0x270C598D,0x00006B0C,0x00000000,0x005A0C0C,0x00000000,0x0C0C0C0C,0x86A2788E
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x00000078,0x0C120078,0x29000000,0x0C00600C,0x0C120000,0x12005A0C,0x0C0C0C8E,0x8A005A0C
	.word 0x0C0C0C0C,0x2700600C,0x0C0C0C0C,0x0C530054,0x8A0C0C0C,0x0C7C0000,0x0053580C,0x0C0C8E00
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x000C0C0C,0x0C0C0C0C,0x806A0C0C,0x0C0C0C0C,0x0C830047,0x8D0C0C0C,0x0C0C6B00
	.word 0x0C59460C,0x0C0C0C0C,0x0C465A0C,0x0C0C0C0C,0x0C0C6858,0x0C0C0C0C,0x0C0C0C7F,0x4B0C0C0C
	.word 0x0C0C0C8E,0x00710C0C,0x0C0C0C0C,0x0000230C,0x0C0C0C0C,0x00000086,0x6A5A460C,0x87920000

	.word 0xB2000047,0x11111111,0x910000C6,0x11111141,0x119F0000,0x11111111,0x1111C000,0x11111111
	.word 0x11111100,0x11111111,0x11111119,0x11111111,0x111111A0,0x11111111,0x11111111,0x11111111
	.word 0xB4111111,0x00000000,0x11111111,0x00000FAE,0x11111111,0x8F36A011,0x11111111,0x41418C11
	.word 0x11111111,0x41411111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x5910D46B,0x686E3E1F,0x00000000,0x00000000,0x00000000,0x39000000,0xA4AC1CBF,0x9C1B43AC
	.word 0x11114141,0x41411111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x5700004D,0x0C0C0CC1,0x56000000,0x180683BE,0x00000019,0x00000000,0x36B1818C,0x49A575B1
	.word 0x11114141,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.word 0x00CD8D42,0x60BECE00,0xB40F0000,0x0F0F393F,0x1141B903,0x41411111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x000000C8,0x1141CB39,0xA5994019,0x11111141,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0xA5111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0xA5114111,0x11111111,0x391B4111,0xC9994111,0x00003937,0x0000003F,0x6E86CD00

	.word 0x8C411111,0x41414141,0x07411111,0x0E9FC575,0x00A81111,0x00000000,0x53009F11,0x4E63A26B
	.word 0x1012C639,0x9A474647,0x0C0C0C50,0x0C0C0C0C,0x468D537F,0x0C0C0C0C,0x0C474647,0x0C0C0C0C
	.word 0x11414122,0x11111111,0x071BB9AC,0x11111116,0x39000000,0x1111A3AA,0x0000006A,0xB9A70000
	.word 0x56865A8E,0x00000000,0x100C0C0C,0x00006A8A,0x0C0C0C0C,0x00D3590C,0x0C0C0C0C,0x6B0C0C0C
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x1111119F,0x11111111,0x1111A400,0x11111111,0x11AC0000,0x11111111,0x750F0000,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0xA3111111,0x11111111,0x00361111,0x11111111,0x0000B241,0x9C111111,0x0000000F

	.word 0x11111111,0x00004311,0x81111111,0x7F000000,0x00B48C11,0xD0530000,0x00003998,0x0C47297F
	.word 0x83000000,0x8E0C0C6E,0x47860000,0x7F8D0C0C,0x0C0C6700,0x0000120C,0x0C0C0C79,0x5300580C
	.word 0x54CC0000,0x0C0C0C0C,0x0C0C6EC8,0x7C590C0C,0x100C0C0C,0x00007812,0x4D298E0C,0x5A830000
	.word 0x00007FA2,0x0C478A4D,0x29000000,0x0C0C0C7C,0x0C590B00,0x4E120C0C,0x0C0C0C7C,0x00004E47
	.word 0x0C460C0C,0x0C0C0C0C,0x8A004E8D,0x0C0C0C0C,0x0C468053,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x5A460C0C,0x0C0C5886,0x604D8058,0x0C0C5912,0x475A007F,0x270C0C0C,0x0C0C467F,0x0060460C
	.word 0x0C0C0B7C,0x0C0C0C0C,0x7C00590C,0x0C0C0C0C,0x56270C0C,0x0C0C0C6E,0x8D0C0C0C,0x0C0C2756
	.word 0x0C0C0C0C,0x0C594D6B,0x0C0C0C0C,0x0C296A58,0x0C0C0C27,0x5900800C,0x0C0C0C58,0x297F580C

	.word 0x0300004E,0x111111C3,0x0000000C,0x111141AC,0x0000270C,0x113C2E37,0x006B0C0C,0x1141A800
	.word 0x00270C0C,0x11C3AD00,0x60470C0C,0x8C810000,0x540C0C0C,0x416C0000,0x6E0C0C0C,0x41AC0020
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0xB41C1111,0x11111111,0x00001E49,0x11111111,0x00000003,0xBD111111,0x4E000000
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x41411111,0x52529C8C,0x9C87A09C
	.word 0x19193796,0xA9AD3F37,0x00000000,0x00000000,0x00000000,0x00000000,0x590C4758,0x7C7C7C7C
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0xA38C1111,0x079C9C9C,0x00B4B975
	.word 0x3FC9A9A9,0x00000019,0x00000000,0x60000000,0x4D000000,0x477C1286,0x0C0C0C46,0x0C0C0C0C

	.word 0x00991111,0x27560000,0x0000B48C,0x0C104E00,0x00000037,0x0C0C5960,0x86000000,0x0C0C0C46
	.word 0x0C8D4E00,0x0C0C0C0C,0x0C0C7C5A,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x290C0C0C,0x0B000000,0x00A20C0C,0x0C290000,0x0000860C,0x0C0C5A00,0x6A00007C,0x0C0C0C12
	.word 0x586A0054,0x120C0C0C,0x0C276B47,0x6A580C0C,0x0C0C470C,0x000B0C0C,0x0C0C0C0C,0x0000540C
	.word 0x0C0C0C0C,0x58000054,0xA2590C0C,0x0C580000,0x0056270C,0x0C0C127F,0x0000008E,0x0C0C0C8A
	.word 0x68000000,0x0C0C0C0C,0x0C600000,0x0C0C0C0C,0x0C0C0000,0x0C0C0C0C,0x0C0C4700,0x0C0C0C0C
	.word 0x0C0C0C0C,0x006B0C0C,0x0C0C0C0C,0x005A0C0C,0x0C0C0C0C,0x6A470C0C,0x0C0C0C0C,0x530C0C0C
	.word 0x0C0C0C0C,0x0B0C0C0C,0x0C0C0C0C,0x8A0C0C0C,0x0C0C0C0C,0x8E0C0C0C,0x0C0C0C0C,0x100C0C0C

	.word 0x590C0C0C,0x8C3F0060,0x0C0C0C6E,0x8C390078,0x0C0C0C4E,0x4100008D,0x0C0C0C00,0x4100005A
	.word 0x0C0C5900,0x8C00CC54,0x0C0C2900,0x4119CC54,0x0C0C6000,0x35A9008A,0x0C0C7F00,0x41B9008D
	.word 0x19111111,0x0C2B0000,0x39111111,0x0C0C5600,0x39111111,0x0C0C4E00,0x39111111,0x0C0C4D00
	.word 0xB2111111,0x0C080000,0x2E111111,0x12560000,0x11111111,0x7F0000B1,0xC3111111,0x00009811
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x27128653,0x8A545827,0x00000000,0x00000000
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x835A0C0C,0x270C0C0C,0xA2004E86,0x6A4D4E80,0x0C6E0000,0x00000000,0x0C0C0C8A

	.word 0x0C0C0C0C,0x0C0C0C0C,0x6E0C0C0C,0x0C0C0C27,0x8D297C0C,0x0C0C0C0C,0x0C296054,0x0C0C0C0C
	.word 0x0C0C544E,0x0C0C0C0C,0x0C0C0C59,0x0C0C0C0C,0x0C0C0C0C,0x6E0C0C0C,0x0C0C0C0C,0x56470C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C6E,0x0C0C0C0C,0x0C0C0C12,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0000680C,0x0C0C0C0C,0x4E008A0C,0x0C0C0C0C,0x1060270C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C8A,0x0C0C0C0C,0x0C0C0C46,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C

	.word 0x0C0C0C0C,0x470C0C0C,0x0C0C0C0C,0x470C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x590C7F00,0x1187394E,0x290C7F00,0x1141B000,0x00450000,0x11118C36,0xA8370000,0x11111141
	.word 0x11990000,0x11111111,0x11750000,0x11111111,0x11750000,0x11111111,0x11A30000,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x9C111111
	.word 0x11111111,0x038C1111,0x11111111,0x00BD1111,0x11111111,0x00391111,0x11111111,0x00001111
	.word 0x3C111111,0xA1111141,0x758C1111,0x000039A4,0x00372F8C,0x56000000,0x00000096,0x6E8D804E
	.word 0x8A4E0000,0x0C0C0C10,0x0C598000,0x0C0C0C0C,0x0C0C1038,0x0C0C0C0C,0x0C0C0C80,0x0C0C0C0C

	.word 0x0000000F,0x00000000,0x00000000,0x6B566A00,0x0B6B834E,0x0C0C5829,0x0C0C0C59,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C8D0000,0x0C0C0C0C,0x0C0C0C6E,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x74590C0C,0x0C0C0C0C,0x00008D0C
	.word 0x0C0C0C0C,0x8353590C,0x0C0C0C0C,0x8D006059,0x7C0C0C0C,0x274D0060,0xC8270C0C,0x0C860000
	.word 0x1925120C,0x0C10560F,0x88372D68,0x0C0C7800,0x00BD1E00,0x0C0C0C76,0x000F750E,0x0C0C0C05
	.word 0x0C0C0C47,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C

	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x55470C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x270C0C0C,0x0C0C0C0C,0x785A0C0C
	.word 0x0C0C0C0C,0x596B8646,0x8E0C0C0C,0x0C274E21,0xCC538E0C,0x0C058300,0xAC000000,0x0C58252F
	.word 0x0C0C0C0C,0x590C0C0C,0x0C0C0C0C,0x100C0C0C,0x0C0C0C59,0x270C0C0C,0x0C0C0C46,0x100C0C0C
	.word 0x0C0C0C0C,0x470C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x11A30000,0x11111111,0x11A30000,0x11111111,0x11A30000,0x11111111,0x11750000,0x11111111
	.word 0x11B90000,0x11111111,0x11B40000,0x11111111,0x41030056,0x11111111,0x36000029,0x11111111

	.word 0x11111111,0x00001111,0x11111111,0x00A91111,0x11111111,0x002E1111,0x11111111,0x97111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x0C0C476B,0x0C0C0C0C,0x0C0C5A00,0x0C0C0C0C,0x7C8A6A00,0x0C0C0C0C,0x4E000000,0x54548A29
	.word 0x000000AE,0x00000000,0x37BDA511,0x00000000,0x35111111,0x75A39887,0x11111111,0x11111111
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x590C0C0C,0x590C0C0C,0x51861258,0x60788A5A,0x0000007F
	.word 0x00000000,0xB4190000,0x1E390000,0x41BB0D36,0x1634492E,0x07111116,0x11111111,0x00B63D11
	.word 0x8E0C0C0C,0xAE000000,0x00007827,0x2E2E3F00,0x37000000,0x00B91102,0x8CAC3F00,0x0000A411
	.word 0xA311C3B1,0x4E000003,0x00A9A511,0x4A600000,0x000039B4,0x0C0C6D00,0x56000000,0x0C0C0C7C

	.word 0x7A000FA5,0x0C0C0C0C,0x0C5D0039,0x0C0C0C0C,0x0C0C5300,0x0C0C0C0C,0x0C0C4753,0x0C0C0C0C
	.word 0x0C0C0C7C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x8D0C0C0C,0x0C0C0C0C,0x00120C0C,0x0C0C0C0C,0x00537C0C,0x0C0C0C0C,0x0000860C
	.word 0x0C0C0C0C,0x00007F6E,0x53100C0C,0x33390000,0x0000120C,0x112EA900,0x0F000029,0x111141BD
	.word 0xA3390000,0x11111111,0x11A50000,0x11111111,0x11111B00,0x11111111,0x11111199,0x11111111
	.word 0x11411900,0x0C8E003B,0x4111111B,0x0C12006C,0x41111111,0x0C5F00A3,0x41111111,0x0C5A0099
	.word 0x11111111,0x0C5A0099,0x11111111,0x0C010075,0x11111111,0x0C2A0098,0x11111111,0x0C040098

	.word 0x1900000C,0x1111112E,0x0000150C,0x11418CA9,0x004D0C0C,0x11410200,0x6A7C0C0C,0x111B0F00
	.word 0x5A0C0C0C,0x41370000,0x0C0C0C0C,0xA4000086,0x0C0C0C0C,0x0000834A,0x0C0C0C0C,0x0000860C
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111141,0x11111111,0x11111181,0x11111111
	.word 0x11111111,0x0000007B,0xA5111111,0x4D000000,0x19111111,0x47830000,0x00751111,0x0C277F00
	.word 0x009F1111,0x0C0C8300,0x001E1111,0x0C0C2900,0x00A91111,0x0C0C7800,0x009C1111,0x0C0C5300
	.word 0x0C476000,0x0C0C0C0C,0x0C0C0C6E,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C

	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x8E0C0C0C,0x0C0C0C0C,0x7F6E0C0C,0x0C0C0C0C,0x00006E0C
	.word 0x0C0C0C0C,0xC5000013,0x8E0C0C0C,0x419F0000,0x00270C0C,0x419CC000,0x00006E0C,0x11110790
	.word 0x0F007F8E,0x111111BB,0x75000057,0x11111111,0x11B10000,0x11111111,0x11119F00,0x11111111
	.word 0x11111111,0x4A830075,0x11111111,0x58000075,0x11111111,0x6000033D,0x11111111,0x00009711
	.word 0x11111111,0x00A78711,0x11111111,0xA6071111,0x11111111,0x41111111,0x11111111,0x11111111
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C0C,0x0C0C0C46,0x0C0C0C0C,0x0C0C5980,0x0C0C0C0C
	.word 0x58688300,0x470C0C47,0x4D000000,0x4E60604E,0x00000097,0x00000000,0xA69E3511,0x00000000

	.word 0x0C0C0C0C,0x00008D0C,0x0C0C0C0C,0x0000680C,0x0C0C0C0C,0x00004E47,0x580C0C0C,0x00000060
	.word 0x56808A27,0x99000000,0x0000004D,0x11991900,0x00000000,0x114187AE,0x111BBA37,0x11111111
	.word 0x111111A3,0x11111111,0x11111199,0x11111111,0x11111181,0x11111111,0x11111135,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0xA9111111,0x0C800000,0xA8111111,0x86000000,0x52111111,0x0000000F,0x11111111,0x000FC0A3
	.word 0x11111111,0xACA32211,0x11111111,0x8C414111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x0C0C0C0C,0x0C0C0C0C,0x0C0C4659,0x0C0C0C0C,0x128DA20F,0x126E6E6E,0x00000000,0x00000000
	.word 0x000000A7,0x00000000,0x2FA31B07,0x99A14302,0x41411111,0x41414141,0x11111111,0x11111111

	.word 0x0C0C0C0C,0x0000005A,0x607C470C,0xA9000000,0x0000838D,0x8CAC3900,0x0F000000,0x111198B4
	.word 0x759F3700,0x11111111,0x1111A075,0x11111111,0x11111141,0x11111111,0x11111111,0x11111111
	.word 0x11111140,0x11111111,0x1111118C,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.section .rodata
	.align	2
	.global RSPMap		@ 768 unsigned chars
RSPMap:
	.hword 0x0001,0x0001,0x0001,0x0001,0x0002,0x0003,0x0004,0x0005
	.hword 0x0006,0x0007,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0008,0x0009,0x000A,0x000B
	.hword 0x000C,0x000D,0x000E,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x000F,0x0010,0x0011,0x0012,0x0011
	.hword 0x0011,0x0013,0x0014,0x0015,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0016,0x0017,0x0018,0x0011,0x0019
	.hword 0x001A,0x0011,0x001B,0x001C,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x001D,0x001E,0x0011,0x0011,0x001F
	.hword 0x0020,0x0021,0x0022,0x0023,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0024,0x0025,0x0011,0x0011,0x0026
	.hword 0x0027,0x0028,0x0029,0x002A,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x002B,0x002C,0x0011,0x002D
	.hword 0x002E,0x002F,0x0030,0x0031,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0032,0x0033,0x0034,0x0035
	.hword 0x0036,0x0037,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0038,0x0039,0x003A,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x003B,0x003C,0x003D,0x003E,0x003F,0x0040
	.hword 0x0041,0x0042,0x0043,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0044,0x0045,0x0046,0x0011,0x0047,0x0048
	.hword 0x0049,0x0011,0x004A,0x004B,0x004C,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x004D,0x004E,0x004F,0x0050,0x0051
	.hword 0x0052,0x0053,0x0011,0x0054,0x0055,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0056,0x0057,0x0058,0x0011,0x0059,0x005A
	.hword 0x0011,0x005B,0x0011,0x005C,0x005D,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x005E,0x005F,0x0060,0x0061,0x0062,0x0063
	.hword 0x0064,0x0065,0x0066,0x0067,0x0068,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0069,0x0001,0x0001,0x006A,0x006B
	.hword 0x006C,0x006D,0x006E,0x006F,0x0070,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0071
	.hword 0x0072,0x0073,0x0074,0x0075,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0076
	.hword 0x0077,0x0078,0x0079,0x007A,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x007B,0x007C
	.hword 0x007D,0x007E,0x007F,0x0080,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0081,0x0082,0x0083,0x0084,0x0011
	.hword 0x0085,0x0086,0x0087,0x0088,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0089,0x008A,0x008B,0x008C,0x008D
	.hword 0x008E,0x008F,0x0090,0x0091,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0092,0x0093,0x0094,0x0095,0x0096,0x0097
	.hword 0x0098,0x0099,0x009A,0x009B,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x009C,0x009D,0x009E,0x009F,0x00A0,0x00A1
	.hword 0x00A2,0x00A3,0x0011,0x00A4,0x00A5,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x00A6,0x00A7,0x00A8,0x00A9
	.hword 0x0001,0x00AA,0x00AB,0x00AC,0x00AD,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x00AE,0x00AF,0x00B0,0x00B1
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.section .rodata
	.align	2
	.global RSPPal		@ 512 unsigned chars
RSPPal:
	.hword 0x0000,0x4A72,0x042F,0x0005,0x39CF,0x6F9B,0x1CC7,0x0859
	.hword 0x5AF7,0x1085,0x0441,0x2D6B,0x7FFF,0x0834,0x000A,0x0001
	.hword 0x6B5A,0x107D,0x56B5,0x4630,0x2509,0x358D,0x087B,0x7BBE
	.hword 0x1063,0x0003,0x002D,0x0856,0x0452,0x62F8,0x0007,0x77BC
	.hword 0x0021,0x18C5,0x087C,0x4E94,0x0400,0x0C62,0x56D6,0x6739
	.hword 0x20E8,0x4210,0x4A32,0x39AE,0x254A,0x0020,0x0857,0x0431
	.hword 0x002C,0x316B,0x6F7A,0x0008,0x085A,0x107C,0x042E,0x0004
	.hword 0x1484,0x0002,0x0435,0x0433,0x0C5C,0x0858,0x739B,0x0006

	.hword 0x040B,0x0C7C,0x73BD,0x0430,0x1083,0x2527,0x7BDE,0x77BD
	.hword 0x0029,0x107B,0x739D,0x18E6,0x7FDE,0x1084,0x18C6,0x10A4
	.hword 0x5AD4,0x0442,0x0C59,0x14A5,0x5294,0x2949,0x0C63,0x0422
	.hword 0x6318,0x739C,0x4E73,0x3DEE,0x0843,0x1D07,0x779C,0x52B4
	.hword 0x2108,0x0C5B,0x4E74,0x2129,0x6338,0x0C42,0x107A,0x4A53
	.hword 0x3DEF,0x14A6,0x0842,0x2529,0x0833,0x39CD,0x5EF7,0x5F17
	.hword 0x35AC,0x4231,0x5295,0x6B7B,0x1CE8,0x0855,0x0821,0x082D
	.hword 0x39CE,0x5EF6,0x4652,0x0C31,0x6F7B,0x3DF0,0x35CD,0x0421

	.hword 0x318C,0x0C57,0x4E52,0x1CE7,0x4610,0x0C53,0x35AD,0x0C5A
	.hword 0x040A,0x296A,0x4A52,0x0C54,0x0C7B,0x4631,0x5AD6,0x0403
	.hword 0x0404,0x0C55,0x0023,0x2D6C,0x3E0F,0x0409,0x0407,0x082E
	.hword 0x0C56,0x0853,0x6F5A,0x0C52,0x0C7A,0x0024,0x0C2F,0x042C
	.hword 0x0C79,0x0831,0x294A,0x0854,0x042B,0x0C58,0x0405,0x0406
	.hword 0x0830,0x0429,0x082B,0x6B5B,0x042D,0x0408,0x082F,0x0C78
	.hword 0x0832,0x0851,0x0027,0x082C,0x042A,0x0879,0x0025,0x1057
	.hword 0x18C4,0x0852,0x0C2D,0x0877,0x5AB5,0x0850,0x2528,0x0C77

	.hword 0x0428,0x6F9C,0x0427,0x087A,0x002A,0x0450,0x318B,0x0C51
	.hword 0x14A4,0x0028,0x5AD5,0x044F,0x0420,0x0841,0x2D6A,0x1064
	.hword 0x52B5,0x6F5B,0x0455,0x1D08,0x4A73,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(RSP)
