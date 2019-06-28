struct bone
  {
  struct bone *up;
  struct bone *prev;
  struct bone *next;
  struct charvector3 off;
  struct vector3 len;
  matrix base;
  matrix curr;
  struct truecolor color;
  bool drawline;
  struct shape *geom;
  }bone_typ;

/*
struct aniframe
  {
  struct aniframe *prev;
  struct aniframe *next;
  struct matrix *aniqueue;
  unsigned char n_frames;
  };

struct skeleton
  {
  struct bone *root;
  struct aniframe *aninext;
  const unsigned char n_bones;
  };

struct thing
  {
  struct thing *prev;
  struct thing *next;
  const struct matrix base;
  struct matrix curr;
  struct shape *geom;
  };

animateskel(subject)
  struct skeleton subject;
  {
  struct bone **current = subject.root;
  for (n = 0;n < subject.n_bones;n++)
    {
    matpush(current.curr,subject.aninext.aniqueue[n]);
    current = current.next;
    }
  subject.aninext = subject->aninext.next;
  }
*/
