//meta_flag_tabme
//startup
//you arived here from main
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
mesurements TAILOR
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
    switch (n)
      {
      case 1 :
        {
        ini_file = fopen("~/.iwannafly/conf.ini","r")
        break
        }
      case 2 :
        {
        ini_file = fopen("/etc/iwannafly/conf.ini","r")
        break
        }
      case 3 :
        {
        ini_file = fopen("./conf.ini","r")
        break
        }
      default :
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

  char ini_buffer[BUFFER_MAX]
  char dimpath[BUFFER_MAX]
  char angpath[BUFFER_MAX]
  char *ini_key
  char *ini_data
  while fscanf(ini_file,"\n",ini_buffer)
    {
    ini_key = strtok(ini_buffer,"=")
    if (ini_key != NULL)
      {
      ini_data = strtok(NULL,"\n")
      if (ini_data != NULL)
        {
        short ini_key_hash = HASH5(ini_key[0],ini_key[1],ini_key[2])
        if (ini_key_hash > 0)
          {
          switch ini_key_hash
            {
            case HASH5('s','p','e') ://the macro HASH5 truncates 3 chars to the lower 5 bits of each (so is not case sensitive) and returns a short
              {
              base_species = atoi(ini_data)
              break
              }
            case HASH5('f','o','r') :
              {
              forcebaseten = atoi(ini_data)
              break
              }
            case HASH5('s','e','a') :
              {
              sealevel = atoi(ini_data)
              break
              }
            case HASH5('j','o','y') :
              {
              strncpy(joypath,ini_data,sizeof(joypath) - 1)
              break
              }
            case HASH5('m','a','p') :
              {
              strncpy(mappath,ini_data,sizeof(mappath) - 1)
              break
              }
            case HASH5('d','o','l') :
              {
              dologs = atoi(ini_data)
              break
              }
            case HASH5('l','o','g') :
              {
              strncpy(logpath,ini_data,sizeof(logpath) - 1)
              break
              }
            case HASH5('d','i','m') :
              {
              strncpy(dimpath,ini_data,sizeof(dimpath) - 1)
              break
              }
            case HASH5('a','n','g') :
              {
              strncpy(dimpath,ini_data,sizeof(dimpath) - 1)
              break
              }
            default :
              {
              break
              }
            }
          }
        }
      }
    }
    fclose(ini_file); free(ini_data); free(ini_key); free(ini_key_hash)

  FILE dim_file
  dim_file = fopen(dimpath,"r")
  if (dim_file != NULL)
    {
    char tsv_buffer[BUFFER_MAX]
    char *tsv_whole
    char *tsv_num
    for (n=0;fscanf(dim_file,"\n",tsv_buffer);n++)
      {
      tsv_whole = strtok(tsv_buffer,"\t")
      if ( tsv_whole != NULL )
        {
        tsv_num = strtok(NULL,"\t")
        if ( tsv_num != NULL )
          {
          TAILOR.fr.[n].whole = atoi(tsv_whole)
          TAILOR.fr.[n].num = atoi(tsv_num)
          }
        }
      }
    fclose(dim_file); 
    }

  FILE ang_file
  ang_file = fopen(angpath,"r")
  if (ang_file != NULL)
    {
    char tsv_q[BUFFER_MAX]
    fscanf(ang_file,"\n",tsv_buffer)
    atof(
    }

  switch (base_species)
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
    for (n = 1;n;n++)
      {
      switch (n)
        {
        case 1 :
          {
          logfile = fopen(logpath,"a")
          break
          }
        case 2 :
          {
          logfile = fopen("/var/log/iwannafly.log","a")
          break
          }
        case 3 :
          {
          logfile = fopen("~/.iwannafly.log","a")
          break
          }
        case 4 :
          {
          logfile = fopen("./iwannafly.log","a")
          break
          }
        default :
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
