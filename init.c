//startup
//you arived here from main
#include "./init.h"

#include "./config.c"

#define BUFFER_MAX 512

unsigned char sealevel
bool forcebaseten
bool yinv
  
bool run = 0
char joypath[16]
char mappath[256]
char logpath[64]
bool dologs
unsigned char base_species
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
  for(n = 1,n,n++)
    {
    switch n
      {
      case : 1
        {
        ini_file = fopen("~/.iwannafly/conf.ini","r")
        break
        }
      case : 2
        {
        ini_file = fopen("/etc/iwannafly/conf.ini","r")
        break
        }
      case : 3
        {
        ini_file = fopen("./conf.ini","r")
        break
        }
      default
        {
        HARD_ERROR_MACRO("init","line#"__LINE__", if-else failure escape","Cannot find conf.ini in (\"~/.iwannafly/\" | \"/etc/iwannafly/\" | \"./\") or access is denied")
        break
        }
      }
    if (ini_file != NULL)
      {
      n = FALSE
      }
    }

  char ini_data[BUFFER_MAX]
  char *ini_key
  while fscanf(ini_file,"\n",ini_data)
    {
    ini_key = ini_data
    if ( strtok(ini_data,"=") != NULL )
      {
      if !(strcmp("species",ini_key))
        {
        base_species = atoi(ini_data)
        }
      else if !(strcmp("forcebaseten",ini_key))
        {
        forcebaseten = atoi(ini_data)
        }
      else if !(strcmp("sealevel",ini_key))
        {
        sealevel = atoi(ini_data)
        }
      else if !(strcmp("joypath",ini_key))
        {
        strncpy(joypath,ini_data,sizeof(joypath) - 1)
        }
      else if !(strcmp("mappath",ini_key))
        {
        strncpy(mappath,ini_data,sizeof(mappath) - 1)
        }
      else if !(strcmp("dologs",ini_key))
        {
        dologs = atoi(ini_data)
        }
      else if !(strcmp("logpath",ini_key))
        {
        strncpy(logpath,ini_data,sizeof(logpath) - 1)
        }
      else
        {
        NOP
        }
      }
    }
  fclose(ini_file); free(ini_data); free(ini_key)
    
  switch (smallsettings.species)
    {
    case 0 :
      {
      polymorph_avian(PLAYER)
      forcebten ? CAMERA.base = 0 : CAMERA.base = 1
      PLAYER.stat.yinv = yinv
      break
      }
    case 1 :
      {
      polymorph_human(PLAYER)
      CAMERA.base = 0
      PLAYER.stat.yinv = yinv
      break
      }
    case 2 :
      {
      polymorph_merfolk(PLAYER)
      CAMERA.base = 0
      PLAYER.stat.yinv = yinv
      break
      }
    case 3 :
      {
      polymorph_insectoid(PLAYER)
      forcebten ? CAMERA.base = 0 : CAMERA.base = 1
      PLAYER.stat.yinv = yinv
      }/*
    case 4 :
      {
      polymorph_felid(PLAYER)
      CAMERA.base = 0
      PLAYER.stat.yinv = yinv
      break
      }
    case 5 :
      {
      polymorph_draconic(PLAYER)
      smallsettings.forcebten ? CAMERA.base = 0 : CAMERA.base = -1
      PLAYER.stat.yinv = yinv
      break
      }
    case 6 :
      {
      polymorph_elf(PLAYER)
      smallsettings.forcebten ? CAMERA.base = 0 : CAMERA.base = -1
      PLAYER.stat.yinv = yinv
      break
      }
    case 7 :
      {
      polymorph_dwarf(PLAYER)
      CAMERA.base = 0
      PLAYER.stat.yinv = yinv
      break
      }*/
    default :
      {
      SOFT_ERROR_MACRO("parseing of conf.ini by "__FILE__,"form switch default escape, at line#"__LINE__,"invalid value in species-field of ini file.")
      polymorph_avian(PLAYER)
      forcebten ? CAMERA.base = 0 : CAMERA.base = 1
      PLAYER.stat.yinv = yinv
      break
      }
    }
  
  free(yinv);

  FILE heightmap_file = fopen(mappath,"rb")
  fread(MAP.dots,sizeof(char),sizeof(MAP.dots),heightmap_file)
  fclose(heightmap_file)
  free(mappath)
  MAP.sealevel = sealevel

  free(sealevel);

  if dologs
    {
    for (n = 1,n,n++)
      {
      switch n
        {
        case : 1
          {
          logfile = fopen(logpath,"a")
          break
          }
        case : 2
          {
          logfile = fopen("/var/log/iwannafly.log","a")
          break
          }
        case : 3
          {
          logfile = fopen("~/.iwannafly.log","a")
          break
          }
        case : 4
          {
          logfile = fopen("./iwannafly.log","a")
          break
          }
        default
          {
          SOFT_ERROR_MACR)("init","line#"__LINE__,"Cannot open a log file at specified path, or any of: \"/var/log/iwannafly.log\", \"~/.iwannafly.log\", \"./iwannafly.log\". What's up with your perms?!"}
          fclose(logfile)
          break
          }
        }
      if (logfile != NULL)
        {
        n = 0
        }
      }
    }
  run = 1
  }
