#define ZCOORD hightfloat(MAP->dots[n%360][m%360])

refresh_land()
	{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	signed char xloop = VIEWRNGmin;
	for (signed short n = PLAYER->pos.x + VIEWRNGmin;n < (PLAYER->pos.x + VIEWRNGlim);n++)
		{
		signed char yloop = VIEWRNGmin;
		for (signed short m = PLAYER->pos.y + VIEWRNGmin;m < (PLAYER->pos.y + VIEWRNGlim);m++)
			{
			glColor4ub(0,0xFF,0,0xFF);
			glBegin(GL_TRIANGLE_STRIP);
				glVertex3f(xloop*60,yloop*60,ZCOORD);
				glVertex3f((xloop+1)*60,yloop*60,ZCOORD);
				glVertex3f((xloop+1)*60,(yloop+1)*60,ZCOORD);
				glVertex3f(xloop*60,(yloop+1)*60,ZCOORD);
			glEnd();
			glColor4ub(0,0x7F,0,0xFF);
			glBegin(GL_LINE_LOOP);
				glVertex3f(xloop*60,yloop*60,ZCOORD);
				glVertex3f((xloop+1)*60,yloop*60,ZCOORD);
				glVertex3f((xloop+1)*60,(yloop+1)*60,ZCOORD);
				glVertex3f(xloop*60,(yloop+1)*60,ZCOORD);
			glEnd();
			glBegin(GL_LINES);
				glVertex3f(xloop*60,yloop*60,ZCOORD);
				glVertex3f((xloop+1)*60,(yloop+1)*60,ZCOORD);
			glEnd();
			glColor4ub(0,0,0,0xFF);
			glBegin(GL_POINTS);
				glVertex3f(xloop*60,yloop*60,ZCOORD);
				glVertex3f((xloop+1)*60,yloop*60,ZCOORD);
				glVertex3f((xloop+1)*60,(yloop+1)*60,ZCOORD);
				glVertex3f(xloop*60,(yloop+1)*60,ZCOORD);
			glEnd();
			yloop++;
			}
		xloop++;
		}
	glFinish();
	glPopMatrix();
	}
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
