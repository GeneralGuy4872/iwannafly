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

typedef signed char tern

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

float g = 9.8
char Ff = 2
char Dair = 0
char Dwater = 2

clock_t prevframe = clock()
int msec
int timer = 100
bool pause FALSE

float sealevel = 0
float north = 0

struct entity
	{
	vec3 pos
	vec3 size
	vec2 off
	vec3 Velo
	vec3 rot
	vec3 Torq
	mat4 ori
	bool grounded
	bool wet
	float drag
	float wdrag
	tern bouyent
	unsigned char mass
	skeleton dembones
	}

struct light
	{
	vec3 pos
	vec3 size
	broadcolor emission
	}

#define MAX (A,B) A > B ? A : B
#define MIN (A,B) A < B ? A : B
#define PHYSICS (Ff * player.mass * player.grounded)) / ((player.wdrag * player.wet) + (player.drag * not(player.wet)
#define GRAVITY (g * not(player.grounded))) / ((player.wdrag * player.bouyent * player.wet) + (player.drag * not(player.wet)

void onstep_player ()
	{
	player.VeloX = MAX(((player.Velo.x + axis_buffer_0.x) - PHYSICS),0)
	player.VeloY = MAX(((player.Velo.y + axis_buffer_0.y) - PHYSICS),0)
	player.VeloZ = (player.Velo.z + axis_buffer_0.z + axis_buffer_1.z) - GRAVITY)
	player.TorqX = ((player.Torq.x + (axis_buffer_1.z - axis_buffer_0.z)) * not(player.grounded)
	player.TorqZ = modulo(player.Torq.z + axis_buffer_1.x,360)
	player.TorqY = modulo(player.Torq.y + axis_buffer_1.y,360)
	
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
	entity parent
	vec4 coord
	}

void onstep_camera ()
	{
	camera.coord.x = modulo(camera.coord.x + axis_buffer_2.x,360)
	camera.coord.y = modulo(camera.coord.y + axis_buffer_2.y,360)
	camera.coord.z = camera.coord.z + axis_buffer_2.z
	camera.coord.w = modulo(camera.fov + axis_buffer_2.w,360)
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
