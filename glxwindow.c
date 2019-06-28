//you arrived here from main.c

#include <X11/Xlib.h>
#include <X11/Xutils.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>

#include "./glxwindow.h"

glx__SetCamera()
  {    
  glMatrixMode(GL_MODELVIEW);
  glTraslate(EYECOORDS(PLAYER));
  glMultMatrix(PLAYER.ori);
  glMultMatrix(matgen_sphere(CAMERA->coord.x,CAMERA->coord.y,NEG(CAMERA->coord.z),1,1))
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(camera.coord.fov,1,.25,100);
  }

glx__DrawLoop()
  {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  struct entity *nextent = WORLD->ent
  while TRUE
    {
    glLoadMatrix(nextent.rot);
    struct bone *nextbone = nextent.dembones.root
    while TRUE
      {
      if (nextbone->up == NULL)
        {
        glLoadIdentity()
        if nextent.stat.horiz
          {
          glMultMatrix(matgen_zeuler_deg(player.rot.z,player.rot.y,player.rot.x,1,1,1))
          glMultMatrix(matgen_y_deg(90,1))
          }
        else
      		{
      		glMultMatrix(matgen_master_deg(player.rot.x,player.rot.y,player.rot.z,1,1,1))
      		}
        gltranslate(nextent->pos.x,nextent->pos.y,( nextent->pos.z + (frfl(nextent->hitbox.z) * frfl(nextent->hitbox.offset)) ))
        }
      else
        {
        glLoadMatrixf(nextbone->up->curr)
        gltranslate(nextbone->up->len.x * frfl(nextbone->off.x),nextbone->up->len.y * frfl(nextbone.off.y),nextbone->up->len.z * frfl(nextbone->off.z))
        }
      glMultMatrixf(nextbone.base)
      glGetfloatv(GL_MODELVIEW_MATRIX,nextbone.curr) 
      boneloop(nextbone)
      if (nextbone->next != NULL)
        {
        nextbone = nextbone->next
        }
      else
        break
      }
    if (nextent->next != NULL)
      {
      nextent = nextent->next
      }
    else
      break
    }
  
  glx__SetCamera();
  glXSwapBuffers(dsply,glxwin)
  }
