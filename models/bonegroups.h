#define doublelink(M) M.prev->next = M
#define deref_next(T,M) ((T)M)->next
#define deref_prev(T,M) ((T)M)->prev
#define deref_up(T,M) ((T)M)->up
#define macrodelete(T,M) {M.prev != NULL ? deref_next(T,M.prev) = M.next : SWYM; M.next != NULL ? deref_prev(T,M.next) = M.prev : SWYM; free(M)}

void deletent(xyzzy)
  entity xyzzy;
  {
  xyzzy.prev != NULL ? deref_next(entity*,xyzzy.prev) = xyzzy.next : HARD_ERROR_MACRO;
  xyzzy.next != NULL ? deref_prev(entity*,xyzzy.next) = xyzzy.prev : WORLD.ent_tail = xyzzy.prev;
  free(&xyzzy);
  }

void deletscn(xyzzy)
  thing xyzzy;
  {
  xyzzy.prev != NULL ? deref_next(thing*,xyzzy.prev) = xyzzy.next : WORLD.scen;
  xyzzy.next != NULL ? deref_prev(thing*,xyzzy.next) = xyzzy.prev : WORLD.scen_tail = xyzzy.prev;
  free(&xyzzy);
  }

void deletevnt(xyzzy)
  mainh_event xyzzy;
  {
  xyzzy.prev != NULL ? deref_next(mainh_event*,xyzzy.prev) = xyzzy.next : WORLD.evnt = xyzzy.next;
  xyzzy.next != NULL ? deref_prev(mainh_event*,xyzzy.next) = xyzzy.prev : WORLD.evnt_tail = xyzzy.prev;
  free(&xyzzy);
  }

//use of irrational constants is as a starting point, will fine-tune values later

