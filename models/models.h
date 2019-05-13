struct polygon
  {
  struct vec3 A
  struct vec3 B
  struct vec3 C
  }

struct bone
  {
  struct bone *up,
  struct bone *prev,
  struct bone *next,
  struct vec3 off,
  struct vec3 len,
  struct mat4 base,
  struct mat4 curr,
  bool drawline,
  polygon *faces[],
  unsigned char n_polys,
  }

struct aniframe
  {
  struct aniframe *prev
  struct aniframe *next
  struct mat4 *aniqueue[]
  }

struct skeleton
  {
  struct bone *root
  struct aniframe *aninext 
  unsigned char n_bones
  struct broadcolor pigment
  }
  
//opengl stuff
