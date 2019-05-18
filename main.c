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

#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <GL/gl.h>
//#include <GL/glu.h> what does this do even?
#include <GL/glx.h>
//#include <fluidsynth.h>

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

/*all exact mesurements should folow SI units or SI acceptable units (i.e. degrees),
* since real mesurements are used, conclusions can be made about the
* physical characteristics of any elements of the game, so be careful!
* this does not apply to the friction factors and may or may not apply to the speed factors
* of the basic physics implementation; inprecise mesures of time based on accumulated loops
* approximately equal to one second with a margin of error based on CPU speed and strain
* use "microfortnights" as in VMS for the PDP-11, to distinguish them from exact values.
*/

float grav = 9.8 / FPS //meters / second / microfortnight

clock_t prevframe = clock()
int msec
int timer = 100
bool pause FALSE

struct entity
	{
	struct vector3 pos
	struct vector3 rot
	struct vector4 hitbox //x = radius, y = eye height offset, z = height, w = base bone z offset
	struct vector3 Velo
	struct vector3 Torq
	float rot[4][4] = matgen_ident
	struct statreg stat //bool ground, bool wet, bool yinv, bool horiz, tern bouy, bool uv, bool infa NOT IMPLEMENTED
	struct microvec collid //NOT IMPLEMENTED x = restrict x movement, y = restrict y movement, z = restrict z movement, w = flip dir
	unsigned char health //NOT IMPLEMENTED
	struct vector3 Ff //x = Friction, y = Water Drag, z = Air Drag
	struct bytevector Spd //x = Land Speed, y = Mud Speed, z = Air Speed, w = Water speed
	struct skeleton dembones
	//aside from half-floats or fixed-points, niether of which I have, this is as small as it gets...
	}
	/*collid.w sets hitbox proporties; 0=cylinder about z, 1=cylinder about x, -1 = cuboid of dimensions r*h*h.
	*hitbox.y is relative to this parameter, being along x at z = 0 if collid.w == 1,
	*along z at x = hitbox.radius otherwise. hitbox.w is always along z axis
	*and should be equal to hitbox.x if collid.w == 1*/


struct light
	{
	struct vector3 pos
	struct vector3 size
	struct truecolor emission
	}
//HERE BE DRAGONS
#define SPEED (X) ((X.stat.wet ? (X.stat.ground ? X.Spd.y : X.Spd.w) : (X.stat.ground ? X.Spd.x : X.Spd.z)) * X.collid.w)
#define INVPIT(X) (SANE(FSGN(X.stat.yinv)))
#define PHYSICS (X,Y,Z) ((X.Y + (Z * SPEED(X))) - ( (MIN((X.Ff.x * X.stat.ground * (Z * SPEED(X))),fabs(X.Y + (Z * SPEED(X)))) * FSGN(X.Y + (Z * SPEED(X))) / SANE((X.Ff.w * X.stat.wet) + (X.Ff.y * !(X.stat.wet))
#define GRAVITY (X,Y,Z) (((X.Y + (Z * X.Spd.z)) - (grav * !(X.stat.ground) * (X.stat.bouy * X.stat.wet))) * !(X.stat.ground)) / SANE((X.Ff.y * !(X.stat.ground) * X.stat.wet) + (X.Ff.z * !(X.stat.ground) * !(X.stat.wet))
#define ROLL (X,Y,Z) ((X.Y + (Z * X.Spd.z)) * !(X.stat.ground) / SANE((X.Ff.y * !(X.stat.ground) * X.stat.wet) + (X.Ff.z * !(X.stat.ground) * !(X.stat.wet))
//end dragons

void onstep_player ()
	{
	player.Velo.x = PHYSICS(player,Velo.x,player_buffer.x0)
	player.Velo.y = PHYSICS(player,Velo.y,player_buffer.y0)
	player.Velo.z = GRAVITY(player,Velo.z,(player_buffer.rt + player_buffer.lt))
	player.Torq.x = ROLL(player,Torq.x,(player_buffer.rt - player_buffer.lt))
	player.Torq.z = PHYSICS(player,Torq.z,player_buffer.x1)
	player.Torq.y = PHYSICS(player,Torq.y,player_buffer.y1)
	
	player.pos.x = (player.pos.x + player.Velo.x)%360 //degrees
	player.pos.y = (player.pos.y + player.Velo.y)%360 //degrees
	//torii are easier than spheres. cylinders are a better approximation, but have invisible walls the entire length of the poles.
	player.pos.z = MAX(MIN((player.pos.z + player.Velo.z),-127),255) //meters, 8bit heightmap
	player.rot.x = (player.rot.x + player.Torq.x)%360 //degrees
	player.rot.y = (player.rot.y + player.Torq.y)%360 //degrees
	player.rot.z = (player.rot.z + player.Torq.z)%360 //degrees
	if (player.stat.horiz)
	{
	matset_zeuler_deg(player.ori,player.rot.x,player.rot.y,player.rot.z,1,INVPIT(player),1)
	}
	else
	{
	matset_master_deg(player.ori,player.rot.x,player.rot.y,player.rot.z,1,INVPIT(player),1)
	}

struct cameratype camera
	{
	struct entity root
	struct vector4 coord
	//camera origin = root.pos + {0,0,root.off.y}
	}

void onstep_camera ()
	{
	camera.coord.x = (camera.coord.x + camera_buffer.x)%360 //degrees
	camera.coord.y = (camera.coord.y + camera_buffer.y)%360 //degrees
	camera.coord.z = MAX(MIN((camera.coord.z + camera_buffer.z),-90),90) //meters, soccer pitch
	camera.coord.w = MAX(MIN((camera.coord.w + camera_buffer.w),5),270) //degrees
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
