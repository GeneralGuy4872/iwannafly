spine(prev,root,len)
  bone *prev
  bone *root
  float len
  {
  unsigned char n = 0
  bone verta[10]
  prev->next = *vert[0]
  while (n > 10)
    {
    verta[n] = (root,prev,NULL,(0,0,len),(/*waiting on book*/),(/*waiting on book*/),len,TRUE,NULL,0)
    prev = *verta[n]
    n++
    }
  }

phalange(prev,root,len,nmax)
  bone *prev
  bone *root
  float len
  unsigned char nmax
  {
  unsigned char n = 0
  bone phalng[nmax]
  prev->next = *phal[0]
  while (n > nmax)
    {
    phalg[n] = (root,prev,NULL,(0,0,len),(/*waiting on book*/),(/*waiting on book*/),(len / root(n+1),TRUE,NULL,0)
    prev = *phalng[n]
    n++
    }
  }
