/*
    Copyright © 2017, The Apollo Team. All rights reserved.
*/

#ifndef _SAGAGFXBITMAP_H
#define _SAGAGFXBITMAP_H

#define IID_Hidd_SAGAGFXBitMap "hidd.bitmap.saga"

#include "sagartg.h"

/* This structure is used as instance data for the bitmap class. */

struct sagabm_data
{
    struct MinNode node;
    struct SignalSemaphore bmLock;
    OOP_Object	    	*pixfmtobj;	/* Cached pixelformat object */
    OOP_Object	    	*gfxhidd;	/* Cached driver object */
    ULONG rgbformat;
    UBYTE *VideoData;
    ULONG memsize;
    BOOL invram;
    WORD width, height, align;
    WORD bytesperpixel;
    WORD bytesperline;
    UBYTE *palette;
    WORD topedge, leftedge;
    WORD locked;
};

#define LOCK_BITMAP(data)    {ObtainSemaphore(&(data)->bmLock);}
#define TRYLOCK_BITMAP(data) (AttemptSemaphore(&(data)->bmLock))
#define UNLOCK_BITMAP(data)  {ReleaseSemaphore(&(data)->bmLock);}

#endif
