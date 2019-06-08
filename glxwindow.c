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

glx__DrawLoop()
  {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  struct entity *nextent = WORLD->ent
  while 1
    {
    glLoadMatrix(nextent.rot);
    struct bone *nextbone = nextent.dembones.root
    while 1
      {
      if (nextbone->up == NULL)
        {
        glLoadIdentity()
        if nextent.stat.horiz
          {
          glMultMatrix(matgen_y_deg(90,1)
          }
        gltranslate(nextent.pos.x,nextent.pos.y,BASEBONEPOS(nextent))
        glMultMatrixf(plugh.rot)
        }
      else
        {
        glLoadMatrixf(nextbone.up.curr)
        gltranslate(nextbone.up.len.x * frfl(nextbone.off.x),nextbone.up.len.y * frfl(nextbone.off.y),nextbone.up.len.z * frfl(nextbone.off.z))
        }
      glMultMatrixf(nextbone.base)
      glGetfloatv(GL_MODELVIEW_MATRIX,nextbone.curr) 
      boneloop(nextbone)
      if (nextbone->next != NULL)
        {
        nextbone = nextbone->next
        }
      else
        {
        return 0
        }
      }
    glx__SetCamera(plugh.camera)
    if (nextent->next != NULL)
      {
      nextent = nextent->next
      }
    else
      {
      return 0
      }
    }
  }
