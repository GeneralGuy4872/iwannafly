//need to start moveing #define-s, struct-s, and typedef-s here

/* whether a variable is in ALL_CAPS or not is not a reliable indicator of if it is a macro; what it means
 * is that it is a global value that may be called (and sometimes modified) by functions safely.
 * a macro function in ALL_CAPS is a true macro, and less complicated than one that is lowercase,
 * which is a subroutine. all this is complicated by the fact that even this convoluted formatting
 * is currently inconsistant, and the terms "subroutine" and "macro function" are interchangeable
 * by definition and I have yet to establish a true boundry.
 */

#define BUFFER_MAX 512

#define __MYVERS__ "000.001.000"
#define REV_MAIN "003.000"
#define REV_JS "000.002"
#define VITALSTAT(S) "Iwannafly v"__MYVERS__", "S", Compiled on "__DATE__

#define FOREVER for (;;)

div_t div_tmp;

/* the library at <math.h> must provide:
 * M_E  M_LN2  M_LN10  M_LOG2E  M_LOG10E
 * M_PI  M_PI_2  M_PI_4  M_2_PI  M_1_PI
 * M_SQRT_2  M_SQRT1_2
 */

#define COS_PI_8 0.9238795325112867561282
#define COS_PI_16 0.9807852804032304491262
#define COS_PI_32 0.9951847266721968862448
#define SQRT_5 2.236067977499789696409
#define G_RATIO 1.618033988749894848205
#define S_RATIO 2.414213562373095048802
#define LOG_3_PI 1.041978045992185865114
#define LOG_3_E 0.9102392266268373936142
#define ONE_1_9 1.11111111111111111111111

#define FPS 30 //frames per second (hz)
static const float uSEC_FRAME = ((1.0 / FPS) * CLOCKS_PER_SEC);
static const float uSEC_STEP = 100;

#define PI_N(N) (M_PI / N)
#define PI_2_N(N) (M_PI_2 / N)

long JSAXISBUFF_ADDRESS;
signed short (*JSAXISBUFF)[8];
long JSAXISFLAG_ADDRESS;
signed char *JSAXISFLAG;
int MAIN_PID;
unsigned char RUN;

typedef int (*eventfunc)(int,int,int,const char[8]); //you know you're getting serious when you're using function pointers
typedef signed char tern;
typedef unsigned char quard;
typedef char mydate_str[24];

#ifdef __bool_true_false_are_defined
#ifndef TRUE
#define TRUE (true)
#endif /*!(TRUE)*/
#ifndef FALSE
#define FALSE (false)
#endif /*!(FALSE)*/
#else /*!(__bool_true_false_are_defined)*/
#define TRUE ((bool) 1)
#define FALSE ((bool) 0)
#endif /*__bool_true_false_are_defined*/

#define UNTRUE FALSE 
#define CORRECT TRUE
//I keep using the wrong values with inverted bools

#define TRISTATE ((tern) -1)
#define QUANTUM ((tern) -2)

#define LEFT -1
#define RIGHT 1
#define xLEFT(N) (LEFT * N)
#define xRIGHT(N) (RIGHT * N)

//VIEWRNG shall be an odd number
#define VIEWRNG 5
#define VIEWRNGmax ((VIEWRNG - 1) / 2)
#define VIEWRNGmin (VIEWRNGmax * -1)
#define VIEWRNGlim (VIEWRNGmax + 1)

#define hightfloat(N) (( (float) N - 15) * 5)

const char WEEKDAYS[8][4] = {" SUN"," MON","TUES"," WED","THUR"," FRI"," SAT","OVER"};
const char AM_PM[2][2] = {"am","pm"};

void noop () {}
#define SWYM sleep(0);
#define X_HCF_X exit(1);

typedef float matrix[4][4];

#define toggle(setting) setting = !setting;

typedef struct vector4
  {
  float x;
  float y;
  float z;
  float w;
  } vector4;

typedef struct vector3
  {
  float x;
  float y;
  float z;
  } vector3;

typedef struct camera_ang
  {
  unsigned char az;
  unsigned char alt;
  signed char z;
  unsigned char fov;
  } camera_ang;
