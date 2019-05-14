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

//NOTE: I've decided that it's faster to write the code first and worry about syntax later.

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <fluidsynth.h>

#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <X11/CoreP.h>
#include <X11/Xatom.h>
#include <X11/Xaw/Form.h>
#include <X11/Xaw/Box.h>
#include <X11/Xaw/Label.h>
#include <X11/Xaw/Command.h>
#include <X11/Xaw/Toggle.h>
#include <X11/Xaw/Scrollbar.h>
//originally wanted these for extra input, but fixed that
//still might use them for pause menu

#include "./main.h"

#include "./joystick.c"

#include "./xwindow.c"
#include "./glxwindow.c"
#include "./textout.c"

#include "./init.c"
#include "./models/all.c"

/*all mesurements should folow SI units,
* with the exception of using both degrees and radians in different places.
* since real meters and kilograms are used, conclusions can be made about
* the physical characteristics of any elements of the game, so be careful!*/

float grav = 9.8

clock_t prevframe = clock()
int msec
int timer = 100
bool pause FALSE

float sealevel = 0
float north = 0

struct entity
	{
	struct vector3 pos
	struct vector3 rot
	struct vector4 hitbox
	struct vector3 Velo
	struct vector3 Torq
	float rot[4][4] = matgen_ident
	struct bytevec stat //x = collision, y = reserved, z = bouyency, w = wet
	struct vector3 Ff //x = Friction, y = Water Drag, z = Air Drag
	struct vector4 Spd //x = Land Speed, y = Mud Speed, z = Air Speed, w = Water speed
	struct skeleton dembones
	//aside from half-floats or fixed-points, niether of which I have, this is as small as it gets...
	}

struct light
	{
	struct vector3 pos
	struct vector3 size
	struct truecolor emission
	}
//HERE BE DRAGONS
#define SPEED (X) (X.stat.w ? (X.stat.x ? X.Spd.y : X.Spd.w) : (X.stat.x ? X.Spd.x : X.Spd.z))
#define PHYSICS (X,Y,Z) ((X.Y + (Z * SPEED(X))) - ABSMIN(X.Ff.x * X.stat.x * SIGN(X.Y + (Z * SPEED(X) )),X.Y + (Z * SPEED(X)) ) / SANE((X.Ff.w * X.stat.w) + (X.Ff.y * !(X.stat.w))
#define GRAVITY (X,Y,Z) (((X.Y + (Z * X.Spd.z)) - (grav * !(X.stat.x) * (X.stat.z * X.stat.w))) * !(X.stat.x)) / SANE((X.Ff.y * !(X.stat.x) * X.stat.w) + (X.Ff.z * !(X.stat.x) * !(X.stat.w)
#define ROLL (X,Y,Z) ((X.Y + (Z * X.Spd.z)) * !(X.stat.x) / SANE((X.Ff.y * !(X.stat.x) * X.stat.w) + (X.Ff.z * !(X.stat.x) * !(X.stat.w)
//end dragons

void onstep_player ()
	{
	player.Velo.x = PHYSICS(player,Velo.x,player_buffer.x0)
	player.Velo.y = PHYSICS(player,Velo.y,player_buffer.y0)
	player.Velo.z = GRAVITY(player,Velo.z,(player_buffer.rt + player_buffer.lt))
	player.Torq.x = ROLL(player,Torq.x,(player_buffer.rt - player_buffer.lt))
	player.Torq.z = PHYSICS(player,Torq.z,player_buffer.x1)
	player.Torq.y = PHYSICS(player,Torq.y,player_buffer.y1)
	
	player.pos.x = MOD(player.pos.x + player.Velo.x,21600) //arcminutes
	player.pos.y = MOD(player.pos.y + player.Velo.y,10800) //arcminutes
	//torii are easier than spheres. cylinders are a better approximation, but have invisible walls the entire length of the poles.
	player.pos.z = MAX(MIN(player.pos.z + player.Velo.z,-10000),10000) //meters
	player.rot.x = MOD(player.rot.x + player.Torq.x,360)
	player.rot.y = MOD(player.rot.y + player.Torq.y,360)
	player.rot.z = MOD(player.rot.z + player.Torq.z,360)
	matset_master_deg(player.ori,,,))
	}

struct cameratype camera
	{
	struct entity root
	struct vector4 coord
	//camera origin = root.pos + {0,0,root.off.y}
	}

void onstep_camera ()
	{
	camera.coord.x = MOD(camera.coord.x + camera_buffer.x,360)
	camera.coord.y = MOD(camera.coord.y + camera_buffer.y,360)
	camera.coord.z = camera.coord.z + camera_buffer.z
	camera.coord.w = MAX((MIN((camera.coord.w + camera_buffer.w),5),270)
	}

void onstep_buffers ()
	{}

void onstep_render ()
	{}

void onstep_master ()
	{
	onstep_player()
	//implement ai entitys
	//implement collision checking
	onstep_camera()
	onstep_buffers()
	onstep_render()
	}

/*>>>MAIN<<<*/
main () {
	clock_t diff
		while !pause {
			diff = clock() - prevframe
			msec = diff * 1000 / CLOCKS_PER_SEC
			if (msec > timer) {
				prevframe = clock
				onstep_master()
				}
			}

//reimpliment gimbal lock fixers

//impliment a location checker
