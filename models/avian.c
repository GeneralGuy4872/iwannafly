struct bone *sculpt_avian(geomet)
  mesurements geomet
  {
  //{*up,*prev,*next,{off.x,off.y,off.z},{len.x,len.y,len.z},matrix base,matrix curr,bool drawline,shape *geom}
  struct bone *pelvis = malloc(sizeof(struct bone))
  *pelvis = {NULL,NULL,NULL,{FR_ZERO,FR_ZERO,FR_ZERO},{0,SUITFIT(geomet,hip)/2,SUITFIT(geomet,coxyx)},matgen_ident,matgen_ident,FALSE,malloc(sizeof(struct shape))}
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
  struct bone *lfinger3 = finger(larm,lthumb,3,{0,0,0},1)
  struct bone *lfinger2 = finger(larm,lfinger3,3,{0,0,11.25},COS_PI_32)
  struct bone *lfinger4 = finger(larm,lfinger2,3,{0,0,-11.25},COS_PI_32)
  
  struct bone *rshoulder = malloc(sizeof(struct bone))
  *rshoulder = {index_spine,lfinger4,NULL,{FR_ZERO,FR_ZERO,FR_ZERO},{SUITFIT(geomet,shld),0,0},matgen_z_deg(90),matgen_ident,TRUE,NULL}
  doublelink(rshoulder)

  struct bone *rarm = arm(rshoulder,rshoulder,SUITFIT(geomet,humr),RIGHT)
  struct bone *rthumb = thumbphalanges(rarm,rarm,3,{0,0,45})
  struct bone *rfinger3 = finger(rarm,rthumb,3,{0,0,0},1)
  struct bone *rfinger2 = finger(rarm,rfinger3,3,{0,0,11.25},COS_PI_32)
  struct bone *rfinger4 = finger(rarm,rfinger2,3,{0,0,-11.25},COS_PI_32)
  struct bone *lleg = digiti(pelvis,rfinger4,SUITFIT(geomet,femr),( NEG(SUITFIT(geomet,q_angle)),15),LEFT)
  struct bone *ltoe2 = talonphalanges(lleg,lleg,3,{0,0,30},COS_PI_16)
  struct bone *ltoe3 = talonphalanges(lleg,ltoe2,3,{0,0,0},1)
  struct bone *ltoe4 = talonphalanges(lleg,ltoe3,3,{0,0,-30},COS_PI_8)
  struct bone *ltoe1 = talonphalanges(lleg,ltoe4,2,{0,0,180},M_SQRT1_2)
  struct bone *rleg = digiti(pelvis,ltoe1,SUITFIT(geomet,femr),(SUITFIT(geomet,q_angle),15),LEFT)
  struct bone *rtoe2 = talonphalanges(rleg,rleg,3,{0,0,-30},COS_PI_16)
  struct bone *rtoe3 = talonphalanges(rleg,rtoe2,3,{0,0,0},1)
  struct bone *rtoe4 = talonphalanges(rleg,rtoe3,3,{0,0,30},COS_PI_8)
  struct bone *rtoe1 = talonphalanges(rleg,rtoe4,2,{0,0,180},M_SQRT1_2)
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
