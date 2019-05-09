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
  vec3 len, //x=l,d y=r,w z=h
  vec3 trans,
  boolvec freedom,
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

  /*a skeleton is a doubly-linked list of bone elements, traversed with struct fields .prev and .next,
  *that is also organized into a root-directed tree, traversed in one direction only by field .up.
  *the root of the tree and the head of the list are the same element.
  *the renderer will traverse the skeleton LINKED LIST, FORWARD, and propogate rotations along the TREE, OUTWARDS,
  *each time it is called with an animation queue.
  *an element pointed to by .up should occur in the list before the element referenceing it,
  *or rotations will not propogate proporly. (this could be a desired effect in some unforseen circumstance??)*/

struct aniframe
  {
  aniframe *next
  mat4 *rot
  }

  /*an animation queue is an array of pointers to matrixes, one for each bone in the asscociated skeleton.
  *an animation sequence is a circular singly linked list of animation queues
  *and a pointer that circles through it. an animation pointer points to the pointer of the active animation sequence.*/
  
//opengl stuff
