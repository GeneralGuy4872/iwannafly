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