//azimuth and altitude are taken (n % 180) * 2
//z and fov are literal

typedef struct vector2
  {
  float x;
  float y;
  } vector2;

typedef struct vectorZ
  {
  float x;
  float z;
  } vectorZ;

typedef struct ushortvector4
  {
  unsigned short x;
  unsigned short y;
  unsigned short z;
  unsigned short w;
  } ushortvector4;
//they're comfy and easy to...wait...
typedef struct ushortvector3
  {
  unsigned short x;
  unsigned short y;
  unsigned short z;
  } ushortvector3;

typedef struct ushortvector2
  {
  unsigned short x;
  unsigned short y;
  } ushortvector2;

typedef struct shortvector4
  {
  signed short x;
  signed short y;
  signed short z;
  signed short w;
  } shortvector4;

typedef struct shortvector3
  {
  signed short x;
  signed short y;
  signed short z;
  } shortvector3;

typedef struct shortvector2
  {
  signed short x;
  signed short y;
  } shortvector2;

typedef struct microvector
  {
  tern x : 2;
  tern y : 2;
  tern z : 2;
  tern w : 2;
  } microvector;

typedef struct minivector
  {
  quard x : 2;
  quard y : 2;
  quard z : 2;
  quard w : 2;
  } minivector;

typedef struct minicolor
  {
  quard r : 2;
  quard g : 2;
  quard b : 2;
  quard a : 2;
  } minicolor;

typedef struct bytevector4
  {
  unsigned int x : 8;
  unsigned int y : 8;
  unsigned int z : 8;
  unsigned int w : 8;
  } bytevector4;

typedef struct bytevector3
  {
  unsigned int x : 8;
  unsigned int y : 8;
  unsigned int z : 8;
  } bytevector3;

typedef struct bytevector2
  {
  unsigned int x : 8;
  unsigned int y : 8;
  } bytevector2;

typedef struct charvector4
  {
  signed char x : 8;
  signed char y : 8;
  signed char z : 8;
  signed char w : 8;
  } charvector4;

typedef struct charvector3
  {
  signed char x : 8;
  signed char y : 8;
  signed char z : 8;
  } charvector3;

typedef struct charvector2
  {
  signed char x : 8;
  signed char y : 8;
  } charvector2;

typedef struct halfbytes
  {
  unsigned char hi : 4;
  unsigned char lo : 4;
  } halfbytes;

typedef struct halfvector
  {
  signed char x : 4;
  signed char y : 4;
  } halfvector;

typedef struct magic_type
  {
  bool fire : 1;
  bool air : 1;
  bool water : 1;
  bool earth : 1;
  bool chaos : 1;
  bool light : 1;
  bool dark : 1;
  bool energy : 1;
  } magic_type;

typedef struct spell
  {
  unsigned int damage : 7;
  signed int recoil : 7;
  quard spread : 2; //0 = pinpoint, 1 = narrow, 2 = wide, 3 = omnidirectional
  halfbytes impact; //hi = knockback, lo = splash radius
  magic_type type;
  } spell;//these are used as arguments to a proto-magic function. spells should be const and are only defined once, in a header.

#include "spells.h"

typedef spell *spellbook[4]; //entitys can have up to 4 pointers to spells

#define FR_ONE 64
#define flfr(input) ((signed short) (input * FR_ONE))
#define frfl(input) ((float) input / FR_ONE)

typedef signed short mesurements[16];
enum mesure_index {mes_skull,mes_neck,mes_shld,mes_back,mes_humr,mes_femr,
  mes_pelv,mes_cxyx,mes_tail,mes_wing,mes_q,mes_dig,mes_fan_len,mes_fan_rad,
  mes_fan_ang};

typedef struct my_date_time
  {
  unsigned int month : 4;
  unsigned int day : 5;
  unsigned int weekday : 3;
  bool am_pm : 1;
  unsigned int hour : 5;
  unsigned int minute : 6;
  } my_date_time;

