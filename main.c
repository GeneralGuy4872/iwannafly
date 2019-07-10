/***********************************
 * Working Title: I wanna Fly      *
 *                                 *
 * An open world/flight simulation *
 * program with a winged humanoid  *
 * player character, written on    *
 * OpenGL/Mesa and Athena (Xt,Xaw) *
 ***********************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <string.h>
//#include <regex.h>

#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
//#include <err.h>
//#include <errno.h>

#include <GL/gl.h>
#include <GL/glu.h> //know what this does now

#include "main.h"
#include "init.c"
#include "joystick.c"
#include "timeing.c"

//#include "xwindow.c"
#include "glxwindow.c"
//#include "textout.c"

//---<HR>---

/* all exact mesurements should folow SI units or SI acceptable units (i.e. degrees),
 * since real mesurements are used, conclusions can be made about the
 * physical characteristics of any elements of the game, so be careful!
 * this does not apply to the friction factors and may or may not apply to the speed factors
 * of the basic physics implementation; inprecise mesures of time based on accumulated loops
 * approximately equal to one second with a margin of error based on CPU speed and strain
 * use "microfortnights" as in VMS for the PDP-11, to distinguish them from exact values.
 *
 * meters currently equal one arcminute on the surface of the torus exactly.
 * feet are exactly 30cm
 * 
 * some mesurements may be stored using a conversion factor to save space,
 * most common variant is CMS mesurements in interger types.
 */

#define grav (9.8 / FPS)
//meters / second / microfortnight

#define air_dense 1.225
//standard approximation
#define water_dense 1000.0
//formerly by definition

//HERE BE DRAGONS
#define SPEED(X,Y,Z) (X.Y + ((Z * ACCL(X))/ X.m))
#define ACCL(X) SANE(X.stat.wet ? (X.stat.wings ? (X.Fa->y / 4) : X.Fa->y) : (X.stat.ground ? X.Fa->x : X.Fa->z ))
#define DRAG(X) SANE(X.stat.wet ? (X.stat.ground ? (2 * X.Drag->y) : X.Drag->y) : (X.stat.ground ? X.Drag->x : X.Drag->z))
#define PHYSICS(X,Y,Z) ((SPEED(X,Y,Z) - ABSMIN( (X.Ff * X.stat.ground * SGN(SPEED(X,Y,Z))) , SPEED(X,Y,Z) )) / DRAG(X))
#define GRAVITY(X,Y) ( (X.Y - (X.stat.ground ? 0 : (X.stat.wet ? (grav * (water_dense - X.density)) : (grav * (air_dense - X.density)) ))) / DRAG(X) ) //eh, close enough for now.
#define ROLL(X,Y,Z) (X.stat.ground ? 0 : PHYSICS(X,Y,Z))
//end dragons

