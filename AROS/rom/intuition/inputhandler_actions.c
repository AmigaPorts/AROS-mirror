#define AROS_ALMOST_COMPATIBLE 1 /* NEWLIST macro */
#include <proto/exec.h>
#include <proto/boopsi.h>
#include <proto/intuition.h>
#include <proto/alib.h>
#include <proto/layers.h>
#include <proto/graphics.h>
#include <proto/keymap.h>
#include <exec/memory.h>
#include <exec/alerts.h>
#include <exec/interrupts.h>
#include <exec/ports.h>
#include <intuition/intuition.h>
#include <intuition/intuitionbase.h>
#include <intuition/gadgetclass.h>
#include <intuition/cghooks.h>
#include <intuition/sghooks.h>
#include <devices/inputevent.h>
#include "inputhandler.h"

#include "boopsigadgets.h"
#include "boolgadgets.h"
#include "propgadgets.h"
#include "strgadgets.h"
#include "gadgets.h"
#include "intuition_intern.h" /* EWFLG_xxx */
#include "inputhandler_support.h"
#include "inputhandler_actions.h"
#include "menus.h"

#undef DEBUG
#define DEBUG 0
#include <aros/debug.h>

/*******************************************************************************************************/

static void WindowSizeWillChange(struct Window *targetwindow, WORD dx, WORD dy, 
				 struct IntuitionBase *IntuitionBase)
{
    /* Erase the old frame on the right/lower side if
       new size is bigger than old size
    */

    D(bug("********* WindowSizeWillChange ********\n"));

    if ( ((dx > 0) && (targetwindow->BorderRight  > 0)) ||
	 ((dy > 0) && (targetwindow->BorderBottom > 0)) )
    {
        struct RastPort 	*rp = targetwindow->BorderRPort;
        struct Layer 	*L = rp->Layer;
        struct Rectangle 	rect;
        struct Region 	*oldclipregion;
        WORD 		ScrollX;
        WORD 		ScrollY;

        /* 
        ** In case a clip region is installed then I have to 
        ** install the regular cliprects of the layer
        ** first. Otherwise the frame might not get cleared correctly.
        */

        LockLayer(0, L);

        oldclipregion = InstallClipRegion(L, NULL);

	ScrollX = L->Scroll_X;
        ScrollY = L->Scroll_Y;

	L->Scroll_X = 0;
        L->Scroll_Y = 0;

        if ((dx > 0) && (targetwindow->BorderRight > 0))
        {
	    rect.MinX = targetwindow->Width - targetwindow->BorderRight;
	    rect.MinY = 0;
	    rect.MaxX = targetwindow->Width - 1;
	    rect.MaxY = targetwindow->Height - 1;

            EraseRect(rp, rect.MinX, rect.MinY, rect.MaxX, rect.MaxY);

	    OrRectRegion(L->DamageList, &rect);
	    L->Flags |= LAYERREFRESH;
        }

        if ((dy > 0) && (targetwindow->BorderBottom > 0))

        {
	    rect.MinX = 0;
	    rect.MinY = targetwindow->Height - targetwindow->BorderBottom;
	    rect.MaxX = targetwindow->Width - 1;
	    rect.MaxY = targetwindow->Height - 1;

            EraseRect(rp, rect.MinX, rect.MinY, rect.MaxX, rect.MaxY);

	    OrRectRegion(L->DamageList, &rect);
	    L->Flags |= LAYERREFRESH;
        }


        /*
        ** Reinstall the clipregions rectangles if there are any.
        */
        if (NULL != oldclipregion)
        {
             InstallClipRegion(L, oldclipregion);
        }

	L->Scroll_X = ScrollX;
        L->Scroll_Y = ScrollY;

	UnlockLayer(L);

    } /* if ( ((dx > 0) && (targetwindow->BorderRight  > 0)) || ((dy > 0) && (targetwindow->BorderBottom > 0)) ) */

    /* Before resizing the layers eraserect the area of all
       GFLG_REL??? gadgets and add the area to the damagelist */

    EraseRelGadgetArea(targetwindow, FALSE, IntuitionBase);
	
}

/*******************************************************************************************************/

