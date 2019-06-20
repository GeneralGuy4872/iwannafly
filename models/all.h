#include "./bonegroups.h"
#include "./avian.c"
#include "./human.c"
#include "./merfolk.c"
#include "./feline.c"
#include "./draconic.c"

/* *skeleton sculpt_foo(mesurements geomet) provided in each included file creates the model for an entity
 * (int) polymorph_foo(entity *bar,mesurements geomet) changes an existing entity to the default values of foo, keeping velocity, rotation, and position
 * (int) summon_foo(float xcoord,float ycoord,float zcoord,mesurements geomet) creates a new entity of the species foo and appends it to the list of entitys
 *
 * macros are for converting joystick inputs into speed and friction factors.
 * these are currently chosen arbitrarily, but will eventually be based on classical physics
 * (once I have a better understanding of the relevent equasions and coefficiants)
 * so that they are consistant.
 */

polymorph_avian(target,geomet)
	entity target
	mesurements geomet
	{
	target.dembones = sculpt_avian(geomet)
	target.stat.horiz = FALSE
	target.stat.uv = TRUE
	target.stat.infra = FALSE
	target.Ff = AVE_FRIC
	target.m = AVE_MASS
	target.Drag[0] = AVE_DRAG_WATER
	target.Drag[1] = AVE_DRAG_AIR
	forcebaseten ? NOP : CAMERA.base = TRISTATE
	}

*entity summon_avian(xcoord,ycoord,zcoord,geomet)
	float xcoord
	float ycoord
	float zcoord
	mesurements geomet
	{
	entity *parent
	entity *tmp = malloc(sizeof(struct entity))
	if (WORLD.ent_tail != NULL)
  		{
		parent = WORLD.ent_tail
		WORLD.ent_tail = &tmp
		}
	else
		{
		if (world.ent == NULL)
			{
			WORLD.ent = &tmp
			WORLD.ent_tail = &tmp
			}
		else
			{
			WORLD.ent_tail = &tmp
			parent = WORLD.ent
			while (parent->next != NULL)
				{
				parent = parent->next
				}
			}
  		}
	struct entity *tmp = {WORLD.ent_tail,NULL,{xcoord,ycoord,zcoord},{geomet[mes_hbr],geomet[mes_hbh],frtr(geomet[mes_hboff]),frtr(geomet[mes_hbeyes])},{0,0,0},{0,0,0},matgen_ident,'\0','\0',255,AVE_FRIC,AVE_MASS,{AVE_DRAG_WATER,AVE_DRAG_AIR},sculpt_avian(geomet)}
	}
