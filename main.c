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

signed short JSAXISBUFF[8] = mmap(NULL,sizeof(JSAXISBUFF),PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANON,-1,0);
signed char JSAXISFLAG = mmap(NULL,sizeof(JSAXISFLAG),PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANON,-1,0);

#define BEGIN {
#define END mainloop();}

main()
	{
	if (fork() == 0)
BEGIN
#include "./joystick.c"
END
	else
BEGIN
#include "./main.h"
#include "./models/all.c"
#include "./init.c"
#include "./timing.c"

#include "./xwindow.c"
#include "./glxwindow.c"
#include "./textout.c"

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

struct entity
	{
	struct entity *prev;
	struct entity *next;
	struct vector4 pos;
	struct vector3 rot;
	struct hitbox_type hitbox;
	struct vector3 Velo;
	struct vector3 Torq;
	struct statreg stat;
		/* bool ground
		 * bool wet
		 * bool horiz
		 * bool caster
		 * bool wings
		 * bool locks
		 * bool gills - deferred
		 * bool fireproof - deferred
		 */
	struct sensereg detects;
		/* bool uv
		 * bool infra - deferred
		 * bool trouble - deferred
		 * bool weather - deferred
		 * bool good - deferred
		 * bool evil - deferred
		 * bool law - deferred
		 * bool chaos deferred
		 */
	struct plotparam alignment; //x = lawful/chaotic, y = good/evil
	unsigned char health;
	float Ff;
	unsigned short m;
	unsigned short density;
	//they're comfy and easy to...wait...
	struct vector3 *Drag; //x = ground, y = water, z = air
	struct vector3 *Fa; //x = ground, y = water, z = air
	struct skeleton dembones;
	spellbook spells;
	//aside from half-floats or fixed-points, niether of which I have, this is as small as it gets...
	};

//HERE BE DRAGONS
#define SPEED(X,Y,Z) (X.Y + ((Z * ACCL(X))/ X.m)
#define ACCL(X) SANE(X.stat.wet ? (X.stat.wings ? (X.Fa->y / 4) : X.Fa->y) : (X.stat.ground ? X.Fa->x : X.Fa->z ))
#define DRAG(X) SANE(X.stat.wet ? (X.stat.ground ? (2 * X.Drag->y) : X.Drag->y) : (X.stat.ground ? X.Drag->x : X.Drag->z))
#define PHYSICS(X,Y,Z) ((SPEED(X,Y,Z) - ABSMIN((X.Ff * X.stat.ground * SGN(SPEED(X,Y,Z)),SPEED(X,Y,Z))) / DRAG(X)))
#define GRAVITY(X,Y) (X.Y - (X.stat.ground ? 0 : (X.stat.wet ? (grav * ((X.density * 15.625) - water_dense)) : (grav * ((X.density * 15.625) - air_dense)) )) / DRAG(X)) //eh, close enough for now.
#define ROLL(X,Y,Z) (X.stat.ground ? 0 : PHYSICS(X,Y,Z))
//end dragons

onstep_player
	{
	PLAYER.Torq.x = ROLL(player,Torq.x,MOVEBUFFER_rol);
	PLAYER.Torq.z = PHYSICS(player,Torq.z,MOVEBUFFER.yaw);
	PLAYER.Torq.y = PHYSICS(player,Torq.y,MOVEBUFFER.pit);

	PLAYER.rot.x = CLAMP((player.rot.x + player.Torq.x),-90,90); //degrees
	PLAYER.rot.y = CLAMP((player.rot.y + player.Torq.y),-90,90); //degrees
	PLAYER.rot.z = (player.rot.z + player.Torq.z)%360; //degrees

	PLAYER.Velo.x = PHYSICS(player,Velo.x,((MOVEBUFFER.x * cos(PLAYER.rot.z) * cos(PLAYER.rot.y)) + (MOVEBUFFER.y * sin(PLAYER.rot.z) * sin(PLAYER.rot.x)) + (MOVEBUFFER_Z * cos(PLAYER.rot.y) * cos(PLAYER.rot.z))));
	PLAYER.Velo.y = PHYSICS(player,Velo.y,((MOVEBUFFER.x * sin(PLAYER.rot.z) * cos(PLAYER.rot.y)) + (MOVEBUFFER.y * cos(PLAYER.rot.z) * sin(PLAYER.rot.x)) + (MOVEBUFFER_Z * sin(PLAYER.rot.x) * sin(PLAYER.rot.z))));
	PLAYER.Velo.z = PHYSICS(player,Velo.z,((MOVEBUFFER.x * cos(PLAYER.rot.z) * sin(PLAYER.rot.y)) + (MOVEBUFFER.y * sin(PLAYER.rot.z) * cos(PLAYER.rot.x)) + (MOVEBUFFER_Z * sin(PLAYER.rot.y) * cos(PLAYER.rot.x))));
	PLAYER.Velo.z = GRAVITY(player,Velo.z);

	PLAYER.pos.x = (player.pos.x + player.Velo.x)%21600; //arcminutes
	PLAYER.pos.y = (player.pos.y + player.Velo.y)%21600; //arcminutes
	PLAYER.pos.w = groundcheck(PLAYER);
	PLAYER.pos.z = CLAMP((player.pos.z + player.Velo.z),PLAYER.pos.w,6000); //meters, groundlevel;arbitrary ceiling

	if (PLAYER.pos.w >= PLAYER.pos.z)
		{
		PLAYER.stat.ground = TRUE;
		}
	else
		{
		PLAYER.stat.ground = FALSE;
		}
	
	if ( (MAP.sealevel * 5) >= (PLAYER.pos.z + (PLAYER.stat.ground * frfl(PLAYER.hitbox.z))) )
		{
		PLAYER.stat.wet = TRUE;
		}
	else
		{
		PLAYER.stat.wet = FALSE;
		}
	

	}

struct cameratype
	{
	struct camera_ang coord;
	struct viewform format;
		/*
		int base 0 = dec, 1 = oct, -n = hex
		rotation base 0 = deg, 1 = rad base pi, -1 = gradians, -2 rad base 10
		distance units 0 = m, 1 = km, -1 = cm, -2 = ft
		
		(latitude/longitude is always in degrees* minutes' format)
		infrared
		uv

		exact conversion of 1ft = 30cm
		*/
	unsigned short gold;
	unsigned short points;
	};

onstep_camera
	{
	CAMERA.coord.az = (CAMERA.coord.az + CAMBUFFER.x)%180; //degrees/2
	CAMERA.coord.alt = (CAMERA.coord.alt + CAMBUFFER.y)%180; //degrees/2; no roll axis, so not clamped to 180 to allow for inverting the view
	CAMERA.coord.z = CLAMP((CAMERA.coord.z + CAMBUFFER.z),-120,120); //meters, 2 arcminutes either direction
	CAMERA.coord.fov = CLAMP((CAMERA.coord.fov + CAMBUFFER.w),5,255); //degrees (solid degrees?)
	}

struct world
	{
	struct torusmap *map;
	struct entity *ent;
	struct entity *ent_tail;
	struct thing *scen;
	struct thing *scen_tail;
	struct event *evnt;
	struct event *evnt_tail;
	struct cameratype *cam;
	};

//---<HR>---

onstep_master ()
	{
	glx__eventswitch(dsply,glxwin);
	onstep_player();
	onstep_camera();
	ready = TRUE;
	}

onstep_paused ()
	{
	glx__eventswitch(dsply,glxwin);
	onstep_camera();
	ready = TRUE;
	}

#include "./models/mapgen.h"

/*MAIN*/
mainloop ()
	{
	init__setup();
	printf(" \033[1;97m~~ Iwannafly ~~\033[m\n  version: %s\n\n \033[97m- %s -\033[m\n  main program revision: %s\n   joystick handler revision: %s\n\n\033[3mCompiled on %s\033[m\n",__MYVERS__,"Prealpha",REV_MAIN,REV_JS,__DATE__);
	while (run)
		{
		if (nextframe)
			{
			if (ready)
				{
				glx__drawLoop(WORLD);
				nextframe = FALSE;
				ready = FALSE;
				}
			else
				{
				if (paused)
					{
					onstep_paused();
					}
				else
					{
					if (stepcount < MSEC_FRAME)
						{
						onstep_master();
						stepcount++;
						}
					else
						{
						refresh_land();
						onstep_master();
						stepcount = 0;
						}
					}
				}
			}
		else
			{}
		}
	printf("runlevel lowered, exiting...\n");
	exit(0);
	}
END}
