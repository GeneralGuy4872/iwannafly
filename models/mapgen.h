#define HMCOORD(M) M[xcoord%360][ycoord%360]
#define HMVERT(M) {xcoord%360,ycoord%360,HMCOORD(M)}

/*terrain generation should load smaller heightmaps that measure 60"*60"*256m (arcminutes,arcminutes,meters)
* exactly 9 of these are loaded at all times based on player position on the torus.
* only the 200 vertexes surrounding the player will be loaded from their meshes; the ones in the set:
* (floor(pos.x)-4 <= x <= ceil(pos.x)+4),(floor(pos.y)-4 <= y <= ceil(pos.y)+4)
* vertecies that exit this range will be unloaded. every map has 36 sectors.
* the entire world map is stored in ram, as a pointer array would be larger than the
* actual char array. (entire map is 127KiB, what's the point of splitting it?)*/

struct vector3 ground[150]

create_land(map)
  struct torusmap map
  {
  unsigned char n = 0
  unsigned char m
  signed short xcoord = -4
  signed short xmax = 5
  signed short ycoord
  signed short ymax = 5
  while (xcoord < xmax)
    {
    m = 0
    ycoord = -4
    while (ycoord < ymax)
      {
      //line xy xy1;x1y;x1y1
      m++
      ycoord++
      }
    n++
    xcoord++
    }}

refresh_land(player)
  struct entity player
  {
  unsigned char n = 0
  unsigned char m
  signed short xcoord = MYFLOOR(player.pos.x) - 4
  signed short xmax = MYCEIL(player.pos.x) + 4
  signed short ycoord
  signed short ymax = MYCEIL(player.pos.y) + 4
  while (xcoord < xmax)
    {
    m = 0
    ycoord = MYFLOOR(player.pos.x) - 4
    while (ycoord < ymax)
      {
      //line xy xy1;x1y;x1y1
      m++
      ycoord++
      }
    n++
    xcoord++
    }}

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
