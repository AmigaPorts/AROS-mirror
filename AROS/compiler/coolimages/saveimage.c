/*
    Copyright � 1995-2001, The AROS Development Team. All rights reserved.
    $Id$
*/

#include "coolimages.h"

#define SAVEIMAGE_WIDTH     23
#define SAVEIMAGE_HEIGHT    16
#define SAVEIMAGE_COLORS    5

static const UBYTE saveimage_data[] =
{
	00,04,04,04,04,04,04,04,04,04,04,04,04,04,04,00,00,00,00,00,00,00,00,
	04,04,02,02,02,02,02,02,02,02,02,02,02,04,04,00,00,00,00,00,00,00,00,
	04,04,02,02,04,04,04,04,04,04,04,02,02,04,02,03,03,03,03,00,00,00,00,
	04,04,02,02,02,02,02,02,02,02,02,02,02,02,03,03,03,03,03,01,00,00,00,
	04,04,02,02,04,04,04,04,02,02,02,02,02,03,03,03,03,03,03,03,01,00,00,
	04,04,02,02,02,02,02,02,02,02,02,02,02,03,03,03,01,03,03,03,03,01,00,
	04,04,04,02,02,02,02,02,02,02,02,02,03,03,03,01,00,03,03,03,03,03,01,
	04,04,04,04,04,04,04,04,02,03,03,02,03,03,01,02,00,00,03,03,03,03,01,
	04,04,04,04,04,04,04,04,02,03,03,03,03,03,01,02,00,00,00,03,03,03,01,
	04,04,04,02,02,02,02,02,02,03,03,03,03,03,03,03,03,00,00,00,03,01,00,
	04,04,04,02,02,04,04,02,02,03,03,03,03,03,03,03,01,00,00,00,00,00,00,
	04,04,04,02,02,04,04,02,02,02,03,03,03,03,01,01,00,00,00,00,00,00,00,
	04,04,04,02,02,04,04,02,02,02,03,03,03,01,02,01,00,00,00,00,00,00,00,
	04,04,04,02,02,02,02,02,02,02,02,03,01,02,04,01,00,00,00,00,00,00,00,
	00,01,01,01,01,01,01,01,01,01,01,02,02,01,00,00,00,00,00,00,00,00,00,
	00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00
};

static const UBYTE saveimage_pal[] =
{
	0xb3,0xb3,0xb3,0x00,0x00,0x00,
	0xe0,0xe0,0xe0,0xdb,0x20,0x26,
	0x65,0x4b,0xbf
};

const struct CoolImage cool_saveimage =
{
	saveimage_data,
	saveimage_pal,
	SAVEIMAGE_WIDTH,
	SAVEIMAGE_HEIGHT,
	SAVEIMAGE_COLORS
};