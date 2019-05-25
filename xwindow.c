//you arrived here from main.c

#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <X11/CoreP.h>
#include <X11/Xatom.h>
#include <X11/Xaw/Form.h>
#include <X11/Xaw/Box.h>
#include <X11/Xaw/Label.h>
#include <X11/Xaw/Command.h>
#include <X11/Xaw/Toggle.h>

#include "./xwindow.h"

//see repo X11-Xt-Xaw-test

xaw_inputwindow_main

void quit(void)
{
	XtDestroyApplicationContext(xtcontext)
	exit(0)
}
