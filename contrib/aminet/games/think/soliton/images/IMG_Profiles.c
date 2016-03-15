#ifdef USE_IMG_PROFILES_COLORS
const ULONG IMG_Profiles_colors[24] =
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
#endif

//Width 54 Height 40 Depth 3 - converting...
#define IMG_PROFILES_WIDTH        54
#define IMG_PROFILES_HEIGHT       40
#define IMG_PROFILES_DEPTH         3
#define IMG_PROFILES_COMPRESSION   1
#define IMG_PROFILES_MASKING       2

#ifdef USE_IMG_PROFILES_HEADER
const struct BitMapHeader IMG_Profiles_header =
{ 54,40,44,191,3,2,1,0,0,22,22,1024,768 };
#endif

//ifdef USE_IMG_PROFILES_BODY
const UBYTE IMG_Profiles_body[766] = {
0xf9,0x00,0xf9,0x00,0xf9,0x00,0x07,0x00,0x10,0x00,0x03,0x83,0x80,0x00,0x00,
0x07,0x00,0x10,0x00,0x03,0x83,0x80,0x00,0x00,0x07,0x00,0x10,0x00,0x03,0x83,
0x80,0x00,0x00,0x07,0x00,0x10,0x00,0x0f,0xef,0xe0,0x00,0x00,0x07,0x00,0x10,
0x00,0x0f,0xef,0xe0,0x00,0x00,0x07,0x00,0x10,0x00,0x0f,0xef,0xe0,0x00,0x00,
0x07,0x00,0x38,0x00,0x1f,0xef,0xf0,0x00,0x00,0x07,0x00,0x38,0x00,0x1f,0xef,
0xf0,0x00,0x00,0x07,0x00,0x38,0x00,0x1f,0xef,0xf0,0x00,0x00,0x07,0x00,0x38,
0x00,0x1f,0xff,0xf0,0x00,0x00,0x07,0x00,0x38,0x00,0x1f,0xff,0xf0,0x00,0x00,
0x07,0x00,0x38,0x00,0x1f,0xff,0xf0,0x00,0x00,0x07,0x00,0x7c,0x00,0x1f,0xff,
0xf0,0x00,0x00,0x07,0x00,0x7c,0x00,0x1f,0xff,0xf0,0x00,0x00,0x07,0x00,0x7c,
0x00,0x1f,0xff,0xf0,0x00,0x00,0x07,0x00,0xfe,0x00,0x1f,0xff,0xf0,0x00,0x00,
0x07,0x00,0xfe,0x00,0x1f,0xff,0xf0,0x00,0x00,0x07,0x00,0xfe,0x00,0x1f,0xff,
0xf0,0x00,0x00,0x07,0x01,0xff,0x00,0x1f,0xff,0xf0,0x00,0x00,0x07,0x01,0xff,
0x00,0x1f,0xff,0xf0,0x00,0x00,0x07,0x01,0xff,0x00,0x1f,0xff,0xf0,0x00,0x00,
0x07,0x03,0xff,0x80,0x1f,0xff,0xf0,0x00,0x00,0x07,0x03,0xff,0x80,0x1f,0xff,
0xf0,0x00,0x00,0x07,0x03,0xff,0x80,0x1f,0xff,0xf0,0x00,0x00,0x07,0x07,0xff,
0xc0,0x0f,0xff,0xe0,0x00,0x00,0x07,0x07,0xff,0xc0,0x0f,0xff,0xe0,0x00,0x00,
0x07,0x07,0xff,0xc0,0x0f,0xff,0xe0,0x00,0x00,0x07,0x1f,0xff,0xf0,0x0f,0xff,
0xe0,0x00,0x00,0x07,0x1f,0xff,0xf0,0x0f,0xff,0xe0,0x00,0x00,0x07,0x1f,0xff,
0xf0,0x0f,0xff,0xe0,0x00,0x00,0x07,0x7f,0xff,0xfc,0x07,0xff,0xc0,0x00,0x00,
0x07,0x7f,0xff,0xfc,0x07,0xff,0xc0,0x00,0x00,0x07,0x7f,0xff,0xfc,0x07,0xff,
0xc0,0x00,0x00,0x07,0x1f,0xff,0xf0,0x03,0xff,0x80,0x00,0x00,0x07,0x1f,0xff,
0xf0,0x03,0xff,0x80,0x00,0x00,0x07,0x1f,0xff,0xf0,0x03,0xff,0x80,0x00,0x00,
0x04,0x07,0xff,0xc0,0x01,0xff,0xfe,0x00,0x04,0x07,0xff,0xc0,0x01,0xff,0xfe,
0x00,0x04,0x07,0xff,0xc0,0x01,0xff,0xfe,0x00,0x04,0x03,0xff,0x80,0x00,0xfe,
0xfe,0x00,0x04,0x03,0xff,0x80,0x00,0xfe,0xfe,0x00,0x04,0x03,0xff,0x80,0x00,
0xfe,0xfe,0x00,0x04,0x01,0xff,0x00,0x00,0x7c,0xfe,0x00,0x04,0x01,0xff,0x00,
0x00,0x7c,0xfe,0x00,0x04,0x01,0xff,0x00,0x00,0x7c,0xfe,0x00,0x04,0x00,0xfe,
0x07,0x00,0x7c,0xfe,0x00,0x04,0x00,0xfe,0x00,0x00,0x7c,0xfe,0x00,0x04,0x00,
0xfe,0x00,0x00,0x7c,0xfe,0x00,0x07,0x00,0x7c,0x0f,0x80,0x38,0x04,0x00,0x00,
0x04,0x00,0x7c,0x00,0x00,0x38,0xfe,0x00,0x04,0x00,0x7c,0x00,0x00,0x38,0xfe,
0x00,0x07,0x00,0x38,0x1f,0xc0,0x10,0x04,0x00,0x00,0x04,0x00,0x38,0x00,0x00,
0x10,0xfe,0x00,0x04,0x00,0x38,0x00,0x00,0x10,0xfe,0x00,0x07,0x00,0x38,0x3f,
0xe0,0x10,0x0e,0x00,0x00,0x04,0x00,0x38,0x00,0x00,0x10,0xfe,0x00,0x04,0x00,
0x38,0x00,0x00,0x10,0xfe,0x00,0x07,0x00,0x10,0x3f,0xe0,0x00,0x1f,0x00,0x00,
0x01,0x00,0x10,0xfb,0x00,0x01,0x00,0x10,0xfb,0x00,0x07,0x00,0x10,0x3f,0xe0,
0x00,0x3f,0x80,0x00,0x01,0x00,0x10,0xfb,0x00,0x01,0x00,0x10,0xfb,0x00,0xff,
0x00,0x05,0x3f,0xe0,0x00,0x7f,0xc0,0x00,0xf9,0x00,0xf9,0x00,0x07,0x00,0x03,
0x9f,0xce,0x00,0xff,0xe0,0x00,0xf9,0x00,0xf9,0x00,0x07,0x00,0x07,0xcf,0x9f,
0x01,0xff,0xf0,0x00,0xf9,0x00,0xf9,0x00,0x07,0x00,0x0f,0xe7,0x3f,0x83,0xff,
0xf8,0x00,0xf9,0x00,0xf9,0x00,0x07,0x00,0x1f,0xff,0xff,0xc3,0xff,0xf8,0x00,
0xf9,0x00,0xf9,0x00,0x07,0x00,0x1f,0xff,0xff,0xc7,0xff,0xfc,0x00,0xf9,0x00,
0xf9,0x00,0x07,0x00,0x1f,0xff,0xff,0xc7,0xff,0xfc,0x00,0xf9,0x00,0xf9,0x00,
0x07,0x00,0x1f,0xff,0xff,0xc7,0xff,0xfc,0x00,0xf9,0x00,0xf9,0x00,0x07,0x00,
0x0f,0xe7,0x3f,0x87,0xff,0xfc,0x00,0xf9,0x00,0xf9,0x00,0x07,0x00,0x07,0xc7,
0x1f,0x07,0xff,0xfc,0x00,0xf9,0x00,0xf9,0x00,0x07,0x00,0x03,0x87,0x0e,0x03,
0xee,0xf8,0x00,0xf9,0x00,0xf9,0x00,0xff,0x00,0x05,0x0f,0x80,0x00,0x0e,0x00,
0x00,0xf9,0x00,0xf9,0x00,0xff,0x00,0x05,0x0f,0x80,0x00,0x1f,0x00,0x00,0xf9,
0x00,0xf9,0x00,0xff,0x00,0x05,0x1f,0xc0,0x00,0x1f,0x00,0x00,0xf9,0x00,0xf9,
0x00,0xff,0x00,0x05,0x1f,0xc0,0x00,0x3f,0x80,0x00,0xf9,0x00,0xf9,0x00,0xff,
0x00,0x05,0x3f,0xe0,0x00,0x3f,0x80,0x00,0xf9,0x00,0xf9,0x00,0xff,0x00,0x05,
0x38,0xe0,0x00,0x71,0xc0,0x00,0xf9,0x00,0xf9,0x00,0xf9,0x00,0xf9,0x00,0xf9,
0x00, };
//endif