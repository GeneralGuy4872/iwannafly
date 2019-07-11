//meta_flag_tabme
//startup
//you arived here from main

unsigned char sealevel;
bool forcebten;
bool yinv;

char joypath[16];
char mappath[256];
char logpath[64];
bool dologs;
unsigned char base_role;
mesurements TAILOR;
FILE *logfile;

init__setup ()
  {
  FILE *ini_file;
  for (unsigned char n;;n++)
    {
    switch (n)
      {
      case 0 :
        {
        ini_file = fopen("~/.iwannafly/conf.ini","r");
        break;
        }
      case 1 :
        {
        ini_file = fopen("/etc/iwannafly/conf.ini","r");
        break;
        }
      case 2 :
        {
        ini_file = fopen("./conf.ini","r");
        break;
        }
      default :
        {
        HARD_ERROR_MACRO
        break;
        }
      }
    if (ini_file != NULL)
      break;
    }

  char ini_buffer[BUFFER_MAX];
  char dimpath[BUFFER_MAX];
  char angpath[BUFFER_MAX];
  char *ini_key;
  char *ini_data;
  while (fscanf(ini_file,"\n",ini_buffer))
    {
    ini_key = strtok(ini_buffer,"=");
    if (ini_key != NULL)
      {
      ini_data = strtok(NULL,"\n");
      if (ini_data != NULL)
        {
        short ini_key_hash = HASH5(ini_key[0],ini_key[1],ini_key[2]);
        if (ini_key_hash > 0)
          {
          switch (ini_key_hash)
            {
            case HASH5('r','o','l') ://the macro HASH5 truncates 3 chars to the lower 5 bits of each (so is not case sensitive) and returns a short
              {
              base_role = atoi(ini_data);
              break;
              }
            case HASH5('f','o','r') :
              {
              forcebten = atoi(ini_data);
              break;
              }
            case HASH5('s','e','a') :
              {
              sealevel = atoi(ini_data);
              break;
              }
            case HASH5('j','o','y') :
              {
              strncpy(joypath,ini_data,sizeof(joypath) - 1);
              break;
              }
            case HASH5('m','a','p') :
              {
              strncpy(mappath,ini_data,sizeof(mappath) - 1);
              break;
              }
            case HASH5('d','o','l') :
              {
              dologs = atoi(ini_data);
              break;
              }
            case HASH5('l','o','g') :
              {
              strncpy(logpath,ini_data,sizeof(logpath) - 1);
              break;
              }
            case HASH5('d','i','m') :
              {
              strncpy(dimpath,ini_data,sizeof(dimpath) - 1);
              break;
              }
            case HASH5('a','n','g') :
              {
              strncpy(dimpath,ini_data,sizeof(dimpath) - 1);
              break;
              }
            default :
              {
              break;
              }
            }
          }
        }
      }
    }
    fclose(ini_file);

  FILE *dim_file;
  dim_file = fopen(dimpath,"r");
  if (dim_file != NULL)
    {
    for (unsigned char n = 0;n<20;n++)
      {
      fscanf(dim_file,"%hd",TAILOR[n]);
      }
    fclose(dim_file); 
    }

  switch (base_role)
    {
    case 0 :
      {
      summon_avian(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = !forcebten;
      file_cat("/usr/share/iwannafly/avianquest");
      break;
      }/*
    case 1 :
      {
      summon_human(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = 0;
      file_cat("/usr/share/iwannafly/knightquest");
      break;
      }
    case 2 :
      {
      summon_merfolk(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = 0;
      file_cat("/usr/share/iwannafly/merquest");
      break;
      }
    case 3 :
      {
      summon_insectoid(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = !forcebten;
      file_cat("/usr/share/iwannafly/hivequest");
      break;
      }
    case 4 :
      {
      summon_felid(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = 0;
      file_cat("/usr/share/iwannafly/felidquest");
      break;
      }
    case 5 :
      {
      summon_draconic(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = -!forcebten;
      file_cat("/usr/share/iwannafly/o_dr_quest");
      break;
      }
    case 6 :
      {
      summon_elf(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = -!forcebten;
      file_cat("/usr/share/iwannafly/elfquest");
      break;
      }
    case 7 :
      {
      summon_dwarf(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = 0;
      file_cat("/usr/share/iwannafly/dwarfquest");
      break;
      }
    case 8 :
      {
      summon_rogue(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = 0;
      file_cat("/usr/share/iwannafly/roguequest");
      break;
      }
    case 9 :
      {
      summon_drow(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = -!forcebten;
      file_cat("/usr/share/iwannafly/drowquest");
      break;
      }
    case 10 :
      {
      summon_gnome(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = -!forcebten;
      file_cat("/usr/share/iwannafly/gnomequest");
      break;
      }
    case 11 :
      {
      summon_draconic(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = -!forcebten;
      file_cat("/usr/share/iwannafly/c_dr_quest");
      break;
      }
    case 12 :
      {
      summon_seaelf(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = -!forcebten;
      file_cat("/usr/share/iwannafly/seaelfquest");
      break;
      }
    case 13 :
      {
      summon_wizard(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = 0;
      file_cat("/usr/share/iwannafly/wizardquest");
      break;
      }*/
    default :
      {
      summon_avian(0.0,0.0,groundmake(0.0,0.0),TAILOR,(truecolor)color6(3,3,3,3),(truecolor)color6(2,2,2,2));
      CAMERA->format.base = 0;
      printf("you are error.\n");
      break;
      }
    }

  FILE *heightmap_file = fopen(mappath,"rb");
  if (heightmap_file != NULL)
    {
    fread(MAP->dots,sizeof(char),sizeof(MAP->dots),heightmap_file);
    }
  else
    {
    HARD_ERROR_MACRO
    }
  fclose(heightmap_file);

  MAP->sealevel = sealevel;
  }
