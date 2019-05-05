struct line
  {
  xyzdouble O
  xyzdouble P
  }

struct poly
  {
  xyzdouble A
  xyzdouble B
  xyzdouble C
  }

struct bone
  {
  bone *prev
  xyzdouble *off
  mat4 base
  mat4 curr
  float len
  float rad
  float w
  float h
  line *lines[]
  poly *polys[]
  int n_lines
  int n_polys
  }
  
  //opengl stuff
