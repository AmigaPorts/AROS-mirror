/*
    Copyright � 1995-2015, The AROS Development Team. All rights reserved.
    $Id$

    Desc: Wait for some signal.
    Lang: english
*/
#define DEBUG 0

#include <aros/debug.h>
#include <exec/execbase.h>
#include <aros/libcall.h>
#include <proto/exec.h>
#include <proto/kernel.h>

#include "exec_intern.h"

/*****************************************************************************

    NAME */

	AROS_LH1(ULONG, Wait,

/*  SYNOPSIS */
	AROS_LHA(ULONG, signalSet, D0),

/*  LOCATION */
	struct ExecBase *, SysBase, 53, Exec)

/*  FUNCTION
	Wait until some signals are sent to the current task. If any signal
	of the specified set is already set when entering this function it
	returns immediately. Since almost any event in the OS can send a
	signal to your task if you specify it to do so signals are a very
	powerful mechanism.

    INPUTS
	signalSet - The set of signals to wait for.

    RESULT
	The set of active signals.

    NOTES
	Naturally it's not allowed to wait in supervisor mode.

	Calling Wait() breaks an active Disable() or Forbid().

    EXAMPLE

    BUGS

    SEE ALSO
	Signal(), SetSignal(), AllocSignal(), FreeSignal()

    INTERNALS

    HISTORY

******************************************************************************/
{
    AROS_LIBFUNC_INIT

#if defined(__AROSEXEC_SMP__)
    spinlock_t *task_listlock = NULL;
#endif
    ULONG rcvd;
    struct Task *me;

    /* Get pointer to current task - I'll need it very often */
    me = FindTask(NULL);

    D(bug("[Exec] Wait(%08lX)\n", signalSet));

    /* If at least one of the signals is already set do not wait. */
    while (!(me->tc_SigRecvd & signalSet))
    {
	/* Set the wait signal mask */
	me->tc_SigWait = signalSet;
#if defined(__AROSEXEC_SMP__)
        if (me->tc_State != TS_WAIT)
        {
#endif
	D(bug("[Exec] Moving '%s' @ 0x%p to Task Wait queue\n", me->tc_Node.ln_Name, me));
        D(bug("[Exec] Task state = %08x\n", me->tc_State));

        /* Protect the task lists against access by other tasks. */
#if defined(__AROSEXEC_SMP__)
            switch (me->tc_State)
            {
                case TS_RUN:
                    task_listlock = &PrivExecBase(SysBase)->TaskRunningSpinLock;
                    break;
                default:
                    task_listlock = &PrivExecBase(SysBase)->TaskReadySpinLock;
                    break;
            }
            EXEC_SPINLOCK_LOCK(task_listlock, SPINLOCK_MODE_WRITE);
#endif
        Disable();
#if defined(__AROSEXEC_SMP__)
            Remove(&me->tc_Node);
            EXEC_SPINLOCK_UNLOCK(task_listlock);
            Enable();
            EXEC_SPINLOCK_LOCK(&PrivExecBase(SysBase)->TaskWaitSpinLock, SPINLOCK_MODE_WRITE);
            Disable();
#endif
        /*
	    Clear TDNestCnt (because Switch() will not care about it),
	    but memorize it first. IDNestCnt is handled by Switch().
	*/
	me->tc_TDNestCnt = TDNESTCOUNT_GET;
	TDNESTCOUNT_SET(-1);

	/* Move current task to the waiting list. */
        me->tc_State = TS_WAIT;
	Enqueue(&SysBase->TaskWait, &me->tc_Node);
#if defined(__AROSEXEC_SMP__)
            EXEC_SPINLOCK_UNLOCK(&PrivExecBase(SysBase)->TaskWaitSpinLock);
        }
        else
        {
            Disable();
            me->tc_TDNestCnt = TDNESTCOUNT_GET;
            TDNESTCOUNT_SET(-1);
        }
#endif
	/* And switch to the next ready task. */
	KrnSwitch();

	/*
	    OK. Somebody awakened me. This means that either the
	    signals are there or it's just a finished task exception.
	    Test again to be sure (see above).
	*/

	/* Restore TDNestCnt. */
	TDNESTCOUNT_SET(me->tc_TDNestCnt);

        Enable();
    }
    /* Get active signals. */
    rcvd = (me->tc_SigRecvd & signalSet);

    /* And clear them. */
    me->tc_SigRecvd &= ~signalSet;

    /* All done. */
    return rcvd;

    AROS_LIBFUNC_EXIT
}

