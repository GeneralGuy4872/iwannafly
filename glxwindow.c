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
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(RAD(CAMERA->coord.fov),MWASPECT,0.1,FARAWAY);
	glScalef(1.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(-(PLAYER->pos.x),-(PLAYER->pos.y),-(PLAYER->pos.z));
	mainhTranslatef(EYECOORD((*PLAYER)));
	glRotatef(CAMERA->coord.az,0.0,0.0,1.0);
	glRotatef(CAMERA->coord.alt,0.0,1.0,0.0);
	glTranslatef(0.0,0.0,CAMERA->coord.z);
	}
	
void
glx__DrawLoop()
	{
	glMatrixMode(GL_MODELVIEW);
	struct entity *nextent = PLAYER;
	struct bone *nextbone = PLAYER->dembones->root;
	glPushMatrix();
	FOREVER
		{
		FOREVER
			{
			if (nextbone->up == NULL)
				{
				if (nextent->stat.horiz)
					{
					glTranslatef(nextent->pos.x,nextent->pos.y,nextent->pos.z);
					mainhMultMatrixf(matgen_y_deg(90,1));
					mainhMultMatrixf(matgen_zeuler_deg(nextent->rot.z,nextent->rot.y,nextent->rot.x,1,1,1));
					}
				else
					{
					glTranslatef(nextent->pos.x,nextent->pos.y,nextent->pos.z + nextent->dembones->off.x);
					mainhMultMatrixf(matgen_master_deg(nextent->rot.z,nextent->rot.y,nextent->rot.x,1,1,1));
					}
				}
			else
				{
				mainhLoadMatrixf(nextbone->up->curr);
				glTranslatef(nextbone->up->len.x * frfl(nextbone->off.x),nextbone->up->len.y * frfl(nextbone->off.y),nextbone->up->len.z * frfl(nextbone->off.z));
				}
			raw_mainhMultMatrixf(nextbone->base);
			glGetFloatv(GL_MODELVIEW_MATRIX,(float *)(nextbone->curr));
			boneloop(nextbone);
			if (nextbone->next != NULL)
				{
				nextbone = nextbone->next;
				}
			else
				{
				break;
				}
			}
		if (nextent->next != NULL)
			{
			nextent = nextent->next;
			}
		else
			{
			glPopMatrix();
			return;
			}
		}
	}
