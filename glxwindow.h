//you arrived here from glxwindow.c

//preliminary outline from glancing over toutorials.
//need to nano -v headers and read docs/manpages to double-check stuff

Display *dsply;
int attrib[64] = {GLX_RGBA,GLX_DEPTH_SIZE,24,GLX_DOUBLEBUFFER,None};
Window desktop;
Window glxwin;
XSetWindowAttributes swa;
XWindowAttributes GotWinAtt;
GLXContext glxctx;
XVisualInfo *xvi;
Colormap cmap;
ushortvector2 MWSIZE = {505,303};
#define MWASPECT ((float)MWSIZE.x/MWSIZE.y)

static void
glx__resize()
	{
	glViewport(0,0,MWSIZE.x,MWSIZE.y);
	}

static signed short
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
			case XK_KP_Add : noop();
			case XK_plus :
				{
				CAMBUFFER.w++;
				puts("Zoom In");
				return STR_INT(0,'+',0);
				break;
				}
			case XK_KP_Subtract : noop(); 
			case XK_minus :
				{
				CAMBUFFER.w--;
				puts("Zoom Out");
				return STR_INT(0,'-',0);
				break;
				}
			case XK_KP_7 : noop();
			case XK_KP_Home : noop();
			case XK_Home :
				{
				PLAYER->Torq.z = fmod((PLAYER->Torq.z + (CAMERA->coord.az * 2)),360);
				return STR_INT(0,'\r',0);
				break;
				}
			case XK_KP_4 : noop();
			case XK_KP_Left : noop();
			case XK_Left :
				{
				CAMBUFFER.x++;
				puts("Orbit <-");
				return STR_INT(0,0x9b,'D');
				break;
				}
			case XK_KP_6 : noop();
			case XK_KP_Right : noop();
			case XK_Right :
				{
				CAMBUFFER.x--;
				puts("Orbit ->");
				return STR_INT(0,0x9b,'C');
				break;
				}
			case XK_KP_8 : noop();
			case XK_KP_Up : noop();
			case XK_Up :
				{
				CAMBUFFER.y++;
				puts("Orbit Up");
				return STR_INT(0,0x9b,'A');
				break;
				}
			case XK_KP_2 : noop();
			case XK_KP_Down : noop();
			case XK_Down :
				{
				CAMBUFFER.y--;
				puts("Orbit Down");
				return STR_INT(0,0x9b,'B');
				break;
				}
			case XK_KP_9 : noop();
			case XK_KP_Page_Up : noop();
			case XK_Page_Up :
				{
				CAMBUFFER.z++;
				puts("Closer");
				return STR_INT(0,0x9b,'S');
				break;
				}
			case XK_KP_3 : noop();
			case XK_KP_Page_Down : noop();
			case XK_Page_Down :
				{
				CAMBUFFER.z--;
				puts("Farther");
				return STR_INT(0,0x9b,'T');
				break;
				}
			case XK_KP_1 : noop();
			case XK_KP_End : noop();
			case XK_End :
				{
				CAMERA->coord.az=0;
				CAMERA->coord.alt=0;
				CAMERA->coord.z=0;
				CAMERA->coord.fov=50;
				return STR_INT(0,0x19,0);
				break;
				}
			case XK_Escape :
				{
				RUN++;
				return STR_INT(0,033,0);
				puts("Escape!!!");
				break;
				}
			case XK_Pause :
				{
				toggle(PAUSE);
				puts("!Pause");
				return STR_INT(0,0x15,0);
				break;
				}
			default :
				{
				return -1;
				break;
				}
			}
		}
	else if (event.type = ConfigureNotify)
		{
		MWSIZE.x = event.xconfigure.width;
		MWSIZE.y = event.xconfigure.height;
		glx__resize();
		return STR_INT(0,1,0);
		}
	}
/* esc = 0   @33   0
 * ctrl = 0   $9F   0
 * alt = 0   $9D   0
 * shift = 0   $F   0
 * f# = #   0   0
 * caps = never caught
 *
 * data format (signed short):
 * special indicator (1 bit)
 * ISO-8859 character or control code (8 bits)
 * ASCII character modifier (7 bits, usually absent)
 */

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
		glxwin = XCreateWindow(dsply,desktop,0,0,MWSIZE.x,MWSIZE.y,0,xvi->depth,InputOutput,xvi->visual,CWColormap | CWEventMask,&swa);
	XMapWindow(dsply,glxwin);
		glxctx = glXCreateContext(dsply,xvi,NULL,TRUE);
	glXMakeCurrent(dsply,glxwin,glxctx);
	glDisable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	//some_func_setwrap_x(-360*60,360*60);
	//some_func_setwrap_y(-360*60,360*60);
	XStoreName(dsply, glxwin, VITALSTAT(REV_MAIN));
	glDrawBuffer(GL_BACK_LEFT);
	}
