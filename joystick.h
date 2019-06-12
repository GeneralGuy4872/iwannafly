//ioctl interface for input via /dev/js0
//you arrived here from main

struct inbuff
  {
  signed short x
  signed short y
  float yaw
  float pit
  float az
  float alt
  unsigned short lt
  unsigned short rt
  signed short zoom
  unsigned short fov
  }

/*

get js0
pack js0 into joybuf
get mouse xy
pack mouse xy into moubuff.x/y
on mouse scroll or page up/down, add/subtract from moubuff.z if within -90 <= z <= 90
on left/right click, add/subtract from moubuff.w if doesn't overflow

*/
