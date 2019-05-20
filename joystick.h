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

/*

get js0
pack js0 into joybuf
get mouse xy
pack mouse xy into moubuff.x/y
on mouse scroll or page up/down, add/subtract from moubuff.z if within -90 <= z <= 90
on left/right click, add/subtract from moubuff.w if doesn't overflow

*/
