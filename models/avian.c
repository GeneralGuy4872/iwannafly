struct bone *sculpt_avian(geomet)
  mesurements geomet
  {
  struct bone *pelvis = malloc(sizeof(struct bone))
  *pelvis = {NULL,NULL,NULL,{FR_ZERO,FR_ZERO,FR_ZERO},{0,SUITFIT(geomet,hip)/2,SUITFIT(geomet,coxyx)},matgen_ident,matgen_ident,FALSE,malloc(sizeof(struct shape))}
  //{*up,*prev,*next,{off.x,off.y,off.z},{len.x,len.y,len.z},matrix base,matrix curr,bool drawline,shape *geom}
  struct shape *(pelvis->geom) = shape_poly_triangle(SUITFIT(geomet,coxyx),SUITFIT(geomet,hip)/2)
  struct bone *index_spine = spine(pelvis,pelvis,SUITFIT(geomet,back),16)
  struct bone *neck = spine(index_spine,index_spine,SUITFIT(geomet,neck),7)
  struct bone *skull = malloc(sizeof(struct bone))
  *skull = {neck,neck,NULL,{FR_ZERO,FR_ZERO,FR_ZERO},{SUITFIT(geomet,skull),0,0},matgen_ident,matgen_ident,FALSE,malloc(sizeof(struct shape))}
  struct shape *(skull->geom) = shape_poly_octo(SUITFIT(geomet,skull))
  doublelink(skull)
  struct bone *lshoulder = malloc(sizeof(struct bone))
  *lshoulder = {index_spine,skull,NULL,{FR_ZERO,FR_ZERO,FR_ZERO},{SUITFIT(geomet,shld),0,0},matgen_z_deg(-90),matgen_ident,TRUE,NULL}
  doublelink(lshoulder)
  struct bone *larm = arm(lshoulder,lshoulder,SUITFIT(geomet,humr),LEFT)
  struct bone *lthumb = thumbphalanges(larm,larm,3,{0,0,45})
  struct bone *lcarple3 = malloc(sizeof(struct bone))
  *lcarple3 = {larm,lthumb,NULL,{FR_ONE,FR_ZERO,FR_ZERO},{larm->len.x / M_PI,0,0},matgen_ident,matgen_ident,TRUE,NULL}
  doublelink(lcarple3)
  struct bone *lfinger3 = handphalanges(lcarple3,lcarple3,3,{0,0,0})
  struct bone *lcarple2 = malloc(sizeof(struct bone))
  *lcarple2 = {larm,lfinger3,NULL,{FR_ONE,FR_ZERO,FR_ZERO},{(larm->len.x / M_PI) * COS_PI_32,0,0},matgen_z_deg(11.25),matgen_ident,TRUE,NULL}
  doublelink(lcarple2)
  struct bone *lfinger2 = handphalanges(lcarple2,lcarple2,3,{0,0,0})
  struct bone *lcarple4 = malloc(sizeof(struct bone))
  *lcarple4 = {larm,lfinger2,NULL,{FR_ONE,FR_ZERO,FR_ZERO},{(larm->len.x / M_PI) * COS_PI_32,0,0},matgen_z_deg(-11.25),matgen_ident,TRUE,NULL}
  doublelink(lcarple4)
  struct bone *lfinger4 = handphalanges(lcarple4,lcarple4,3,{0,0,0})
  struct bone *rshoulder = malloc(sizeof(struct bone))
  *rshoulder = {index_spine,lfinger,NULL,{FR_ZERO,FR_ZERO,FR_ZERO},{SUITFIT(geomet,shld),0,0},matgen_z_deg(90),matgen_ident,TRUE,NULL}
  doublelink(rshoulder)
  struct bone *rarm = arm(rshoulder,rshoulder,SUITFIT(geomet,humr),RIGHT)
  struct bone *rthumb = thumbphalanges(rarm,rarm,3,{0,0,45})
  struct bone *rcarple3 = malloc(sizeof(struct bone))
  *rcarple3 = {rarm,rthumb,NULL,{FR_ONE,FR_ZERO,FR_ZERO},{rarm->len.x / M_PI,0,0},matgen_ident,matgen_ident,TRUE,NULL}
  doublelink(rcarple3)
  struct bone *rfinger3 = handphalanges(rcarple3,rcarple3,3,{0,0,0})
  struct bone *rcarple2 = malloc(sizeof(struct bone))
  *rcarple2 = {rarm,rfinger3,NULL,{FR_ONE,FR_ZERO,FR_ZERO},{(rarm->len.x / M_PI) * COS_PI_32,0,0},matgen_z_deg(-11.25),matgen_ident,TRUE,NULL}
  doublelink(rcarple2)
  struct bone *rfinger2 = handphalanges(rcarple2,rcarple2,3,{0,0,0})
  struct bone *rcarple4 = malloc(sizeof(struct bone))
  *rcarple4 = {rarm,rfinger2,NULL,{FR_ONE,FR_ZERO,FR_ZERO},{(rarm->len.x / M_PI) * COS_PI_32,0,0},matgen_z_deg(11.25),matgen_ident,TRUE,NULL}
  doublelink(rcarple4)
  struct bone *rfinger4 = handphalanges(rcarple4,rcarple4,3,{0,0,0})
  struct bone *lleg = digiti(pelvis,rfinger4,SUITFIT(geomet,femr),( NEG(SUITFIT(geomet,q_angle)),15),LEFT)
  struct bone *ltoe2 = talonphalanges(lleg,lleg,3,{0,0,30},COS_PI_16)
  struct bone *ltoe3 = talonphalanges(lleg,ltoe2,3,{0,0,0},1)
  struct bone *ltoe4 = talonphalanges(lleg,ltoe3,3,{0,0,-30},COS_PI_8)
  struct bone *ltoe1 = talonphalanges(lleg,ltoe4,2,{0,0,180},M_SQRT1_2)
  struct bone *lleg = digiti(pelvis,rfinger4,SUITFIT(geomet,femr),(SUITFIT(geomet,q_angle),15),LEFT)
  struct bone *ltoe2 = talonphalanges(lleg,lleg,3,{0,0,-30},COS_PI_16)
  struct bone *ltoe3 = talonphalanges(lleg,ltoe2,3,{0,0,0},1)
  struct bone *ltoe4 = talonphalanges(lleg,ltoe3,3,{0,0,30},COS_PI_8)
  struct bone *ltoe1 = talonphalanges(lleg,ltoe4,2,{0,0,180},M_SQRT1_2)
  struct bone *lwing = avewing(index_spine->prev->prev->prev->prev->prev,rwing,SUITFIT(geom,wing),LEFT)
  struct bone *rwing = avewing(index_spine->prev->prev->prev->prev->prev,lwing,SUITFIT(geom,wing),RIGHT)
  //spine() returns vert[nmax-1], so wing.up = vert[nmax-6]
  //vert is the internal abbriviation for vertabra
  //nmax is the length of the array (meaning nmax-1 is the last element)
  struct bone *index_tail = malloc(sizeof(struct bone))
  *index_tail = {pelvis,rwing,NULL,{FR_ZERO,FR_ZERO,FR_ZERO},{SUITFIT(geomet,tail),SUITFIT(geomet,fan_out),0},matgen_ident,matgen_ident,FALSE,malloc(sizeof(struct shape))}
  struct shape *(tail->geom) = shape_poly_xfan(SUITFIT(geomet,tail),SUITFIT(geomet,fan_out)/2,4)
  doublelink(tail)
  return pelvis
  }
