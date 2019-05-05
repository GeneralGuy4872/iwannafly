struct poly
  {
  vec3 A
  vec3 B
  vec3 C
  }

struct bone
  {
  bone *prev
  vec3 *off
  mat4 base
  mat4 curr
  vec3 dim
  bool line
  poly *polys[]
  int n_polys
  }

struct skeleton
  {
  bone *bones[]
  int n_bones
  }

  //opengl stuff
