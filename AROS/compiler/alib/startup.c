/*
    (C) 1995-96 AROS - The Amiga Replacement OS
    $Id$

    Desc: Common startup code
    Lang: english
*/
#include <dos/dos.h>
#include <clib/exec_protos.h>
#include <clib/dos_protos.h>

/* Don't define symbols before the entry point. */
extern int main (int argc, char ** argv);
extern APTR __startup_mempool; /* malloc() and free() */

/*
    TODO: This won't work for normal AmigaOS for two reasons:
    1. You can't expect SysBase to be in A6. The correct way
       is to use *(struct ExecBase **)4.
    2. Amiga gcc puts strings into the code section - and since
       all gccs emit strings for a certain function _before_ the
       code the program will crash immediately.
*/
AROS_LH0(LONG,entry,struct ExecBase *,sysbase,,)
{
    AROS_LIBFUNC_INIT
    LONG error=RETURN_FAIL;

    SysBase=sysbase;
    DOSBase=(struct DosLibrary *)OpenLibrary(DOSNAME,39);
    if(DOSBase!=NULL)
    {
	char * argv[2];

	argv[0] = "dummy";
	argv[1] = NULL;

	error = main (1, argv);

	CloseLibrary((struct Library *)DOSBase);
    }

    if (__startup_mempool)
	DeletePool (__startup_mempool);

    return error;
    AROS_LIBFUNC_EXIT
}

struct ExecBase *SysBase;
struct DosLibrary *DOSBase;

APTR __startup_mempool = NULL;

/*	Stub function for GCC __main().

	The __main() function is originally used for C++ style constructors
	and destructors in C. This replacement does nothing and gets rid of
	linker-errors about references to __main().
*/

void __main(void)
{
/* Do nothing. */
}

