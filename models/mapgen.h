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
	
/* ground collisions
if x+y<1
	if y<x
		z = ((pos.x%1)*map[x][y]) + ((1 - pos.x%1)*map[x+1][y])/2
	else if y>x
		z = ((pos.y%1)*map[x][y]) + ((1 - pos.y%1)*map[x][y+1])/2
	else
		z = ((pos.x%1)*map[x][y]) + ((1 - pos.x%1)*((map[x+1][y]+map[x][y+1])/2))/2
else if x+y>1
	if y<x
		z = ((pos.x%1)*map[x+1][y]) + ((1 - pos.x%1)*map[x+1][y+1])
	else if y>x
		z = ((pos.y%1)*map[x][y+1]) + ((1 - pos.y%1)*map[x+1][y+1])
	else
		z = ((pos.x%1)*((map[x+1][y]+map[x][y+1])/2))) + ((1 - pos.x%1)*map[x+1][y+1]/2
else
	z = ((pos.x%1)*map[x][y+1]) + ((1 - pos.x%1)*map[x+1][y])/2
*/

#undefine XCOORD
#undefine YCOORD
#undefine ZCOORD
