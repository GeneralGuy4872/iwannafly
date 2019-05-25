//you arrived here from main.c

#include <X11/Xlib.h>
#include <X11/Xutils.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>

#include "./glxwindow.h"

glx__SetCamera(camera)
  struct cameratype camera
  {    
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(camera.coord.w,1,.25,100);
  }

glx__DrawLoop(plugh)
  struct world plugh
  {
  glClearColor(255,255,255,255);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  SetCamera(plugh.cam)
  
  glMatrixMode(GL_MODELVIEW);
  struct entity *nextent = plugh->ent
  while (*nextent->next != NULL)
  {
  glLoadMatrix(plugh.rot);
  unsigned char n = 0
  struct bone *nextbone = plugh.dembones.root
    {
    glLoadMatrixf(plugh.rot)
    glMultMatrixf(nextbone.base)
    glGetfloatv(GL_MODELVIEW_MATRIX,nextbone.curr)
    shapeloop(nextbone.shape.geom)
    *nextbone = nextbone->next
    n++
    }
  while (n < plugh.dembones.n_bones)
    {
    glLoadMatrixf(nextbone.up.curr)
    gltranslate(bone.up.len.x * bone.off.x,bone.up.len.y * bone.off.y,bone.up.len.z * bone.off.z)
    glMultMatrixf(nextbone.base)
    glGetfloatv(GL_MODELVIEW_MATRIX,nextbone.curr) 
    shapeloop(nextbone.shape.geom)
    *nextbone = nextbone->next
    n++
    }
  }
