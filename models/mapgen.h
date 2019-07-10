#define XCOORD(N) (((n + N) % 360) * 60)
#define YCOORD(N) (((m + N) % 360) * 60)
#define ZCOORD hightfloat(MAP->dots[n][m])

refresh_land()
	{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	for (signed short n = PLAYER->pos.x + VIEWRNGmin;n < (PLAYER->pos.x + VIEWRNGlim);n++)
		{
		for (signed short m = PLAYER->pos.y + VIEWRNGmin;m < (PLAYER->pos.y + VIEWRNGlim);m++)
			{
			glBegin(GL_TRIANGLE_STRIP);
				glVertex3f(XCOORD(0),YCOORD(0),ZCOORD);
				glVertex3f(XCOORD(1),YCOORD(0),ZCOORD);
				glVertex3f(XCOORD(1),YCOORD(1),ZCOORD);
				glVertex3f(XCOORD(0),YCOORD(1),ZCOORD);
			glEnd();
			}
		}
	}
#undef XCOORD
#undef YCOORD
#undef ZCOORD
	
float groundcheck(argument)
	entity *argument;
	{
	double xpos = argument->pos.x / 60;
	short xcoord = fmod(floor(xpos),360);
	float xrem = xpos - xcoord;
	double ypos = argument->pos.y / 60;
	short ycoord = fmod(floor(ypos),360);
	float yrem = ypos - ycoord;
	float ground;
	
	if ((xrem == 0) && (yrem == 0))
		{
		ground = MAP->dots[xcoord][ycoord];
		}
	else if (xrem == 0)
		{
		ground = ((yrem * MAP->dots[xcoord][ycoord]) + ((1 - yrem) * MAP->dots[xcoord][(ycoord + 1)%360]) / 2);
		}
	else if (yrem == 0)
		{
		ground = ((xrem * MAP->dots[xcoord][ycoord]) + ((1 - xrem) * MAP->dots[(xcoord + 1)%360][ycoord]) / 2);
		}
	else if ((xrem + yrem) == 60)
		{
		ground = ((xrem * MAP->dots[xcoord][ycoord]) + ((1 - xrem) * MAP->dots[(xcoord + 1)%360][(ycoord + 1)%360]) / 2);
		}
	else if ((xrem + yrem) > 60)
		{
		ground = (((xrem * MAP->dots[xcoord][(ycoord + 1)%360]) + ((1 - xrem) * MAP->dots[(xcoord + 1)%360][(ycoord + 1)%360]) / 2) + ((yrem * MAP->dots[(xcoord + 1)%360][ycoord]) + ((1 - yrem) * MAP->dots[(xcoord + 1)%360][(ycoord + 1)%360]) / 2) / 2);
		}
	else
		{
		ground = (((xrem * MAP->dots[xcoord][ycoord]) + ((1 - xrem) * MAP->dots[(xcoord + 1)%360][ycoord]) / 2) + ((yrem * MAP->dots[xcoord][ycoord]) + ((1 - yrem) * MAP->dots[xcoord][(ycoord + 1)%360]) / 2) / 2);
		}
	
	return hightfloat(ground);
	}

float groundmake(xraw,yraw)
	float xraw;
	float yraw;
	{
	double xpos = xraw / 60;
	short xcoord = fmod(floor(xpos),360);
	float xrem = xpos - xcoord;
	double ypos = yraw / 60;
	short ycoord = fmod(floor(ypos),360);
	float yrem = ypos - ycoord;
	float ground;
	
	if ((xrem == 0) && (yrem == 0))
		{
		ground = MAP->dots[xcoord][ycoord];
		}
	else if (xrem == 0)
		{
		ground = ((yrem * MAP->dots[xcoord][ycoord]) + ((1 - yrem) * MAP->dots[xcoord][(ycoord + 1)%360]) / 2);
		}
	else if (yrem == 0)
		{
		ground = ((xrem * MAP->dots[xcoord][ycoord]) + ((1 - xrem) * MAP->dots[(xcoord + 1)%360][ycoord]) / 2);
		}
	else if ((xrem + yrem) == 60)
		{
		ground = ((xrem * MAP->dots[xcoord][ycoord]) + ((1 - xrem) * MAP->dots[(xcoord + 1)%360][(ycoord + 1)%360]) / 2);
		}
	else if ((xrem + yrem) > 60)
		{
		ground = (((xrem * MAP->dots[xcoord][(ycoord + 1)%360]) + ((1 - xrem) * MAP->dots[(xcoord + 1)%360][(ycoord + 1)%360]) / 2) + ((yrem * MAP->dots[(xcoord + 1)%360][ycoord]) + ((1 - yrem) * MAP->dots[(xcoord + 1)%360][(ycoord + 1)%360]) / 2) / 2);
		}
	else
		{
		ground = (((xrem * MAP->dots[xcoord][ycoord]) + ((1 - xrem) * MAP->dots[(xcoord + 1)%360][ycoord]) / 2) + ((yrem * MAP->dots[xcoord][ycoord]) + ((1 - yrem) * MAP->dots[xcoord][(ycoord + 1)%360]) / 2) / 2);
		}
	
	return hightfloat(ground);
}
