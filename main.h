//need to start moveing #define-s, struct-s, and typedef-s here


//I don't know how the optimizer works and don't want to have arithmatic calculations called every time I need a constant
//M_SQRT1_2 is standard, and sqrt(1/2) = sqrt(2)/2 = cos(pi/4)
#define COS_PI_8 0.9238795325112867561282
#define COS_PI_16 0.9807852804032304491262
#define COS_PI_32 0.9951847266721968862448

//M_SQRT2 is standard
#define SQRT_5 2.236067977499789696409

#define G_RATIO 1.618033988749894848205
#define S_RATIO 2.414213562373095048802

//standard math library must provide: e, ln(2), pi, pi/2, pi/4, 2/pi, 1/pi, and several other values derived of e and pi.
//but not 2 * pi
#define TAU 6.283185307179586476925

#define FPS 30

//may need to be globaly swapped
#define LEFT -1
#define RIGHT 1

typedef signed char tern

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

struct vector2
  {
  float x
  float y
  }

struct microvector
  {
  signed char x : 2
  signed char y : 2
  signed char z : 2
  signed char w : 2
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

struct statreg
  {
  bool ground : 1
  bool wet : 1
  bool yinv : 1
  bool horiz : 1
  tern bouy : 2
  bool uv : 1
  bool infa : 1
  }

struct viewform
  {
  bool vis : 1 //0 = normal vision, 1 = falsecolor overlay
  bool dist : 1 //0 = metric, 1 = imperial
  tern speed : 2 //0 = m/s, 1 = kph, -1 = mph, -2 = ft/s
  tern base : 2 //0 = base ten, 1 = hexadecimal, -1 = octal, -2 = binary
  tern deg : 2 //0 = degrees, 1 = radians, -1 = turns, -2 = gradians
  }

struct halfbytes
  {
  unsigned char h : 4
  unsigned char l : 4
  }

struct truecolor
  {
  unsigned int r : 8
  unsigned int g : 8
  unsigned int b : 8
  unsigned int a : 8
  }

struct torusmap
  {
  signed char height[360][360]
  signed char sealevel
  struct bytevector2 start
  }
  
#define RAD(N) ((N%360)*(M_PI/180))
#define zin(N) (-1 * sin(N))
#define MAX(A,B) (A > B ? A : B)
#define MIN(A,B) (A < B ? A : B)
#define SANE(N) (N == 0 ? TRUE : N)
#define SGN(N) (N == 0 ? FALSE : (N < 0 ? (tern) -1 : TRUE))
#define FSGN(N) (SGN(N) * -1) //flipped sign

//HERE BE DRAGONS. use an editor with regular expresions here.

/*won't know if these are flipped along a '\' diagonal until I have a proof of concept build,
* have not found a clear definition on what layer of the matrix needs to be column major for opengl
* since I have to rewrite glm, may have dug too deep.*/
#define matgen_raw(A,B,C,D,E,F,G,H,I,X,Y,Z) {{A,D,G,0},{B,E,H,0},{C,F,I,0},{X,Y,Z,1}}
//generate a column-major matrix declaration from a row-major list
#define matset_raw(M,A,B,C,D,E,F,G,H,I,X,Y,Z) {  M[0][0] = A; M[0][1] = D; M[0][2] = G; M[0][3] = 0; M[1][0] = B; M[1][1] = E; M[1][2] = H; M[1][3] = 0; M[2][0] = C; M[2][1] = F; M[2][2] = I; M[2][3] = 0; M[3][0] = X; M[3][1] = Y; M[3][2] = Z; M[3][3] = 0;  }
//iterate a colomn-major matrix redefinition from a row-major list

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

#define matgen_sphere_rad(A,E,L,Z,Y) matgen_raw(cos(A)*cos(E),zin(A)*Z,cos(A)*sin(E)*Y,sin(A)*Z*cos(E),cos(A),sin(A)*Z*sin(E)*Y,zin(E)*Y,0,cos(E))
#define matset_sphere_rad(M,A,E,L,Z,Y) matset_raw(M,cos(A)*cos(E),zin(A)*Z,cos(A)*sin(E)*Y,sin(A)*Z*cos(E),cos(A),sin(A)*Z*sin(E)*Y,zin(E)*Y,0,cos(E))
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