tick_tock (counter)
  my_date_time counter;
  {
  div_tmp = div(counter.minute + 1,60);
  counter.minute = div_tmp.rem;
  div_tmp = div(counter.hour + div_tmp.quot,24);
  counter.hour = div_tmp.rem;
  counter.am_pm = (div_tmp.rem / 12) % 2;
  counter.weekday = (counter.weekday + div_tmp.quot)%7; //carry in and mod, no carry out
  div_tmp = div(counter.day + div_tmp.quot,30);
  counter.day = div_tmp.rem;
  counter.month = (counter.month + div_tmp.quot) % 12;
  }

#define sprinttimedate24(N,O) sprintf(O,"%i:%i %s %i/%i",N.hour,N.minute,WEEKDAYS[N.weekday],N.day + 1,N.month + 1)
#define fprinttimedate24(N,O) fprintf(O,"%i:%i %s %i/%i\n",N.hour,N.minute,WEEKDAYS[N.weekday],N.day + 1,N.month + 1)
#define printtimedate24(N) printf("%i:%i %s %i/%i\n",N.hour,N.minute,WEEKDAYS[N.weekday],N.day + 1,N.month + 1)

#define sprinttimedate12(N,O) sprintf(O,"%i:%i%s %s %i/%i",N.hour == 12 ? 12 : N.hour % 12,N.minute,AM_PM[N.am_pm],WEEKDAYS[N.weekday],N.day + 1,N.month + 1)
#define fprinttimedate12(N,O) fprintf(O,"%i:%i%s %s %i/%i\n",N.hour == 12 ? 12 : N.hour % 12,N.minute,AM_PM[N.am_pm],WEEKDAYS[N.weekday],N.day + 1,N.month + 1)
#define printtimedate12(N) printf("%i:%i%s %s %i/%i\n",N.hour == 12 ? 12 : N.hour % 12,N.minute,AM_PM[N.am_pm],WEEKDAYS[N.weekday],N.day + 1,N.month + 1)

typedef struct statreg
  {
  bool ground : 1;
  bool wet : 1;
  bool horiz : 1;
  bool caster : 1;
  bool locks : 1;
  bool gills : 1;
  bool wings : 1;
  bool fireproof : 1;
  } statreg;

typedef struct sensereg
  {
  bool uv : 1;
  bool infra : 1;
  bool trouble : 1;
  bool weather : 1;
  bool good : 1;
  bool evil : 1;
  bool law : 1;
  bool chaos : 1;
  } sensereg;

typedef struct viewform
  {
  tern base : 2;
  tern deg : 2;
  tern dist : 2;
  bool time : 1;
  bool uv : 1;
  } viewform;

typedef struct shape
  {
  vector3 (*vertlist)[];
  unsigned char (*bytecode)[];
  unsigned char inum;
  unsigned char vnum;
  } shape;

typedef struct event_props
  {
  unsigned short rol : 9;
  unsigned short pit : 9;
  unsigned short yaw : 9;
  bool r : 1;
  bool g : 1;
  bool b : 1;
  quard shape : 2;
  } event_props;

typedef struct mainh_event
  {
  struct mainh_event *prev;
  struct mainh_event *next;
  shortvector3 coords; //fraction
  bytevector3 size;
  event_props attrib; //shape 0 = disk of x, shape 1 = sphere of x, shape 2 = cylinder xz, shape 3 = cuboid
  unsigned short durat; //0 means until triggered, otherwise in _seconds_
  struct eventfunc *ontrigger; //the function that the event triggers
  int params[3]; //intended as arguments to switches in ontrigger; actual args are globals with fixed names, like CAMERA->points.
  const char textfile[8]; //the unique filename of the file containing the text for ontrigger. is opened, read, and closed in tight context.
  } mainh_event;

#include "event_funcs.h"

typedef struct truecolor
  {
  unsigned int r : 8;
  unsigned int g : 8;
  unsigned int b : 8;
  unsigned int a : 8;
  } truecolor;

typedef struct highcolor
  {
  unsigned int r : 5;
  unsigned int g : 6;
  unsigned int b : 5;
  } highcolor;

