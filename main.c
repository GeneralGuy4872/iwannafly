/**************************************
*
* Working Title: I wanna Fly
*
* An open world/flight simulation
* program with a winged humanoid
* player character, written on
* OpenGL/Mesa and Athena (Xt,Xaw)
*
**************************************/

//NOTE: I've decided that it's faster to write first and worry about syntax later.
//the resulting psudocode is largely C-based with elements borrowed from C++, GLSL, and Mathmatic Notation

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
//#include <string.h>
//#include <regex.h>

#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
//#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <signal.h>
//#include <err.h>
//#include <errno.h>

#include <GL/gl.h>
#include <GL/glu.h> //know what this does now

//HORIZONTAL_RULE

#include "./main.h"
#include "./models/all.c"
#include "./init.c"
#include "./timing.c"

#include "./joystick.c"
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

const float grav = 9.8 / FPS //meters / second / microfortnight

struct entity
	{
	struct entity *prev
	struct entity *next
	struct vector3 pos
	const struct vector3 hitbox //x = radius, y = height, z = bone offset
	struct vector3 Velo
	struct vector3 Torq
	matrix rot = matgen_ident
	struct statreg stat //bool ground, bool wet, bool yinv, bool horiz, tern bouy, bool uv, bool infra NOT IMPLEMENTED
	struct microvec collid //NOT IMPLEMENTED x = restrict x movement, y = restrict y movement, z = restrict z movement, w = bone offset from
	unsigned char health
	const struct vector3 Ff //x = Friction, y = Water Drag, z = Air Drag
	const struct bytevector4 Spd //x = Land Speed, y = Mud Speed, z = Air Speed, w = Water speed
	struct skeleton dembones
	//aside from half-floats or fixed-points, niether of which I have, this is as small as it gets...
	}

//HERE BE DRAGONS
#define SPEED(X) ((X.stat.wet ? (X.stat.ground ? X.Spd.y : X.Spd.w) : (X.stat.ground ? X.Spd.x : X.Spd.z)) * X.collid.w)
#define INVPIT(X) (SANE(FSGN(X.stat.yinv)))
#define PHYSICS(X,Y,Z) ((X.Y + (Z * SPEED(X))) - ( (MIN((X.Ff.x * X.stat.ground * (Z * SPEED(X))),fabs(X.Y + (Z * SPEED(X)))) * FSGN(X.Y + (Z * SPEED(X))) / SANE((X.Ff.w * X.stat.wet) + (X.Ff.y * !(X.stat.wet))
#define GRAVITY(X,Y,Z) (((X.Y + (Z * X.Spd.z)) - (grav * !(X.stat.ground) * (X.stat.bouy * X.stat.wet))) * !(X.stat.ground)) / SANE((X.Ff.y * !(X.stat.ground) * X.stat.wet) + (X.Ff.z * !(X.stat.ground) * !(X.stat.wet))
#define ROLL(X,Y,Z) ((X.Y + (Z * X.Spd.z)) * !(X.stat.ground) / SANE((X.Ff.y * !(X.stat.ground) * X.stat.wet) + (X.Ff.z * !(X.stat.ground) * !(X.stat.wet))
//end dragons

onstep_player (player)
	struct entity player
	{
	player.Velo.x = PHYSICS(player,Velo.x,player_buffer.x0)
	player.Velo.y = PHYSICS(player,Velo.y,player_buffer.y0)
	player.Velo.z = GRAVITY(player,Velo.z,(player_buffer.rt + player_buffer.lt))
	player.Torq.x = ROLL(player,Torq.x,(player_buffer.rt - player_buffer.lt))
	player.Torq.z = PHYSICS(player,Torq.z,player_buffer.x1)
	player.Torq.y = PHYSICS(player,Torq.y,player_buffer.y1)
	
	player.pos.x = (player.pos.x + player.Velo.x)%21600 //arcminutes
	player.pos.y = (player.pos.y + player.Velo.y)%21600 //arcminutes
	/*torii are easier than spheres. cylinders are a better approximation, but have invisible walls the entire length
	* of the poles because their y axis is clamped. torri are modded instead of clamped.
	* this torus has a circumfrence of exactly 21600 meters and a ratio of 1:1.
	* assuming the original definition of 1 nautical mile = 1 arcminute, it would be = 1 meter
	* because of this, conversions between those units is moot.
	*/
	player.pos.z = CLAMP((player.pos.z + player.Velo.z),0,2048) //meters, zero;arbitrary ceiling
	player.rot.x = (player.rot.x + player.Torq.x)%360 //degrees
	player.rot.y = CLAMP((player.rot.y + player.Torq.y),-90,90) //degrees
	player.rot.z = (player.rot.z + player.Torq.z)%360 //degrees

	if (player.stat.horiz)
		{
		matset_zeuler_deg(player.ori,player.rot.z,player.rot.y,player.rot.x,1,INVPIT(player),1)
		}
	else
		{
		matset_master_deg(player.ori,player.rot.x,player.rot.y,player.rot.z,1,INVPIT(player),1)
		}
	
	xwind__update_vals(player)
	}

struct cameratype
	{
	struct entity *root
	struct vector4 coord
	matrix rot = matgen_ident
	struct viewform format //0 = dec, 1 = oct, -n = hex : 0 = deg, 1 = rad, 2 = turn, 3 = gon : 0 = m/ or nmi/, 1 = km/ : 0 = /s, 1 = /h : infra : uv
	unsigned short points
	//since degrees are technically base 60 and speed is a float, points is the only thing that uses base
	}

onstep_camera (camera)
	struct cameratype camera
	{
	camera.coord.x = (camera.coord.x + camera_buffer.x)%360 //degrees
	camera.coord.y = (camera.coord.y + camera_buffer.y)%360 //degrees; no roll axis, so not clamped to 180
	camera.coord.z = CLAMP((camera.coord.z + camera_buffer.z),-90,90) //meters, soccer pitch
	camera.coord.w = CLAMP((camera.coord.w + camera_buffer.w),5,270) //degrees
	matset_sphere_deg(camera,camera.coord.x,camera.coord.y,camera.coord.z,1,1)
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
main ()
	{
	init__setup()
	printf(VITALSTAT_FULL(Without forks,REV_NOFORK))
	//still see no reason that this couldn't be just as well with a goto-jump table...
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
