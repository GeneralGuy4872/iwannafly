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
//#include <regex.h> : external awk script should work instead

#include <sys/stat.h>
#include <fcntl.h>
//#include <signal.h> : crash debugger might need this??
//#include <errno.h> : crash debugger might need this??

#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glx.h"

//Sound is a bit much for right now...
//#include "AL/al.h"
//#include "AL/alut.h"

#include "X11/Intrinsic.h"
#include "X11/StringDefs.h"
#include "X11/CoreP.h"
#include "X11/Xatom.h"
#include "X11/Xaw/Form.h"
#include "X11/Xaw/Box.h"
#include "X11/Xaw/Label.h"
#include "X11/Xaw/Command.h"
#include "X11/Xaw/Toggle.h"
#include "X11/Xaw/Scrollbar.h"
//originally wanted these for extra input, but fixed that
//still might use them for pause menu

#include "./joystick.c"

#include "./xwindow.c"
#include "./glxwindow.c"
#include "./textout.c"

#include "./init.c"

float g = 9.8
char Ff = 2

clock_t prevframe = clock()
int msec
int timer = 100
bool pause FALSE

long long sealevel = 0
double north = 0

struct xyzdouble
	{
	x
	y
	z
	}

struct entity
	{
	xyzdouble loc
	unsigned int length
	unsigned int width
	unsigned int depth
	unsigned char m
	xyzdouble Velo
	xyzdouble Torq
	}

void onstep_player ()
	{
	player.VeloX = (player.Velo.x + axis_buffer_x0) / (Ff * player.m)
	player.VeloY = (player.Velo.y + axis_buffer_y0) / (Ff * player.m)
	player.VeloZ = (player.Velo.z + axis_buffer_lt + axis_buffer_rt) - (g * player.m)
	player.TorqX = ((player.Torq.x + axis_buffer_lt) - axis_buffer_rt) / (Ff * player.m)
	player.TorqZ = (player.Torq.z + axis_buffer_x1) / (Ff * player.m)
	player.TorqY = (player.Torq.y + axis_buffer_y1) / (Ff * player.m)
	
	player.x = player.loc.x + player.Velo.x
	player.y = player.loc.y + player.Velo.y
	player.z = player.loc.z + player.Velo.z
	
	/*waiting on linear algabra book
	glTranslated(player.Velo.x,player.Velo.y,player.Velo.z)
	glRotated(player.Torq.z,0,0,1)
	glRotated(player.Torq.y,0,1,0)
	glRotated(player.Torq.x,1,0,0)*/
	}

struct cameratype camera
	{
	xyzdouble loc
	double azimuth
	double elevation
	double range
	double fov
	}

void onstep_camera ()
	{
	camera.azimuth = camera.azimuth + axis_buffer_x2
	camera.elevation = camera.elevation + axis_buffer_y2
	camera.range = camera.range + axis_buffer_x3
	camera.fov = camera.zoom + axis_buffer_y3
	
	//waiting on linear algabra book
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
