/**********************************
* Working Title: I wanna Fly      *
*                                 *
* An open world/flight simulation *
* program with a winged humanoid  *
* player character, written on    *
* OpenGL/Mesa and Athena (Xt,Xaw) *
***********************************/

//NOTE: I've decided that it's faster to write first and worry about syntax later.
//the resulting psudocode is largely C-based with elements borrowed from C++, GLSL, and Mathmatic Notation

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
//for use with forks, to keep track of what code belongs to what process.
//(this isn't SNOBOL this time; SNOBOL has no loops. it's Pascal.)
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

/*all exact mesurements should folow SI units or SI acceptable units (i.e. degrees),
* since real mesurements are used, conclusions can be made about the
* physical characteristics of any elements of the game, so be careful!
* this does not apply to the friction factors and may or may not apply to the speed factors
* of the basic physics implementation; inprecise mesures of time based on accumulated loops
* approximately equal to one second with a margin of error based on CPU speed and strain
* use "microfortnights" as in VMS for the PDP-11, to distinguish them from exact values.
* nautical miles and meters may (but shouldn't) be used interchangeably for reasons explained below
*/

#define grav (9.8 / FPS)
//meters / second / microfortnight

struct entity
	{
	struct entity *prev
	struct entity *next
	struct vector3 pos
	struct hitbox_type hitbox
	struct vector3 Velo
	struct vector3 Torq
	matrix rot = matgen_ident
	struct statreg stat
		/* bool ground
		 * bool wet
		 * bool yinv
		 * bool horiz
		 * tern bouy
		 * bool uv
		 * bool infra - deferred
		 * -BOUND-
		 * bool gills - deferred
		 * bool wings
		 * bool fireproof - deferred
		 * bool caster - deferred
		 * bool trouble - deferred
		 * bool weather - deferred
		 * bool darkpower - deferred
		 * bool lightpower - deferred
		 */
	struct minivector collid //NOT IMPLEMENTED x = restrict x movement, y = restrict y movement, z = restrict z movement, w = mirror movement/parlyz
	unsigned char health
	float Ff
	unsigned short m
	struct vector2 *Drag //x = ground, y = water, z = air
	struct vector3 *Fa //x = ground, y = water, z = air
	struct skeleton dembones
	//aside from half-floats or fixed-points, niether of which I have, this is as small as it gets...
	}

//HERE BE DRAGONS
#define INVPIT(X) (SANE(FSGN(X.stat.yinv)))
#define SPEED(X,Y,Z) (X.Y + ((Z * ACCL(X))/ X.m)
#define ACCL(X) SANE(X.stat.wet ? (X.stat.wings ? (X.Fa->y / 4) : X.Fa->y) : (X.stat.ground ? X.Fa->x : X.Fa->z ))
#define DRAG(X) SANE(X.stat.wet ? (X.stat.ground ? (2 * X.Drag->y) : X.Drag->y) : (X.stat.ground ? X.Drag->x : X.Drag->z))
#define PHYSICS(X,Y,Z) ((SPEED(X,Y,Z) - ABSMIN((X.Ff * X.stat.ground * SGN(SPEED(X,Y,Z)),SPEED(X,Y,Z))) / DRAG(X)))
#define GRAVITY(X,Y) (X.Y - (X.stat.ground ? 0 : (X.stat.wet ? (grav * X.stat.bouy) : grav)) / DRAG(X))
#define ROLL(X,Y,Z) (X.stat.ground ? 0 : PHYSICS(X,Y,Z))
//end dragons

