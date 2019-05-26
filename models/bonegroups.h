#include "./models.h"
#include "./shapes.h"
#include "./matrixgen.h"

void doublelink(xyzzy)
  struct bone *xyzzy
  {
  xyzzy->prev->next = *xyzzy
  }

struct bone *spine(prev,root,nmax,len)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  float len
  {
  unsigned char n = 0
  struct bone verta[10]
  while (n < nmax)
    {
    verta[n] = {root,prev,NULL,{0,0,n!=0},{0,0,len/nmax},matgen_ident,matgen_ident,TRUE,NULL,0}
    prev->next = *verta[n]
    prev = *verta[n]
    n++
    }
  return *verta[nmax-1]
  }
  
struct bone *xtail(prev,root,nmax,len)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  float len
  {
  unsigned char n = 0
  struct bone verta[10]
  while (n < nmax)
    {
    verta[n] = {root,prev,NULL,{-1,0,0},{-len/nmax,0,0},matgen_ident,matgen_ident,TRUE,NULL,0}
    prev->next = *verta[n]
    prev = *verta[n]
    n++
    }
  return *verta[nmax-1]
  }
  
struct bone *ztail(prev,root,nmax,len)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  float len
  {
  unsigned char n = 0
  struct bone verta[10]
  while (n < nmax)
    {
    verta[n] = {root,prev,NULL,{0,0,-1},{-len/nmax,0,0},matgen_ident,matgen_ident,TRUE,NULL,0}
    prev->next = *verta[n]
    prev = *verta[n]
    n++
    }
  return *verta[nmax-1]
  }

struct bone *handphalanges(prev,root,nmax,rot)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  struct vector3 rot
  {
  float len = root->len.x
  unsigned char n = 0
  struct bone phalng[nmax]
  while (n < nmax)
    {
    float len = len/G_RATIO
    phalng[n] = {root,prev,NULL,{1,0,0},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z),matgen_ident,TRUE,NULL,0}
    prev->next = *phalng[n]
    prev = *phalng[n]
    n++
    rot = {0,0,0}
    }
  return *phalng[nmax-1]
  }

struct bone *thumbphalanges(prev,root,nmax,rot)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  struct vector3 rot
  {
  float len = root.len.x / M_PI
  unsigned char n = 0
  struct bone phalng[nmax]
  while (n < nmax)
    {
    phalng[n] = {root,prev,NULL,{1,0,0},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z),matgen_ident,TRUE,NULL,0}
    prev->next = *phalng[n]
    prev = *phalng[n]
    n++
    rot = {0,0,0}
    len = len/G_RATIO
    }
  return *phalng[nmax-1]
  }

struct bone *footphalanges(prev,root,nmax,rot)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  struct vector3 rot
  {
  float len = root.len.x
  unsigned char n = 0
  struct bone phalng[nmax]
  while (n < nmax)
    {
    len = len/S_RATIO
    phalng[n] = {root,prev,NULL,{1,0,-1*(n==0)},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z),matgen_ident,TRUE,NULL,0}
    prev->next = *phalng[n]
    prev = *phalng[n]
    n++
    rot = {0,0,0}
    }
  return *phalng[nmax-1]
  }

struct bone *talonphalanges(prev,root,nmax,rot,factor)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  struct vector3 rot
  double factor
  {
  float len = ((root.len.z * -1) / M_E) * factor
  unsigned char n = 0
  struct bone phalng[nmax]
  while (n < nmax)
    {
    len = len/G_RATIO
    phalng[n] = {root,prev,NULL,{1,0,-1*(n==0)},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z),matgen_ident,TRUE,NULL,0}
    prev->next = *phalng[n]
    prev = *phalng[n]
    n++
    rot = {0,0,0}
    }
  return *phalng[nmax-1]
  }

struct bone *arm(prev,root,len,side)
  struct bone *prev
  struct bone *root
  float len
  tern side
  {
  struct bone limb[2]
    {
    prev->next = *limb[0]
    limb[0] = {root,prev,limb[1],{1,0,0},{len,0,0},matgen_ident,matgen_ident,TRUE,NULL,0}
    len = len/G_RATIO
    limb[1] = {root,limb[0],NULL,{1,0,0},{len,0,0},matgen_x_deg(90),matgen_ident,TRUE,NULL,0}
    }
  return *limb[1]
  }

struct bone *leg(prev,root,len,Q,side)
  struct bone *prev
  struct bone *root
  float len
  float Q
  tern side
  {
  struct bone limb[2]
    {
    prev->next = *limb[0]
    limb[0] = {root,prev,limb[1],{0,side/2,1},{0,0,-1*len},matgen_x_deg(Q),matgen_ident,TRUE,NULL,0}
    len = len/G_RATIO
    Q = Q * -1
    limb[1] = {root,limb[0],NULL,{0,0,1},{0,0,-1*len},matgen_x_deg(Q),matgen_ident,TRUE,NULL,0}
    }
  return *limb[1]
  }

struct bone *digiti(prev,root,len,Q,side)
  struct bone *prev
  struct bone *root
  float len
  struct vector2 Q
  tern side
  {
  struct bone limb[3]
    {
    prev->next = *limb[0]
    limb[0] = {root,prev,limb[1],{0,side/2,1},{0,0,-1 * len},matgen_master_deg(Q.x,Q.y,0),matgen_ident,TRUE,NULL,0}
    Q = {Q.x * -1,Q.y * 2 * -1}
    limb[1] = {root,limb[0],limb[2],{0,0,1},{0,0,-1 * len * G_RATIO},matgen_master_deg(Q.x,Q.y,0),matgen_ident,TRUE,NULL,0}
    Q = {0,Q.y * -1}
    limb[2] = {root,limb[1],NULL,{0,0,1},{0,0,-1 * len},matgen_master_deg(Q.x,Q.y,0),matgen_ident,TRUE,NULL,0}
    }
  return *limb[2]
  }

struct bone *avewing(prev,root,len,side)
  struct bone *prev
  struct bone *root
  float len
  tern side
  {
  struct bone limb[3]
    {
    prev->next = *limb[0]
    limb[0] = {root,prev,limb[1],{0,0,1},{0,0,len},matgen_x_deg(135 * side),matgen_ident,TRUE,NULL,0}
    limb[1] = {root,limb[0],limb[2],{0,0,1},{0,0,len * G_RATIO},matgen_x_deg(108 * side),matgen_ident,TRUE,NULL,0}
    limb[2] = {root,limb[1],NULL,{0,0,1},{0,0,len},matgen_x_deg(150 * -1 * side),matgen_ident,TRUE,NULL,0}
    }
  return *limb[2]
  }
