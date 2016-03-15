const ULONG IMG_Winner_colors[24] =
{
  0x92929292,0x92929292,0x92929292,
  0x00000000,0x00000000,0x00000000,
  0xefefefef,0xefefefef,0xefefefef,
  0x31313131,0x61616161,0xa2a2a2a2,
  0x71717171,0x71717171,0x71717171,
  0xa2a2a2a2,0xa2a2a2a2,0xa2a2a2a2,
  0xa2a2a2a2,0x92929292,0x71717171,
  0xefefefef,0xa2a2a2a2,0x92929292,
};

//Width 42 Height 33 Depth 3 - converting...
#define IMG_WINNER_WIDTH        42
#define IMG_WINNER_HEIGHT       33
#define IMG_WINNER_DEPTH         3
#define IMG_WINNER_COMPRESSION   0
#define IMG_WINNER_MASKING       2

#ifdef USE_IMG_WINNER_HEADER
const struct BitMapHeader IMG_Winner_header =
{ 42,33,286,718,3,2,0,0,0,22,22,1024,768 };
#endif

//ifdef USE_IMG_WINNER_BODY
const UBYTE IMG_Winner_body[594] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x06,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x00,0x00,0x00,
0x00,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,
0x00,0x00,0x00,0x00,0x00,0x1f,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,
0x00,0x00,0x0a,0x00,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x80,0x00,0x00,0x06,0x00,0x00,0x80,
0x30,0x00,0x0c,0x00,0x00,0x00,0x30,0x00,0x0a,0x00,0x01,0x80,0x70,0x00,0x04,
0x00,0x03,0x80,0x20,0x00,0x08,0x00,0x01,0x00,0x70,0x20,0x06,0x01,0x03,0x80,
0x30,0x20,0x0e,0x01,0x01,0x80,0x60,0x10,0x05,0x00,0x83,0x00,0x50,0x10,0x05,
0x00,0x85,0x80,0x40,0x30,0x0d,0x01,0x81,0x80,0x28,0x00,0x16,0x00,0x02,0x00,
0x18,0x20,0x11,0x03,0x8b,0x00,0x20,0x20,0x0d,0x01,0x84,0x00,0x44,0x30,0x12,
0x01,0x02,0x00,0x4c,0x30,0x0f,0x04,0x97,0x00,0x68,0x00,0x1d,0x02,0x0a,0x00,
0x12,0x28,0x0e,0x80,0x04,0x00,0x36,0x08,0x0d,0x89,0xaf,0x00,0x04,0x20,0x15,
0x85,0x12,0x00,0x79,0x04,0x2a,0x00,0x0c,0x00,0x2b,0x04,0x22,0x91,0xde,0x00,
0x32,0x20,0x14,0x09,0x24,0x00,0x0c,0x8a,0x29,0x06,0x18,0x00,0x35,0x82,0x12,
0xe1,0xae,0x00,0x29,0x20,0x32,0xd1,0x44,0x00,0x16,0x4d,0x1c,0x0e,0x28,0x00,
0x02,0xc1,0x1b,0xc3,0x6e,0x00,0x0c,0x88,0x2f,0xa6,0x98,0x00,0x03,0x26,0xd1,
0x08,0x60,0x00,0x15,0x60,0xd1,0xc6,0x9e,0x00,0x1a,0x40,0x3e,0xc5,0x3a,0x00,
0x05,0x9f,0x51,0x38,0x80,0x00,0x1a,0xb0,0x3a,0x4d,0x1c,0x00,0x15,0x20,0x6e,
0x4a,0x58,0x00,0x0a,0xcf,0x30,0x31,0x20,0x00,0x00,0xdf,0xa0,0xf8,0x9c,0x00,
0x07,0x97,0x64,0xfd,0x94,0x00,0x00,0xe0,0xa0,0x80,0x80,0x00,0x0b,0xaf,0x7d,
0xf5,0xb8,0x00,0x0d,0xca,0x8c,0x59,0xa0,0x00,0x03,0x21,0x79,0xc5,0x40,0x00,
0x0c,0x95,0x73,0xa1,0x38,0x00,0x0a,0x24,0x9e,0x72,0x30,0x00,0x04,0x91,0x71,
0x81,0x00,0x00,0x00,0x08,0xe5,0x83,0x78,0x00,0x03,0x11,0x3d,0x24,0x68,0x00,
0x00,0x4c,0xe6,0xd3,0x00,0x00,0x05,0x11,0xce,0xe6,0xf0,0x00,0x06,0x8e,0x76,
0x98,0x40,0x00,0x01,0x11,0xcf,0x66,0x80,0x00,0x06,0xbb,0x9f,0xc7,0x70,0x00,
0x05,0x45,0x6b,0x89,0x60,0x00,0x02,0xbb,0x9b,0x57,0x00,0x00,0x00,0x44,0xcf,
0xc8,0xf0,0x00,0x01,0x8e,0x7e,0x9c,0x90,0x00,0x00,0x60,0xce,0x62,0x00,0x00,
0x03,0x0e,0x07,0x1c,0xe0,0x00,0x02,0x5f,0x1d,0x3e,0xc0,0x00,0x01,0x00,0x44,
0x41,0x00,0x00,0x02,0x3f,0xf7,0xff,0xe0,0x00,0x02,0x1e,0xaa,0xaa,0x00,0x00,
0x00,0xc4,0x00,0x08,0x00,0x00,0x01,0x23,0xff,0xe0,0xe0,0x00,0x01,0xc3,0xbe,
0xe0,0xa0,0x00,0x00,0x35,0x41,0x55,0x00,0x00,0x01,0x56,0xf7,0xb2,0xe0,0x00,
0x01,0xb7,0xff,0xf6,0xa0,0x00,0x00,0x5a,0x94,0xab,0x00,0x00,0x01,0x5f,0xff,
0xf6,0xc0,0x00,0x01,0x8f,0x73,0xd4,0x00,0x00,0x00,0x64,0x59,0x19,0x00,0x00,
0x01,0x17,0x00,0x57,0xc0,0x00,0x01,0x68,0x00,0x56,0x40,0x00,0x00,0x97,0xff,
0xa8,0x00,0x00,0x00,0xff,0xff,0xff,0xc0,0x00,0x00,0xfa,0xa8,0x00,0x40,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, };
//endif