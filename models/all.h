#include "./bonegroups.h"
#include "./avian.c"
#include "./human.c"
#include "./merfolk.c"
#include "./feline.c"
#include "./draconic.c"

/*
each species has the following functions:

*skeleton sculpt_foo() provided in each included file

polymorph_foo(entity *bar) changes an existing entity to the default values of foo, keeping velocity, rotation, and position

*entity summon_foo() creates a new entity of the species foo and appends it to the list of entitys

*/
