//you arrived here from glxwindow.c

//preliminary outline from glancing over toutorials.
//need to nano -v headers and read docs/manpages to double-check stuff
#define MAINWINSIZE 505,505

Display *monitor = XOpenDisplay(NULL);
Window desktop = DefaultRootWindow(monitor);
int attrib[] = {GLX_RGBA,GLX_DEPTH_SIZE,24,GLX_DOUBLEBUFFER,None};
XVisualInfo *VisInf = glXChooseVisual(monitor, 0, attrib);
XSetWindowAttributes WinAtt;
WinAtt.colormap = XCreateColormap(monitor,desktop,VisInf->visual,AllocNone);
WinAtt.eventmask = ExposureMask | KeyPressMask | VisibilityChangeMask | Button1MotionMask | Button2MotionMask //start here and finnagle around with it if unexpected results
Window mainwindow = XCreateWindow(monitor,desktop,0,0,MAINWINSIZE,0,VisInf->depth,InputOutput,VisInf->visual,CWColormap | CWEventMask,&swa);
GLXContext glxc = glXCreateContext(monitor,VisInf,NULL,TRUE);
XWindowAttributes GotWinAtt;
XEvent x_event;

glx__startup()
  {
  XMapWindow(monitor,mainwindow);
  glXMakeCurrent(monitor,WinAtt,glxc);
  glEnable(GL_CULL_FACE);
  glEnable(GL_DEPTH_TEST);
  XStoreName(dpy, win, VITALSTAT(REV_NOFORK));
  }
