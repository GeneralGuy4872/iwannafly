#include "./models.h"
#include "./shapes.h"
#include "./matrixgen.h"

float gratio = (1+root(5))/2
float sratio = 1+root(2)

bone *spine(prev,root,nmax,len)
  bone *prev
  bone *root
  unsigned char nmax
  float len
  {
  unsigned char n = 0
  bone verta[10]
  while (n < nmax)
    {
    verta[n] = (root,prev,NULL,(0,0,len),(0,0,0),matgen_identity,matgen_translate(0,0,len),TRUE,NULL,0)
    prev->next = *verta[n]
    prev = *verta[n]
    n++
    }
  return *verta[nmax-1]
  }

bone *handphalanges(prev,root,nmax,rot)
  bone *prev
  bone *root
  unsigned char nmax
  vec3 rot
  vec3 scale
  {
  float len = root.len.x
  unsigned char n = 0
  bone phalng[nmax]
  while (n < nmax)
    {
    len = len/gratio
    phalng[n] = (root,prev,NULL,(len,0,0),(0,0,0),matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *phalng[n]
    prev = *phalng[n]
    n++
    dir = 1
    }
  return *phalng[nmax-1]
  }

bone *footphalanges(prev,root,nmax,rot,dir)
  bone *prev
  bone *root
  unsigned char nmax
  vec3 rot
  signed char dir
  {
  float len = root.len.x
  unsigned char n = 0
  bone phalng[nmax]
  while (n < nmax)
    {
    len = len/sratio
    phalng[n] = (root,prev,NULL,(len,0,0),(0,0,0),matgen_master_deg(rot.x,rot.y,rot.z,dir,1,dir),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *phalng[n]
    prev = *phalng[n]
    n++
    dir = 1
    }
  return *phalng[nmax-1]
  }

bone *arm(prev,root,len)
  bone *prev
  bone *root
  float len
  {
  unsigned char n = 0
  bone limb[2]
  while (n < 2)
    {
    limb[n] = (root,prev,NULL,(len,0,0),(0,0,0),matgen_identity,matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len/gratio
    n++
    }
  return limb[1]
  }

bone *leg(prev,root,len,Q,dir)
  bone *prev
  bone *root
  float len
  float Q
  signed char dir
  {
  unsigned char n = 0
  signed char s = 1
  bone limb[2]
  while (n < 2)
    {
    limb[n] = (root,prev,NULL,(0,0,len),(0,0,0),matgen_master_deg(180+Q,0,0,dir,1,dir),matgen_translate(0,0,len),TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len/gratio
    n++
    s = s * -1
    dir = 1
    }
  return limb[1]
  }

bone *digiti(prev,root,len,dir)
  bone *prev
  bone *root
  float len
  signed char dir
  {
  unsigned char n = 0
  signed char s = 1
  bone limb[nmax]
  while (n < 3)
    {
    limb[n] = (root,prev,NULL,(len,0,0),(0,0,0),matgen_master_deg(0,180,0,dir,s,dir),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len/gratio
    n++
    s = -1
    dir = 1
    }
  return *limb[2]
  }

bone *avewing(prev,root,len,rot,dir)
  bone *prev
  bone *root
  float len
  vec3 rot
  signed char dir
  {
  unsigned char n = 0
  signed char s = 1
  bone limb[3]
  while (n < 3)
    {
    limb[n] = (root,prev,NULL,(len,0,0),(0,0,0),matgen_master_deg(rot.x*(n==0),rot.y*(n==0),rot.z*(n==0),dir*s,dir,1),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len*sratio
    n++
    s = -1
    dir = 1
    }
  return *limb[2]
  }
