//need to start moveing #define-s, struct-s, and typedef-s here

/*whether a variable is in ALL_CAPS or not is not an indicator of if it is a macro; what it means
* is that it is a global value that may be called (or even modified) by functions stealthily.
* a macro function in ALL_CAPS is a true macro, andless complicated than one that is not,
* which is a subroutine. all this is complicated by the fact that even this convoluted formatting
* is currently inconsistant, and the terms "subroutine" and "macro function" are interchangeable
* by definition and I have yet to establish a true boundry.
*/

/*figure out iff && when time comes
*
* #define SHMLOCK(V) some_func(V)
* #define SHMUNLOCK(V) sume_func(V)
* #define SHMEX(V,F) SHMLOCK(V); F; SHMUNLOCK(V);
*
* #define MMAKE(M,L,N) *M = sizeof(L) mmem [N]
* #define MMLOCK(V) some_func(V)
* #define MMUNLOCK(V) sume_func(V)
* #define MMEX(V,F) MMLOCK(V); F; MMUNLOCK(V);
*/

//these will eventualy be dependent on wait times, once I figure out how to fork without causing wabbits
//see notes/forks.txt
#define SPINLOAD sleep(100); printf(" \b|\b"); sleep(100); printf(" \b/\b"); sleep(100); printf(" \b-\b"); sleep(100); printf(" \b\\\b"); 
#define DOTLOAD sleep(100); printf("\b\b\b   "); sleep(100); printf("\b\b\b.  "); sleep(100); printf("\b\b\b.. "); sleep(100); printf("\b\b\b..."); sleep(100); printf("\b\b\b .."); sleep(100); printf("\b\b\b  ."); sleep(100); printf("\b\b\b . "); sleep(100); printf("\b\b\b.  "); sleep(100); printf("\b\b\b . "); sleep(100); printf("\b\b\b  ."); sleep(100); printf("\b\b\b .:"); sleep(100); printf("\b\b\b...");

#define __MYVERS__ "00.00.01"
#define REV_NOFORK "000.000"
#define VITALSTAT(Z) "Iwannafly "__MYVERS__";"Z" Compiled on "__DATE__
#define VITALSTAT_FULL(N,Z) " \033[1;97m~~ Iwannafly ~~\033[m\n  version: "__MYVERS__"\n\n \033[97m- "N" -\033[m\n  revision: "Z"\n\n\033[3mCompiled on "__DATE__"\033[m\n"

/*
the library at <math.h> must provide:
M_E  M_LN2  M_LN10  M_LOG2E  M_LOG10E
M_PI  M_PI_2  M_PI_4  M_2_PI  M_1_PI
M_SQRT_2  M_SQRT1_2
*/
#define COS_PI_8 0.9238795325112867561282
#define COS_PI_16 0.9807852804032304491262
#define COS_PI_32 0.9951847266721968862448
#define SQRT_5 2.236067977499789696409
#define G_RATIO 1.618033988749894848205
#define S_RATIO 2.414213562373095048802
#define MY_TAU 6.283185307179586476925

#define FPS 30 //frames per second (hz)
static const float MSEC_FRAME = ((1.0 / FPS) * 1000) //milliseconds per frame (msec)

#define PI_N(N) (M_PI / N)
#define PI_2_N(N) (M_PI_2 / N)

div_t div_tmp;

typedef int (*eventfunc)(int,*char[]) //you know you're getting serious when you're using function pointers
typedef signed char tern
typedef unsigned char quard
typedef char mydate_str[24]

#ifdef __bool_true_false_are_defined
#ifndef TRUE
#define TRUE true
#endif /*!(TRUE)*/
#ifndef FALSE
#define FALSE false
#endif /*!(FALSE)*/
#else /*!(__bool_true_false_are_defined)*/
#define TRUE ((bool) 1)
#define FALSE ((bool) 0)
#endif /*__bool_true_false_are_defined*/

#define TRISTATE (tern) -1
#define QUANTUM (tern) -2

#define LEFT -1
#define RIGHT 1
#define xLEFT(N) (LEFT * N)
#define xRIGHT(N) (RIGHT * N)


