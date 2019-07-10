#include "models.h"
#include "shapes.h"
#include "bonegroups.h"
#include "mapgen.h"

/* skeleton *sculpt_foo(mesurements geomet,minicolor fg,minicolor bg) provided in each included file creates the model for an entity
 * (int) polymorph_foo(entity *bar,mesurements geomet,minicolor fg,minicolor bg) changes an existing entity to the default values of foo, keeping velocity, rotation, and position
 * (int) summon_foo(float xcoord,float ycoord,float zcoord,mesurements geomet) creates a new entity of the species foo and appends it to the list of entitys
 *
 * macros are for converting joystick inputs into speed and friction factors.
 * these are currently chosen arbitrarily, but will eventually be based on classical physics
 * (once I have a better understanding of the relevent equasions and coefficiants)
 * so that they are consistant.
 */

ent_add (new)
	entity *new;
	{
	entity *parent = NULL;
	if (WORLD.ent_tail != NULL)
		{
		parent = WORLD.ent_tail;
		WORLD.ent_tail = new;
		new->prev = parent;
		parent->next = new;
		}
	else
		{
		if (PLAYER == NULL)
			{
			PLAYER = new;
			WORLD.ent_tail = new;
			}
		else
			{
			WORLD.ent_tail = new;
			parent = PLAYER;
			while (parent->next != NULL)
				{
				parent = parent->next;
				}
			new->prev = parent;
			parent->next = new;
			}
		}
	}

#include "avian.c"
//#include "human.c"
//#include "merfolk.c"
//#include "draconic.c"
//#include "elf.c"