typedef struct lowcolor
  {
  unsigned int r : 3;
  unsigned int g : 3;
  unsigned int b : 2;
  } lowcolor;

#define two_to_eight(N) (N == 0 ? 0x00 : (N == 1 ? 0x55 : (N == 2 ? 0xAA : 0xFF)))
#define color6(R,G,B,A) {two_to_eight(R),two_to_eight(G),two_to_eight(B),two_to_eight(A)}

typedef struct torusmap
  {
  unsigned char dots[360][360];
  unsigned char sealevel;
  /* unsigned char water[360][360];
   * unsigned char wind[360][360]; //each sector has wind in direction of halfvector
   */
  vector2 start[8];
  } torusmap;

#define char_to_hv(N) (halfvector){(N | 0xF0) >> 4 , N | 0x0F}
#define char_to_hb(N) (halfbytes){(N | 0xF0) >> 4 , N | 0x0F}

enum start_index {st_city,st_village,st_forest,st_mountains,st_mines,
	st_caves,st_seaside,st_underwater};

#define MAX(A,B) (A > B ? A : B)
#define MIN(A,B) (A < B ? A : B)
#define ABSMIN(A,B) (fabs(A) < fabs(B) ? A : B)
#define CLAMP(N,A,B) MIN(MAX(N,A),B)
#define RAD(N) (fmod(N,360)*(M_PI/180))
#define DEG(N) (N*(180/M_PI))
#define R_GON(N) (N*(200/M_PI))
#define D_GON(N) (fmod(N,360)*(10/9))
#define G_RAD(N) (fmod(N,400)*(M_PI/200))
#define G_DEG(N) (fmod(N,400)*(9/10))
#define R_BPI(N) (N/M_PI)
#define zin(N) NEG(sin(N))
#define bos(N) NEG(cos(N))
#define SANE(N) (N == 0 ? 1 : N)
#define SGN(N) (N == 0 ? 0 : (N < 0 ? -1 : (N > 0 ? 1 : -2)))
#define TOSGN(N) ( N < 0 ? -1 : 0 )
#define NEG(N) (-1 * (N))
#define bitlength(N) ( (unsigned int) (floor(log2(N) - 1)) )
#define fnextline(F) fscanf(F,"%*[^\n]s");
#define nextline scanf("%*[^\n]s");

#define BASECOORD(M) M.stat.horiz ? (vector3){M.pos.x,M.pos.y,M.pos.z} : vecadd((vector3){M.pos.x,M.pos.y,M.pos.z},matmult((matrix)matgen_master_deg(M.rot.z,M.rot.y,M.rot.x,1,1,1),{0,0,M.dembones.x})
#define EYECOORD(M) vecadd((vector3){M.pos.x,M.pos.y,M.pos.z},(M.stat.horiz ? matmult((matrix)matgen_xeuler_deg(M.rot.z,M.rot.y,M.rot.x,1,1,1),(vector3){M.dembones->hitbox.x - (M.dembones->off.x + M.dembones->off.y),0,0}) : matmult((matrix)matgen_master_deg(M.rot.z,M.rot.y,M.rot.x,1,1,1),(vector3){0,0,M.dembones->hitbox.z - M.dembones->off.y})))

//HERE BE DRAGONS. use an editor with regular expresions here.

/* won't know if these are flipped along a '\' diagonal until I have a proof of concept build,
 * have not found a clear definition on what layer of the matrix needs to be column major for opengl
 * since I have to rewrite glm, may have dug too deep.
 */
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

