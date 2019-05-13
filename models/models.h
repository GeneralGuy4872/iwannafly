struct bytevec
  {
  signed int x : 2
  signed int y : 2
  signed int z : 2
  signed int w : 2
  }

struct broadcolor
  {
  vec3 color
  vec2 hyper
  }

struct polygon
  {
  vec3 A
  vec3 B
  vec3 C
  }

struct bone
  {
  bone *up,
  bone *prev,
  bone *next,
  vec3 off,
  vec3 len,
  mat4 base,
  mat4 curr,
  bool drawline,
  polygon *faces[],
  unsigned char n_polys,
  }

struct aniframe
  {
  aniframe *prev
  aniframe *next
  mat4 *aniqueue[]
  }

struct skeleton
  {
  bone *root
  aniframe *aninext 
  unsigned char n_bones
  broadcolor pigment
  }
  
//opengl stuff
