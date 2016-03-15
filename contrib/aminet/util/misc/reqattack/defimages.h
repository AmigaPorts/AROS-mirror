#ifndef DEFIMAGES_H
#define DEFIMAGES_H

/* Cancel Image */

#define CANCELWIDTH 11
#define CANCELHEIGHT 11
#define CANCELCOLS 4

static UBYTE cancelpal[] =
{
		0xAA,0xAA,0xAA,0xDF,0x35,0x35,
		0x82,0x00,0x00,0xFF,0xFF,0xFF
};

static UBYTE canceldata[] =
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x60,0xC0,
  0x20,0x80,0x51,0x40,0x11,0x00,0x2A,0x80,
  0x0A,0x00,0x15,0x00,0x04,0x00,0x0A,0x00,
  0x0A,0x00,0x15,0x00,0x11,0x00,0x2A,0x80,
  0x20,0x80,0x51,0x40,0x00,0x00,0x60,0xC0,
  0x00,0x00,0x00,0x00
};

static struct MyImageSpec cancelimagespec =
{
	(ULONG *)canceldata,
	cancelpal,
	CANCELWIDTH,
	CANCELHEIGHT,
	CANCELCOLS,
	CANCELWIDTH,
	CANCELHEIGHT
};

/* Use Image */

#define USEWIDTH 11
#define USEHEIGHT 10
#define USECOLS 4

static UBYTE usepal[] =
{
	0xAA,0xAA,0xAA,0x18,0x5D,0x31,0x55,0xB2,0x59,0x39,0x8A,0x45
	
};

