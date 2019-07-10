//you arrived here from main.c

#include <X11/Intrinsic.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>

#include "glxwindow.h"
#include "models/shapeloop.h"

void
glx__SetCamera()
	{    
	glMatrixMode(GL_MODELVIEW);
	mainhTranslatef(EYECOORD((*PLAYER)));
	mainhMultMatrixf(matgen_z_deg(PLAYER->rot.z,1));
	mainhMultMatrixf(matgen_sphere_deg(CAMERA->coord.az,CAMERA->coord.alt,NEG(CAMERA->coord.z),1,1));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(RAD(CAMERA->coord.fov),1,.25,100);
	}

void
glx__DrawLoop()
	{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	struct entity *nextent = PLAYER;
	struct bone *nextbone = PLAYER->dembones->root;
	FOREVER
		{
		FOREVER
			{
			if (nextbone->up == NULL)
				{
				glLoadIdentity();
				if (nextent->stat.horiz)
					{
					mainhMultMatrixf(matgen_y_deg(90,1));
					mainhMultMatrixf(matgen_zeuler_deg(PLAYER->rot.z,PLAYER->rot.y,PLAYER->rot.x,1,1,1));
					}
				else
					{
					mainhMultMatrixf(matgen_master_deg(PLAYER->rot.z,PLAYER->rot.y,PLAYER->rot.x,1,1,1));
					}
				glTranslatef(nextent->pos.x,nextent->pos.y,nextent->pos.z + (nextent->stat.horiz ? 0 : nextent->dembones->off.x));
				}
			else
				{
				mainhLoadMatrixf(nextbone->up->curr);
				glTranslatef(nextbone->up->len.x * frfl(nextbone->off.x),nextbone->up->len.y * frfl(nextbone->off.y),nextbone->up->len.z * frfl(nextbone->off.z));
				}
			raw_mainhMultMatrixf(nextbone->base);
			glGetFloatv(GL_MODELVIEW_MATRIX,nextbone->curr);
			boneloop(nextbone);
			if (nextbone->next != NULL)
				{
				nextbone = nextbone->next;
				}
			else
				break;
			}
		if (nextent->next != NULL)
			{
			nextent = nextent->next;
			}
		else
			break;
		}
  
  glx__SetCamera();
  glXSwapBuffers(dsply,glxwin);
  }
