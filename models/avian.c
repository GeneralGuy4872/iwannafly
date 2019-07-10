#define AVE_FRIC M_E
#define AVE_MASS 35
#define AVE_DENSE 50
struct vector3 AVE_DRAG = {.9,.9,.9};
struct vector3 AVE_SPD = {8 + (8/9),1,88 + (8/9)};

struct skeleton *sculpt_avian(geomet,fg,bg)
  mesurements geomet;
  minicolor fg;
  minicolor bg;
  {
  skeleton *tmp = malloc(sizeof(struct skeleton));
  //{*up,*prev,*next,(char){off.x,off.y,off.z},{len.x,len.y,len.z},matrix base,matrix curr,truecolor color,bool ultraviolet,bool drawline,shape *geom}
    struct bone *pelvis = malloc(sizeof(struct bone));
    *pelvis = (bone){NULL,NULL,NULL,{0,0,0},{0,frfl(geomet[mes_pelv]),frfl(geomet[mes_cxyx])},matgen_ident,matgen_ident,color6(bg.r,bg.g,bg.b,bg.a),FALSE,FALSE,malloc(sizeof(struct shape))};
    *(pelvis->geom) = frfl_shape_poly_triangle(geomet[mes_cxyx],geomet[mes_pelv]);
  struct bone *index_spine = spine(pelvis,pelvis,geomet[mes_back],16,bg,FALSE);
  struct bone *neck = spine(index_spine,index_spine,geomet[mes_neck],7,bg.r,bg,FALSE);
    struct bone *skull = malloc(sizeof(struct bone));
    *skull = (bone){neck,neck,NULL,{0,0,0},{frfl(geomet[mes_skull]),0,0},matgen_ident,matgen_ident,color6(fg.r,fg.g,fg.b,fg.a),TRUE,FALSE,malloc(sizeof(struct shape))};
    *(skull->geom) = frfl_shape_poly_octo(geomet[mes_skull]);
    doublelink(skull);
    struct bone *lshoulder = malloc(sizeof(struct bone));
    *lshoulder = (bone){index_spine,skull,NULL,{0,0,0},{frfl(geomet[mes_shld]),0,0},matgen_z_deg(xLEFT(90),1),matgen_ident,color6(fg.r,fg.g,fg.b,fg.a),TRUE,TRUE,NULL};
    doublelink(lshoulder);
  struct bone *larm = arm(lshoulder,lshoulder,geomet[mes_humr],LEFT,fg,FALSE);
  struct bone *lthumb = thumbphalanges(larm,larm,3,(vector3){0,0,xLEFT(-45)},bg,FALSE);
  struct bone *lfinger3 = finger(larm,lthumb,3,(vector3){0,0,0},1,bg,FALSE);
  struct bone *lfinger2 = finger(larm,lfinger3,3,(vector3){0,0,xLEFT(-11.25)},COS_PI_32,bg,FALSE);
  struct bone *lfinger4 = finger(larm,lfinger2,3,(vector3){0,0,xLEFT(11.25)},COS_PI_32,bg,FALSE);
    struct bone *rshoulder = malloc(sizeof(struct bone));
    *rshoulder = (bone){index_spine,lfinger4,NULL,{0,0,0},{frfl(geomet[mes_shld]),0,0},matgen_z_deg(xRIGHT(90),1),matgen_ident,color6(fg.r,fg.g,fg.b,fg.a),TRUE,TRUE,NULL};
    doublelink(rshoulder);
  struct bone *rarm = arm(rshoulder,rshoulder,geomet[mes_humr],RIGHT,fg,FALSE);
  struct bone *rthumb = thumbphalanges(rarm,rarm,3,(vector3){0,0,xRIGHT(-45)},bg,FALSE);
  struct bone *rfinger3 = finger(rarm,rthumb,3,(vector3){0,0,0},1,bg,FALSE);
  struct bone *rfinger2 = finger(rarm,rfinger3,3,(vector3){0,0,xRIGHT(-11.25)},COS_PI_32,bg,FALSE);
  struct bone *rfinger4 = finger(rarm,rfinger2,3,(vector3){0,0,xRIGHT(11.25)},COS_PI_32,bg,FALSE);
  struct bone *lleg = digiti(pelvis,rfinger4,geomet[mes_femr],(shortvector2){xLEFT(geomet[mes_q]),geomet[mes_dig]},LEFT,fg,FALSE);
  struct bone *ltoe2 = talonphalanges(lleg,lleg,3,(vector3){0,0,xLEFT(-30)},COS_PI_16,bg,FALSE);
  struct bone *ltoe3 = talonphalanges(lleg,ltoe2,3,(vector3){0,0,0},1,bg,FALSE);
  struct bone *ltoe4 = talonphalanges(lleg,ltoe3,3,(vector3){0,0,xLEFT(30)},COS_PI_8,bg,FALSE);
  struct bone *ltoe1 = talonphalanges(lleg,ltoe4,2,(vector3){0,0,180},M_SQRT1_2,bg,FALSE);
  struct bone *rleg = digiti(pelvis,ltoe1,geomet[mes_femr],(shortvector2){xRIGHT(geomet[mes_q]),geomet[mes_dig]},RIGHT,fg,FALSE);
  struct bone *rtoe2 = talonphalanges(rleg,rleg,3,(vector3){0,0,xRIGHT(-30)},COS_PI_16,bg,FALSE);
  struct bone *rtoe3 = talonphalanges(rleg,rtoe2,3,(vector3){0,0,0},1,bg,FALSE);
  struct bone *rtoe4 = talonphalanges(rleg,rtoe3,3,(vector3){0,0,xRIGHT(30)},COS_PI_8,bg,FALSE);
  struct bone *rtoe1 = talonphalanges(rleg,rtoe4,2,(vector3){0,0,180},M_SQRT1_2,bg,FALSE);
  struct bone *lwing = avewing(((bone*)index_spine->prev)->prev,rtoe1,geomet[mes_wing],LEFT,fg,TRUE);
  struct bone *rwing = avewing(((bone*)index_spine->prev)->prev,lwing,geomet[mes_wing],RIGHT,fg,TRUE);
    struct bone *index_tail = malloc(sizeof(struct bone));
    *index_tail = (bone){pelvis,rwing,NULL,{0,0,0},{frfl(geomet[mes_fan_len]),frfl(geomet[mes_fan_rad]),0},matgen_ident,matgen_ident,color6(fg.r,fg.g,fg.b,fg.a),TRUE,FALSE,malloc(sizeof(struct shape))};
    *(index_tail->geom) = frfl_shape_poly_xfan(geomet[mes_fan_len],geomet[mes_fan_rad],geomet[mes_fan_ang]);
    doublelink(index_tail);
  tmp->root = pelvis;
  tmp->hitbox.x = MAX(frfl(geomet[mes_shld]),frfl(geomet[mes_pelv])) * 2;
  tmp->off.x = cosine_digiti(geomet[mes_femr],(shortvector2){geomet[mes_q],geomet[mes_dig]}) + frfl(geomet[mes_cxyx]);
  tmp->off.y = frfl(geomet[mes_skull]);
  tmp->hitbox.z = tmp->off.x + frfl(geomet[mes_back]) + frfl(geomet[mes_neck]) + frfl(geomet[mes_skull]) + tmp->off.y;
  tmp->fg = fg;
  tmp->bg = bg;
  return tmp;
  }

