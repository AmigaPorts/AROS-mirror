const ULONG Forward_colors[48] =
{
	0x90909090,0x90909090,0x90909090,
	0x00000000,0x00000000,0x00000000,
	0xffffffff,0xffffffff,0xffffffff,
	0xf0f0f0f0,0xf0f0f0f0,0x00000000,
	0x70707070,0x70707070,0x70707070,
	0xa0a0a0a0,0xa0a0a0a0,0xa0a0a0a0,
	0xf0f0f0f0,0x00000000,0xf0f0f0f0,
	0xf0f0f0f0,0x00000000,0x00000000,
	0x40404040,0x40404040,0xf0f0f0f0,
	0xc0c0c0c0,0xc0c0c0c0,0xf0f0f0f0,
	0x00000000,0xa0a0a0a0,0x00000000,
	0x70707070,0x70707070,0xf0f0f0f0,
	0xe0e0e0e0,0x40404040,0x40404040,
	0x60606060,0xe0e0e0e0,0x60606060,
	0x00000000,0x40404040,0xd0d0d0d0,
	0xc0c0c0c0,0xf0f0f0f0,0xc0c0c0c0,
};
#define FORWARD_WIDTH        24
#define FORWARD_HEIGHT       22
#define FORWARD_DEPTH         4
#define FORWARD_COMPRESSION   0
#define FORWARD_MASKING       2

const struct BitMapHeader Forward_header =
{ 24,22,0,0,4,2,0,0,0,10,11,640,400 };
const UBYTE Forward_body[352] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0xf8,0x00,0x00,0x00,0x20,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0xe7,0xbf,0xfc,0x00,0x00,0x00,0x30,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0xe7,0xbf,0xfe,0x00,0x00,0x00,
0x38,0x00,0x00,0x00,0x00,0x00,0x43,0x1f,0xfc,0x00,0xe6,0xbf,0xff,0x00,0x00,
0x0f,0xfc,0x00,0x00,0x00,0x00,0x00,0x43,0x1f,0xfe,0x00,0xe6,0xbf,0xfd,0x00,
0x00,0x0f,0xfc,0x00,0x00,0x00,0x00,0x00,0x43,0x1f,0xfe,0x00,0xe6,0xb0,0x3a,
0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x43,0x1f,0xfc,0x00,0xe7,0xbf,
0xb4,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,
0x00,0xa8,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,
0x00,0x00,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,
0x00,0x00,0x00,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x40,0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00, };