static UBYTE usedata[] =
{
  0x00,0x00,0x00,0x00,0x00,0x60,0x00,0xE0,
  0x00,0xE0,0x01,0xC0,0x01,0xC0,0xC3,0x80,
  0xC3,0x80,0xE7,0x00,0x67,0x00,0x7E,0x00,
  0x3E,0x00,0x3C,0x00,0x1C,0x00,0x18,0x00,
  0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

static struct MyImageSpec useimagespec =
{
	(ULONG *)usedata,
	usepal,
	USEWIDTH,
	USEHEIGHT,
	USECOLS,
	USEWIDTH,
	USEHEIGHT
};

/* Point Image */

#define POINTWIDTH 10
#define POINTHEIGHT 8
#define POINTCOLS 4

static UBYTE pointpal[] =
{
	0xAA,0xAA,0xAA,0xE3,0xE3,0xE3,
	0x8A,0x8A,0x8A,0x60,0x60,0x60,
};

static UBYTE pointdata[] =
{
  0x60,0x00,0x00,0x00,0x58,0x00,0x00,0x00,
  0x46,0x00,0x00,0x00,0x41,0x80,0x00,0x00,
  0x41,0x80,0x03,0x80,0x47,0x00,0x0F,0x00,
  0x5C,0x00,0x3C,0x00,0x70,0x00,0x70,0x00
};

static struct MyImageSpec pointimagespec =
{
	(ULONG *)pointdata,
	pointpal,
	POINTWIDTH,
	POINTHEIGHT,
	POINTCOLS,
	POINTWIDTH,
	POINTHEIGHT
};

/* Warn Image */

#define WARNWIDTH 34
#define WARNHEIGHT 34
#define WARNCOLS 8

static UBYTE warnpal[] =
{
	0xAA,0xAA,0xAA,0x00,0x00,0x00,
	0xFA,0xFA,0xFA,0xC6,0xC6,0xC6,
	0x8A,0x8A,0x8A,0x69,0x69,0x69,
	0x49,0x49,0x49,0x28,0x28,0x28
};

static UBYTE warndata[] =
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,
  0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x3F,0xFF,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,
  0x00,0x00,0x00,0xFF,0xFF,0xC0,0x00,0x00,
  0x00,0x03,0xF0,0x00,0x00,0x00,0x00,0x13,
  0x02,0x00,0x00,0x00,0x01,0xEF,0xFD,0xE0,
  0x00,0x00,0x00,0x1F,0xFE,0x00,0x00,0x00,
  0x00,0x7F,0x3F,0x80,0x00,0x00,0x03,0xA9,
  0xE5,0x70,0x00,0x00,0x00,0x6A,0x15,0x80,
  0x00,0x00,0x00,0xFE,0x1F,0xC0,0x00,0x00,
  0x07,0x43,0xF0,0xB8,0x00,0x00,0x00,0xC4,
  0x08,0xC0,0x00,0x00,0x00,0xFC,0x0F,0xC0,
  0x00,0x00,0x0F,0x83,0xF0,0x7C,0x00,0x00,
  0x01,0x84,0x08,0x60,0x00,0x00,0x01,0xFE,
  0x1F,0xE0,0x00,0x00,0x1F,0x03,0xF0,0x3E,
  0x00,0x00,0x03,0x04,0x08,0x30,0x00,0x00,
  0x07,0xFF,0x3F,0xF8,0x00,0x00,0x3A,0x01,
  0xE0,0x17,0x00,0x00,0x06,0x02,0x10,0x18,
  0x00,0x00,0x0F,0xFF,0xFF,0xFC,0x00,0x00,
  0x34,0x00,0x00,0x0B,0x00,0x00,0x0C,0x00,
  0x00,0x0C,0x00,0x00,0x07,0xFF,0xFF,0xF8,
  0x00,0x00,0x78,0x00,0x00,0x07,0x80,0x00,
  0x08,0x00,0x00,0x04,0x00,0x00,0x1F,0xFC,
  0x1F,0xFE,0x00,0x00,0x60,0x07,0xF0,0x01,
  0x80,0x00,0x10,0x00,0x00,0x02,0x00,0x00,
  0x0F,0xFC,0x0F,0xFC,0x00,0x00,0xF0,0x01,
  0xE0,0x03,0xC0,0x00,0x10,0x00,0x00,0x02,
  0x00,0x00,0x1F,0xFC,0x0F,0xFE,0x00,0x00,
  0xF0,0x01,0xE0,0x03,0xC0,0x00,0x10,0x00,
  0x00,0x02,0x00,0x00,0x3F,0xFC,0x0F,0xFF,
  0x00,0x00,0xF0,0x01,0xE0,0x03,0xC0,0x00,
  0x30,0x00,0x00,0x03,0x00,0x00,0x3F,0xFC,
  0x0F,0xFF,0x00,0x00,0xF0,0x01,0xE0,0x03,
  0xC0,0x00,0x30,0x00,0x00,0x03,0x00,0x00,
  0x3F,0xFC,0x0F,0xFF,0x00,0x00,0xF0,0x01,
  0xE0,0x03,0xC0,0x00,0x30,0x00,0x00,0x03,
  0x00,0x00,0x3F,0xFC,0x0F,0xFF,0x00,0x00,
  0xF0,0x01,0xE0,0x03,0xC0,0x00,0x30,0x00,
  0x00,0x03,0x00,0x00,0x3F,0xFC,0x0F,0xFF,
  0x00,0x00,0xF0,0x01,0xE0,0x03,0xC0,0x00,
  0x30,0x00,0x00,0x03,0x00,0x00,0x3F,0xFC,
  0x0F,0xFF,0x00,0x00,0xF0,0x01,0xE0,0x03,
  0xC0,0x00,0x30,0x00,0x00,0x03,0x00,0x00,
  0x1F,0xFC,0x0F,0xFE,0x00,0x00,0xF0,0x01,
  0xE0,0x03,0xC0,0x00,0x10,0x00,0x00,0x02,
  0x00,0x00,0x0F,0xFC,0x0F,0xFC,0x00,0x00,
  0xF0,0x01,0xE0,0x03,0xC0,0x00,0x10,0x00,
  0x00,0x02,0x00,0x00,0x1F,0xFC,0x0F,0xFE,
  0x00,0x00,0x60,0x01,0xE0,0x05,0x80,0x00,
  0x10,0x00,0x00,0x06,0x00,0x00,0x07,0xFC,
  0x0F,0xFC,0x00,0x00,0x78,0x01,0xE0,0x03,
  0x80,0x00,0x08,0x00,0x00,0x04,0x00,0x00,
  0x0F,0xFC,0x0F,0xFC,0x00,0x00,0x34,0x01,
  0xE0,0x0B,0x00,0x00,0x0C,0x00,0x00,0x0C,
  0x00,0x00,0x07,0xFE,0x0F,0xF8,0x00,0x00,
  0x3A,0x03,0xE0,0x17,0x00,0x00,0x06,0x00,
  0x00,0x18,0x00,0x00,0x01,0xF8,0x07,0xE0,
  0x00,0x00,0x1F,0x03,0xE0,0x3E,0x00,0x00,
  0x03,0x04,0x08,0x30,0x00,0x00,0x00,0xF8,
  0x07,0xC0,0x00,0x00,0x0F,0x8F,0xFC,0x7C,
  0x00,0x00,0x01,0x80,0x00,0x60,0x00,0x00,
  0x00,0xFF,0xFF,0x40,0x00,0x00,0x07,0x40,
  0x01,0xB8,0x00,0x00,0x00,0xC0,0x01,0xC0,
  0x00,0x00,0x00,0x7F,0xFE,0x80,0x00,0x00,
  0x03,0xA0,0x03,0x70,0x00,0x00,0x00,0x60,
  0x03,0x80,0x00,0x00,0x00,0x17,0xFA,0x00,
  0x00,0x00,0x01,0xEF,0xFD,0xE0,0x00,0x00,
  0x00,0x1F,0xFE,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xC0,
  0x00,0x00,0x00,0x07,0xF8,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,
  0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x0F,0xFC,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00
};

