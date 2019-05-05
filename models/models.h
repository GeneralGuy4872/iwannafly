struct poly
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
  mat4 base,
  mat4 curr,
  float len
  bool line,
  poly *faces[],
  unsigned char n_polys,
  }

struct skeleton
  {
  bone *root
  unsigned char n_bones
  }

  //opengl stuff
