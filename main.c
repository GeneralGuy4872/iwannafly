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

#define FWD 1
#define RT 1
#define UP 1
#define BKWD -1
#define LFT -1
#define DN -1

#include "./joystick.c"

#include "./xwindow.c"
#include "./glxwindow.c"
#include "./textout.c"

#include "./init.c"
#include "./models/all.c"

float g = 9.8
char Ff = 2

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
	bool airborn
	unsigned char mass
	unsigned char drag
	skeleton dembones
	}

struct light
	{
	vec3 pos
	vec3 size
	broadcolor emission
	}

void onstep_player ()
	{
	player.VeloX = (player.Velo.x + axis_buffer_0.x) / ((Ff * not(airborn) * player.mass) + player.drag)
	player.VeloY = (player.Velo.y + axis_buffer_0.y) / ((Ff * not(airborn) * player.mass) + player.drag)
	player.VeloZ = (player.Velo.z + axis_buffer_0.z + axis_buffer_1.z) - (g / drag)
	player.TorqX = ((player.Torq.x + (axis_buffer_0.z - axis_buffer_1.z)) / (player.mass + player.drag)) * player.airborn
	player.TorqZ = (player.Torq.z + axis_buffer_1.x) / ((Ff * not(airborn) * player.mass) + player.drag)
	player.TorqY = (player.Torq.y + axis_buffer_1.y) / ((Ff * not(airborn) * player.mass) + player.drag)
	
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