#define matgen_super_zeuler_rad(A,E,R,X,Y,Z,B,C,D) matgen_raw(((cos(A)*cos(E)*cos(R))+(zin(A)*Z*sin(R)*X))*B,(cos(A)*cos(E)*zin(R)*X)+(zin(A)*Z*cos(R)),cos(A)*cos(E)*Y,(sin(A)*Z*cos(E)*cos(R))+(cos(A)*sin(R)*X),((sin(A)*Z*cos(E)*zin(R)*X)+(cos(A)*cos(R)))*C,sin(A)*Z*sin(E)*Y,zin(E)*Y,zin(E)*Y*zin(R)*X,cos(E)*D,0,0,0)
#define matset_super_zeuler_rad(M,A,E,R,X,Y,Z,B,C,D) matset_raw(M,((cos(A)*cos(E)*cos(R))+(zin(A)*Z*sin(R)*X))*B,(cos(A)*cos(E)*zin(R)*X)+(zin(A)*Z*cos(R)),cos(A)*cos(E)*Y,(sin(A)*Z*cos(E)*cos(R))+(cos(A)*sin(R)*X),((sin(A)*Z*cos(E)*zin(R)*X)+(cos(A)*cos(R)))*C,sin(A)*Z*sin(E)*Y,zin(E)*Y,zin(E)*Y*zin(R)*X,cos(E)*D,0,0,0)
#define matgen_super_zeuler_deg(A,E,R,X,Y,Z,B,C,D) matgen_super_zeuler_rad(RAD(A),RAD(E),RAD(R),X,Y,Z,B,C,D)
#define matset_super_zeuler_deg(M,A,E,R,X,Y,Z,B,C,D) matset_super_zeuler_rad(M,RAD(A),RAD(E),RAD(R),X,Y,Z,B,C,D)

#define matgen_zeuler_rad(A,E,R,X,Y,Z) matgen_raw((cos(A)*cos(E)*cos(R))+(zin(A)*Z*sin(R)*X),(cos(A)*cos(E)*zin(R)*X)+(zin(A)*Z*cos(R)),cos(A)*cos(E)*Y,(sin(A)*Z*cos(E)*cos(R))+(cos(A)*sin(R)*X),(sin(A)*Z*cos(E)*zin(R)*X)+(cos(A)*cos(R)),sin(A)*Z*sin(E)*Y,zin(E)*Y,zin(E)*Y*zin(R)*X,cos(E),0,0,0)
#define matset_zeuler_rad(M,A,E,R,X,Y,Z) matset_raw(M,(cos(A)*cos(E)*cos(R))+(zin(A)*Z*sin(R)*X),(cos(A)*cos(E)*zin(R)*X)+(zin(A)*Z*cos(R)),cos(A)*cos(E)*Y,(sin(A)*Z*cos(E)*cos(R))+(cos(A)*sin(R)*X),(sin(A)*Z*cos(E)*zin(R)*X)+(cos(A)*cos(R)),sin(A)*Z*sin(E)*Y,zin(E)*Y,zin(E)*Y*zin(R)*X,cos(E),0,0,0)
#define matgen_zeuler_deg(A,E,R,X,Y,Z) matgen_zeuler_rad(RAD(A),RAD(E),RAD(R),X,Y,Z)
#define matset_zeuler_deg(M,A,E,R,X,Y,Z) matset_zeuler_rad(M,RAD(A),RAD(E),RAD(R),X,Y,Z)

#define matgen_super_xeuler_rad(R,E,A,X,Y,Z,B,C,D) matgen_raw(cos(E)*B,sin(E)*Y*sin(A)*Z,sin(E)*Y*cos(A),zin(R)*X*zin(E)*Y,((cos(R)*cos(A))+(zin(R)*X*cos(E)*sin(A)*Z))*C,(cos(R)*zin(A)*Z)+(zin(R)*X*cos(E)*cos(A)),cos(R)*zin(E)*Y,(sin(R)*X*cos(A))+(cos(R)*cos(E)*sin(A)*Z),((sin(R)*X*zin(A)*Z)+(cos(R)*cos(E)*cos(A)))*D,0,0,0)
#define matset_super_xeuler_rad(M,R,E,A,X,Y,Z,B,C,D) matset_raw(M,cos(E)*B,sin(E)*Y*sin(A)*Z,sin(E)*Y*cos(A),zin(R)*X*zin(E)*Y,((cos(R)*cos(A))+(zin(R)*X*cos(E)*sin(A)*Z))*C,(cos(R)*zin(A)*Z)+(zin(R)*X*cos(E)*cos(A)),cos(R)*zin(E)*Y,(sin(R)*X*cos(A))+(cos(R)*cos(E)*sin(A)*Z),((sin(R)*X*zin(A)*Z)+(cos(R)*cos(E)*cos(A)))*D,0,0,0)
#define matgen_super_xeuler_deg(R,E,A,X,Y,Z,B,C,D) matgen_super_xeuler_rad(RAD(A),RAD(E),RAD(R),X,Y,Z,B,C,D)
#define matset_super_xeuler_deg(M,R,E,A,X,Y,Z,B,C,D) matset_super_xeuler_rad(M,RAD(A),RAD(E),RAD(R),X,Y,Z,B,C,D)

