//startup
//you arived here from main
#include "./init.h"

#include "./config.c"

#define BUFFER_MAX 512
#define FORM_MAX 6

struct smallsettings
  {
  unsigned char species : 3 // 0 = avian, 1 = human, 2 = merfolk, 3 = insectoid, 4 = feline, 5 = draconic
  bool forcebten : 1 //0 = use base determined by species, 1 = self explanitory
  bool yinv : 1 //0 = computer-style controls, 1 = airplane-style controls
  char : 0
  unsigned char sealevel : 8
  }

bool run = 0
struct settings iniparsed
char joypath[16]
char mappath[256]
torusmap planet
#define MAP planet
entity player1
#define PLAYER player1
cameratype camera1
#define CAMERA camera1
world everything = {&MAP,&PLAYER,&PLAYER,NULL,NULL,NULL,NULL,&CAMERA}
#define WORLD everything

init__setup(argv)
  int argc
  char **argv
  {
  FILE ini_file
  ini_file = fopen("../conf.ini","r")
  char ini_next[BUFFER_MAX]
  char *ini_data
  char *ini_key
  fread(ini_next,sizeof(char),sizeof(ini_next),inisettings)
  fclose(ini_file)
  ini_data = ini_file
  ini_key = ini_file
  while ( strtok(ini_file,"\n") != NULL )
    {
    if ( strtok(ini_data,"=") != NULL )
      {
      if !(strcmp("species",ini_key))
        {
        struct settings.species = atoi(ini_data)
        }
      else if !(strcmp("forcebten",ini_key))
        {
        struct settings.species = atoi(ini_data)
        }
      else if !(strcmp("sealevel",ini_key))
        {
        struct settings.sealevel = atoi(ini_data)
        }
      else if !(strcmp("joypath",ini_key))
        {
        strncpy(joypath,ini_data,16)
        }
      else if !(strcmp("mappath",ini_key))
        {
        strncpy(mappath,ini_data,256)
        }
      }
    ini_data = ini_next
    ini_key = ini_next
    }
  free(ini_next); free(ini_data); free(ini_key)
    
  if (smallsettings.species < FORM_MAX)
    {
    if (smallsettings.species == 0)
      {
      polymorph_avian(PLAYER)
      if smallsettings.forcebten
        {
        CAMERA.base = 0
        }
      else
        {
        CAMERA.base = 1
        }
      }
    else if (smallsettings.species == 1)
      {
      polymorph_human(PLAYER)
      CAMERA.base = 0
      }
    else if (smallsettings.species == 2)
      {
      polymorph_merfolk(PLAYER)
      CAMERA.base = 0
      }
    else if (smallsettings.species == 3)
      {
      polymorph_insectoid(PLAYER)
      if smallsettings.forcebten
        {
        CAMERA.base = 0
        }
      else
        {
        CAMERA.base = 1
        }
      }
    else if (smallsettings.species == 4)
      {
      polymorph_felid(PLAYER)
      CAMERA.base = 0
      }
    else if (smallsettings.species == 5)
      {
      polymorph_draconic(PLAYER)
      if smallsettings.forcebten
        {
        CAMERA.base = 0
        }
      else
        {
        CAMERA.base = -1
        }
      }
    }
  else
    {
    HARD_ERROR_MACRO("init","formtable","invalid value in species-field of ini file.")
    }

  FILE heightmap_file = fopen(mappath,"rb")
  fread(MAP.dots,sizeof(char),sizeof(MAP.dots),heightmap_file)
  fclose(heightmap_file)
  MAP.sealevel = smallsettings.sealevel
  
  run = 1
  }
