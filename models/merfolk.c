bone *sculpt_merfolk() //mermay 2019, I guess?
  {
  polygon pelvis[1] = bone_half_octo(.173,.125)
  *center = (foo->root,NULL,NULL,(0,0,0),(0,.346,.125),matgen_ident,matgen_ident,FALSE,*pelvis,1)
  //(*up,*prev,*next,(off.x,off.y,off.z),(len.x,len.y,len.z),base,curr,drawline,*faces,n_polys)
  bone *cervical = spine(*center,*center,.66,16)
  bone *neck = spine(*cervical,*cervical,.125,7)
  polygon skull[8] = bone_octohedron(.1)
  bone *head = (*neck,*neck,NULL,(0,0,1),(0,.1,0),matgen_ident,matgen_ident,FALSE,*skull,8)
  doublelink(*head)
  bone *lshoulder = (*cervical,*head,NULL,(0,0,0),(.198,0,0),matgen_z_deg(-90),matgen_ident,TRUE,NULL,0)
  doublelink(*lshoulder)
  bone *lwrist = arm(*lshoulder,*lshoulder,.3,LEFT)
  bone *lthumb = thumbphalanges(*lwrist,*lwrist,3,(0,0,45))
  bone *lcarple3 = (*lwrist,*lthumb,NULL,(1,0,0),(lwrist->len.x / M_PI,0,0),matgen_ident,matgen_ident,TRUE,NULL,0)
  doublelink(*lcarple3)
  bone *lfinger3 = handphalanges(*lcarple3,*lcarple3,3,(0,0,0))
  bone *lcarple2 = (*lwrist,*lfinger3,NULL,(1,0,0),((lwrist->len.x / M_PI) * COS_PI_32,0,0),matgen_z_deg(11.25),matgen_ident,TRUE,NULL,0)
  doublelink(*lcarple2)
  bone *lfinger2 = handphalanges(*lcarple2,*lcarple2,3,(0,0,-11.25))
  bone *lcarple4 = (*lwrist,*lfinger2,NULL,(1,0,0),((lwrist->len.x / M_PI) * COS_PI_32,0,0),matgen_z_deg(-11.25),matgen_ident,TRUE,NULL,0)
  doublelink(*lcarple4)
  bone *lfinger4 = handphalanges(*lcarple4,*lcarple4,3,(0,0,11.25))
  bone *lcarple5 = (*lwrist,*lfinger4,NULL,(1,0,0),((lwrist->len.x / M_PI) * COS_PI_16,0,0),matgen_z_deg(-22.5),matgen_ident,TRUE,NULL,0)
  doublelink(*lcarple5)
  bone *lfinger5 = handphalanges(*lcarple5,*lcarple5,3,(0,0,22.5))
  bone *rshoulder = (*cervical,*lfinger5,NULL,(0,0,0),(.198,0,0),matgen_z_deg(90),matgen_ident,TRUE,NULL,0)
  doublelink(*rshoulder)
  bone *rwrist = arm(*rshoulder,*rshoulder,.3,RIGHT)
  bone *rthumb = thumbphalanges(*rwrist,*rwrist,3,(0,0,-45))
  bone *rcarple3 = (*rwrist,*rthumb,NULL,(1,0,0),(rwrist->len.x / M_PI,0,0),matgen_ident,matgen_ident,TRUE,NULL,0)
  doublelink(*rcarple3)
  bone *rfinger3 = handphalanges(*rcarple3,*rcarple3,3,(0,0,0))
  bone *rcarple2 = (*rwrist,*rfinger3,NULL,(1,0,0),((rwrist->len.x / M_PI) * COS_PI_32,0,0),matgen_z_deg(-11.25),matgen_ident,TRUE,NULL,0)
  doublelink(*rcarple2)
  bone *rfinger2 = handphalanges(*rcarple2,*rcarple2,3,(0,0,11.25))
  bone *rcarple4 = (*rwrist,*rfinger2,NULL,(1,0,0),((rwrist->len.x / M_PI) * COS_PI_32,0,0),matgen_z_deg(11.25),matgen_ident,TRUE,NULL,0)
  doublelink(*rcarple4)
  bone *rfinger4 = handphalanges(*rcarple4,*rcarple4,3,(0,0,-11.25))
  bone *rcarple5 = (*rwrist,*rfinger4,NULL,(1,0,0),((rwrist->len.x / M_PI) * COS_PI_16,0,0),matgen_z_deg(22.5),matgen_ident,TRUE,NULL,0)
  doublelink(*rcarple5)
  bone *rfinger5 = handphalanges(*rcarple5,*rcarple5,3,(0,0,-22.5))
  bone *tail = ztail(*rfinger5,*center,32,1.32)
  polygon triangle[1] = bone_inv_triangle(.5,.5)
  bone *tailfin = (*center,*tail,NULL,(1,0,0),(0,.5,-.5),matgen_y_deg(45),matgen_ident,FALSE,*triangle,1)
  doublelink(tail)
  return *center
}
