#ifndef AROS_CONFIG_H
#define AROS_CONFIG_H
/*
    This is an automatically generated file.
    DO NOT EDIT!

    Edit $(TOP)/configure.in and $(TOP)/config.h.in and rerun configure.
*/

#define AROS_FLAVOUR_NATIVE		1
#define AROS_FLAVOUR_STANDALONE		2
#define AROS_FLAVOUR_EMULATION		4
#define AROS_FLAVOUR_LINKLIB		8
#define AROS_FLAVOUR_BINCOMPAT		16

#define AROS_FLAVOUR	    	    	AROS_FLAVOUR_EMULATION

#define AROS_DEFAULT_WBWIDTH		800
#define AROS_DEFAULT_WBHEIGHT		600
#define AROS_DEFAULT_WBDEPTH		8

#define AROS_BOCHS_HACK			0
#define AROS_SERIAL_DEBUG		0

#define AROS_PALM_DEBUG_HACK	    	0

#define AROS_NESTING_SUPERVISOR     	0

#define AROS_MUNGWALL_DEBUG 	    	1
#define AROS_STACK_DEBUG    	    	1
#define AROS_MODULES_DEBUG		1
#define USE_XSHM	    	    	1
#define USE_VIDMODE			1

#define ENABLE_DBUS			0
#define ENABLE_X11			1

#endif /* AROS_CONFIG_H */