onstep_player ()
	{
	PLAYER->Torq.x = ROLL((*PLAYER),Torq.x,MOVEBUFFER_rol);
	PLAYER->Torq.z = PHYSICS((*PLAYER),Torq.z,MOVEBUFFER.yaw);
	PLAYER->Torq.y = PHYSICS((*PLAYER),Torq.y,MOVEBUFFER.pit);

	PLAYER->rot.x = CLAMP((PLAYER->rot.x + PLAYER->Torq.x),-90,90); //degrees
	PLAYER->rot.y = CLAMP((PLAYER->rot.y + PLAYER->Torq.y),-90,90); //degrees
	PLAYER->rot.z = fmod(PLAYER->rot.z + PLAYER->Torq.z,360); //degrees

	vector3 abs_movebuff = matmult((PLAYER->stat.horiz ? (matrix)matgen_xeuler_deg(PLAYER->rot.z,PLAYER->rot.y,PLAYER->rot.x,1,1,1) : (matrix)matgen_master_deg(PLAYER->rot.z,PLAYER->rot.y,PLAYER->rot.x,1,1,1)),(vector3){MOVEBUFFER.x,MOVEBUFFER.y,MOVEBUFFER_z});

	PLAYER->Velo.x = CLAMP(PHYSICS((*PLAYER),Velo.x,abs_movebuff.x),-340.3,340.3);
	PLAYER->Velo.y = CLAMP(PHYSICS((*PLAYER),Velo.y,abs_movebuff.y),-340.3,340.3);
	PLAYER->Velo.z = CLAMP(PHYSICS((*PLAYER),Velo.z,abs_movebuff.z),-340.3,340.3);
	PLAYER->Velo.z = CLAMP(GRAVITY((*PLAYER),Velo.z),-340.3,340.3);
	//players may not break the sound barrier

	PLAYER->pos.x = fmod(PLAYER->pos.x + PLAYER->Velo.x,21600); //arcminutes
	PLAYER->pos.y = fmod(PLAYER->pos.y + PLAYER->Velo.y,21600); //arcminutes
	PLAYER->pos.w = groundcheck(PLAYER);
	PLAYER->pos.z = CLAMP((PLAYER->pos.z + PLAYER->Velo.z),PLAYER->pos.w,10000); //meters, groundlevel;arbitrary ceiling

	if (PLAYER->pos.w >= PLAYER->pos.z)
		{
		PLAYER->stat.ground = TRUE;
		}
	else
		{
		PLAYER->stat.ground = FALSE;
		}
	
	if ((MAP->sealevel * 5) >= PLAYER->pos.w + (PLAYER->stat.ground * frfl(PLAYER->dembones->hitbox.z))) //bool * fraction
		{
		PLAYER->stat.wet = TRUE;
		}
	else
		{
		PLAYER->stat.wet = FALSE;
		}
	}

onstep_camera ()
	{
	CAMERA->coord.az = (CAMERA->coord.az + CAMBUFFER.x)%180; //degrees/2
	CAMERA->coord.alt = (CAMERA->coord.alt + CAMBUFFER.y)%180; //degrees/2; no roll axis, so not clamped to 180 to allow for inverting the view
	CAMERA->coord.z = CLAMP((CAMERA->coord.z + CAMBUFFER.z),-120,120); //meters, 2 arcminutes either direction
	CAMERA->coord.fov = CLAMP((CAMERA->coord.fov + CAMBUFFER.w),5,255); //degrees (solid degrees?)
	}


//---<HR>---

onstep_master ()
	{
	glx__eventswitch(dsply,glxwin);
	onstep_player();
	onstep_camera();
	}

onstep_paused ()
	{
	glx__eventswitch(dsply,glxwin);
	onstep_camera();
	}

/*MAIN*/
mainloop ()
	{
	init__setup();
	printf(" \033[1;97m~~ Iwannafly ~~\033[m\n  version: %s\n\n \033[97m- %s -\033[m\n  main program revision: %s\n   joystick handler revision: %s\n\n\033[3mCompiled on %s\033[m\n",__MYVERS__,"Prealpha",REV_MAIN,REV_JS,__DATE__);
	while (run)
		{
		if (!paused)
			{
			if (nextframe)
				{
				refresh_land();
				onstep_master();
				glx__DrawLoop();
				nextframe = FALSE;
				ready = FALSE;
				}
			if (nextstep)
				{
				onstep_master();
				}
			}
		else if (nextstep)
			{
			onstep_paused();
			}
		}
	printf("runlevel lowered, exiting...\n");
	exit(0);
	}

main()
	{
	JSAXISBUFF_ADDRESS = (long) mmap(NULL,sizeof(short) * 8,PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANON,-1,0);
	JSAXISFLAG_ADDRESS = (long) mmap(NULL,sizeof(bool),PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANON,-1,0);
	if (fork() == 0)
		{
		JSAXISBUFF = JSAXISBUFF_ADDRESS;
		JSAXISFLAG = JSAXISFLAG_ADDRESS;
		jsloop();
		}
	else
		{
		JSAXISBUFF = JSAXISBUFF_ADDRESS;
		JSAXISFLAG = JSAXISFLAG_ADDRESS;
		mainloop();
		}
	}
