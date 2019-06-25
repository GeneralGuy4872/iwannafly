#define XCOORD(N) (((n + N) % 360) * 60)
#define YCOORD(N) (((m + N) % 360) * 60)
#define ZCOORD (MAP.dots[n][m] * 5)

refresh_land()
	{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	for (n = player.pos.x + VIEWRNGmin;n < (player.pos.x + VIEWRNGlim);n++)
		{
		for (m = player.pos.y + VIEWRNGmin;m < VIEWRNG;m++)
			{
			glBegin(GL_TRIANGLE_FAN)
				glvertex3f(XCOORD(0),YCOORD(0),ZCOORD)
				glvertex3f(XCOORD(1),YCOORD(0),ZCOORD)
				glvertex3f(XCOORD(1),YCOORD(1),ZCOORD)
				glvertex3f(XCOORD(0),YCOORD(1),ZCOORD)
			glEnd()
			}
		}
	}
#undefine XCOORD
#undefine YCOORD
#undefine ZCOORD
	
groundcheck(argument)
	entity argument
	{
	
	double xpos = argument.pos.x / 60
	short xcoord = floor(xpos) % 360
	float xrem = xpos - xcoord
	double ypos = argument.pos.y / 60
	short ycoord = floor(ypos) % 360
	float yrem = ypos - ycoord
	float groundlvl
	
	if ((xrem == 0) && (yrem == 0))
		{
		groundlvl = MAP.dots[xcoord][ycoord]
		}
	else if (xrem == 0)
		{
		groundlvl = ((yrem * MAP.dots[xcoord][ycoord]) + ((1 - yrem) * MAP.dots[xcoord][(ycoord + 1)%360]) / 2)
		}
	else if (yrem == 0)
		{
		groundlvl = ((xrem * MAP.dots[xcoord][ycoord]) + ((1 - xrem) * MAP.dots[(xcoord + 1)%360][ycoord]) / 2)
		}
	else if ((xrem + yrem) == 60)
		{
		groundlvl = ((xrem * MAP.dots[xcoord][ycoord]) + ((1 - xrem) * MAP.dots[(xcoord + 1)%360][(ycoord + 1)%360]) / 2)
		}
	else if ((xrem + yrem) > 60)
		{
		groundlvl = (((xrem * MAP.dots[xcoord][(ycoord + 1)%360]) + ((1 - xrem) * MAP.dots[(xcoord + 1)%360][(ycoord + 1)%360]) / 2) + ((yrem * MAP.dots[(xcoord + 1)%360][ycoord]) + ((1 - yrem) * MAP.dots[(xcoord + 1)%360][(ycoord + 1)%360]) / 2) / 2)
		}
	else
		{
		groundlvl = (((xrem * MAP.dots[xcoord][ycoord]) + ((1 - xrem) * MAP.dots[(xcoord + 1)%360][ycoord]) / 2) + ((yrem * MAP.dots[xcoord][ycoord]) + ((1 - yrem) * MAP.dots[xcoord][(ycoord + 1)%360]) / 2) / 2)
		}
	
	groundlvl = groundlvl * 5
	
	if (argument.pos.z <= groundlvl)
		{
		argument.stat.ground = TRUE
		}
	else
		{
		argument.stat.ground = FALSE
		}
	
	if (argument.pos.z < groundlvl)
		{
		argument.pos.z = groundlvl
		}
	}
