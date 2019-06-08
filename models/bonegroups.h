#include "./models.h"
#include "./shapes.h"
#include "./matrixgen.h"

void doublelink(xyzzy)
  struct bone xyzzy
  {
  xyzzy->prev->next = xyzzy
  }

void deletent(xyzzy)
  struct entity xyzzy
  {
  xyzzy.prev ? xyzzy->prev->next = xyzzy->next : HARD_ERROR_MACRO("function call","deletent() of "__FILE__"; Line#"__LINE__,"Invalid operation: Tried to unload player. This would lead to undefined behavior throughout the entire program. Session terminated by safty officer")
  xyzzy.next ? xyzzy->next->prev = xyzzy->prev : WORLD.ent_tail = xyzzy->prev
  free(xyzzy)
  }

void deletscn(xyzzy)
  struct thing xyzzy
  {
  xyzzy.prev ? xyzzy->prev->next = xyzzy->next : WORLD.scen = xyzzy->next
  xyzzy.next ? xyzzy->next->prev = xyzzy->prev : WORLD.scen_tail = xyzzy->prev
  free(xyzzy)
  }

void deletevnt(xyzzy)
  struct event xyzzy
  {
  xyzzy.prev ? xyzzy->prev->next = xyzzy->next : WORLD.evnt = xyzzy->next
  xyzzy.next ? xyzzy->next->prev = xyzzy->prev : WORLD.evnt_tail = xyzzy->prev
  free(xyzzy)
  }

struct bone *spine(root,prev,nmax,len)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  float len
  {
  struct bone verta[10]
  for (n = 0;n < nmax;n++)
    {
    verta[n] = {root,prev,NULL,{NFR_ZERO,NFR_ZERO,n==0 ? NFR_ZERO : NFR_ONE},{0,0,len/nmax},matgen_ident,matgen_ident,TRUE,NULL}
    prev->next = verta[n]
    prev = verta[n]
    }
  return verta[nmax-1]
  }

struct bone *offspine(root,prev,nmax,len)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  float len
  {
  struct bone verta[10]
  for (n = 0;n < nmax;n++)
    {
    verta[n] = {root,prev,NULL,{NFR_ZERO,NFR_ZERO,NFR_ONE},{0,0,len/nmax},matgen_ident,matgen_ident,TRUE,NULL}
    prev->next = verta[n]
    prev = verta[n]
    }
  return verta[nmax-1]
  }
  
struct bone *xtail(root,prev,nmax,len)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  float len
  {
  struct bone verta[10]
  for (n = 0;n < nmax;n++)
    {
    verta[n] = {root,prev,NULL,{NFR_MONE,NFR_ZERO,NFR_ZERO},{-len/nmax,0,0},matgen_ident,matgen_ident,TRUE,NULL}
    prev->next = verta[n]
    prev = verta[n]
    }
  return verta[nmax-1]
  }
  
struct bone *ztail(root,prev,nmax,len)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  float len
  {
  struct bone verta[10]
  for (n = 0;n < nmax;n++)
    {
    verta[n] = {root,prev,NULL,{NFR_ZERO,NFR_ZERO,NFR_MONE},{-len/nmax,0,0},matgen_ident,matgen_ident,TRUE,NULL}
    prev->next = verta[n]
    prev = verta[n]
    }
  return verta[nmax-1]
  }

struct bone *handphalanges(root,prev,nmax,rot)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  struct vector3 rot
  {
  float len = root->len.x
  struct bone phalng[nmax]
  for (n = 0;n < nmax;n++)
    {
    float len = len/G_RATIO
    phalng[n] = {root,prev,NULL,{NFR_ONE,NFR_ZERO,NFR_ZERO},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z),matgen_ident,TRUE,NULL}
    prev->next = *phalng[n]
    prev = *phalng[n]
    rot = {0,0,0}
    }
  return *phalng[nmax-1]
  }

struct bone *thumbphalanges(root,prev,nmax,rot)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  struct vector3 rot
  {
  float len = root.len.x / M_PI
  struct bone phalng[nmax]
  for (n = 0;n < nmax;n++)
    {
    phalng[n] = {root,prev,NULL,{NFR_ONE,NFR_ZERO,NFR_ZERO},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z),matgen_ident,TRUE,NULL}
    prev->next = *phalng[n]
    prev = *phalng[n]
    rot = {0,0,0}
    len = len/G_RATIO
    }
  return *phalng[nmax-1]
  }

