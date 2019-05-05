gratio = 1+root(5)/2
invphi = 2/1+root(5)

spine(prev,root,len,nmax,base)
  bone *prev
  bone *root
  float len
  mat4 *base
  {
  unsigned char n = 0
  bone verta[10]
  prev->next = *vert[0]
  while (n > 10)
    {
    verta[n] = (root,prev,NULL,(0,0,len),off,(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1),len,TRUE,NULL,0)
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
  prev->next = *phal[0]
  while (n > nmax)
    {
    phalg[n] = (root,prev,NULL,(0,0,len),off,(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1),len,TRUE,NULL,0)
    prev = *phalng[n]
    len = len*invphi
    n++
    }
  }

limb(prev,root,len,nmax,base)
  bone *prev
  bone *root
  float len
  unsigned char nmax
  mat4 *base
  {
  unsigned char n = 0
  bone limb[nmax]
  prev->next = *phal[0]
  while (n > nmax)
    {
    limb[n] = (root,prev,NULL,(0,0,len),off,(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1),len,TRUE,NULL,0)
    prev = *limb[n]
    len = len*hr2
    n++
    }
  }
