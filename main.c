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
#include <regex.h>
#include <sys/stat.h>
#include <fcntl.h>

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

#include "./joystick.c"
#include "./xwindow.c"
#include "./glxwindow.c"

float g = 9.8
char Ff = 2

clock_t prevframe = clock()
int msec
int timer = 100
bool pause FALSE

long long sealevel = 0
double north = 0

struct entity
	{
	long long x
	long long y
	long long z
	double yaw
	double pitch
	double roll
	unsigned int length
	unsigned int width
	unsigned int depth
	unsigned char m
	int VeloX
	int VeloY
	int VeloZ
	int TorqZ
	int TorqY
	int TorqX
	}

void onstep_player ()
	{
	player.VeloX = (player.VeloX + axis_buffer_x0) / (Ff * player.m)
	player.VeloY = (player.VeloY + axis_buffer_y0) / (Ff * player.m)
	player.VeloZ = (player.VeloZ + axis_buffer_lt + axis_buffer_rt) - (g * player.m)
	player.TorqX = ((player.TorqX + axis_buffer_lt) - axis_buffer_rt) / (Ff * player.m)
	player.TorqZ = (player.TorqZ + axis_buffer_x1) / (Ff * player.m)
	player.TorqY = (player.TorqY + axis_buffer_y1) / (Ff * player.m)
	
	player.x = player.x + player.VeloX
	player.y = player.y + player.VeloY
	player.z = player.z + player.VeloZ
	player.yaw = player.yaw + player.TorqZ
	player.pitch = player.pitch + player.TorqY
	player.roll = player.roll + player.TorqX
	}

struct cameratype camera
	{
	int x
	int y
	unsigned int z
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

/*****MAIN*****/
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

void emrbrake (runaway)
entity runaway
	{
	runaway.VeloX = 0
	runaway.VeloY = 0
	runaway.VeloZ = 0
	printf("Do you know how fast you were going?\n")
	}

void gimbllock (stalled)
entity stalled
	{
	stalled.TorqX = 0
	stalled.TorqY = 0
	stalled.TorqZ = 0
	stalled.pitch = 0
	stalled.roll = 0
	stalled.yaw = 0
	printf("Send me a fouth gimbal for christmas!\n")
	}

void resetcamera ()
	{
	camera.azimuth = 0
	camera.elevation = 0
	camera.range = 0
	camera.fov = 55 * (M_PI / 180)
	printf("Lakitu! Cut that out!\n")
	}