#define matgen_xeuler_rad(R,E,A,X,Y,Z) matgen_raw(cos(E),sin(E)*Y*sin(A)*Z,sin(E)*Y*cos(A),zin(R)*X*zin(E)*Y,(cos(R)*cos(A))+(zin(R)*X*cos(E)*sin(A)*Z),(cos(R)*zin(A)*Z)+(zin(R)*X*cos(E)*cos(A)),cos(R)*zin(E)*Y,(sin(R)*X*cos(A))+(cos(R)*cos(E)*sin(A)*Z),(sin(R)*X*zin(A)*Z)+(cos(R)*cos(E)*cos(A)),0,0,0)
#define matset_xeuler_rad(M,R,E,A,X,Y,Z) matset_raw(M,cos(E),sin(E)*Y*sin(A)*Z,sin(E)*Y*cos(A),zin(R)*X*zin(E)*Y,(cos(R)*cos(A))+(zin(R)*X*cos(E)*sin(A)*Z),(cos(R)*zin(A)*Z)+(zin(R)*X*cos(E)*cos(A)),cos(R)*zin(E)*Y,(sin(R)*X*cos(A))+(cos(R)*cos(E)*sin(A)*Z),(sin(R)*X*zin(A)*Z)+(cos(R)*cos(E)*cos(A)),0,0,0)
#define matgen_xeuler_deg(R,E,A,X,Y,Z) matgen_xeuler_rad(RAD(A),RAD(E),RAD(R),X,Y,Z)
#define matset_xeuler_deg(M,R,E,A,X,Y,Z) matset_xeuler_rad(M,RAD(A),RAD(E),RAD(R),X,Y,Z)

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

#define matgen_perspect(X,Y,N,F) {{cot(X),0,0,0},{0,cot(Y),0,0},{0,0,(N+F)/(N-F),-1},{0,0,(2*N*F)/(N-F),0}}
#define matset_perspect(M,X,Y,N,F) {  M[0][0] = cot(X); M[0][1] = 0; M[0][2] = 0; M[0][3] = 0; M[1][0] = 0; M[1][1] = cot(Y); M[1][2] = 0; M[1][3] = 0; M[2][0] = 0; M[2][1] = 0; M[2][2] = (N+F)/(N-F); M[2][3] = -1; M[3][0] = 0; M[3][1] = 0; M[3][2] = (2*N*F)/(N-F); M[3][3] = 0;  }

vector3 matmult(rot,vec)
	matrix rot;
	vector3 vec;
	{
	vector3 output;
	output.x = (rot[0][0] * vec.x)+(rot[0][1] * vec.y)+(rot[0][2] * vec.z);
	output.y = (rot[1][0] * vec.x)+(rot[1][1] * vec.y)+(rot[1][2] * vec.z);
	output.z = (rot[2][0] * vec.x)+(rot[2][1] * vec.y)+(rot[2][2] * vec.z);
	return output;
	}

vector3 vecadd(vecbase,vecoff)
	vector3 vecbase;
	vector3 vecoff;
	{
	vector3 output;
	output.x = vecbase.x + vecoff.x;
	output.y = vecbase.y + vecoff.y;
	output.z = vecbase.z + vecoff.z;
	return output;
	}

div_t radf_to_deg(input)
  float input;
  {
  div_t output = div(input,60);
  
  output.quot = (output.quot % 360) - 180;
  if (output.quot > -180) output.quot = output.quot + 360;
  return output;
  }

