//startup
//you arived here from main
#include "./init.h"

#include "./config.c"

#define BUFFER_MAX 512
#define FORM_MAX 4

struct smallsettings
  {
  unsigned char species : 3 // 0 = avian, 1 = human, 2 = merfolk, 3 = insectoid, 4 = feline, 5 = draconic
  bool forcebten : 1 //0 = use base determined by species, 1 = self explanitory
  bool yinv : 1 //0 = computer-style controls, 1 = airplane-style controls
  bool prntlog : 1 //output a log file
  char : 0
  unsigned char sealevel : 8
  }

bool run = 0
struct settings iniparsed
char joypath[16]
char mappath[256]
char logpath[64]
FILE logfile
torusmap planet1
entity player1
cameratype camera1
world WORLD = {&planet1,&player1,&player1,NULL,NULL,NULL,NULL,&camera1}
#define MAP WORLD->map
#define PLAYER WORLD->ent
#define CAMERA WORLD->cam

init__setup()
  {
  FILE ini_file
  ini_file = fopen("./conf.ini","r")
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
        strncpy(joypath,ini_data,sizeof(joypath) - 1)
        }
      else if !(strcmp("mappath",ini_key))
        {
        strncpy(mappath,ini_data,sizeof(mappath) - 1)
        }
      else if !(strcmp("logpath",ini_key))
        {
        strncpy(logpath,ini_data,sizeof(logpath) - 1)
        }
      else
        {
        continue
        }
      }
    ini_data = ini_next
    ini_key = ini_next
    }
  free(ini_next); free(ini_data); free(ini_key)
    
  switch (smallsettings.species)
    {
    case 0 :
      {
      polymorph_avian(PLAYER)
      smallsettings.forcebten ? CAMERA.base = 0 : CAMERA.base = 1
      break
      }
    case 1 :
      {
      polymorph_human(PLAYER)
      CAMERA.base = 0
      }
    case 2 :
      {
      polymorph_merfolk(PLAYER)
      CAMERA.base = 0
      }
    case 3 :
      {
      polymorph_insectoid(PLAYER)
      smallsettings.forcebten ? CAMERA.base = 0 : CAMERA.base = 1
      }/*
    case 4 :
      {
      polymorph_felid(PLAYER)
      CAMERA.base = 0
      }
    case 5 :
      {
      polymorph_draconic(PLAYER)
      smallsettings.forcebten ? CAMERA.base = 0 : CAMERA.base = -1
      }
    case 6 :
      {
      polymorph_elf(PLAYER)
      smallsettings.forcebten ? CAMERA.base = 0 : CAMERA.base = -1
      }
    case 7 :
      {
      polymorph_dwarf(PLAYER)
      CAMERA.base = 0
      }*/
    default :
      {
      SOFT_ERROR_MACRO("parseing of conf.ini by "__FILE__,"form switch default escape, at line#"__LINE__,"invalid value in species-field of ini file.")
      polymorph_avian(PLAYER)
      smallsettings.forcebten ? CAMERA.base = 0 : CAMERA.base = 1
      break
      }
    }
  
  noop() //algol conditional just for variety

  FILE heightmap_file = fopen(mappath,"rb")
  fread(MAP.dots,sizeof(char),sizeof(MAP.dots),heightmap_file)
  fclose(heightmap_file)
  free(mappath)
  MAP.sealevel = smallsettings.sealevel
  
  smallsettings.prntlog ? logfile = fopen(logpath,"w") : free(logfile)
  
  run = 1
  }
