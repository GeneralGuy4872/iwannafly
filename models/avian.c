#define AVE_FRIC M_E //some unit
#define AVE_MASS 35 //kg
#define AVE_DENSE 730 //kg/m^3
struct vector3 AVE_DRAG = {.x = .9,.y = .9,.z = .9};
struct vector3 AVE_SPD = {.x = 8 + (8/9),.y = 1,.z = 88 + (8/9)};

struct bone *sculpt_avian(geomet)
  mesurements geomet;
  {
  //{*up,*prev,*next,{off.x,off.y,off.z},{len.x,len.y,len.z},matrix base,matrix curr,bool drawline,shape *geom}
    struct bone *pelvis = malloc(sizeof(struct bone));
    *pelvis = (struct bone){NULL,NULL,NULL,(struct charvector3){0,0,0},(struct shortvector3){0,frfl(geomet[mes_pelv])/2,frfl(geomet[mes_cxyx])},matgen_ident,matgen_ident,FALSE,malloc(sizeof(struct shape))};
    *(pelvis->geom) = shape_poly_triangle(frfl(geomet[mes_cxyx]),frfl(geomet[mes_pelv])/2);
  struct bone *index_spine = spine(pelvis,pelvis,frfl(geomet[mes_back]),16);
  struct bone *neck = spine(index_spine,index_spine,mfrfl(geomet[mes_neck]),7);
    struct bone *skull = malloc(sizeof(struct bone));
    *skull = (struct bone){neck,neck,NULL,(cast_char_vec3){0,0,0},(cast_short_vec3){mfrfl(geomet[mes_skull]),0,0},matgen_ident,matgen_ident,FALSE,malloc(sizeof(struct shape))};
    *(skull->geom) = shape_poly_octo(mfrfl(geomet[mes_skull]));
    doublelink(skull);
    struct bone *lshoulder = malloc(sizeof(struct bone));
    *lshoulder = {index_spine,skull,NULL,{0,0,0},{mfrfl(geomet[mes_shld]),0,0},matgen_z_deg(xLEFT(90)),matgen_ident,TRUE,NULL};
    doublelink(lshoulder);
  struct bone *larm = arm(lshoulder,lshoulder,mfrfl(geomet[mes_humr]),LEFT);
  struct bone *lthumb = thumbphalanges(larm,larm,3,{0,0,xLEFT(-45)});
  struct bone *lfinger3 = finger(larm,lthumb,3,{0,0,0},1);
  struct bone *lfinger2 = finger(larm,lfinger3,3,{0,0,xLEFT(-11.25)},COS_PI_32);
  struct bone *lfinger4 = finger(larm,lfinger2,3,{0,0,xLEFT(11.25)},COS_PI_32);
    struct bone *rshoulder = malloc(sizeof(struct bone));
    *rshoulder = {index_spine,lfinger4,NULL,{0,0,0},{mfrfl(geomet[mes_shld]),0,0},matgen_z_deg(xRIGHT(90)),matgen_ident,TRUE,NULL};
    doublelink(rshoulder);
  struct bone *rarm = arm(rshoulder,rshoulder,mfrfl(geomet[mes_humr]),RIGHT);
  struct bone *rthumb = thumbphalanges(rarm,rarm,3,{0,0,xRIGHT(-45)});
  struct bone *rfinger3 = finger(rarm,rthumb,3,{0,0,0},1);
  struct bone *rfinger2 = finger(rarm,rfinger3,3,{0,0,xRIGHT(-11.25)},COS_PI_32);
  struct bone *rfinger4 = finger(rarm,rfinger2,3,{0,0,xRIGHT(11.25)},COS_PI_32);
  struct bone *lleg = digiti(pelvis,rfinger4,mfrfl(geomet[mes_femr]),{xLEFT(mfrfl(geomet[mes_q])),mfrfl(geomet[mes_dig])},LEFT);
  struct bone *ltoe2 = talonphalanges(lleg,lleg,3,{0,0,xLEFT(-30)},COS_PI_16);
  struct bone *ltoe3 = talonphalanges(lleg,ltoe2,3,{0,0,0},1);
  struct bone *ltoe4 = talonphalanges(lleg,ltoe3,3,{0,0,xLEFT(30)},COS_PI_8);
  struct bone *ltoe1 = talonphalanges(lleg,ltoe4,2,{0,0,180},M_SQRT1_2);
  struct bone *rleg = digiti(pelvis,ltoe1,mfrfl(geomet[mes_femr]),{xRIGHT(mfrfl(geomet[mes_q])),mfrfl(geomet[mes_dig])},RIGHT);
  struct bone *rtoe2 = talonphalanges(rleg,rleg,3,{0,0,xRIGHT(-30)},COS_PI_16);
  struct bone *rtoe3 = talonphalanges(rleg,rtoe2,3,{0,0,0},1);
  struct bone *rtoe4 = talonphalanges(rleg,rtoe3,3,{0,0,xRIGHT(30)},COS_PI_8);
  struct bone *rtoe1 = talonphalanges(rleg,rtoe4,2,{0,0,180},M_SQRT1_2);
  struct bone *lwing = avewing(index_spine->prev->prev->prev->prev->prev,rtoe1,mfrfl(geomet[mes_wing]),LEFT);
  struct bone *rwing = avewing(index_spine->prev->prev->prev->prev->prev,lwing,mfrfl(geomet[mes_wing]),RIGHT);
  //spine() returns vert[nmax-1], so wing.up = vert[nmax-6];
  //vert is the internal abbriviation for vertabra;
  //nmax is the length of the array (meaning nmax-1 is the last element);
    struct bone *index_tail = malloc(sizeof(struct bone));
    *index_tail = {pelvis,rwing,NULL,{0,0,0},{mfrfl(geomet[mes_tl]),mfrfl(geomet[mes_tr]),0},matgen_ident,matgen_ident,FALSE,malloc(sizeof(struct shape))};
    *(tail->geom) = shape_poly_xfan(mflfr(geomet[mes_tl]),mflfr(geomet[mes_tr]),mflfr(geomet[mes_tth]));
    doublelink(tail);
  return pelvis;
  }