static struct MyImageSpec warnimagespec =
{
	(ULONG *)warndata,
	warnpal,
	WARNWIDTH,
	WARNHEIGHT,
	WARNCOLS,
	WARNWIDTH,
	WARNHEIGHT
};

/* Ask Image */

#define ASKWIDTH 34
#define ASKHEIGHT 34
#define ASKCOLS 8

UBYTE askpal[] =
{
	0xAA,0xAA,0xAA,0x00,0x00,0x00,
	0xFB,0xFB,0xFB,0xC6,0xC6,0xC6,
	0x8A,0x8A,0x8A,0x69,0x69,0x69,
	0x49,0x49,0x49,0x28,0x28,0x28
};

UBYTE askdata[] =
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,
  0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x3F,0xFF,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x03,0xF0,0x00,
  0x00,0x00,0x00,0xFF,0xFF,0xC0,0x00,0x00,
  0x00,0x07,0xF8,0x00,0x00,0x00,0x00,0x10,
  0x02,0x00,0x00,0x00,0x01,0xEC,0x0D,0xE0,
  0x00,0x00,0x00,0x1F,0xFE,0x00,0x00,0x00,
  0x00,0x48,0x06,0x80,0x00,0x00,0x03,0xB7,
  0xF9,0x70,0x00,0x00,0x00,0x78,0x05,0x80,
  0x00,0x00,0x00,0xC0,0x03,0xC0,0x00,0x00,
  0x07,0x3F,0xFE,0x38,0x00,0x00,0x00,0xE0,
  0x00,0xC0,0x00,0x00,0x00,0x03,0xF1,0x80,
  0x00,0x00,0x0F,0xF9,0x5E,0x7C,0x00,0x00,
  0x01,0xC7,0x61,0x60,0x00,0x00,0x00,0x07,
  0xF8,0xC0,0x00,0x00,0x1F,0xF0,0x0F,0xBE,
  0x00,0x00,0x03,0x8C,0x10,0x30,0x00,0x00,
  0x05,0x8F,0xFC,0xE8,0x00,0x00,0x3A,0x70,
  0x07,0x97,0x00,0x00,0x06,0x88,0x08,0x58,
  0x00,0x00,0x0F,0x0F,0xFC,0x7C,0x00,0x00,
  0x30,0xF8,0x03,0xC3,0x00,0x00,0x0C,0x08,
  0x04,0x0C,0x00,0x00,0x0F,0x07,0xFC,0x3C,
  0x00,0x00,0x70,0xF0,0x03,0xC3,0x80,0x00,
  0x08,0x0C,0x00,0x04,0x00,0x00,0x17,0x03,
  0xF8,0x3E,0x00,0x00,0x68,0xF9,0x03,0xC1,
  0x80,0x00,0x18,0x07,0x04,0x02,0x00,0x00,
  0x0F,0x80,0xF4,0x7C,0x00,0x00,0xF0,0xFD,
  0x07,0xC3,0xC0,0x00,0x10,0x83,0x08,0x02,
  0x00,0x00,0x0F,0xC0,0xF8,0xFC,0x00,0x00,
  0xF0,0x7D,0x0F,0x83,0xC0,0x00,0x10,0x41,
  0x10,0x42,0x00,0x00,0x3F,0xE0,0xD1,0x7F,
  0x00,0x00,0xF0,0x19,0x1F,0x83,0xC0,0x00,
  0x30,0x21,0x20,0x83,0x00,0x00,0x3F,0xF5,
  0xE3,0xFF,0x00,0x00,0xF0,0x03,0x3E,0x03,
  0xC0,0x00,0x30,0x1F,0x41,0x03,0x00,0x00,
  0x3F,0xFF,0x45,0xFF,0x00,0x00,0xF0,0x00,
  0x7E,0x03,0xC0,0x00,0x30,0x00,0x82,0x03,
  0x00,0x00,0x3F,0xFE,0x8F,0xFF,0x00,0x00,
  0xF0,0x00,0xF8,0x03,0xC0,0x00,0x30,0x01,
  0x04,0x03,0x00,0x00,0x3F,0xFD,0x17,0xFF,
  0x00,0x00,0xF0,0x01,0xF8,0x03,0xC0,0x00,
  0x30,0x02,0x08,0x03,0x00,0x00,0x3F,0xFF,
  0x3F,0xFF,0x00,0x00,0xF0,0x03,0xE0,0x03,
  0xC0,0x00,0x30,0x00,0x10,0x03,0x00,0x00,
  0x0F,0xFC,0x1F,0xFC,0x00,0x00,0xF0,0x03,
  0xE0,0x03,0xC0,0x00,0x10,0x00,0x20,0x02,
  0x00,0x00,0x0F,0xFC,0x3F,0xFC,0x00,0x00,
  0xF0,0x03,0xC0,0x03,0xC0,0x00,0x10,0x00,
  0x00,0x02,0x00,0x00,0x1F,0xFC,0x3F,0xFE,
  0x00,0x00,0x60,0x03,0xC0,0x01,0x80,0x00,
  0x10,0x00,0x00,0x02,0x00,0x00,0x07,0xFC,
  0x3F,0xF8,0x00,0x00,0x78,0x01,0x80,0x07,
  0x80,0x00,0x08,0x02,0x40,0x04,0x00,0x00,
  0x0F,0xFC,0x3F,0xFC,0x00,0x00,0x30,0x03,
  0xC0,0x03,0x00,0x00,0x0C,0x03,0xC0,0x0C,
  0x00,0x00,0x05,0xFC,0x3F,0xE8,0x00,0x00,
  0x3A,0x03,0xC0,0x17,0x00,0x00,0x06,0x03,
  0xC0,0x18,0x00,0x00,0x00,0xFE,0x7F,0xC0,
  0x00,0x00,0x1F,0x0B,0xD0,0x3E,0x00,0x00,
  0x03,0x0C,0x30,0x30,0x00,0x00,0x00,0x7C,
  0x3F,0x80,0x00,0x00,0x0F,0x83,0xC0,0x7C,
  0x00,0x00,0x01,0x8C,0x30,0x60,0x00,0x00,
  0x00,0xFC,0x3F,0xC0,0x00,0x00,0x07,0x03,
  0xC0,0x38,0x00,0x00,0x00,0xCC,0x30,0xC0,
  0x00,0x00,0x00,0x7E,0x7F,0x80,0x00,0x00,
  0x03,0x8B,0xD0,0x70,0x00,0x00,0x00,0x6C,
  0x31,0x80,0x00,0x00,0x00,0x10,0x32,0x00,
  0x00,0x00,0x01,0xEF,0xFD,0xE0,0x00,0x00,
  0x00,0x1F,0xFE,0x00,0x00,0x00,0x00,0x00,
  0x30,0x00,0x00,0x00,0x00,0xFF,0xFF,0xC0,
  0x00,0x00,0x00,0x03,0xF0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,
  0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x0F,0xFC,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00
};

static struct MyImageSpec askimagespec =
{
	(ULONG *)askdata,
	askpal,
	ASKWIDTH,
	ASKHEIGHT,
	ASKCOLS,
	ASKWIDTH,
	ASKHEIGHT
};

#endif
