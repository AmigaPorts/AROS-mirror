/*
    Copyright (C) 1995-2000 AROS - The Amiga Research OS
    $Id$

    Desc: Read a big endian floating point (32bit) from a streamhook
    Lang: english
*/
#include <proto/dos.h>

/******************************************************************************

    NAME */
#include <stdio.h>
#include <aros/bigendianio.h>
#include <proto/alib.h>

	BOOL ReadFloat (

/*  SYNOPSIS */
	struct Hook * hook,
	FLOAT	    * dataptr,
	void	    * stream)

/*  FUNCTION
	Reads one big endian 32bit floating point value from a streamhook.

    INPUTS
	hook - Streamhook
	dataptr - Put the data here
	stream - Read from this stream

    RESULT
	The function returns TRUE on success. On success, the value
	read is written into dataptr. On failure, FALSE is returned and the
	contents of dataptr are not changed.

    NOTES
	This function reads big endian values from a streamhook even on
	little endian machines.

    EXAMPLE

    BUGS

    SEE ALSO
	ReadByte(), ReadWord(), ReadLong(), ReadFloat(), ReadDouble(),
	ReadString(), ReadStruct(), WriteByte(), WriteWord(), WriteLong(),
	WriteFloat(), WriteDouble(), WriteString(), WriteStruct()

    HISTORY
	14.09.93    ada created

******************************************************************************/
{
    ULONG   value;
    LONG    c;
    UBYTE * ptr;

#if AROS_BIG_ENDIAN
    ptr = (UBYTE *)&value;
#   define NEXT ++
#else
    ptr = ((UBYTE *)&value) + 3;
#   define NEXT --
#endif

#define READ_ONE_BYTE		    \
    if ((c = CallHook (hook, stream, BEIO_READ)) == EOF) \
	return FALSE;		    \
				    \
    *ptr NEXT = c

    READ_ONE_BYTE;
    READ_ONE_BYTE;
    READ_ONE_BYTE;
    READ_ONE_BYTE;

    *dataptr = *(FLOAT *)&value;

    return TRUE;
} /* ReadFloat */

