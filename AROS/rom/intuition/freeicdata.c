/*
    Copyright (C) 1997-2001 AROS - The Amiga Research OS
    $Id$

    Desc: Support function for icclass and gadgetclass
    Lang: english
*/

#include <exec/types.h>
#include <proto/exec.h>
#include <proto/utility.h>

#include "intuition_intern.h"

/*****i***********************************************************************

    NAME */
#include <intuition_private.h>

#include "maybe_boopsi.h"

	AROS_LH1(void, FreeICData,

/*  SYNOPSIS */
	AROS_LHA(struct ICData *, icdata, A0),

/*  LOCATION */
	struct IntuitionBase *, IntuitionBase, 146, Intuition)

/*  FUNCTION
	This private function will free the data that belongs to an object
	of the type ICCLASS. It is primarily in as a private function for
	the benefit of intuition.library's gadgetclass implementation, 
	which includes an icclass of its own.

    INPUTS
	    icdata	-	The address of a struct ICData
	
    RESULT
	    The data associated will have been freed (including the TagList).
    
    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

    HISTORY

******************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct IntuitionBase *, IntuitionBase)

#if INTERNAL_BOOPSI

    icdata->ic_LoopCounter = 0UL;
    
    if(icdata->ic_CloneTags)
    {
	FreeTagItems(icdata->ic_CloneTags);
	icdata->ic_CloneTags = NULL;
    }

#else

    /* call boopsi.library function */    
    FreeICData(icdata);
    
#endif

    AROS_LIBFUNC_EXIT
    
} /* FreeICData */
