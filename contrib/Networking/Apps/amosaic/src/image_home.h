const ULONG Home_colors[48] =
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
#define HOME_WIDTH        24
#define HOME_HEIGHT       22
#define HOME_DEPTH         4
#define HOME_COMPRESSION   0
#define HOME_MASKING       2

const struct BitMapHeader Home_header =
{ 24,22,0,0,4,2,0,0,0,10,11,640,400 };
const UBYTE Home_body[352] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x3c,0xe0,0x00,0x00,0x08,0x00,0x00,0x00,0x18,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x7e,0xe0,0x00,0x00,0x1c,0x00,0x00,0x00,0x3c,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0x00,0x00,0x36,0x00,0x00,0x00,0x7e,
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xe7,0xe0,0x00,0x00,0x7b,0x00,0x00,0x00,
0xe7,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xc3,0xe0,0x00,0x00,0xfd,0x80,0x00,
0x01,0xc3,0x80,0x00,0x00,0x00,0x00,0x00,0x07,0x81,0xe0,0x00,0x01,0xfe,0xc0,
0x00,0x03,0x81,0xc0,0x00,0x00,0x00,0x00,0x00,0x0f,0x00,0xf0,0x00,0x03,0xff,
0x60,0x00,0x07,0x00,0xe0,0x00,0x00,0x00,0x00,0x00,0x1e,0x00,0x78,0x00,0x07,
0xff,0xb0,0x00,0x0e,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x3c,0x00,0x3c,0x00,
0x0f,0xff,0xd8,0x00,0x1c,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x3e,
0x00,0x07,0xff,0xc0,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x0b,0xe7,
0xb0,0x00,0x04,0x18,0x40,0x00,0x02,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x0b,
0x24,0xb0,0x00,0x04,0x18,0x40,0x00,0x02,0x00,0x20,0x00,0x00,0x00,0x00,0x00,
0x0b,0x24,0xb0,0x00,0x04,0x18,0x40,0x00,0x02,0x00,0x20,0x00,0x00,0x00,0x00,
0x00,0x0b,0x27,0xb0,0x00,0x04,0x18,0x40,0x00,0x02,0x00,0x20,0x00,0x00,0x00,
0x00,0x00,0x0b,0x20,0x30,0x00,0x04,0x1f,0xc0,0x00,0x02,0x00,0x20,0x00,0x00,
0x00,0x00,0x00,0x0f,0x3f,0xf0,0x00,0x00,0x00,0x00,0x00,0x06,0x1f,0xe0,0x00,
0x00,0x00,0x00,0x00,0x0f,0x3f,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00, };