#define sprintdeg(N,O) div_tmp = radf_to_deg(N); sprintf(O,"%4i*%2i'",div_tmp.quot,div_tmp.rem)
#define fprintdef(N,O) div_tmp = radf_to_deg(N); fprintf(O,"%4i*%2i'\n",div_tmp.quot,div_tmp.rem)
#define printdeg(N) div_tmp = radf_to_deg(N); printf("%4i*%2i'\n",div_tmp.quot,div_tmp.rem)

#define sprintbase(O,N) (CAMERA.base == 0 ? sprintf(O,"=%7d",CAMERA.N) : (CAMERA.base > 0 ? sprintf(O,"@%7o",CAMERA.N) : sprintf(O,"$%7x",CAMERA.N)))
#define fprintbase(O,N) (CAMERA.base == 0 ? fprintf(O,"=%7d\n",CAMERA.N) : (CAMERA.base > 0 ? fprintf(O,"@%7o\n",CAMERA.N) : fprintf(O,"$%7x\n",CAMERA.N)))
#define printbase(N) (CAMERA.base == 0 ? printf("=%7d\n",CAMERA.N) : (CAMERA.base > 0 ? printf("@%7o\n",CAMERA.N) : printf("$%7x\n",CAMERA.N)))

#define HASH5(A,B,C) ( (( (A <= ' ') || (A == '#') || (A == ';') || (A == '[') ) ? (short) 0xFFFFFFFF : (short) 0x00000000) | ((0x0000001f & (short) A) << 10) | ((0x0000001f & (short) B) << 5) | (0x0000001f & (short) C) )
#define STR_INT(A,B,C,D) (unsigned int) ( ((A | 0x000000FF) << 24) | ((B | 0x000000FF) << 16) | ((C | 0x000000FF) << 8) | (D | 0x000000FF) )

file_cat (path)
  const char *path;
  {
  FILE *tmp = fopen(path,"r");
  int lines;
  if (tmp == NULL)
    {
    return -1;
    }
  char tmpbuffer[BUFFER_MAX];
  for (bool n = TRUE;n;noop())
    {
    if (fgets(tmpbuffer,BUFFER_MAX,tmp) == NULL)
      {
      n = FALSE;
      }
    else
      {
      printf(tmpbuffer);
      lines++;
      }
    }
  fclose(tmp);
  return lines;
  }

typedef struct movement_buffer_t
  {
  float x;
  float y;
  float yaw;
  float pit;
  float lt;
  float rt;
  } movement_buffer_t;

movement_buffer_t MOVEBUFFER;
#define MOVEBUFFER_z ((MOVEBUFFER.rt + MOVEBUFFER.lt) / 2)
#define MOVEBUFFER_rol (MOVEBUFFER.rt - MOVEBUFFER.lt)

fetchJSAXIS ()
  {
  while (JSAXISFLAG >= 0)
    {
    SWYM
    }
  (*JSAXISFLAG)++;
  MOVEBUFFER.x = (float) (*JSAXISBUFF)[1] / -SHRT_MAX;
  MOVEBUFFER.y = (float) (*JSAXISBUFF)[0] / SHRT_MAX;
  MOVEBUFFER.pit = (float) (*JSAXISBUFF)[5] / -SHRT_MAX;
  MOVEBUFFER.yaw = (float) (*JSAXISBUFF)[4] / SHRT_MAX;
  MOVEBUFFER.lt = ((float) (*JSAXISBUFF)[3] + SHRT_MIN) / USHRT_MAX;
  MOVEBUFFER.rt = ((float) (*JSAXISBUFF)[6] + SHRT_MIN) / USHRT_MAX;
  (*JSAXISFLAG)--;
  }
  
struct charvector4 CAMBUFFER;

#define _$_ "\xA4"
//bypass localization for now by specifying currency symbol is whatever this generates.

#define SOFT_ERROR_MACRO fprintf(stderr,"SOFT ERROR, file:%s line:%d\n",__FILE__,__LINE__); printf("\a");
#define HARD_ERROR_MACRO fprintf(stderr,"HARD ERROR, file:%s line:%d\n",__FILE__,__LINE__); printf("\a"); X_HCF_X

