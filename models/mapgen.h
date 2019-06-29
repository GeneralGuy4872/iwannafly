#define XCOORD(N) (((n + N) % 360) * 60)
#define YCOORD(N) (((m + N) % 360) * 60)
#define ZCOORD hightfloat(MAP.dots[n][m])

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
	
float groundcheck(argument)
	entity argument
	{
	
	double xpos = argument.pos.x / 60
	short xcoord = floor(xpos) % 360
	float xrem = xpos - xcoord
	double ypos = argument.pos.y / 60
	short ycoord = floor(ypos) % 360
	float yrem = ypos - ycoord
	float ground
	
	if ((xrem == 0) && (yrem == 0))
		{
		ground = MAP.dots[xcoord][ycoord]
		}
	else if (xrem == 0)
		{
		ground = ((yrem * MAP.dots[xcoord][ycoord]) + ((1 - yrem) * MAP.dots[xcoord][(ycoord + 1)%360]) / 2)
		}
	else if (yrem == 0)
		{
		ground = ((xrem * MAP.dots[xcoord][ycoord]) + ((1 - xrem) * MAP.dots[(xcoord + 1)%360][ycoord]) / 2)
		}
	else if ((xrem + yrem) == 60)
		{
		ground = ((xrem * MAP.dots[xcoord][ycoord]) + ((1 - xrem) * MAP.dots[(xcoord + 1)%360][(ycoord + 1)%360]) / 2)
		}
	else if ((xrem + yrem) > 60)
		{
		ground = (((xrem * MAP.dots[xcoord][(ycoord + 1)%360]) + ((1 - xrem) * MAP.dots[(xcoord + 1)%360][(ycoord + 1)%360]) / 2) + ((yrem * MAP.dots[(xcoord + 1)%360][ycoord]) + ((1 - yrem) * MAP.dots[(xcoord + 1)%360][(ycoord + 1)%360]) / 2) / 2)
		}
	else
		{
		ground = (((xrem * MAP.dots[xcoord][ycoord]) + ((1 - xrem) * MAP.dots[(xcoord + 1)%360][ycoord]) / 2) + ((yrem * MAP.dots[xcoord][ycoord]) + ((1 - yrem) * MAP.dots[xcoord][(ycoord + 1)%360]) / 2) / 2)
		}
	
	return hightfloat(ground)
	}
