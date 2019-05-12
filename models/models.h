struct bytevec
  {
  signed char x
  signed char y
  signed char z
  }

struct boolvec
  {
  bool x
  bool y
  bool z
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
