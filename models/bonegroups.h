float gratio = 1+root(5)/2
float invphi = 2/1+root(5)

spine(prev,root,len,nmax)
  bone *prev
  bone *root
  float len
  {
  unsigned char n = 0
  bone verta[10]
  while (n < nmax)
    {
    verta[n] = (root,prev,NULL,(1,1,1),(0,0,len),(0,0,0),(1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1),(1,0,0,0,0,1,0,0,0,0,1,0,0,0,len,1),len,TRUE,NULL,0)
    prev->next = *verta[n]
    prev = *verta[n]
    n++
    }
  }

phalanges(prev,root,len,nmax,base)
  bone *prev
  bone *root
  float len
  unsigned char nmax
  mat4 *base
  {
  unsigned char n = 0
  bone phalng[nmax]
  while (n < nmax)
    {
    phalg[n] = (root,prev,NULL,(0,1,n==0),(len,0,0),(0,0,0),(1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1),(1,0,0,0,0,1,0,0,0,0,1,0,len,0,0,1),len,TRUE,NULL,0)
    prev->next = *phalg[n]
    prev = *phalng[n]
    len = len*invphi
    n++
    }
  }

arm(prev,root,len,nmax,base)
  bone *prev
  bone *root
  float len
  unsigned char nmax
  mat4 base[nmax]
  {
  unsigned char n = 0
  bone limb[nmax]
  while (n < nmax)
    {
    limb[n] = (root,prev,NULL,(1,n==0,1),(len,0,0),(0,0,0),(1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1),(1,0,0,0,0,1,0,0,0,0,1,0,len,0,0,1),len,TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len*hr2
    n++
    }
  }