typedef struct bone
  {
  struct bone *up;
  struct bone *prev;
  struct bone *next;
  charvector3 off;
  vector3 len;
  matrix base;
  matrix curr;
  truecolor color;
  bool ultraviolet;
  bool drawline;
  struct shape *geom;
  } bone;

typedef struct skeleton
  {
  bone *root;
  vectorZ hitbox;
  vector2 off;
  minicolor fg;
  minicolor bg;
  } skeleton;

typedef struct thing
  {
  struct thing *prev;
  struct thing *next;
  matrix rot;
  struct shape *geom;
  } thing;

typedef struct entity
	{
	struct entity *prev;
	struct entity *next;
	vector4 pos;
	vector3 rot;
	vector3 Velo;
	vector3 Torq;
	statreg stat;
		/* bool ground
		 * bool wet
		 * bool horiz
		 * bool caster
		 * bool wings
		 * bool locks
		 * bool gills - deferred
		 * bool fireproof - deferred
		 */
	sensereg detects;
		/* bool uv
		 * bool infra - deferred
		 * bool trouble - deferred
		 * bool weather - deferred
		 * bool good - deferred
		 * bool evil - deferred
		 * bool law - deferred
		 * bool chaos deferred
		 */
	charvector2 alignment;
		/* x = lawful/chaotic
		 * y = good/evil
		 * $90<=n<=$FE : evil/chaotic
		 * $20<=n<=$7F : good/lawful
		 * $00<=n<=$1F : neutral
		 * $80<=n<=$8F : ^
		 *   n == $FF  : mindless
		 */
	unsigned short health;
	float Ff;
	unsigned short m;
	unsigned short density;
	struct vector3 *Drag; //x = ground, y = water, z = air
	struct vector3 *Fa; //x = ground, y = water, z = air
	struct skeleton *dembones;
	spellbook spells;
	//aside from half-floats or fixed-points, niether of which I have, this is as small as it gets...
	} entity;

typedef struct cameratype
	{
	camera_ang coord;
	viewform format;
		/*
		int base 0 = dec, 1 = oct, -n = hex
		rotation base 0 = deg, 1 = rad base pi, -1 = gradians, -2 rad base 10
		distance units 0 = m, 1 = km, -1 = cm, -2 = ft
		
		(latitude/longitude is always in degrees* minutes' format)
		infrared
		uv

		exact conversion of 1ft = 30cm
		*/
	unsigned short gold;
	unsigned short points;
	} cameratype;

typedef struct worldtype
	{
	struct torusmap *map;
	struct entity *ent;
	struct entity *ent_tail;
	struct thing *scen;
	struct thing *scen_tail;
	struct mainh_event *evnt;
	struct mainh_event *evnt_tail;
	struct cameratype *cam;
	} worldtype;

torusmap planet1;
cameratype camera1;
worldtype WORLD = {&planet1,NULL,NULL,NULL,NULL,NULL,NULL,&camera1};
#define MAP WORLD.map
#define PLAYER WORLD.ent
#define CAMERA WORLD.cam

#define mainh__arralloc(A,N,S) for (int n = 0;n<N;n++) {A[n] = malloc(S);}
#define mainh__arrfree(A,N) for (int n = N;n>0;n--) {free(A[n-1]);}

#define mainh__fork__reap (getppid() == MAIN_PID) //needs more cowbell

#ifdef __gl_h_
void __mainhTranslatef(vec)
	vector3 vec;
	{
	glTranslatef(vec.x,vec.y,vec.z);
	}
#define mainhTranslatef(V) __mainhTranslatef((vector3)V)

void raw_mainhMultMatrixf(mat)
	matrix mat;
	{
	glMultMatrixf((const float *)mat);
	}
#define mainhMultMatrixf(M) raw_mainhMultMatrixf((matrix)M)

void mainhLoadMatrixf(mat)
	matrix mat;
	{
	glLoadMatrixf((const float *)mat);
	}
#else
#error opengl is required
#endif

#include "models/all.h"
