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
  glLoadMatrix(camera.root.head.curr);
  glMultMatrix(camera.coord)
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(camera.coord.w,1,.25,100);
  }

glx__DrawLoop(plugh)
  struct world plugh
  {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  struct entity *nextent = plugh->ent
  while (*nextent->next != NULL)
  {
  glLoadMatrix(nextent.rot);
  unsigned char n = 0
  struct bone *nextbone = plugh.dembones.root
    {
    glLoadIdentity()
    gltranslate(plugh.pos.x,plugh.pos.y,BASEBONEPOS(plugh))
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
  glx__SetCamera(plugh.camera)
  }
