struct bytevec
  {
  signed char x
  signed char y
  signed char z
  }

struct broadcolor
  {
  vec3 color
  vec3 hyper
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
  bytevec ident,
  vec3 len, //x=l,d y=r,w z=h
  vec3 trans,
  mat4 base,
  mat4 curr,
  bool drawline,
  polygon *faces[],
  unsigned char n_polys,
  }

struct skeleton
  {
  bone *root
  unsigned char n_bones
  broadcolor pigment
  }

  //opengl stuff