struct bone *footphalanges(root,prev,nmax,rot)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  struct vector3 rot
  {
  float len = root.len.x
  struct bone phalng[nmax]
  for (n = 0;n < nmax;n++)
    {
    len = len/S_RATIO
    phalng[n] = {root,prev,NULL,{NFR_ONE,NFR_ZERO,n==0 ? NFR_MONE : NFR_ZERO},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z),matgen_ident,TRUE,NULL}
    prev->next = *phalng[n]
    prev = *phalng[n]
    rot = {0,0,0}
    }
  return *phalng[nmax-1]
  }

struct bone *talonphalanges(root,prev,nmax,rot,factor)
  struct bone *prev
  struct bone *root
  unsigned char nmax
  struct vector3 rot
  double factor
  {
  float len = ((root.len.z * -1) / M_E) * factor
  struct bone phalng[nmax]
  for (n = 0;n < nmax;n++)
    {
    len = len/G_RATIO
    phalng[n] = {root,prev,NULL,{NFR_ONE,NFR_ZERO,n==0 ? NFR_MONE : NFR_ZERO},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z),matgen_ident,TRUE,NULL}
    prev->next = *phalng[n]
    prev = *phalng[n]
    rot = {0,0,0}
    }
  return *phalng[nmax-1]
  }

struct bone *arm(root,prev,len,side)
  struct bone *prev
  struct bone *root
  float len
  tern side
  {
  struct bone limb[2]
    {
    prev->next = *limb[0]
    limb[0] = {root,prev,limb[1],{NFR_ONE,NFR_ZERO,NFR_ZERO},{len,0,0},matgen_ident,matgen_ident,TRUE,NULL}
    len = len/G_RATIO
    limb[1] = {root,limb[0],NULL,{NFR_ONE,NFR_ZERO,NFR_ZERO},{len,0,0},matgen_x_deg(90),matgen_ident,TRUE,NULL}
    }
  return *limb[1]
  }

struct bone *leg(root,prev,len,Q,side)
  struct bone *prev
  struct bone *root
  float len
  float Q
  tern side
  {
  struct bone limb[2]
    {
    prev->next = *limb[0]
    limb[0] = {root,prev,limb[1],{NFR_ZERO,NFR_SIGN(side,1,2),NFR_ONE},{0,0,-1*len},matgen_x_deg(Q),matgen_ident,TRUE,NULL}
    len = len/G_RATIO
    Q = Q * -1
    limb[1] = {root,limb[0],NULL,{NFR_ZERO,NFR_ZERO,NFR_ONE},{0,0,-1*len},matgen_x_deg(Q),matgen_ident,TRUE,NULL}
    }
  return *limb[1]
  }

struct bone *digiti(root,prev,len,Q,side)
  struct bone *prev
  struct bone *root
  float len
  struct vector2 Q
  tern side
  {
  struct bone limb[3]
    {
    prev->next = *limb[0]
    limb[0] = {root,prev,limb[1],{NFR_ZERO,NFR_SIGNED(side,1,2),NFR_ONE},{0,0,-1 * len},matgen_master_deg(Q.x,Q.y,0),matgen_ident,TRUE,NULL}
    Q = {Q.x * -1,Q.y * 2 * -1}
    limb[1] = {root,limb[0],limb[2],{NFR_ZERO,NFR_ZERO,NFR_ONE},{0,0,-1 * len * G_RATIO},matgen_master_deg(Q.x,Q.y,0),matgen_ident,TRUE,NULL}
    Q = {0,Q.y * -1}
    limb[2] = {root,limb[1],NULL,{NFR_ZERO,NFR_ZERO,NFR_ONE},{0,0,-1 * len},matgen_master_deg(Q.x,Q.y,0),matgen_ident,TRUE,NULL}
    }
  return *limb[2]
  }

struct bone *avewing(root,prev,len,side)
  struct bone *prev
  struct bone *root
  float len
  tern side
  {
  struct bone limb[3]
    {
    prev->next = *limb[0]
    limb[0] = {root,prev,limb[1],{NFR_ZERO,NFR_ZERO,NFR_ONE},{0,0,len},matgen_x_deg(135 * side),matgen_ident,TRUE,NULL}
    limb[1] = {root,limb[0],limb[2],{NFR_ZERO,NFR_ZERO,NFR_ONE},{0,0,len * G_RATIO},matgen_x_deg(108 * side),matgen_ident,TRUE,NULL}
    limb[2] = {root,limb[1],NULL,{NFR_ZERO,NFR_ZERO,NFR_ONE},{0,0,len},matgen_x_deg(150 * -1 * side),matgen_ident,TRUE,NULL}
    }
  return limb[2]
  }
