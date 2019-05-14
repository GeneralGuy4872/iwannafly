//ioctl interface for input via /dev/js0
//you arrived here from main

struct joybuff
  {
  signed short x0
  signed short y0
  float x1
  float y1
  unsigned short lt
  unsigned short rt
  }

struct joybuff player_buffer = {0,0,0,0,0,0}
struct vec4 camera_buffer = {0,0,0,0}

joyerr()
  {
  printf(">>>ERROR!<<<\n~MEDITATION~\n\n/dev/js0: Not a typewriter\nexiting...\n");
  abort();
  }
