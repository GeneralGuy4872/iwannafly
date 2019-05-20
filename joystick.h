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

struct moubuff
  {
  float x
  float y
  signed char z
  unsigned char w
  }

struct joybuff player_buffer = {0,0,0,0,0,0}
struct moubuff camera_buffer = {0,0,0,0}
