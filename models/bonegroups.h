#include "./models.h"
#include "./shapes.h"
#include "./matrixgen.h"

float gratio = (1+root(5))/2
float sratio = 1+root(2)

spine(prev,root,len,nmax)
  bone *prev
  bone *root
  float len
  {
  unsigned char n = 0
  bone verta[10]
  while (n < nmax)
    {
    verta[n] = (root,prev,NULL,(1,1,1),(0,0,len),(0,0,0),matgen_identity,matgen_translate(0,0,len),TRUE,NULL,0)
    prev->next = *verta[n]
    prev = *verta[n]
    n++
    }
  }

handphalanges(prev,root,nmax,rot)
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
    phalng[n] = (root,prev,NULL,(0,1,n==0),(len,0,0),(0,0,0),matgen_master(rot.x,rot.y,rot.z,1,1,1),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *phalng[n]
    prev = *phalng[n]
    n++
    }
  }

footphalanges(prev,root,nmax,rot)
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
    len = len/sratio
    phalng[n] = (root,prev,NULL,(0,1,n==0),(len,0,0),(0,0,0),matgen_master(rot.x,rot.y,rot.z,1,-1,1),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *phalng[n]
    prev = *phalng[n]
    n++
    }
  }

limb2(prev,root,len,is_arm)
  bone *prev
  bone *root
  float len
  unsigned char nmax
  bool is_arm
  {
  unsigned char n = 0
  bone limb[nmax]
  while (n < 2)
    {
    limb[n] = (root,prev,NULL,(is_arm||n==0,n==0,1),(len,0,0),(0,0,0),matgen_master(rot.x,rot.y,rot.z,1,1,1),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len/gratio
    n++
    }
  }

digiti(prev,root,len,Q,dir)
  bone *prev
  bone *root
  float len
  unsigned char nmax
  float Q
  vec3 dir
  {
  unsigned char n = 0
  signed char s = 1
  bone limb[nmax]
  while (n < 3)
    {
    limb[n] = (root,prev,NULL,(n==0,n==0,1),(len,0,0),(0,0,0),matgen_master(0,Q*(.5^n==0)),0,dir.x,dir.y*s,dir.z),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len/gratio
    n++
    s = s * -1
    }
  }

avewing(prev,root,len,Q,rot,dir)
  bone *prev
  bone *root
  float len
  unsigned char nmax
  float Q
  vec3 rot
  vec3 dir
  {
  unsigned char n = 0
  signed char s = 1
  bone limb[nmax]
  while (n < 3)
    {
    limb[n] = (root,prev,NULL,(0,n==0,1),(len,0,0),(0,0,0),matgen_master(rot.x*n==0,rot.y*n==0+Q*(n!=0),rot.z*n==0,dir.x,dir.y*s,dir.z),matgen_translate(len,0,0),TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len*sratio
    n++
    s = s * -1
    }
  }
