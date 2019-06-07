struct bone
  {
  struct bone *up,
  struct bone *prev,
  struct bone *next,
  const struct nfrvector3 off,
  const struct vector3 len,
  const struct matrix base,
  struct matrix curr,
  struct truecolor color,
  bool doline,
  struct shape geom,
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
  struct bone *head,
  struct aniframe *aninext,
  const unsigned char n_bones
  }

struct thing
  {
  struct thing *prev,
  struct thing *next,
  const struct mat4 base,
  struct mat4 curr,
  struct shape geom
  }

animateskel(subject)
  struct skeleton subject
  {
  struct bone **current = subject.root
  for (n = 0;n < subject.n_bones;n++)
    {
    matpush(current.curr,subject.aninext.aniqueue[n])
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
