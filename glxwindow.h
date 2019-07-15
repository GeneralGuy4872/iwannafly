//you arrived here from glxwindow.c

//preliminary outline from glancing over toutorials.
//need to nano -v headers and read docs/manpages to double-check stuff
#define MAINWINSIZE 505

Display *dsply;
int attrib[] = {GLX_RGBA,GLX_DEPTH_SIZE,24,GLX_DOUBLEBUFFER,None};
Window desktop;
Window glxwin;
XSetWindowAttributes swa;
XWindowAttributes GotWinAtt;
GLXContext glxctx;
XVisualInfo *xvi;
Colormap cmap;

static unsigned int
glx__keysymswitch(monitor,windw,event)
	Display *monitor;
	Window windw;
	XEvent event;
	{
	if (event.type == KeyPress)
		{
		int sym_keypressd = XLookupKeysym(&(event.xkey), 0);
		switch (sym_keypressd)
			{
			case XK_plus :
				{
				CAMBUFFER.w++;
				return STR_INT(0,'+',0,0);
				break;
				}
			case XK_minus :
				{
				CAMBUFFER.w--;
				return STR_INT(0,'-',0,0);
				break;
				}
			case XK_Home :
				{
				PLAYER->Torq.z = fmod((PLAYER->Torq.z + (CAMERA->coord.az * 2)),360);
				return STR_INT(0,'\r',0,0);
				break;
				}
			case XK_Left :
				{
				CAMBUFFER.x++;
				return STR_INT(0,0x1b,'[','D');
				break;
				}
			case XK_Right :
				{
				CAMBUFFER.x--;
				return STR_INT(0,0x1b,'[','C');
				break;
				}
			case XK_Up :
				{
				CAMBUFFER.y++;
				return STR_INT(0,0x1b,'[','A');
				break;
				}
			case XK_Down :
				{
				CAMBUFFER.y--;
				return STR_INT(0,0x1b,'[','B');
				break;
				}
			case XK_Page_Up :
				{
				CAMBUFFER.z++;
				return STR_INT(0,0x1b,'[','F');
				break;
				}
			case XK_Page_Down :
				{
				CAMBUFFER.z--;
				return STR_INT(0,0x1b,'[','E');
				break;
				}
			case XK_End :
				{
				CAMERA->coord.az=0;
				CAMERA->coord.alt=0;
				CAMERA->coord.z=0;
				CAMERA->coord.fov=50;
				return STR_INT(0,0x19,0,0);
				break;
				}
			default :
				{
				return -1;
				break;
				}
			}
		}
	}

static void
glx__eventswitch(monitor,windw)
	Display *monitor;
	Window windw;
	{
	if (XPending(monitor))
		{
		XEvent event;
		XNextEvent(monitor,&event);
		glx__keysymswitch(monitor,windw,event);
		}
	}

void
glx__startup()
	{
		dsply = XOpenDisplay(NULL);
		if (dsply == NULL) {HARD_ERROR_MACRO}
		desktop = DefaultRootWindow(dsply);
		XVisualInfo *xvi = glXChooseVisual(dsply, 0, attrib);
		if (xvi == NULL) {HARD_ERROR_MACRO}
		cmap = XCreateColormap(dsply,desktop,xvi->visual,AllocNone);
		swa.colormap = cmap;
		swa.event_mask = ExposureMask | KeyPressMask | VisibilityChangeMask; //start here and finnagle around with it if unexpected results
		glxwin = XCreateWindow(dsply,desktop,0,0,MAINWINSIZE,((3 * MAINWINSIZE)/5),0,xvi->depth,InputOutput,xvi->visual,CWColormap | CWEventMask,&swa);
	XMapWindow(dsply,glxwin);
		glxctx = glXCreateContext(dsply,xvi,NULL,TRUE);
	glXMakeCurrent(dsply,glxwin,glxctx);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	XStoreName(dsply, glxwin, VITALSTAT(REV_MAIN));
	}