//VIEWRNG shall be an odd number
#define VIEWRNG 5
static const signed char VIEWRNGmax = ((VIEWRNG - 1) / 2)
static const signed char VIEWRNGmin = (VIEWRNGmax * -1)
static const signed char VIEWRNGlim = (VIEWRNGmax + 1)

static const char WEEKDAYS[8][4] = {" SUN"," MON","TUES"," WED","THUR"," FRI"," SAT","?ERR"}

noop() {}
#define NOP noop()
#define SWYM sleep(0)
#define X_HCF_X exit(1)

typedef float matrix[4][4]

bool toggle(setting)
  bool setting
  {
  setting = !setting
  return setting
  }

struct vector4
  {
  float x
  float y
  float z
  float w
  }

struct vector3
  {
  float x
  float y
  float z
  }

struct camera_ang
  {
  float x
  float y
  signed short r
  unsigned short f
  }

struct vector2
  {
  float x
  float y
  }

struct ushortvector4
  {
  unsigned short x
  unsigned short y
  unsigned short z
  unsigned short w
  }

struct ushortvector3
  {
  unsigned short x
  unsigned short y
  unsigned short z
  }

struct ushortvector2
  {
  unsigned short x
  unsigned short y
  }

struct microvector
  {
  tern x : 2
  tern y : 2
  tern z : 2
  tern w : 2
  }

struct minivector
  {
  quard x : 2
  quard y : 2
  quard z : 2
  quard w : 2
  }

struct bytevector4
  {
  unsigned int x : 8
  unsigned int y : 8
  unsigned int z : 8
  unsigned int w : 8
  }

struct bytevector2
  {
  unsigned int x : 8
  unsigned int y : 8
  }

struct charvector4
  {
  signed char x : 8
  signed char y : 8
  signed char z : 8
  signed char w : 8
  }

struct charvector2
  {
  signed char x : 8
  signed char y : 8
  }

struct halfbytes
  {
  unsigned char h : 4
  unsigned char l : 4
  }

struct fraction
  {
  tern sign : 2
  unsigned int num : 6
  }
#define FR_ZERO {0,0}
#define FR_ONE {1,63}
#define FR_MONE {-1,63}
#define FR_INF {-2,0}
#define FR(S,N) {S,(N)-1}

struct mixfraction
  {
  unsigned int inter : 8
  tern sign : 2
  unsigned int num : 6
  }
#define MFR_ZERO {0,0,0}
#define MFR_ONE {1,1,0}
#define MFR_MONE {1,-1,0}
#define MFR_INF {0,-2,0}
#define MFR(I,S,N) {I,S,N}

#define FR_DEN 64

struct fracvector3
  {
  struct fraction x
  struct fraction y
  struct fraction z
  }

typedef struct mixfraction mesurements[20]
/*hbradius 0
 *hbheight 1
 *hboffset 2
 *eyes 3
 *skull 4
 *neck 5
 *shoulder 6
 *back 7
 *humerus 8
 *femur 9
 *pelvis 10
 *coxxyx 11
 *tail 12
 *wing 13
 *q angle 14
 *digiti angle 15
 *fan radius 16
 *fan length 17
 *fan angle 18
 */
 
