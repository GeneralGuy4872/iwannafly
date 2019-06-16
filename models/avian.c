struct bone *sculpt_avian(geomet)
  mesurements geomet
  {
  //{*up,*prev,*next,{off.x,off.y,off.z},{len.x,len.y,len.z},matrix base,matrix curr,bool drawline,shape *geom}
    struct bone *pelvis = malloc(sizeof(struct bone))
    *pelvis = {NULL,NULL,NULL,{FR_ZERO,FR_ZERO,FR_ZERO},{0,mfrfl(geomet[11])/2,mfrfl(geomet[10])},matgen_ident,matgen_ident,FALSE,malloc(sizeof(struct shape))}
    *(pelvis->geom) = shape_poly_triangle(mfrfl(geomet[10]),mfrfl(geomet[11])/2)
  struct bone *index_spine = spine(pelvis,pelvis,mfrfl(geomet[7]),16)
  struct bone *neck = spine(index_spine,index_spine,mfrfl(geomet[5]),7)
    struct bone *skull = malloc(sizeof(struct bone))
    *skull = {neck,neck,NULL,{FR_ZERO,FR_ZERO,FR_ZERO},{mfrfl(geomet[4]),0,0},matgen_ident,matgen_ident,FALSE,malloc(sizeof(struct shape))}
    *(skull->geom) = shape_poly_octo(mfrfl(geomet[4]))
    doublelink(skull)
    struct bone *lshoulder = malloc(sizeof(struct bone))
    *lshoulder = {index_spine,skull,NULL,{FR_ZERO,FR_ZERO,FR_ZERO},{mfrfl(geomet[6]),0,0},matgen_z_deg(xLEFT(90)),matgen_ident,TRUE,NULL}
    doublelink(lshoulder)
  struct bone *larm = arm(lshoulder,lshoulder,mfrfl(geomet[8]),LEFT)
  struct bone *lthumb = thumbphalanges(larm,larm,3,{0,0,xLEFT(-45)})
  struct bone *lfinger3 = finger(larm,lthumb,3,{0,0,0},1)
  struct bone *lfinger2 = finger(larm,lfinger3,3,{0,0,xLEFT(-11.25)},COS_PI_32)
  struct bone *lfinger4 = finger(larm,lfinger2,3,{0,0,xLEFT(11.25)},COS_PI_32)
    struct bone *rshoulder = malloc(sizeof(struct bone))
    *rshoulder = {index_spine,lfinger4,NULL,{FR_ZERO,FR_ZERO,FR_ZERO},{mfrfl(geomet[6]),0,0},matgen_z_deg(xRIGHT(90)),matgen_ident,TRUE,NULL}
    doublelink(rshoulder)
  struct bone *rarm = arm(rshoulder,rshoulder,mfrfl(geomet[8]),RIGHT)
  struct bone *rthumb = thumbphalanges(rarm,rarm,3,{0,0,xRIGHT(-45)})
  struct bone *rfinger3 = finger(rarm,rthumb,3,{0,0,0},1)
  struct bone *rfinger2 = finger(rarm,rfinger3,3,{0,0,xRIGHT(-11.25)},COS_PI_32)
  struct bone *rfinger4 = finger(rarm,rfinger2,3,{0,0,xRIGHT(11.25)},COS_PI_32)
  struct bone *lleg = digiti(pelvis,rfinger4,mfrfl(geomet[9]),{xLEFT(mfrfl(geomet[14])),mfrfl(geomet[15])},LEFT)
  struct bone *ltoe2 = talonphalanges(lleg,lleg,3,{0,0,xLEFT(-30)},COS_PI_16)
  struct bone *ltoe3 = talonphalanges(lleg,ltoe2,3,{0,0,0},1)
  struct bone *ltoe4 = talonphalanges(lleg,ltoe3,3,{0,0,xLEFT(30)},COS_PI_8)
  struct bone *ltoe1 = talonphalanges(lleg,ltoe4,2,{0,0,180},M_SQRT1_2)
  struct bone *rleg = digiti(pelvis,ltoe1,mfrfl(geomet[9]),{xRIGHT(mfrfl(geomet[14])),mfrfl(geomet[15])},RIGHT)
  struct bone *rtoe2 = talonphalanges(rleg,rleg,3,{0,0,xRIGHT(-30)},COS_PI_16)
  struct bone *rtoe3 = talonphalanges(rleg,rtoe2,3,{0,0,0},1)
  struct bone *rtoe4 = talonphalanges(rleg,rtoe3,3,{0,0,xRIGHT(30)},COS_PI_8)
  struct bone *rtoe1 = talonphalanges(rleg,rtoe4,2,{0,0,180},M_SQRT1_2)
  struct bone *lwing = avewing(index_spine->prev->prev->prev->prev->prev,rwing,mfrfl(geomet[13]),LEFT)
  struct bone *rwing = avewing(index_spine->prev->prev->prev->prev->prev,lwing,mfrfl(geomet[13]),RIGHT)
  //spine() returns vert[nmax-1], so wing.up = vert[nmax-6]
  //vert is the internal abbriviation for vertabra
  //nmax is the length of the array (meaning nmax-1 is the last element)
    struct bone *index_tail = malloc(sizeof(struct bone))
    *index_tail = {pelvis,rwing,NULL,{FR_ZERO,FR_ZERO,FR_ZERO},{mfrfl(geomet[17]),mfrfl(geomet[16]),0},matgen_ident,matgen_ident,FALSE,malloc(sizeof(struct shape))}
    *(tail->geom) = shape_poly_xfan(mflfr(geomet[17]),mflfr(geomet[16])/2,mflfr(geomet[18]))
    doublelink(tail)
  return pelvis
  }
