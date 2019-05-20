struct bone
  {
  struct bone *up,
  struct bone *prev,
  struct bone *next,
  struct vector3 off,
  struct vector3 len,
  struct matrix base,
  struct matrix curr,
  bool drawline,
  struct polygon *faces[],
  unsigned char n_polys,
  }

struct aniframe
  {
  struct aniframe *prev
  struct aniframe *next
  struct matrix *aniqueue[]
  }

struct skeleton
  {
  struct bone *root
  struct aniframe *aninext 
  unsigned char n_bones
  struct truecolor pigment
  }

struct thing
  {
  struct mat4 base,
  struct mat4 current,
  struct polygon *faces,
  unsigned char n_polys,
  struct aniframe *aninext,
  struct truecolor color,
  struct bytevector2 hypercolor
  }
  
//opengl stuff