static void WindowSizeHasChanged(struct Window *targetwindow, WORD dx, WORD dy,
				 BOOL is_sizewindow, struct IntuitionBase *IntuitionBase)
{
    struct Layer *lay;
    
    D(bug("********* WindowSizeHasChanged ********\n"));

    /* Relayout GFLG_REL??? gadgets */
    DoGMLayout(targetwindow->FirstGadget, targetwindow, NULL, -1, FALSE, IntuitionBase);

    /* Add the new area of all GFLG_REL??? gadgets to the damagelist, but
       don't EraseRect() as the gadgets will be re-rendered at their new
       position anyway */
    EraseRelGadgetArea(targetwindow, TRUE, IntuitionBase);

    /* If new size is smaller than old size add right/bottom
       frame to damagelist */
    if ( ((dx < 0) && (targetwindow->BorderRight  > 0)) ||
	 ((dy < 0) && (targetwindow->BorderBottom > 0)) )
    {
	struct Rectangle rect;

	lay = targetwindow->BorderRPort->Layer;

	LockLayer(0, lay);

	if ((dx < 0) && (targetwindow->BorderRight > 0))
	{
	    rect.MinX = targetwindow->Width - targetwindow->BorderRight;
	    rect.MinY = 0;
	    rect.MaxX = targetwindow->Width - 1;
	    rect.MaxY = targetwindow->Height - 1;

	    OrRectRegion(lay->DamageList, &rect);
	    lay->Flags |= LAYERREFRESH;
	}

	if ((dy < 0) && (targetwindow->BorderBottom > 0))
	{
	    rect.MinX = 0;
	    rect.MinY = targetwindow->Height - targetwindow->BorderBottom;
	    rect.MaxX = targetwindow->Width - 1;
	    rect.MaxY = targetwindow->Height - 1;

	    OrRectRegion(lay->DamageList, &rect);
	    lay->Flags |= LAYERREFRESH;
	}

	UnlockLayer(lay);

    } /* if ( ((dx < 0) && (targetwindow->BorderRight > 0)) || ((dy < 0) && (targetwindow->BorderBottom > 0)) ) */

    if (IS_GZZWINDOW(targetwindow))
    {
        lay = targetwindow->BorderRPort->Layer;

	if (lay->Flags & LAYERREFRESH)
	{
	    Gad_BeginUpdate(lay, IntuitionBase);	
	    RefreshWindowFrame(targetwindow);
	    lay->Flags &= ~LAYERREFRESH;
	    Gad_EndUpdate(lay, TRUE, IntuitionBase);
	}

	lay = targetwindow->WLayer;

	if (lay->Flags & LAYERREFRESH)
	{
	    Gad_BeginUpdate(lay, IntuitionBase);
	    int_refreshglist(targetwindow->FirstGadget, targetwindow, NULL, -1, 0, REFRESHGAD_BORDER, IntuitionBase);
	    Gad_EndUpdate(lay, IS_NOCAREREFRESH(targetwindow), IntuitionBase);
	}

    } else {
        lay = targetwindow->WLayer;

	if (lay->Flags & LAYERREFRESH)
	{
	    Gad_BeginUpdate(lay, IntuitionBase);
	    RefreshWindowFrame(targetwindow);
	    int_refreshglist(targetwindow->FirstGadget, targetwindow, NULL, -1, 0, REFRESHGAD_BORDER, IntuitionBase);
	    Gad_EndUpdate(lay, IS_NOCAREREFRESH(targetwindow), IntuitionBase);
	}
    }

    lay = targetwindow->WLayer;

    if (IS_NOCAREREFRESH(targetwindow))
    {
	LockLayer(0, lay);
        lay->Flags &= ~LAYERREFRESH;
	UnlockLayer(lay);
    }
	    
    if (is_sizewindow)
    {
	/* Send IDCMP_NEWSIZE to resized window */

	ih_fire_intuimessage(targetwindow,
			     IDCMP_NEWSIZE,
			     0,
			     targetwindow,
			     IntuitionBase);
    }
    
    /* Send IDCMP_CHANGEWINDOW to resized window */

    ih_fire_intuimessage(targetwindow,
		    	 IDCMP_CHANGEWINDOW,
			 CWCODE_MOVESIZE,
			 targetwindow,
			 IntuitionBase);

    lay = targetwindow->WLayer;
    
    if (lay->Flags & LAYERREFRESH)
    {
	ih_fire_intuimessage(targetwindow,
			     IDCMP_REFRESHWINDOW,
			     0,
			     targetwindow,
			     IntuitionBase);
    }  
}

