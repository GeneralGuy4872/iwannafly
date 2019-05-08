skeleton *sculpt_human()
  {
  skeleton foo = (malloc(sizeof(bone)),!!!!!COMEBACKHERE!!!!!,((1,1,1),(0,0,0)))
  *pelvis = foo->root
    {
    polygon pelvis[1] = bone_inv_triangle(2,.5)
    foo->root = (NULL,*pointy,NULL,(0,2,.5),(0,0,0),matgen_identity,matgen_identity,FALSE,*pelvis,1)
    //(*up,*prev,*next,(len.x,len.y,len.z),(trans.x,trans.y,trans.z),base,curr,drawline,*faces,n_polys)
    }
    {
    bone *cervical = spine(foo->root,*pointy,.2,10)
      {
      bone *lshoulder = (*cervical,*cervical,NULL,(1,0,0),(0,0,0),matgen_z_deg(90,-1,1,-1),matgen_translate(1,0,0),TRUE,NULL,0)
      bone *lwrist = arm(*lshoulder,*lshoulder,2)
        {
        bone *thumb = handphalanges(*lwrist,*lwrist,3,(-90,0,-90))
        bone *carple3 = (*lwrist,*thumb,NULL,(lwrist->len.x * M_PI,0,0),(0,0,0),matgen_z_deg(11.25,1,1,1),TRUE,NULL,0)
        bone *finger3 = handphalanges(*carple3,*carple3,3,(0,0,-11.25)
        bone *carple2 = (*lwrist,*finger3,NULL,(lwrist->len.x * M_PI * ,0,0),(0,0,0),matgen_z_deg(11.25,1,1,1),TRUE,NULL,0)
        bone *finger2 = handphalanges(*carple2,*carple2,3,(0,0,-11.25)