float frfl(input)
  fraction input
  {
  switch (input.sign)
    {
    case 0 :
      {
      return 0.0
      }
    case -2 :
      {
      switch input.num
        {
        case 0 :
          {
          return INFINITY
          }
        case 63 :
          {
          return INFINITY * -1
          }
        default :
          {
          return NAN
          }
      }
    default :
      {
      return (((float) input.num + 1) / FR_DENOM) * input.sign
      }
    }
  }

float mfrfl(input)
  mixfraction input
  {
  switch (input.sign)
    {
    case 0 :
      {
      return 0.0
      }
    case -2 :
      {
      switch input.num
        {
        case 0 :
          {
          return INFINITY
          }
        case 63 :
          {
          return INFINITY * -1
          }
        default :
          {
          return NAN
          }
      }
    default :
      {
      return ((((float) input.num) / FR_DENOM) + input.whole) * input.sign
      }
    }
  }

struct mixfraction flmfr(input)
  float input
  {
  struct mixfraction output
  output.whole = (unsigned char) input
  output.num = (unsigned char) (input - output.whole) * FRAC_DEN
  output.sign = SGN(input)
  return output
  }

struct fraction flfr(input)
  float input
  {
  struct fraction output
  output.num = ((unsigned int) (input) * FRAC_DEN) - 1
  output.sign = SGN(input)
  return output
  }

struct fraction truncfr(input)
  mixfraction input
  {
  fraction output
  if ((input.num == 0) && ((input.sign == 1) || (input.sign == -1)))
    {
    output = {0,0}
    }
  else
    {
    output = {input.sign,input.num - 1}
    }
  return output
  }

struct my_date_time
  {
  unsigned int year : 3
  unsigned int month : 4
  unsigned int day : 5
  unsigned int weekday : 3
  unsigned int hour : 5
  unsigned int minute : 6
  unsigned int second : 6
  }

tick_tock(counter)
  struct my_date_time counter
  {
  div_tmp = div(counter.second + 1,60) //add, mod, and carry out
  counter.second = div_tmp.rem
  div_tmp = div(counter.minute + div_tmp.quot,60) //carry in, mod, carry out
  counter.minute = div_tmp.rem
  div_tmp = div(counter.hour + div_tmp.quot,24)
  counter.hour = div_tmp.rem
  counter.weekday = (counter.weekday + div_tmp.quot)%7 //carry in and mod, no carry out
  div_tmp = div(counter.day + div_tmp.quot,30)
  counter.day = div_tmp.rem
  div_tmp = div(counter.month + div_tmp.quot,12)
  counter.month = div_tmp.rem
  counter.year = (counter.year + div_tmp.quot)%7
  }    
#define sprinttimedate(N,O) sprintf(O,"%i:%i:%i %s %i/%i/%i",N.hour,N.minute,N.second,WEEKDAYS[N.weekday],N.day,N.month,N.year)
#define fprinttimedate(N,O) fprintf(O,"%i:%i:%i %s %i/%i/%i\n",N.hour,N.minute,N.second,WEEKDAYS[N.weekday],N.day,N.month,N.year)
#define printtimedate(N) printf("%i:%i:%i %s %i/%i/%i\n",N.hour,N.minute,N.second,WEEKDAYS[N.weekday],N.day,N.month,N.year)

struct statreg
  {
  bool ground : 1
  bool wet : 1
  bool yinv : 1
  bool horiz : 1
  tern bouy : 2
  bool uv : 1
  bool infra : 1
  }

struct viewform
  {
  tern base : 2
  tern deg : 2
  tern dist : 2
  bool time : 1
  bool uv : 1
  }

struct hitbox_type
  {
  struct mixfraction r
  struct mixfraction h
  struct fraction eyes
  struct fraction offset
  }

struct shape
  {
  struct vector3 vertlist;
  unsigned char bytecode;
  unsigned char inum
  }

struct event
  {
  struct event *prev
  struct event *next
  ushortvector3 coords
  bytevector2 size
  unsigned long durat
  eventfunc *ontrigger
  char *strings[]
  int params
  }

struct truecolor
  {
  unsigned int r : 8
  unsigned int g : 8
  unsigned int b : 8
  unsigned int a : 8
  }

struct highcolor
  {
  unsigned int r : 5
  unsigned int g : 6
  unsigned int b : 5
  }

struct lowcolor
  {
  unsigned int r : 3
  unsigned int g : 3
  unsigned int b : 2
  }

struct torusmap
  {
  unsigned char dots[360][360]
  unsigned char sealevel
  struct bytevector2 start
  }
  
#define MAX(A,B) (A > B ? A : B)
#define MIN(A,B) (A < B ? A : B)
#define CLAMP(N,A,B) MIN(MAX(N,A),B)
#define RAD(N) ((N%360)*(M_PI/180))
#define DEG(N) (N*(180/M_PI))
#define R_GON(N) (N*(200/M_PI))
#define D_GON(N) ((N%360)*(10/9))
#define G_RAD(N) ((N%400)*(M_PI/200))
#define G_DEG(N) ((N%400)*(9/10))
#define R_BPI(N) ((N/M_PI)%2)
#define zin(N) NEG(sin(N))
#define bos(N) NEG(cos(N))
#define SANE(N) (N == 0 ? TRUE : N)

#define SGN(N) ( isfinite(N) ? ( N == 0 ? 0 : ( N < 0 ? -1 : 1 )) : QUANTUM )
#define TOSGN(N) ( N < 0 ? -1 : 0 )
#define NEG(N) (-1 * N)

#define BASEBONEPOS(M) ( M.stat.horiz ? ( M.pos.z + mixfrfl(M.hitbox.r) + (mixfrfl(M.hitbox.r) * frfl(M.hitbox.offset)) ) : ( M.pos.z + (mixfrfl(M.hitbox.h) / 2) + ((mixfrfl(M.hitbox.h) / 2) * frfl(M.hitbox.offset)) ) )
#define EYECOORD(M) ( M.stat.horiz ? ( M.pos.x + (mixfrfl(M.hitbox.h) * frfl(M.hitbox.eyes)) ) : ( M.pos.z + (mixfrfl(M.hitbox.h) / 2) + ((mixfrfl(M.hitbox.h) / 2) * frfl(M.hitbox.eyes)) ) )

//HERE BE DRAGONS. use an editor with regular expresions here.

/*won't know if these are flipped along a '\' diagonal until I have a proof of concept build,
* have not found a clear definition on what layer of the matrix needs to be column major for opengl
* since I have to rewrite glm, may have dug too deep.*/
#define matgen_raw(A,B,C,D,E,F,G,H,I,X,Y,Z) {{A,D,G,0},{B,E,H,0},{C,F,I,0},{X,Y,Z,1}}
//generate a column-major matrix declaration from a row-major list
#define matset_raw(M,A,B,C,D,E,F,G,H,I,X,Y,Z) {  M[0][0] = A; M[0][1] = D; M[0][2] = G; M[0][3] = 0; M[1][0] = B; M[1][1] = E; M[1][2] = H; M[1][3] = 0; M[2][0] = C; M[2][1] = F; M[2][2] = I; M[2][3] = 0; M[3][0] = X; M[3][1] = Y; M[3][2] = Z; M[3][3] = 1;  }
//iterate a colomn-major matrix redefinition from a row-major list
#define matpush(M,N) {  M[0][0] = N[0][0]; M[0][1] = N[0][1]; M[0][2] = N[0][2]; M[0][3] = N[0][3]; M[1][0] = N[1][0]; M[1][1] = N[1][1]; M[1][2] = N[1][2]; M[1][3] = N[1][3]; M[2][0] = N[2][0]; M[2][1] = N[2][1]; M[2][2] = N[2][2]; M[2][3] = N[2][3]; M[3][0] = N[3][0]; M[3][1] = N[3][1]; M[3][2] = N[3][2]; M[3][3] = N[3][3];  }

#define matgen_ident matgen_raw(1,0,0,0,1,0,0,0,1,0,0,0)
#define matgen_translate(L,W,H) matgen_raw(1,0,0,0,1,0,0,0,1,L,W,H)
#define matgen_reflect(B,C,D) matgen_raw(B,0,0,0,C,0,0,0,D,0,0,0)
#define matgen_transform(B,C,D,L,W,H) matgen_raw(B,0,0,0,C,0,0,0,D,L,W,H)

#define matset_ident(M) matset_raw(M,1,0,0,0,1,0,0,0,1,0,0,0)
#define matset_translate(M,L,W,H) matset_raw(M,1,0,0,0,1,0,0,0,1,L,W,H)
#define matset_reflect(M,B,C,D) matset_raw(M,B,0,0,0,C,0,0,0,D,0,0,0)
#define matset_transform(M,B,C,D,L,W,H) matset_raw(M,B,0,0,0,C,0,0,0,D,L,W,H)

#define matgen_super_rad(A,E,R,X,Y,Z,B,C,D) matgen_raw(cos(A)*cos(E)*B,(zin(A)*Z*cos(R))+(cos(A)*sin(E)*Y*sin(R)*X),(zin(A)*Z*zin(R)*X)+(cos(A)*sin(E)*Y*cos(R)),sin(A)*Z*cos(E),((cos(A)*cos(R))+(sin(A)*Z*sin(E)*Y*sin(R)*X))*C,(cos(A)*zin(R)*X)+(sin(A)*Z*sin(E)*Y*cos(R)),zin(E)*Y,sin(R)*X*cos(E),cos(E)*cos(R)*D,0,0,0)
#define matset_super_rad(M,A,E,R,X,Y,Z,B,C,D) matset_raw(M,cos(A)*cos(E)*B,(zin(A)*Z*cos(R))+(cos(A)*sin(E)*Y*sin(R)*X),(zin(A)*Z*zin(R)*X)+(cos(A)*sin(E)*Y*cos(R)),sin(A)*Z*cos(E),((cos(A)*cos(R))+(sin(A)*Z*sin(E)*Y*sin(R)*X))*C,(cos(A)*zin(R)*X)+(sin(A)*Z*sin(E)*Y*cos(R)),zin(E)*Y,sin(R)*X*cos(E),cos(E)*cos(R)*D,0,0,0)
#define matgen_super_deg(A,E,R,X,Y,Z,B,C,D) matgen_super_rad(RAD(A),RAD(E),RAD(R),X,Y,Z,B,C,D)
#define matset_super_deg(M,A,E,R,X,Y,Z,B,C,D) matset_super_rad(M,RAD(A),RAD(E),RAD(R),X,Y,Z,B,C,D)

#define matgen_master_rad(A,E,R,X,Y,Z) matgen_raw(cos(A)*cos(E),(zin(A)*Z*cos(R))+(cos(A)*sin(E)*Y*sin(R)*X),(zin(A)*Z*zin(R)*X)+(cos(A)*sin(E)*Y*cos(R)),sin(A)*Z*cos(E),(cos(A)*cos(R))+(sin(A)*Z*sin(E)*Y*sin(R)*X),(cos(A)*zin(R)*X)+(sin(A)*Z*sin(E)*Y*cos(R)),zin(E)*Y,sin(R)*X*cos(E),cos(E)*cos(R),0,0,0)
#define matset_master_rad(M,A,E,R,X,Y,Z) matset_raw(M,cos(A)*cos(E),(zin(A)*Z*cos(R))+(cos(A)*sin(E)*Y*sin(R)*X),(zin(A)*Z*zin(R)*X)+(cos(A)*sin(E)*Y*cos(R)),sin(A)*Z*cos(E),(cos(A)*cos(R))+(sin(A)*Z*sin(E)*Y*sin(R)*X),(cos(A)*zin(R)*X)+(sin(A)*Z*sin(E)*Y*cos(R)),zin(E)*Y,sin(R)*X*cos(E),cos(E)*cos(R),0,0,0)
#define matgen_master_deg(A,E,R,X,Y,Z) matgen_master_rad(RAD(A),RAD(E),RAD(R),X,Y,Z)
#define matset_master_deg(M,A,E,R,X,Y,Z) matset_master_rad(M,RAD(A),RAD(E),RAD(R),X,Y,Z)

#define matgen_ultraeuler_rad(A,E,R,X,Y,Z,B,C,D) matgen_raw(((cos(A)*cos(E)*cos(R))+(zin(A)*Z*sin(R)*X))*B,(cos(A)*cos(E)*zin(R)*X)+(zin(A)*Z*cos(R)),cos(A)*cos(E)*Y,(sin(A)*Z*cos(E)*cos(R))+(cos(A)*sin(R)*X),((sin(A)*Z*cos(E)*zin(R)*X)+(cos(A)*cos(R)))*C,sin(A)*Z*sin(E)*Y,zin(E)*Y,zin(E)*Y*zin(R)*X,cos(E)*D,0,0,0)
#define matset_ultraeuler_rad(M,A,E,R,X,Y,Z,B,C,D) matset_raw(M,((cos(A)*cos(E)*cos(R))+(zin(A)*Z*sin(R)*X))*B,(cos(A)*cos(E)*zin(R)*X)+(zin(A)*Z*cos(R)),cos(A)*cos(E)*Y,(sin(A)*Z*cos(E)*cos(R))+(cos(A)*sin(R)*X),((sin(A)*Z*cos(E)*zin(R)*X)+(cos(A)*cos(R)))*C,sin(A)*Z*sin(E)*Y,zin(E)*Y,zin(E)*Y*zin(R)*X,cos(E)*D,0,0,0)
#define matgen_ultraeuler_deg(A,E,R,X,Y,Z,B,C,D) matgen_ultraeuler_rad(RAD(A),RAD(E),RAD(R),X,Y,Z,B,C,D)
#define matset_ultraeuler_deg(M,A,E,R,X,Y,Z,B,C,D) matset_ultraeuler_rad(M,RAD(A),RAD(E),RAD(R),X,Y,Z,B,C,D)

#define matgen_zeuler_rad(A,E,R,X,Y,Z) matgen_raw((cos(A)*cos(E)*cos(R))+(zin(A)*Z*sin(R)*X),(cos(A)*cos(E)*zin(R)*X)+(zin(A)*Z*cos(R)),cos(A)*cos(E)*Y,(sin(A)*Z*cos(E)*cos(R))+(cos(A)*sin(R)*X),(sin(A)*Z*cos(E)*zin(R)*X)+(cos(A)*cos(R)),sin(A)*Z*sin(E)*Y,zin(E)*Y,zin(E)*Y*zin(R)*X,cos(E),0,0,0)
#define matset_zeuler_rad(M,A,E,R,X,Y,Z) matset_raw(M,(cos(A)*cos(E)*cos(R))+(zin(A)*Z*sin(R)*X),(cos(A)*cos(E)*zin(R)*X)+(zin(A)*Z*cos(R)),cos(A)*cos(E)*Y,(sin(A)*Z*cos(E)*cos(R))+(cos(A)*sin(R)*X),(sin(A)*Z*cos(E)*zin(R)*X)+(cos(A)*cos(R)),sin(A)*Z*sin(E)*Y,zin(E)*Y,zin(E)*Y*zin(R)*X,cos(E),0,0,0)
#define matgen_zeuler_deg(A,E,R,X,Y,Z) matgen_xeuler_rad(RAD(A),RAD(E),RAD(R),X,Y,Z)
#define matset_zeuler_deg(M,A,E,R,X,Y,Z) matset_xeuler_rad(M,RAD(A),RAD(E),RAD(R),X,Y,Z)

#define matgen_sphere_rad(A,E,L,Z,Y) matgen_raw(cos(A)*cos(E),zin(A)*Z,cos(A)*sin(E)*Y,sin(A)*Z*cos(E),cos(A),sin(A)*Z*sin(E)*Y,zin(E)*Y,0,cos(E),cos(A)*cos(E)*L,0,0)
#define matset_sphere_rad(M,A,E,L,Z,Y) matset_raw(M,cos(A)*cos(E),zin(A)*Z,cos(A)*sin(E)*Y,sin(A)*Z*cos(E),cos(A),sin(A)*Z*sin(E)*Y,zin(E)*Y,0,cos(E),cos(A)*cos(E)*L,0,0)
#define matgen_sphere_deg(A,E,L,Z,Y) matgen_sphere_rad(RAD(A),RAD(E),L,Z,Y)
#define matset_sphere_deg(M,A,E,L,Z,Y) matset_sphere_rad(M,RAD(A),RAD(E),L,Z,Y)

#define matgen_x_rad(R,X) matgen_raw(1,0,0,0,cos(R),zin(R)*X,0,sin(R)*X,cos(R),0,0,0)
#define matset_x_rad(M,R,X) matset_raw(M,1,0,0,0,cos(R),zin(R)*X,0,sin(R)*X,cos(R),0,0,0)
#define matgen_x_deg(R,X) matgen_x_rad(RAD(R),X)
#define matset_x_deg(M,R,X) matset_x_rad(M,RAD(R),X)

#define matgen_y_rad(E,Y) matgen_raw(cos(E),0,sin(E)*Y,0,1,0,zin(E)*Y,0,cos(E),0,0,0)
#define matset_y_rad(M,E,Y) matset_raw(M,cos(E),0,sin(E)*Y,0,1,0,zin(E)*Y,0,cos(E),0,0,0)
#define matgen_y_deg(E,Y) matgen_y_rad(RAD(E),Y)
#define matset_y_deg(M,E,Y) matset_y_rad(M,RAD(E),Y)

#define matgen_z_rad(A,Z) matgen_raw(cos(A),zin(A)*Z,0,sin(A)*Z,cos(A),0,0,0,1,0,0,0)
#define matset_z_rad(M,A,Z) matset_raw(M,cos(A),zin(A)*Z,0,sin(A)*Z,cos(A),0,0,0,1,0,0,0)
#define matgen_z_deg(A,Z) matgen_z_rad(RAD(A),Z)
#define matset_z_deg(M,A,Z) matset_z_rad(M,RAD(A),Z)

#define matgen_xref_rad(R,X,B,C,D) matgen_raw(B,0,0,0,cos(R)*C,zin(R)*X,0,sin(R)*X,cos(R)*D,0,0,0)
#define matset_xref_rad(M,R,X,B,C,D) matset_raw(M,B,0,0,0,cos(R)*C,zin(R)*X,0,sin(R)*X,cos(R)*D,0,0,0)
#define matgen_xref_deg(R,X,B,C,D) matgen_xref_rad(RAD(R),X,B,C,D)
#define matset_xref_deg(M,R,X,B,C,D) matset_xref_rad(M,RAD(R),X,B,C,D)

#define matgen_yref_rad(E,Y,B,C,D) matgen_raw(cos(E)*B,0,sin(E)*Y,0,C,0,zin(E)*Y,0,cos(E)*D,0,0,0)
#define matset_yref_rad(M,E,Y,B,C,D) matset_raw(M,cos(E)*B,0,sin(E)*Y,0,C,0,zin(E)*Y,0,cos(E)*D,0,0,0)
#define matgen_yref_deg(E,Y,B,C,D) matgen_yref_rad(RAD(E),Y,B,C,D)
#define matset_yref_deg(M,E,Y,B,C,D) matset_yref_rad(M,RAD(E),Y,B,C,D)

#define matgen_zref_rad(A,Z,B,C,D) matgen_raw(cos(A)*B,zin(A)*Z,0,sin(A)*Z,cos(A)*C,0,0,0,D,0,0,0)
#define matset_zref_rad(M,A,Z,B,C,D) matset_raw(M,cos(A)*B,zin(A)*Z,0,sin(A)*Z,cos(A)*C,0,0,0,D,0,0,0)
#define matgen_zref_deg(A,Z,B,C,D) matgen_zref_rad(RAD(A),Z,B,C,D)
#define matset_zref_deg(M,A,Z,B,C,D) matset_zref_rad(M,RAD(A),Z,B,C,D)

#define matgen_xp_rad(R,X,L) matgen_raw(1,0,0,0,cos(R),zin(R)*X,0,sin(R)*X,cos(R),L,0,0)
#define matset_xp_rad(M,R,X,L) matset_raw(M,1,0,0,0,cos(R),zin(R)*X,0,sin(R)*X,cos(R),L,0,0)
#define matgen_xp_deg(R,X,L) matgen_xp_rad(RAD(R),X,L)
#define matset_xp_deg(M,R,X,L) matset_xp_rad(M,RAD(R),X,L)

#define matgen_yp_rad(E,Y,W) matgen_raw(cos(E),0,sin(E)*Y,0,1,0,zin(E)*Y,0,cos(E),0,W,0)
#define matset_yp_rad(M,E,Y,W) matset_raw(M,cos(E),0,sin(E)*Y,0,1,0,zin(E)*Y,0,cos(E),0,W,0)
#define matgen_yp_deg(E,Y,W) matgen_yp_rad(RAD(E),Y,W)
#define matset_yp_deg(M,E,Y,W) matset_yp_rad(M,RAD(E),Y,W)

#define matgen_zp_rad(A,Z,H) matgen_raw(cos(A),zin(A)*Z,0,sin(A)*Z,cos(A),0,0,0,1,0,0,H)
#define matset_zp_rad(M,A,Z,H) matset_raw(M,cos(A),zin(A)*Z,0,sin(A)*Z,cos(A),0,0,0,1,0,0,H)
#define matgen_zp_deg(A,Z,H) matgen_zp_rad(RAD(A),Z,H)
#define matset_zp_deg(M,A,Z,H) matset_zp_rad(M,RAD(A),Z,H)

#define matgen_perspect(X,Y,N,F) {{cot(X),0,0,0},{0,cot(Y),0,0},{0,0,(N+F)/(N-F),-1},{0,0,(2*N*F)/(N-F),0}}
#define matset_perspect(M,X,Y,N,F) {  M[0][0] = cot(X); M[0][1] = 0; M[0][2] = 0; M[0][3] = 0; M[1][0] = 0; M[1][1] = cot(Y); M[1][2] = 0; M[1][3] = 0; M[2][0] = 0; M[2][1] = 0; M[2][2] = (N+F)/(N-F); M[2][3] = -1; M[3][0] = 0; M[3][1] = 0; M[3][2] = (2*N*F)/(N-F); M[3][3] = 0;  }

#define mat4vec4(M,V) {(M[0][0] + M[1][0] + M[2][0] + M[3][0]) * V.x,(M[0][1] + M[1][1] + M[2][1] + M[3][1]) * V.y,(M[0][2] + M[1][2] + M[2][2] + M[3][2]) * V.z,(M[0][3] + M[1][3] + M[2][3] + M[3][3]) * V.w}
#define mat4vec3(M,V) {(M[0][0] + M[1][0] + M[2][0] + M[3][0]) * V.x,(M[0][1] + M[1][1] + M[2][1] + M[3][1]) * V.y,(M[0][2] + M[1][2] + M[2][2] + M[3][2]) * V.z}

matrix mainh__matmult_4(fir,sec)
  matrix fir
  matrix sec
    {
    unsigned char xcoord = 0
    unsigned char ycoord
    matrix result
    while (xcoord < 4)
      {
      ycoord = 0
      while (ycoord < 4)
        {
        result[xcoord][ycoord] = (fir[xcoord][0] * sec[0][ycoord]) + (fir[xcoord][1] * sec[1][ycoord]) + (fir[xcoord][2] * sec[2][ycoord]) + (fir[xcoord][3] * sec[3][ycoord])
        ycoord++
        }
      xcoord++
      }
    return result
    }

div_t radf_to_deg(input)
  float input;
  {
  div_t output = div(input,60);
  
  output.quot = (output.quot % 360) - 180;
  output.quot > -180 ? NOP : output.quot = output.quot + 180
  return output
  }
#define sprintdeg(N,O) div_tmp = radf_to_deg(N); sprintf(O,"%4i*%2i'",div_tmp.quot,div_tmp.rem)
#define fprintdef(N,O) div_tmp = radf_to_deg(N); fprintf(O,"%4i*%2i'\n",div_tmp.quot,div_tmp.rem)
#define printdeg(N) div_tmp = radf_to_deg(N); printf("%4i*%2i'\n",div_tmp.quot,div_tmp.rem)

#define sprintbase(O,N) (C.base == 0 ? sprintf(O,"=%7d",CAMERA.N) : (C.base > 0 ? sprintf(O,"@%7o",CAMERA.N) : sprintf(O,"$%7x",CAMERA.N)))
#define fprintbase(O,N) (C.base == 0 ? fprintf(O,"=%7d\n",CAMERA.N) : (C.base > 0 ? fprintf(O,"@%7o\n",CAMERA.N) : fprintf(O,"$%7x\n",CAMERA.N)))
#define printbase(N) (C.base == 0 ? printf("=%7d\n",CAMERA.N) : (C.base > 0 ? printf("@%7o\n",CAMERA.N) : printf("$%7x\n",CAMERA.N)))

#define HASH5(A,B,C) ( ( ((A == ';') || (B == ';') || (C == ';') ? (short) 0x8000 : (short) 0x0000) | ((0x001f & (short) A) << 10) | ((0x001f & (short) B) << 5) | (0x001f & (short) C) )

#define SOFT_ERROR_MACRO(F,E,A) fprintf(stderr,"%s Generated a \033[95mWARNING\033[m at %s\ntext: %s\n",F,E,A); dologs ? fprintf(logfile,"%s Generated a *WARNING* at %s\ntext: %s\n",F,E,A) : NOP; printf("\n\033[94mO.o <Maybe that's something you should, uhh, take a look at?\033[m\n");
#define HARD_ERROR_MACRO(F,E,A) fprintf(stderr,"%s Threw a \033[91mFATAL ERROR\033[m at %s\nadditional info: %s\nprogram may have exited with side-effects.\nread mmap(2) and shm_open(3) for more information\n",F,E,A); dologs ? fprintf(logfile,"%s Threw a *FATAL ERROR* at %s\nadditional info: %s\nprogram may have exited with side-effects.\nread mmap(2) and shm_open(3) for more information\n",F,E,A) : NOP; printf(\n\033[94mX_X <HELP! I've fallen and I can't get up!\033[m\n"); X_HCF_X;