/*******************************************************************************************************/

static void DoMoveSizeWindow(struct Window *targetwindow, WORD NewLeftEdge, WORD NewTopEdge,
			     WORD NewWidth, WORD NewHeight, struct Layer **L, BOOL *CheckLayersBehind,
			     struct IntuitionBase *IntuitionBase)
{
    struct IntWindow 	* w 	     = (struct IntWindow *)targetwindow;
    struct Layer	*targetlayer = targetwindow->WLayer;
    WORD		OldLeftEdge  = targetwindow->LeftEdge;
    WORD		OldTopEdge   = targetwindow->TopEdge;
    WORD 		OldWidth     = targetwindow->Width;
    WORD 		OldHeight    = targetwindow->Height;
    WORD 		pos_dx, pos_dy, size_dx, size_dy;
    		
    /* correct new window coords if necessary */

    FixWindowCoords(targetwindow, &NewLeftEdge, &NewTopEdge, &NewWidth, &NewHeight);

    pos_dx  = NewLeftEdge - OldLeftEdge;
    pos_dy  = NewTopEdge  - OldTopEdge;
    size_dx = NewWidth    - OldWidth;
    size_dy = NewHeight   - OldHeight;

    if (!pos_dx && !pos_dy && !size_dx && !size_dy) return;

    if (size_dx || size_dy)
    {
	WindowSizeWillChange(targetwindow, size_dx, size_dy, IntuitionBase);
    }

    targetwindow->LeftEdge = NewLeftEdge;
    targetwindow->TopEdge  = NewTopEdge;
    targetwindow->Width    = NewWidth;
    targetwindow->Height   = NewHeight; 

    /* check for GZZ window */
    if (IS_GZZWINDOW(targetwindow))
    {
	/* move outer window first */
	MoveSizeLayer(targetwindow->BorderRPort->Layer, pos_dx, pos_dy, size_dx, size_dy);
    }

    MoveSizeLayer(targetlayer, pos_dx, pos_dy, size_dx, size_dy);

    if (w->ZipLeftEdge != ~0) w->ZipLeftEdge = OldLeftEdge;
    if (w->ZipTopEdge  != ~0) w->ZipTopEdge  = OldTopEdge;
    if (w->ZipWidth    != ~0) w->ZipWidth    = OldWidth;
    if (w->ZipHeight   != ~0) w->ZipHeight   = OldHeight;

    if (pos_dx || pos_dy) UpdateMouseCoords(targetwindow);

    if (size_dx || size_dy)
    {
	/* This func also takes care of sending IDCMP_CHANGEWINDOW
	   and IDCMP_REFRESHWINDOW to targetwindow, therefore ... */

	WindowSizeHasChanged(targetwindow, size_dx, size_dy, FALSE, IntuitionBase);

	/* ... start checking refresh behind targetwindow */

	*L = targetwindow->BorderRPort->Layer->back;
    } else {
	/* Send IDCMP_CHANGEWINDOW to resized window */

	ih_fire_intuimessage(targetwindow,
		    	     IDCMP_CHANGEWINDOW,
			     CWCODE_MOVESIZE,
			     targetwindow,
			     IntuitionBase);

	/* Also check targetwindow for refresh */

	*L = targetlayer;
    }

    if ((size_dx < 0) || (size_dy < 0) || pos_dx || pos_dy)
    {
	*CheckLayersBehind = TRUE;
    }

}

/*******************************************************************************************************/

static void CheckLayerRefresh(struct Layer *lay, struct Screen *targetscreen, struct IntuitionBase *IntuitionBase)
{   
    if (lay->Flags & LAYERREFRESH)
    {
        struct Window *win = (struct Window *)lay->Window;

	if (lay == targetscreen->BarLayer)
	{
	    RenderScreenBar(targetscreen, TRUE, IntuitionBase);
	}
	else if (win)
	{
	    /* Does it belong to a GZZ window and is it
	       the outer window of that GZZ window? */
	    if (IS_GZZWINDOW(win) && (lay == win->BorderRPort->Layer))
	    {
	        /* simply refresh that window's frame */

		Gad_BeginUpdate(lay, IntuitionBase);
	        RefreshWindowFrame(win);
	        lay->Flags &= ~LAYERREFRESH;
		Gad_EndUpdate(lay, TRUE, IntuitionBase);
	    }
	    else
	    {
	        WindowNeedsRefresh(win, IntuitionBase);
	    }
	}
	
    } /* if (lay->Flags & LAYERREFRESH) */
}

