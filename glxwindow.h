//you arrived here from glxwindow.c

//preliminary outline from glancing over toutorials.
//need to nano -v headers and read docs/manpages to double-check stuff
#define MAINWINSIZE 505

Display *dsply = XOpenDisplay(NULL);
Window desktop = DefaultRootWindow(dsply);
int attrib[] = {GLX_RGBA,GLX_DEPTH_SIZE,24,GLX_DOUBLEBUFFER,None};
XVisualInfo *VisInf = glXChooseVisual(dsply, 0, attrib);
XSetWindowAttributes swa;
Window glxwin = XCreateWindow(monitor,desktop,0,0,MAINWINSIZE,MAINWINSIZE,0,VisInf->depth,InputOutput,VisInf->visual,CWColormap | CWEventMask,&swa);
swa.colormap = XCreateColormap(dsply,glxwin,VisInf->visual,AllocNone);
swa.eventmask = ExposureMask | KeyPressMask | VisibilityChangeMask //start here and finnagle around with it if unexpected results
GLXContext glxctx = glXCreateContext(monitor,VisInf,NULL,TRUE);
XWindowAttributes GotWinAtt;

static unsigned int
glx__keysymswitch(monitor,winder,event)
	Display *monitor
	Window winder
	XEvent *event
	{
	if (event->type == keypress)
		{
		sym_keypressd = XLookupKeysym(&event->xkey, 0);
		switch (sym_keypressd)
			{
			case XK_plus :
				{
				CAMBUFFER.w++
				return STR_INT(0,'+',0,0)
				break
				}
			case XK_minus :
				{
				CAMBUFFER.w--
				return STR_INT(0,'-',0,0)
				break
				}
			case XK_Home :
				{
				PLAYER.Torq.z = (PLAYER.torq.z + (CAMERA.coord.az * 2))%360
				return STR_INT(0,'\r',0,0)
				break
				}
			case XK_Left :
				{
				CAMBUFFER.x++
				return STR_INT(0,0x1b,'[','D')
				break
				}
			case XK_Right :
				{
				CAMBUFFER.x--
				return STR_INT(0,0x1b,'[','C')
				break
				}
			case XK_Up :
				{
				CAMBUFFER.y++
				return STR_INT(0,0x1b,'[','A')
				break
				}
			case XK_Down :
				{
				CAMBUFFER.y--
				return STR_INT(0,0x1b,'[','B')
				break
				}
			case XK_Page_Up :
				{
				CAMBUFFER.z++
				return STR_INT(0,0x1b,'[','F')
				break
				}
			case XK_Page_Down :
				{
				CAMBUFFER.z--
				return STR_INT(0,0x1b,'[','E')
				break
				}
			case XK_End :
				{
				CAMERA.coord.az=0
				CAMERA.coord.alt=0
				CAMERA.coord.z=0
				CAMERA.coord.fov=50
				return STR_INT(0,0x19,0,0)
				break
				}
			default :
				{
				return -1
				break
				}
			}
		}
	}

static void
glx__eventswitch(monitor,winder)
	Display *monitor
	Window winder
	{
	while TRUE
		{
		if XPending(monitor)
			{
			XEvent event
			XNextEvent(monitor,&event)
			glx__keysymswitch(monitor,winder,event)
			}
		}
	}

glx__startup()
	{
	XMapWindow(monitor,mainwindow);
	glXMakeCurrent(dsply,glxwin,glxctx);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	XStoreName(dpy, win, VITALSTAT(REV_NOFORK));
	glx__eventswitch(dsply,glxwin);
	}
	
 * XK_End : camera.coord.az=0 camera.coord.alt=0 camera.coord.z=0 camera.coord.fov=50
 */
