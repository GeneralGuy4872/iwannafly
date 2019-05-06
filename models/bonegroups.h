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
    verta[n] = (root,prev,NULL,(1,1,1),(0,0,len),(0,0,0),(0,0,0),(1,0,0,0,0,1,0,0,0,0,1,0,0,0,len,1),TRUE,NULL,0)
    prev->next = *verta[n]
    prev = *verta[n]
    n++
    }
  }

phalanges(prev,root,len,nmax,thumb)
  bone *prev
  bone *root
  float len
  unsigned char nmax
  bool thumb
  {
  unsigned char n = 0
  bone phalng[nmax]
  while (n < nmax)
    {
    phalng[n] = (root,prev,NULL,(0,1,n==0),(len,0,0),(0,0,0),((thumb*M_PI)/2,0,0),(1,0,0,0,0,1,0,0,0,0,1,0,len,0,0,1),TRUE,NULL,0)
    prev->next = *phalng[n]
    prev = *phalng[n]
    len = len/gratio
    n++
    }
  }

limb2(prev,root,len,arm,Q,s)
  bone *prev
  bone *root
  float len
  unsigned char nmax
  bool arm
  float Q
  signed char s
  {
  unsigned char n = 0
  bone limb[nmax]
  while (n < 2)
    {
    limb[n] = (root,prev,NULL,(arm||n==0,n==0,1),(len,0,0),(0,0,0),(0,Q*s,0),(1,0,0,0,0,1,0,0,0,0,1,0,len,0,0,1),TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len/gratio
    n++
    s = s * -1
    }
  }

digiti(prev,root,len,Q,s)
  bone *prev
  bone *root
  float len
  unsigned char nmax
  float Q
  signed char s
  {
  unsigned char n = 0
  bone limb[nmax]
  while (n < 2)
    {
    limb[n] = (root,prev,NULL,(n==0,n==0,1),(len,0,0),(0,0,0),(0,Q*s*(.5^n==0),0),(1,0,0,0,0,1,0,0,0,0,1,0,len,0,0,1),TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len/gratio
    n++
    s = s * -1
    }
  }

avewing(prev,root,len,Q,s)
  bone *prev
  bone *root
  float len
  unsigned char nmax
  float Q
  signed char s
  {
  unsigned char n = 0
  bone limb[nmax]
  while (n < 2)
    {
    limb[n] = (root,prev,NULL,(0,n==0,1),(len,0,0),(0,0,0),(0,Q*(n!=0),0),(1,0,0,0,0,1,0,0,0,0,1,0,len,0,0,1),TRUE,NULL,0)
    prev->next = *limb[n]
    prev = *limb[n]
    len = len*sratio
    n++
    s = s * -1
    }
  }
