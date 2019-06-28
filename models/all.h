#include "models.h"
#include "shapes.h"
#include "bonegroups.h"
#include "avian.c"
#include "human.c"
#include "merfolk.c"
#include "draconic.c"
#include "elf.c"

/* &bone sculpt_foo(mesurements geomet) provided in each included file creates the model for an entity
 * (int) polymorph_foo(entity *bar,mesurements geomet) changes an existing entity to the default values of foo, keeping velocity, rotation, and position
 * (int) summon_foo(float xcoord,float ycoord,float zcoord,mesurements geomet,bool yinv) creates a new entity of the species foo and appends it to the list of entitys
 *
 * macros are for converting joystick inputs into speed and friction factors.
 * these are currently chosen arbitrarily, but will eventually be based on classical physics
 * (once I have a better understanding of the relevent equasions and coefficiants)
 * so that they are consistant.
 */