onstep_player
	{
	PLAYER.Torq.x = ROLL(player,Torq.x,MOVEBUFFER_rol)
	PLAYER.Torq.z = PHYSICS(player,Torq.z,MOVEBUFFER.yaw)
	PLAYER.Torq.y = PHYSICS(player,Torq.y,MOVEBUFFER.pit)

	PLAYER.rot.x = CLAMP((player.rot.x + player.Torq.x),-90,90) //degrees
	PLAYER.rot.y = CLAMP((player.rot.y + player.Torq.y),-90,90) //degrees
	PLAYER.rot.z = (player.rot.z + player.Torq.z)%360 //degrees

	PLAYER.Velo.x = PHYSICS(player,Velo.x,((MOVEBUFFER.x * cos(PLAYER.rot.z) * cos(PLAYER.rot.y)) + (MOVEBUFFER.y * sin(PLAYER.rot.z) * sin(PLAYER.rot.x)) + (MOVEBUFFER_Z * cos(PLAYER.rot.y) * cos(PLAYER.rot.z))))
	PLAYER.Velo.y = PHYSICS(player,Velo.y,((MOVEBUFFER.x * sin(PLAYER.rot.z) * cos(PLAYER.rot.y)) + (MOVEBUFFER.y * cos(PLAYER.rot.z) * sin(PLAYER.rot.x)) + (MOVEBUFFER_Z * sin(PLAYER.rot.x) * sin(PLAYER.rot.z))))
	PLAYER.Velo.z = PHYSICS(player,Velo.z,((MOVEBUFFER.x * cos(PLAYER.rot.z) * sin(PLAYER.rot.y)) + (MOVEBUFFER.y * sin(PLAYER.rot.z) * cos(PLAYER.rot.x)) + (MOVEBUFFER_Z * sin(PLAYER.rot.y) * cos(PLAYER.rot.x))))
	PLAYER.Velo.z = GRAVITY(player,Velo.z)

	PLAYER.pos.x = (player.pos.x + player.Velo.x)%21600 //arcminutes
	PLAYER.pos.y = (player.pos.y + player.Velo.y)%21600 //arcminutes
	PLAYER.pos.z = CLAMP((player.pos.z + player.Velo.z),0,6000) //meters, zero;arbitrary ceiling

	if (PLAYER.stat.horiz)
		{
		matset_zeuler_deg(player.ori,player.rot.z,player.rot.y,player.rot.x,1,TOSGN(!(PLAYER.stat.yinv)),1)
		}
	else
		{
		matset_master_deg(player.ori,player.rot.x,player.rot.y,player.rot.z,1,TOSGN(!(PLAYER.stat.yinv)),1)
		}
	}

struct cameratype
	{
	struct camera_ang coord
	matrix rot
	struct viewform format
		/*
		int base 0 = dec, 1 = oct, -n = hex
		rotation base 0 = deg, 1 = rad base pi, -1 = gradians, -2 rad base 10
		speed units 0 = m/s, 1 = km/h, -1 = cm/s, -2 = ft/s
		elevation units 0 = m, 1 = km, -1 = cm, -2 = ft
		(latitude/longitude is always in degrees*minutes')
		infrared
		uv

		ft = 30cm
		*/
	unsigned short gold
	unsigned short points
	//they're comfy and easy to...wait...
	//since degrees are technically base 60 and speed is a float, points is the only thing that uses base
	}

onstep_camera
	{
	CAMERA.coord.x = (CAMERA.coord.x + CAMBUFFER.az)%360 //degrees
	CAMERA.coord.y = (CAMERA.coord.y + CAMBUFFER.alt)%360 //degrees; no roll axis, so not clamped to 180 to allow for inverting the view
	CAMERA.coord.r = CLAMP((CAMERA.coord.r + CAMBUFFER.zoom),-120,120) //meters, 2 arcminutes either direction
	CAMERA.coord.f = CLAMP((CAMERA.coord.f + CAMBUFFER.fov),5,270) //degrees
	matset_sphere_deg(CAMERA.coord.x + PLAYER.rot.z,CAMERA.coord.y,CAMERA.coord.r,1,1)
	}

struct world
	{
	struct torusmap *map
	struct entity *ent
	struct entity *ent_tail
	struct thing *scen
	struct thing *scen_tail
	struct event *evnt
	struct event *evnt_tail
	struct cameratype *cam
	}

//---<HR>---

onstep_master ()
	{
	onstep_player(PLAYER)
	onstep_camera(CAMERA)
	input__onstep_buffers()
	ready = TRUE
	}

onstep_paused ()
	{
	onstep_camera(CAMERA)
	input__onstep_camonly()
	ready = TRUE
	}

#include "./models/mapgen.h"

/*MAIN*/
mainloop ()
	{
	init__setup()
	printf(VITALSTAT_FULL(Without forks,REV_NOFORK))
	while run
		{
		if nextframe
			{
			if ready
				{
				glx__DrawLoop(WORLD)
				nextframe = FALSE
				ready = FALSE
				}
			else
				{
				if paused
					{
					onstep_paused()
					}
				else
					{
					if (stepcount < FPS)
						{
						onstep_master()
						stepcount++
						}
					else
						{
						refresh_land(PLAYER)
						onstep_master()
						stepcount = 0
						}
					}
				}
			}
		else
			{}
		}
	printf("runlevel lowered, exiting...")
	DOTLOAD
	printf("\n")
	exit(0)
	}
END}
