#include "./models.h"
#include "./shapes.h"
#include "./matrixgen.h"

#define G_RATIO 1.618033988749894848205
#define S_RATIO 2.414213562373095048802

void doublelink(xyzzy)
  bone *xyzzy
  {
  xyzzy->prev->next = *xyzzy
  }

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
    verta[n] = (root,prev,NULL,(0,0,len),(0,0,0),(TRUE,TRUE,TRUE),matgen_identity,matgen_translate(0,0,len),TRUE,NULL,0)
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
  {
  float len = root.len.x
  unsigned char n = 0
  bone phalng[nmax]
  while (n < nmax)
    {
    len = len/G_RATIO
    phalng[n] = (root,prev,NULL,(len,0,0),(0,0,0),(FALSE,TRUE,n==0),matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *phalng[n]
    prev = *phalng[n]
    n++
    rot = (0,0,0)
    }
  return *phalng[nmax-1]
  }

bone *thumbphalanges(prev,root,nmax,rot)
  bone *prev
  bone *root
  unsigned char nmax
  vec3 rot
  {
  float len = root.len.x
  unsigned char n = 0
  bone phalng[nmax]
  while (n < nmax)
    {
    len = len/G_RATIO
    phalng[n] = (root,prev,NULL,(len,0,0),(0,0,0),(n==0,FALSE,TRUE),matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *phalng[n]
    prev = *phalng[n]
    n++
    rot = (0,0,0)
    }
  return *phalng[nmax-1]
  }

bone *footphalanges(prev,root,nmax,rot)
  bone *prev
  bone *root
  unsigned char nmax
  vec3 rot
  {
  float len = root.len.x
  unsigned char n = 0
  bone phalng[nmax]
  while (n < nmax)
    {
    len = len/S_RATIO
    phalng[n] = (root,prev,NULL,(len,0,0),(0,0,0),(FALSE,TRUE,n==0),matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *phalng[n]
    prev = *phalng[n]
    n++
    rot = (0,0,0)
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
    limb[n] = (root,prev,NULL,(len,0,0),(0,0,0),(TRUE,TRUE,n==0),matgen_x_deg(90*n,1,1,1),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len/G_RATIO
    n++
    }
  return limb[1]
  }

bone *leg(prev,root,len,Q,dir,off)
  bone *prev
  bone *root
  float len
  float Q
  bytevec dir
  vec3 off
  {
  unsigned char n = 0
  bone limb[2]
  while (n < 2)
    {
    limb[n] = (root,prev,NULL,(0,0,len),(off.x,off.y,off.z),(n==0,TRUE,n==0),matgen_master_deg(180+Q,0,0,dir.x,dir.y,dir.z),matgen_translate(0,0,len),TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len/G_RATIO
    n++
    Q = Q * -1
    dir = (-1,1,1)
    off = (0,0,0)
    }
  return limb[1]
  }

bone *digiti(prev,root,len,Q,dir,off)
  bone *prev
  bone *root
  float len
  vec2 Q
  bytevec dir
  vec3 off
  {
  unsigned char n = 0
  bone limb[3]
  while (n < 3)
    {
    limb[n] = (root,prev,NULL,(len,0,0),(off.x,off.y,off.z),(n==0,TRUE,n==0),matgen_master_deg(180+Q,180,0,dir.x,dir.y,dir.z),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len/G_RATIO
    n++
    Q = ((Q.x * (n<2) * -1),Q.y * ((n==1) + 1))
    dir = (1,-1,1)
    off = (0,0,0)
    }
  return *limb[2]
  }

bone *avewing(prev,root,len,rot)
  bone *prev
  bone *root
  float len
  vec3 rot
  bytevec dir
  {
  unsigned char n = 0
  signed char s = 1
  bone limb[3]
  while (n < 3)
    {
    limb[n] = (root,prev,NULL,(len,0,0),(0,0,0),(TRUE,n==1,FALSE),matgen_master_deg(rot.x,rot.y,rot.z,s,1,1),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len*S_RATIO
    n++
    s = s * -1
    rot = (0,0,0)
    }
  return *limb[2]
  }
