#define HMCOORD(X,Y,M) {X%360,Y%360,M[X][Y]}

/*terrain generation should load smaller heightmaps that measure 60"*60"*256m (arcminutes,arcminutes,meters)
* exactly 9 of these are loaded at all times based on player position on the torus.
* only the 200 vertexes surrounding the player will be loaded from their meshes; the ones in the set:
* (floor(pos.x)-4 <= x <= ceil(pos.x)+4),(floor(pos.y)-4 <= y <= ceil(pos.y)+4)
* vertecies that exit this range will be unloaded. every map has 36 sectors.
* the entire world map is stored in ram, as a pointer array would be larger than the
* actual char array. (entire map is 127KiB, what's the point of splitting it?)*/

polygon ground[7][7][2]

create_land()
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
      ground[n][m][0] = {HMCOORD(xcoord,ycoord,map),HMCOORD((xcoord + 1),ycoord,map),HMCOORD(xcoord,(ycoord + 1),map)}
      ground[n][m][1] = {HMCOORD((xcoord + 1),(ycoord + 1),map),HMCOORD((xcoord + 1),ycoord,map),HMCOORD(xcoord,(ycoord + 1),map)}
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
      ground[n][m][0] = {HMCOORD(xcoord,ycoord,map),HMCOORD((xcoord + 1),ycoord,map),HMCOORD(xcoord,(ycoord + 1),map)}
      ground[n][m][1] = {HMCOORD((xcoord + 1),(ycoord + 1),map),HMCOORD((xcoord + 1),ycoord,map),HMCOORD(xcoord,(ycoord + 1),map)}
      m++
      ycoord++
      }
    n++
    xcoord++
    }}