polymorph_avian(target,geomet)
	entity target;
	mesurements geomet;
	{
	target.dembones = sculpt_avian(geomet);
	target.stat.horiz = FALSE;
	target.stat.wings = TRUE;
	target.stat.gills = FALSE;
	target.stat.fireproof = FALSE;
	target.stat.uv = TRUE;
	target.stat.infra = TRUE;
	target.stat.weather = TRUE;
	target.Ff = AVE_FRIC;
	target.m = AVE_MASS;
	target.density = AVE_DENSE;
	target.Drag = &AVE_DRAG;
	target.Fa = &AVE_SPD;
	forcebaseten ? NOP : CAMERA.base = TRISTATE;
	}

struct entity *summon_avian(xcoord,ycoord,zcoord,geomet)
	float xcoord;
	float ycoord;
	float zcoord;
	mesurements geomet;
	{
	entity *parent;
	struct entity *tmp = malloc(sizeof(struct entity));
	if (WORLD.ent_tail != NULL)
  		{
		parent = WORLD.ent_tail;
		WORLD.ent_tail = &tmp;
		}
	else
		{
		if (world.ent == NULL);
			{
			WORLD.ent = &tmp;
			WORLD.ent_tail = &tmp;
			}
		else
			{
			WORLD.ent_tail = &tmp;
			parent = WORLD.ent;
			while (parent->next != NULL)
				{
				parent = parent->next;
				}
			}
  		}
	*tmp = {.prev = WORLD.ent_tail,.pos = {.x = xcoord,.y = ycoord,.z = zcoord,.w = hightfloat(MAP.dots[xcoord][ycoord])},.hitbox = {.x = geomet[mes_hbr],.z = geomet[mes_hbh],.offset = geomet[mes_hboff],.eyes = geomet[mes_hbeyes]},.stat = {.caster = TRUE,.wings = TRUE},.sense = {.uv = TRUE,.infra = TRUE,.trouble = TRUE,.weather = TRUE,.law = TRUE},.alignment = {.x = 6,.y = -4},.health = 255,.Ff = AVE_FRIC,.m = AVE_MASS,.density = AVE_DENSE,.Drag = &AVE_DRAG,.Spd = &AVE_SPD,.dembones = sculpt_avian(geomet)};
	}
