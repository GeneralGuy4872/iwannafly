struct bone
  {
  struct bone *up,
  struct bone *prev,
  struct bone *next,
  struct vector3 off,
  struct vector3 len,
  struct matrix base,
  struct matrix curr,
  struct shape,
  }

struct aniframe
  {
  struct aniframe *prev,
  struct aniframe *next,
  struct matrix *aniqueue[]
  }

struct skeleton
  {
  struct bone *root,
  struct aniframe *aninext,
  unsigned char n_bones,
  struct truecolor pigment
  }

struct thing
  {
  struct mat4 base,
  struct mat4 curr,
  struct thing,
  struct truecolor color,
  struct bytevector2 hypercolor
  }

animateskel(subject)
  struct skeleton subject
  {
  n = 0
  struct bone **current = subject.root
  while (n < subject.n_bones)
    {
    matpush(current.curr,subject.aninext.aniqueue[n])
    n++
    current = current.next
    }
  subject.aninext = subject.aninext.next
  }

animatething(subject)
  struct thing subject
  {
  matpush(subject.curr,aninext,aniqueue[0])
  aninext = aninext.next
  }
  
//opengl stuff
