#include "./bonegroups.h"
#include "./avian.c"
#include "./human.c"
#include "./merfolk.c"
#include "./feline.c"
#include "./draconic.c"
/*

*skeleton sculpt_foo() provided in each included file

polymorph_foo(entity *bar) changes an existing entity to the default values of foo, keeping velocity, rotation, and position

*entity summon_foo() creates a new entity of the species foo and appends it to the list of entitys

*/

polymorph_avian(target)
  entity target
  {
  target.dembones = sculpt_avian()
  target.hitbox = {AVE_RADIUS,AVE_HEIGHT,AVE_OFFSET}
  target.stat.horiz = FALSE
  target.stat.uv = TRUE
  target.stat.infra = FALSE
  target.Ff = {AVE_FRIC,AVE_DRAG_W,AVE_DRAG_Z}
  target.Spd = {AVE_SPD_X,AVE_SPD_M,AVE_SPD_Z,AVE_SPD_W}
  forcebaseten ? NOP : CAMERA.base = TRISTATE
  }

*entity summon_avian(xcoord,ycoord,zcoord)
  float xcoord
  float ycoord
  float zcoord
  {
  struct entity tmp =
	  {
	  WORLD.ent_tail,
	  NULL,
	  {xcoord,ycoord,zcoord},
	  {AVE_RADIUS,AVE_HEIGHT,AVE_OFFSET},
	  {0,0,0},
	  {0,0,0},
	  matgen_ident,
	  '\0',
	  '\0',
	  255,
	  {AVE_FRIC,AVE_DRAG_W,AVE_DRAG_Z}
	  {AVE_SPD_X,AVE_SPD_M,AVE_SPD_Z,AVE_SPD_W}
	  sculpt_avian()
    }
  WORLD.ent_tail = &tmp
  }
