/*
    Copyright © 2017, The Apollo Team. All rights reserved.
*/

#ifndef HIDD_Vampire_H
#define HIDD_Vampire_H

#include <exec/libraries.h>
#include <oop/oop.h>
#include <exec/semaphores.h>
#include <exec/interrupts.h>
#include <graphics/gfxbase.h>

#include "vampiregfx_hidd.h"

#define __IHidd_BitMap			(csd->hiddBitMapAttrBase)
#define __IHidd_PlanarBM		(csd->hiddPlanarBitMapAttrBase)
#define __IHidd_VampireGFXBitmap	(csd->hiddVampireGFXBitMapAttrBase)
#define __IHidd_GC				(csd->hiddGCAttrBase)
#define __IHidd_Sync			(csd->hiddSyncAttrBase)
#define __IHidd_PixFmt			(csd->hiddPixFmtAttrBase)
#define __IHidd_Gfx				(csd->hiddGfxAttrBase)
#define __IHidd_Attr			(sd->hiddAttrBase)
#define __IHidd_ColorMap		(csd->hiddColorMapAttrBase)

#define HiddBitMapBase			(csd->hiddBitMapBase)
#define HiddColorMapBase		(csd->hiddColorMapBase)
#define HiddGfxBase				(csd->hiddGfxBase)

#include <hidd/gfx.h>

#define UtilityBase	((csd)->cs_UtilityBase) 

struct RTGMode
{
	struct Node node;
	ULONG modeid;
	UWORD width, height;
	OOP_Object *pf;
	OOP_Object *sync;
};

struct vampiregfx_staticdata
{
    OOP_Class		*basebm;	/* baseclass for CreateObject */
    OOP_Class		*gfxclass;
    OOP_Class		*bmclass;

	OOP_AttrBase hiddBitMapAttrBase;
	OOP_AttrBase hiddVampireGFXBitMapAttrBase;
	OOP_AttrBase hiddGCAttrBase;
	OOP_AttrBase hiddSyncAttrBase;
	OOP_AttrBase hiddPixFmtAttrBase;
	OOP_AttrBase hiddGfxAttrBase;
	OOP_AttrBase hiddAttrBase;
	OOP_AttrBase hiddColorMapAttrBase;

	OOP_MethodID hiddBitMapBase;
	OOP_MethodID hiddColorMapBase;
	OOP_MethodID hiddGfxBase;

	struct List rtglist;
	struct List bitmaplist;
	struct Library *CardBase;
	struct ExecBase *cs_SysBase;
	struct Library *cs_IntuitionBase;
	struct Library *cs_UtilityBase;
	struct Library *cs_OOPBase;
	struct bm_data *disp;
	APTR romvector;
	ULONG rgbformat;
	struct ModeInfo *modeinfo;
	struct ModeInfo *fakemodeinfo;
	UBYTE *boardinfo;
	UBYTE *bitmapextra;
	UBYTE *vram_start;
	ULONG vram_size;
	ULONG vram_used, fram_used;
	struct MemHeader *vmem;
	
	WORD sprite_width, sprite_height;
	BOOL hardwaresprite;
	WORD spritecolors;

	BOOL initialized;
	BOOL superforward; 
	
	UWORD dwidth, dheight;
	ULONG dmodeid;

	UWORD maxwidth[5];
	UWORD maxheight[5];

	struct ViewPort *viewport;
    void (*acb)(void *data, void *bm);
    APTR acbdata;
    
    struct SignalSemaphore HWLock;
    struct SignalSemaphore MultiBMLock;
};

struct VampireGFXclbase
{
    struct Library        library;
    
    struct vampiregfx_staticdata csd;
    IPTR                  cs_SegList;
};

#undef CSD
#define CSD(cl)     	(&((struct VampireGFXclbase *)cl->UserData)->csd)

#define SysBase         (csd->cs_SysBase)
#define OOPBase         (csd->cs_OOPBase)

#define LOCK_HW         {ObtainSemaphore(&(csd)->HWLock);}
#define UNLOCK_HW       {ReleaseSemaphore(&(csd)->HWLock);}

#define LOCK_MULTI_BITMAP   {ObtainSemaphore(&(csd)->MultiBMLock);}
#define UNLOCK_MULTI_BITMAP {ReleaseSemaphore(&(csd)->MultiBMLock);}

/* Private instance data for Gfx hidd class */
struct gfx_data
{
	struct MinList bitmaps;		/* Currently shown bitmap objects */
};

#endif /* HIDD_Vampire_H */

