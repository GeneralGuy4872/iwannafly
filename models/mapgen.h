/*terrain generation should load smaller heightmaps that measure 60"*60"*256m (arcminutes,arcminutes,meters)
* exactly 9 of these are loaded at all times based on player position on the torus.
* only the 200 vertexes surrounding the player will be loaded from their meshes; the ones in the set:
* (floor(pos.x)-4 <= x <= ceil(pos.x)+4),(floor(pos.y)-4 <= y <= ceil(pos.y)+4)
* vertecies that exit this range will be unloaded. every map has 36 sectors.
* the entire world map is stored in ram, as a pointer array would be larger than the
* actual char array. (entire map is 127KiB, what's the point of splitting it?)*/
