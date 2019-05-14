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
	vec3 pos
	vec2 off
	vec2 hitbox
	vec3 Velo
	vec3 rot
	vec3 Torq
	mat4 ori
	bool wet
	bool ground
	tern bouyent
	vec3 Ff //x = Friction, y = Water Drag, z = Air Drag
	vec4 Spd //x = Land Speed, y = Mud Speed, z = Air Speed, w = Water speed
	skeleton dembones
	}

struct light
	{
	vec3 pos
	vec3 size
	broadcolor emission
	}
//HERE BE DRAGONS
#define SPEED (X) (X.wet ? (X.ground ? X.Spd.y : X.Spd.w) : (X.ground ? X.Spd.x : X.Spd.z))
#define PHYSICS (X,Y,Z) ((X.Y + (Z * SPEED(X))) - ABSMIN(X.Ff.x * SIGN(X.Y + (Z * SPEED(X) )),X.Y + (Z * SPEED(X)) ) / SANE((X.Ff.w * X.stat.y) + (X.Ff.y * !(X.stat.y))
#define GRAVITY (X,Y,Z) (((X.Y + (Z * X.Spd.z)) - (grav * !(X.ground) * (X.bouyent * X.wet))) * !(X.ground)) / SANE((X.Ff.y * !(X.ground) * X.wet) + (X.Ff.z * !(X.ground) * !(X.wet)
#define ROLL (X,Y,Z) ((X.Y + (Z * X.Spd.z)) * !(X.ground) / SANE((X.Ff.y * !(X.ground) * X.wet) + (X.Ff.z * !(X.ground) * !(X.wet)
//end dragons

void onstep_player ()
	{
	player.Velo.x = PHYSICS(player,Velo.x,player_buffer.x0)
	player.Velo.y = PHYSICS(player,Velo.y,player_buffer.y0)
	player.Velo.z = GRAVITY(player,Velo.z,(player_buffer.rt + player_buffer.lt))
	player.Torq.x = ROLL(player,Torq.x,(player_buffer.rt - player_buffer.lt))
	player.Torq.z = PHYSICS(player,Torq.z,player_buffer.x1)
	player.Torq.y = PHYSICS(player,Torq.y,player_buffer.y1)
	
	player.pos.x = player.pos.x + player.Velo.x
	player.pos.y = player.pos.y + player.Velo.y
	player.pos.z = player.pos.z + player.Velo.z

	player.rot.x = modulo(player.rot.x + player.Torq.x,360)
	player.rot.y = modulo(player.rot.y + player.Torq.y,360)
	player.rot.z = modulo(player.rot.z + player.Torq.z,360)

	player.ori = matgen_master(player.rot.x,player.rot.y,player.rot.z,1,1,1)
	
	/*
	some_function_gl_set_origin(player.pos.x,player.pos.y,player.pos.z)
	some_function_gl_push_matrix(player.ori)
	*/
	}

struct cameratype camera
	{
	entity root
	vec4 coord
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
