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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	mainhTranslatef(EYECOORD((*PLAYER)));
	glRotatef(PLAYER->rot.z,0.0,0.0,1.0);
	glTranslatef(0.0,0.0,NEG(CAMERA->coord.z));
	glRotatef(CAMERA->coord.az,0.0,0.0,1.0);
	glRotatef(CAMERA->coord.alt,0.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-500,500,-300,300,-1000,1000);
	mainhFOV(RAD(CAMERA->coord.fov));
	}

void
glx__DrawLoop()
	{
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
			printf("nextent %p\n",nextent);
			}
		else
			return;
		}
	}