polymorph_avian(target,geomet)
	entity target;
	mesurements geomet;
	{
	target.dembones = sculpt_avian(geomet,target.dembones->fg,target.dembones->bg);
	target.stat.horiz = FALSE;
	target.stat.wings = TRUE;
	target.stat.gills = FALSE;
	target.stat.fireproof = FALSE;
	target.detects.uv = TRUE;
	target.detects.infra = TRUE;
	target.detects.weather = TRUE;
	target.Ff = AVE_FRIC;
	target.m = AVE_MASS;
	target.density = AVE_DENSE;
	target.Drag = &AVE_DRAG;
	target.Fa = &AVE_SPD;
	}

entity* summon_avian(xcoord,ycoord,zcoord,geomet,fg,bg)
	float xcoord;
	float ycoord;
	float zcoord;
	mesurements geomet;
	minicolor fg;
	minicolor bg;
	{
	entity *tmp = malloc(sizeof(bone));
	*tmp = (entity){NULL,NULL,{xcoord,ycoord,zcoord,groundmake(xcoord,ycoord)},{0,0,0},{0,0,0},{0,0,0},{FALSE,FALSE,FALSE,TRUE,TRUE,FALSE,FALSE,FALSE},{TRUE,TRUE,TRUE,TRUE,FALSE,FALSE,TRUE,FALSE},{6,-4},255,AVE_FRIC,AVE_MASS,AVE_DENSE,&AVE_DRAG,&AVE_SPD,sculpt_avian(geomet,fg,bg),{NULL,NULL,NULL,NULL}};
	ent_add(tmp);
	return tmp;
	}