struct bone* spine(root,prev,nmax,len,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  float len;
  rgbi_param color;
  {
  struct bone verta[10];
  for (unsigned char n = 0;n < nmax;n++)
    {
    verta[n] = (bone){root,prev,NULL,{0,0,n!=0 * FR_ONE},{0,0,len/nmax},matgen_ident,matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &verta[n];
    prev = &verta[n];
    }
  return &verta[nmax-1];
  }

struct bone* offspine(root,prev,nmax,len,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  float len;
  rgbi_param color;
  {
  struct bone verta[10];
  for (unsigned char n = 0;n < nmax;n++)
    {
    verta[n] = (bone){root,prev,NULL,{0,0,FR_ONE},{0,0,len/nmax},matgen_ident,matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &verta[n];
    prev = &verta[n];
    }
  return &verta[nmax-1];
  }
  
struct bone* xtail(root,prev,nmax,len,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  float len;
  rgbi_param color;
  {
  struct bone verta[10];
  for (unsigned char n = 0;n < nmax;n++)
    {
    verta[n] = (bone){root,prev,NULL,{-FR_ONE,0,0},{-len/nmax,0,0},matgen_ident,matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &verta[n];
    prev = &verta[n];
    }
  return &verta[nmax-1];
  }
  
struct bone* ztail(root,prev,nmax,len,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  float len;
  rgbi_param color;
  {
  struct bone verta[10];
  for (unsigned char n = 0;n < nmax;n++)
    {
    verta[n] = (bone){root,prev,NULL,{0,0,-FR_ONE},{-len/nmax,0,0},matgen_ident,matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &verta[n];
    prev = &verta[n];
    }
  return &verta[nmax-1];
  }

struct bone* handphalanges(root,prev,nmax,rot,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  vector3 rot;
  rgbi_param color;
  {
  float len = root->len.x;
  struct bone phalng[nmax];
  for (unsigned char n = 0;n < nmax;n++)
    {
    float len = len/G_RATIO;
    phalng[n] = (bone){root,prev,NULL,{FR_ONE,0,0},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &phalng[n];
    prev = &phalng[n];
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    }
  return &phalng[nmax-1];
  }

struct bone* finger(root,prev,nmax,rot,factor,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  vector3 rot;
  rgbi_param color;
  {
  struct bone *carple = malloc(sizeof(struct bone));
  *carple = (bone){root,prev,NULL,{FR_ONE,0,0},{(root->len.x / M_E) * factor,0,0},matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
  doublelink(carple);
  rot.x = NEG(rot.x);
  rot.y = NEG(rot.y);
  rot.z = NEG(rot.z);
  return handphalanges(carple,carple,nmax,rot,color);
  }

struct bone* thumbphalanges(root,prev,nmax,rot,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  struct vector3 rot;
  rgbi_param color;
  {
  float len = root->len.x / M_PI;
  struct bone phalng[nmax];
  for (unsigned char n = 0;n < nmax;n++)
    {
    phalng[n] = (bone){root,prev,NULL,{FR_ONE,0,0},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &phalng[n];
    prev = &phalng[n];
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    len = len/((n==0) + 1);
    }
  return &phalng[nmax-1];
  }

struct bone* footphalanges(root,prev,nmax,rot,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  struct vector3 rot;
  rgbi_param color;
  {
  float len = root->len.x / M_PI;
  struct bone phalng[nmax];
  for (unsigned char n = 0;n < nmax;n++);
    {
    phalng[n] = {root,prev,NULL,{0,0,FR_ONE},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &phalng[n];
    prev = &phalng[n];
    rot = {0,0,0};
    len = len/M_SQRT_2;
    }
  return &phalng[nmax-1];
  }

struct bone* toe(root,prev,nmax,rot,factor,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  struct vector3 rot;
  rgbi_param color;
  {
  struct bone *carple = malloc(sizeof(struct bone));
  *carple = {root,prev,NULL,{FR_ONE,0,0},{(root->len.z / M_PI) * factor,0,0},matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
  doublelink(carple);
  rot.x = NEG(rot.x);
  rot.y = NEG(rot.y);
  rot.z = NEG(rot.z);
  return footphalanges(carple,carple,nmax,rot,color);
  }

struct bone *talonphalanges(root,prev,nmax,rot,factor,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  struct vector3 rot;
  double factor;
  rgbi_param color;
  {
  float len = ((root->len.z * -1) / M_E) * factor;
  struct bone phalng[nmax];
  for (unsigned char n = 0;n < nmax;n++)
    {
    len = len/G_RATIO;
    phalng[n] = {root,prev,NULL,{n!=0 * FR_ONE,0,n==0 * FR_ONE},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &phalng[n];
    prev = &phalng[n];
    rot = {0,0,0};
    }
  return &phalng[nmax-1];
  }

struct bone *arm(root,prev,len,side,color)
  struct bone *prev;
  struct bone *root;
  float len;
  tern side;
  rgbi_param color;
  {
  struct bone limb[2];
    {
    prev->next = limb[0];
    limb[0] = {root,prev,limb[1],{FR_ONE,0,0},{len,0,0},matgen_ident,matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    len = len/G_RATIO;
    limb[1] = {root,limb[0],NULL,{FR_ONE,0,0},{len,0,0},matgen_x_deg(90,side),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    }
  return &limb[1];
  }

struct bone *leg(root,prev,len,Q,side,color)
  struct bone *prev;
  struct bone *root;
  float len;
  float Q;
  tern side;
  rgbi_param color;
  {
  struct bone limb[2];
    {
    prev->next = limb[0];
    limb[0] = {root,prev,limb[1],{0,side * FR_ONE/2,FR_ONE},{0,0,-1*len},matgen_x_deg(Q,side),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    len = len * LOG_3_E;
    Q = Q * -1;
    limb[1] = {root,limb[0],NULL,{0,0,FR_ONE},{0,0,-1*len},matgen_x_deg(Q,side),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    }
  return &limb[1];
  }

struct bone *digiti(root,prev,len,Q,side,color)
  struct bone *prev;
  struct bone *root;
  float len;
  struct vector2 Q;
  tern side;
  rgbi_param color;
  {
  struct bone limb[3];
    {
    len = len * -1;
    prev->next = limb[0];
    limb[0] = {root,prev,limb[1],{0,side * FR_ONE/2,FR_ONE},{0,0,len},matgen_master_deg(Q.x,Q.y,0,side,side,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    Q = {Q.x * -1,Q.y * 2 * -1};
    len = len * LOG_3_E;
    limb[1] = {root,limb[0],limb[2],{0,0,FR_ONE},{0,0,len},matgen_master_deg(Q.x,Q.y,0,side,side,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    Q = {0,Q.y * -1};
    len = len * LOG_3_E;
    limb[2] = {root,limb[1],NULL,{0,0,FR_ONE},{0,0,len},matgen_master_deg(Q.x,Q.y,0,side,side,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    }
  return &limb[2];
  }

struct bone *avewing(root,prev,len,side,color)
  struct bone *prev;
  struct bone *root;
  float len;
  tern side;
  rgbi_param color;
  {
  struct bone limb[3];
    {
    prev->next = limb[0];
    limb[0] = {root,prev,limb[1],{0,0,FR_ONE},{0,0,len},matgen_x_deg(135,side),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    limb[1] = {root,limb[0],limb[2],{0,0,FR_ONE},{0,0,len * S_RATIO},matgen_x_deg(108,side),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    limb[2] = {root,limb[1],NULL,{0,0,FR_ONE},{0,0,len},matgen_x_deg(-150,side),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    }
  return &limb[2];
  }
