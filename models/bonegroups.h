#include "./models.h"
#include "./shapes.h"
#include "./matrixgen.h"

#define G_RATIO 1.618033988749894848205
#define S_RATIO 2.414213562373095048802
#define LEFT -1
#define RIGHT 1

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
    verta[n] = (root,prev,NULL,(0,0,n!=0),(0,0,len/nmax),matgen_ident,matgen_ident,TRUE,NULL,0)
    prev->next = *verta[n]
    prev = *verta[n]
    n++
    }
  return *verta[nmax-1]
  }
  
bone *tail(prev,root,nmax,len)
  bone *prev
  bone *root
  unsigned char nmax
  float len
  {
  unsigned char n = 0
  bone verta[10]
  while (n < nmax)
    {
    verta[n] = (root,prev,NULL,(-1,0,0),(-len/nmax,0,0),matgen_ident,matgen_ident,TRUE,NULL,0)
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
  float len = root->len.x
  unsigned char n = 0
  bone phalng[nmax]
  while (n < nmax)
    {
    float len = len/G_RATIO
    phalng[n] = (root,prev,NULL,(1,0,0),(len,0,0),matgen_master_deg(rot.x,rot.y,rot.z),matgen_ident,TRUE,NULL,0)
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
  float len = root.len.x / M_PI
  unsigned char n = 0
  bone phalng[nmax]
  while (n < nmax)
    {
    phalng[n] = (root,prev,NULL,(1,0,0),(len,0,0),matgen_master_deg(rot.x,rot.y,rot.z),matgen_ident,TRUE,NULL,0)
    prev->next = *phalng[n]
    prev = *phalng[n]
    n++
    rot = (0,0,0)
    len = len/G_RATIO
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
    phalng[n] = (root,prev,NULL,(1,0,-1*(n==0)),(len,0,0),matgen_master_deg(rot.x,rot.y,rot.z),matgen_ident,TRUE,NULL,0)
    prev->next = *phalng[n]
    prev = *phalng[n]
    n++
    rot = (0,0,0)
    }
  return *phalng[nmax-1]
  }

bone *talonphalanges(prev,root,nmax,rot,factor)
  bone *prev
  bone *root
  unsigned char nmax
  vec3 rot
  double factor
  {
  float len = ((root.len.z * -1) / M_E) * factor
  unsigned char n = 0
  bone phalng[nmax]
  while (n < nmax)
    {
    len = len/G_RATIO
    phalng[n] = (root,prev,NULL,(1,0,-1*(n==0)),(len,0,0),matgen_master_deg(rot.x,rot.y,rot.z),matgen_ident,TRUE,NULL,0)
    prev->next = *phalng[n]
    prev = *phalng[n]
    n++
    rot = (0,0,0)
    }
  return *phalng[nmax-1]
  }

bone *arm(prev,root,len,side)
  bone *prev
  bone *root
  float len
  signed char side
  {
  bone limb[2]
    {
    limb[0] = (root,prev,limb[1],(1,0,0),(len,0,0),matgen_ident,matgen_ident,TRUE,NULL,0)
    len = len/G_RATIO
    limb[1] = (root,limb[0],NULL,(1,0,0),(len,0,0),matgen_x_deg(90),matgen_ident,TRUE,NULL,0)
    }
  return limb[1]
  }

bone *leg(prev,root,len,Q,side)
  bone *prev
  bone *root
  float len
  float Q
  signed char side
  {
  bone limb[2]
    {
    limb[0] = (root,prev,limb[1],(0,side/2,1),(0,0,-1*len),matgen_x_deg(Q),matgen_ident,TRUE,NULL,0)
    len = len/G_RATIO
    Q = Q * -1
    limb[1] = (root,limb[0],NULL,(0,0,1),(0,0,-1*len),matgen_x_deg(Q),matgen_ident,TRUE,NULL,0)
    }
  return limb[1]
  }

bone *digiti(prev,root,len,Q,side)
  bone *prev
  bone *root
  float len
  vec2 Q
  unsigned char side
  {
  bone limb[3]
    {
    limb[0] = (root,prev,limb[1],((0,side/2,1),(0,0,-1*len),matgen_master_deg(Q.x,Q.y,0),matgen_ident,TRUE,NULL,0)
    Q = (Q.x * -1,Q.y * 2 * -1)
    limb[1] = (root,limb[0],limb[2],((0,0,1),(0,0,-1*len*M_SQRT2),matgen_master_deg(Q.x,Q.y,0),matgen_ident,TRUE,NULL,0)
    Q = (0,Q.y * -1)
    limb[2] = (root,limb[1],NULL,((0,0,1),(0,0,-1*len),matgen_master_deg(Q.x,Q.y,0),matgen_ident,TRUE,NULL,0)
    }
  return *limb[2]
  }

bone *avewing(prev,root,len,side)
  bone *prev
  bone *root
  float len
  signed char side
  {
  bone limb[3]
    {
    prev->next = *limb[0]
    limb[0] = (root,prev,limb[1],(0,0,1),(0,0,len),matgen_x_deg(127.5 * side),matgen_ident,TRUE,NULL,0)
    len = len * G_RATIO
    limb[1] = (root,limb[0],limb[2],(0,0,1),(0,0,len),matgen_x_deg(105 * side),matgen_ident,TRUE,NULL,0)
    len = len * G_RATIO
    limb[2] = (root,limb[1],NULL,(0,0,1),(0,0,len),matgen_x_deg(142.5 * -1 * side),matgen_ident,TRUE,NULL,0)
    }
  return *limb[2]
  }

polygon crystal[8] bone_octo(0.1)
polygon crate[12] bone_cube(1,1,1)