/*******************************************************************************************************/

void HandleDeferedActions(struct IIHData *iihdata,
			  struct IntuitionBase *IntuitionBase)
{
    struct DeferedActionMessage *am, *next_am;
    
    D(bug("Handle defered action messages\n"));
    
    ObtainSemaphore(&GetPrivIBase(IntuitionBase)->DeferedActionLock);

    am = (struct DeferedActionMessage *)iihdata->IntuiDeferedActionQueue.mlh_Head;
    next_am = (struct DeferedActionMessage *)am->ExecMessage.mn_Node.ln_Succ;
    
    ReleaseSemaphore(&GetPrivIBase(IntuitionBase)->DeferedActionLock);

    /* Handle defered action messages */

    while(next_am)
    {
        struct Window * targetwindow = am->Window;
	struct Screen * targetscreen = targetwindow ? targetwindow->WScreen : NULL;
        struct Layer  * L, *targetlayer = targetwindow ? targetwindow->WLayer : NULL;
        BOOL CheckLayersBehind = FALSE;
        BOOL CheckLayersInFront = FALSE;
	BOOL remove_am = TRUE;
	BOOL free_am = TRUE;
	
	if (MENUS_ACTIVE && (am->Code != AMCODE_CLOSEWINDOW))
	{
	    remove_am = FALSE;
	    free_am = FALSE;
	    
	    goto next_action;
	}
			
 	switch (am->Code)
	{
	    case AMCODE_CLOSEWINDOW: {
		if (!IS_GZZWINDOW(targetwindow))
		{
		    /* not a GGZ window */
		    L = targetlayer->back;
		}
		else
		{
		    /* a GZZ window */
		    L = targetlayer->back->back;
		}

		if (NULL != L)
		    CheckLayersBehind = TRUE;
		
		ObtainSemaphore(&GetPrivIBase(IntuitionBase)->DeferedActionLock);
		Remove(&am->ExecMessage.mn_Node);
		ReleaseSemaphore(&GetPrivIBase(IntuitionBase)->DeferedActionLock);
		
		remove_am = FALSE; /* because int_closewindow frees the message!!! */
		free_am = FALSE;
		
		int_closewindow(am, IntuitionBase);
	    break; }

	    case AMCODE_WINDOWTOFRONT: {
		if (!(targetlayer->Flags & LAYERBACKDROP))
		{
		    /* GZZ or regular window? */
		    if (IS_GZZWINDOW(targetwindow))
		    {
			/* bring outer window to front first!! */

			UpfrontLayer(NULL, targetwindow->BorderRPort->Layer);
			if (targetwindow->BorderRPort->Layer->Flags & LAYERREFRESH)
			{
			    Gad_BeginUpdate(targetwindow->BorderRPort->Layer, IntuitionBase);
		            RefreshWindowFrame(targetwindow);
			    targetwindow->BorderRPort->Layer->Flags &= ~LAYERREFRESH;
			    Gad_EndUpdate(targetwindow->BorderRPort->Layer, TRUE, IntuitionBase);
			}
		    }

		    UpfrontLayer(NULL, targetlayer);

		    /* only this layer (inner window) needs to be updated */
		    if (targetlayer->Flags & LAYERREFRESH)
		    {
			Gad_BeginUpdate(targetlayer, IntuitionBase);
			
			if (!IS_GZZWINDOW(targetwindow))
			{
			    RefreshWindowFrame(targetwindow);
			}
			
			RefreshGadgets(targetwindow->FirstGadget, targetwindow, NULL);
			
			if (IS_NOCAREREFRESH(targetwindow))
			{
			    targetlayer->Flags &= ~LAYERREFRESH;
			}
			
			Gad_EndUpdate(targetlayer, IS_NOCAREREFRESH(targetwindow), IntuitionBase);

			if (!IS_NOCAREREFRESH(targetwindow))
			{
			    ih_fire_intuimessage(targetwindow,
			                	 IDCMP_REFRESHWINDOW,
						 0,
						 targetwindow,
						 IntuitionBase);
			}
			
		    } /* if (targetlayer->Flags & LAYERREFRESH) */
		    
		} /* if (!(targetlayer->Flags & LAYERBACKDROP)) */
		
		NotifyDepthArrangement(targetwindow, IntuitionBase);
	    break; }

	    case AMCODE_WINDOWTOBACK: {
		/* I don't move backdrop layers! */
		if (!(targetlayer->Flags & LAYERBACKDROP))
		{

		    BehindLayer(0, targetlayer);

		    /* GZZ window or regular window? */
		    if (IS_GZZWINDOW(targetwindow))
		    {
			/* move outer window behind! */
			/* attention: targetlayer->back would not be valid as
		                      targetlayer already moved!! 
			*/
			BehindLayer(0, targetwindow->BorderRPort->Layer);

			/* 
                	 * stegerg: check all layers including inner gzz
			 *          layer because of this: inner layer
			 *          was moved back first, so it gets 
			 *          completely under the outer layer.
			 *          Maybe it would be better to move the
			 *          outer layer first and then move the
			 *          inner layer with MoveLayerinfrontof
			 *          (outerlayer) ????
			 * 
                	 */

			L = targetlayer; /* targetlayer->front */
			CheckLayersInFront = TRUE;

		    } else {

                	/* 
                	 * Check all layers in front of the layer.
                	 */
			L = targetlayer->front;
			CheckLayersInFront = TRUE;
		    }
		}

		NotifyDepthArrangement(targetwindow, IntuitionBase);
	    break; }

	    case AMCODE_ACTIVATEWINDOW: {		
		/* On the Amiga ActivateWindow is delayed if there
		   is an active gadget (altough this does not seem
		   to be true for string gadgets). We just ignore
		   ActivateWindow in such a case. */
		   
		if (!iihdata->ActiveGadget)
		{
		    struct Window *w = IntuitionBase->ActiveWindow;
		    
	    	    if(w)
		    {
		    	ih_fire_intuimessage(w,
					     IDCMP_INACTIVEWINDOW,
					     0,
					     w,
					     IntuitionBase);
		    }

		    int_activatewindow(targetwindow, IntuitionBase);
		    
		    ih_fire_intuimessage(targetwindow,
					 IDCMP_ACTIVEWINDOW,
					 0,
					 targetwindow,
					 IntuitionBase);
		    
		} /* if (!iihdata->ActiveGadget) */
		
	    break; }


            case AMCODE_MOVEWINDOW: { 
		struct IntWindow *w = (struct IntWindow *)targetwindow;
		
		/* correct dx, dy if necessary */
		
		if ((targetwindow->LeftEdge + targetwindow->Width + am->dx) > targetwindow->WScreen->Width)
		{
		    am->dx = targetwindow->WScreen->Width - (targetwindow->LeftEdge + targetwindow->Width);
		} else if ((targetwindow->LeftEdge + am->dx) < 0)
		{
		    am->dx = -targetwindow->LeftEdge;
		}

		if ((targetwindow->TopEdge + targetwindow->Height + am->dy) > targetwindow->WScreen->Height)
		{
		    am->dy = targetwindow->WScreen->Height - (targetwindow->TopEdge + targetwindow->Height);
		} else if ((targetwindow->TopEdge + am->dy) < 0)
		{
		    am->dy = -targetwindow->TopEdge;
		}
		
		if (am->dx || am->dy)
		{   
                    MoveLayer(0,
                              targetlayer,
                              am->dx,
                              am->dy);

                    /* in case of GZZ windows also move outer window */
                    if (IS_GZZWINDOW(targetwindow))
                    {
                	MoveLayer(NULL,
                        	  targetwindow->BorderRPort->Layer,
                        	  am->dx,
                        	  am->dy);
/*                	RefreshWindowFrame(targetwindow);*/
                    }

                    if (w->ZipLeftEdge != ~0) w->ZipLeftEdge = targetwindow->LeftEdge;
                    if (w->ZipTopEdge  != ~0) w->ZipTopEdge  = targetwindow->TopEdge;

                    targetwindow->LeftEdge += am->dx;
                    targetwindow->TopEdge  += am->dy;

                    CheckLayersBehind = TRUE;
                    L = targetlayer;

		    UpdateMouseCoords(targetwindow);
		    
		    /* Send IDCMP_CHANGEWINDOW to moved window */

		    ih_fire_intuimessage(targetwindow,
		    			 IDCMP_CHANGEWINDOW,
					 CWCODE_MOVESIZE,
					 targetwindow,
					 IntuitionBase);
					 
		} /* if (am->dx || am->dy) */
		
            break; }

            case AMCODE_MOVEWINDOWINFRONTOF: { 
                /* If GZZ window then also move outer window */
                if (IS_GZZWINDOW(targetwindow))
		{
                    MoveLayerInFrontOf(targetwindow->BorderRPort->Layer,
                                       am->BehindWindow->WLayer);
/*                    RefreshWindowFrame(targetwindow);*/
                }
                MoveLayerInFrontOf(targetwindow->WLayer,
                                   am->BehindWindow->WLayer);

                CheckLayersBehind = TRUE;
                L = targetlayer;

		NotifyDepthArrangement(targetwindow, IntuitionBase);
            break; }

            case AMCODE_SIZEWINDOW: {
                WORD OldLeftEdge  = targetwindow->LeftEdge;
                WORD OldTopEdge   = targetwindow->TopEdge;
                WORD OldWidth     = targetwindow->Width;
                WORD OldHeight    = targetwindow->Height;
                WORD NewLeftEdge  = OldLeftEdge;
		WORD NewTopEdge   = OldTopEdge;
		WORD NewWidth	  = OldWidth + am->dx;
		WORD NewHeight	  = OldHeight + am->dy;
		WORD size_dx, size_dy;

                /* correct new window coords if necessary */

		FixWindowCoords(targetwindow, &NewLeftEdge, &NewTopEdge, &NewWidth, &NewHeight);
		
		if (NewLeftEdge != OldLeftEdge)
		{
		    /* am->dx was too big */
		    NewLeftEdge = OldLeftEdge;
		    NewWidth    = targetwindow->WScreen->Width - NewLeftEdge;
		}
		if (NewTopEdge != OldTopEdge)
		{
		    /* am->dy was too big */
		    NewTopEdge = OldTopEdge;
		    NewHeight  = targetwindow->WScreen->Height - NewTopEdge;		    
		}

		size_dx = NewWidth - OldWidth;
		size_dy = NewHeight - OldHeight;

		if (!size_dx && !size_dy) break;
		
		WindowSizeWillChange(targetwindow, size_dx, size_dy, IntuitionBase);

                ((struct IntWindow *)targetwindow)->ZipWidth  = targetwindow->Width;
                ((struct IntWindow *)targetwindow)->ZipHeight = targetwindow->Height;

                targetwindow->Width  += size_dx;
                targetwindow->Height += size_dy;

                /* I first resize the outer window if a GZZ window */
                if (IS_GZZWINDOW(targetwindow))
                {
                    SizeLayer(NULL, targetwindow->BorderRPort->Layer, size_dx, size_dy);
                }
                SizeLayer(NULL, targetlayer, size_dx, size_dy);

		WindowSizeHasChanged(targetwindow, am->dx, am->dy, TRUE, IntuitionBase);				

                /* 
                   Only if the window is smaller now there can be damage
                   to report to layers further behind.
                */
                if ((size_dx < 0) || (size_dy < 0))
                {
                    CheckLayersBehind = TRUE;
		    L = targetwindow->BorderRPort->Layer->back;
                }


            break; }

            case AMCODE_ZIPWINDOW: {
                struct IntWindow * w = (struct IntWindow *)targetwindow;
                WORD NewLeftEdge, NewTopEdge, NewWidth, NewHeight;
		
		NewLeftEdge = targetwindow->LeftEdge;
		if (w->ZipLeftEdge != ~0) NewLeftEdge = w->ZipLeftEdge;

		NewTopEdge = targetwindow->TopEdge;
		if (w->ZipTopEdge != ~0) NewTopEdge = w->ZipTopEdge;

		NewWidth = targetwindow->Width;
		if (w->ZipWidth != ~0) NewWidth = w->ZipWidth;

		NewHeight = targetwindow->Height;
		if (w->ZipHeight != ~0) NewHeight = w->ZipHeight;

		DoMoveSizeWindow(targetwindow, NewLeftEdge, NewTopEdge, NewWidth, NewHeight,
					       &L, &CheckLayersBehind, IntuitionBase);
		
            break; }

	    case AMCODE_CHANGEWINDOWBOX: {

		DoMoveSizeWindow(targetwindow, am->left, am->top, am->width, am->height,
					       &L, &CheckLayersBehind, IntuitionBase);
		
	    break; }
	
	    case AMCODE_ACTIVATEGADGET:
	    	/* Note: This message must not be freed, because
		   it must be replied back to the app by sending
		   SIGF_INTUITION to the app task and placing
		   a result code in am->Code!!! */

		ObtainSemaphore(&GetPrivIBase(IntuitionBase)->DeferedActionLock);
		Remove(&am->ExecMessage.mn_Node);
		ReleaseSemaphore(&GetPrivIBase(IntuitionBase)->DeferedActionLock);
		
		remove_am = FALSE;
		free_am = FALSE;

		am->Code = FALSE;
		
		/* Activate gadget only if no other gadget is
		   actually active and the gadget to be
		   activated is in the actual active window
		   and the gadget is not disabled */
		   
		if ((iihdata->ActiveGadget == NULL) &&
		    (IntuitionBase->ActiveWindow == targetwindow) &&
		    ((am->Gadget->Flags & GFLG_DISABLED) == 0))
		{

		    if (DoActivateGadget(targetwindow, am->Gadget, IntuitionBase))
		    {
		    	am->Code = TRUE;
		    }		
		} /* if gadget activation ok (no other gadget active, window active, ...) */
		
		Signal(am->Task, SIGF_INTUITION);
		break;
	    
	    case AMCODE_NEWPREFS:
		/*
		** The preferences were changed and now I need to inform
		** all interested windows about this.
		*/
		notify_newprefs(IntuitionBase);
	        break;
	
	    case AMCODE_SCREENSHOWTITLE:
	    	targetscreen = (struct Screen *)am->Gadget;
		if ((targetscreen->Flags & SHOWTITLE) && (am->dx == FALSE))
		{
		    BehindLayer(0, targetscreen->BarLayer);
		    
		    Forbid();
		    targetscreen->Flags &= ~SHOWTITLE;
		    Permit();
		    
		    L = targetscreen->BarLayer->front;
		    CheckLayersInFront = TRUE;
		    
		} else if (!(targetscreen->Flags & SHOWTITLE) && (am->dx == TRUE))
		{
		    UpfrontLayer(0, targetscreen->BarLayer);
		    
		    if (targetscreen->BarLayer->Flags & LAYERREFRESH)
		    {
		        RenderScreenBar(targetscreen, TRUE, IntuitionBase);
		    }
		    
		    Forbid();
		    targetscreen->Flags |= SHOWTITLE;
		    Permit();
		}
		break;
		
	}

 	/* targetwindow might be invalid here (AM_CLOSEWINDOW) !!!!!!!!! */
	
	if (TRUE == CheckLayersBehind)
	{
	    /* Walk through all layers behind including the layer L
	       and check whether a layer needs a refresh 
	    */ 
	    struct Layer * _L = L;

	    while (NULL != _L)
	    {
		CheckLayerRefresh(_L, targetscreen, IntuitionBase);
	        _L = _L->back;
 
	    } /* while (NULL != _L) */

	} /* if (TRUE == CheckLayersBehind) */

	if (TRUE == CheckLayersInFront)
	{
	    /* Walk through all layers in front of including the layer L
	       and check whether a layer needs a refresh 
	    */

	    if (TRUE == CheckLayersBehind)
		L = L->front; /* the layer L has already been checked */

	    while (NULL != L)
	    {  
                CheckLayerRefresh(L, targetscreen, IntuitionBase);
		L = L->front;

	    } /* while (NULL != L) */

	} /* if (TRUE == CheckLayersInFront) */

next_action:
    	ObtainSemaphore(&GetPrivIBase(IntuitionBase)->DeferedActionLock);	

	if (remove_am) Remove(&am->ExecMessage.mn_Node);
	if (free_am)   FreeMem(am, sizeof(struct DeferedActionMessage));

	am = next_am;
	next_am = (struct DeferedActionMessage *)am->ExecMessage.mn_Node.ln_Succ;

    	ReleaseSemaphore(&GetPrivIBase(IntuitionBase)->DeferedActionLock);
	
    } /* while (next_am) */

}
			  
			  
