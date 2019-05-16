//need to start moveing #define-s, struct-s, and typedef-s here

//M_SQRT1_2 is standard, and sqrt(1/2) = sqrt(2)/2 = cos(pi/4)
#define COS_PI_8 0.9238795325112867561282
#define COS_PI_16 0.9807852804032304491262
#define COS_PI_32 0.9951847266721968862448

//M_SQRT2 is standard
#define SQRT_5 2.236067977499789696409

#define G_RATIO 1.618033988749894848205
#define S_RATIO 2.414213562373095048802

//standard math library provides e, ln(2), pi, pi/2, pi/4, 2/pi, 1/pi, and several other values derived of e and pi.
//but not 2 * pi. this works out to be exactly twice the value of M_PI, but I don't know how the optimizer works
//and don't want to multiply every time. same for the above numbers, but the operations are more expensive
#define M_TAU 6.283185307179586476925

//may need to be globaly swapped
#define LEFT -1
#define RIGHT 1
#define TOWARDS -1
#define AWAY 1

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

struct bytevector
  {
  unsigned int x : 8
  unsigned int y : 8
  unsigned int z : 8
  unsigned int w : 8
  }

struct truecolor
  {
  unsigned int r : 8
  unsigned int g : 8
  unsigned int b : 8
  unsigned int a : 8
  }

struct hicolor //I heard this was popular again. what do you mean that's something else?!
  {
  unsigned char r : 5
  unsigned char g : 5
  unsigned char b : 5
  bool a : 1
  }

#define RAD(N) ((N%360)*(M_PI/180))
#define zin(N) (-1 * sin(N))
#define MAX(A,B) (A > B ? A : B)
#define MIN(A,B) (A < B ? A : B)
#define SANE(N) (N == 0 ? TRUE : N)
#define SGN(N) (N == 0 ? FALSE : (N < 0 ? (tern) -1 : TRUE))
#difine FSGN(N) (SGN(N) * -1) //flipped sign

//HERE BE DRAGONS.
#define matgen_raw(A,B,C,D,E,F,G,H,I,X,Y,Z) {{A,D,G,0},{B,E,H,0},{C,F,I,0},{X,Y,Z,1}}
//generate a column-major matrix declaration from a row-major list
#define matset_raw(N,A,B,C,D,E,F,G,H,I,X,Y,Z) {  N[0][0] = A; N[0][1] = D; N[0][2] = G; N[0][3] = 0; N[1][0] = B; N[1][1] = E; N[1][2] = H; N[1][3] = 0; N[2][0] = C; N[2][1] = F; N[2][2] = I; N[2][3] = 0; N[3][0] = X; N[3][1] = Y; N[3][2] = Z; N[3][3] = 0;  }
//iterate a colomn-major matrix redefinition from a row-major list

#define matgen_ident matgen_raw(1,0,0,0,1,0,0,0,1,0,0,0)
#define matgen_translate(L,W,H) matgen_raw(1,0,0,0,1,0,0,0,1,L,W,H)
#define matgen_reflect(X,Y,Z) matgen_raw(X,0,0,0,Y,0,0,0,Z,0,0,0)
#define matgen_transform(X,Y,Z,L,W,H) matgen_raw(X,0,0,0,Y,0,0,0,Z,L,W,H)
#define matset_ident(N) matset_raw(N,1,0,0,0,1,0,0,0,1,0,0,0)
#define matgen_translate(N,L,W,H) matset_raw(N,1,0,0,0,1,0,0,0,1,L,W,H)
#define matgen_reflect(N,X,Y,Z) matset_raw(N,X,0,0,0,Y,0,0,0,Z,0,0,0)
#define matgen_transform(N,X,Y,Z,L,W,H) matset_raw(N,X,0,0,0,Y,0,0,0,Z,L,W,H)

#define matgen_master_rad(A,P,R,X,Y,Z) matgen_raw(cos(A)*cos(P),(zin(A)*Z*cos(R))+(cos(A)*sin(P)*Y*sin(R)*X),(zin(A)*Z*zin(R)*X)+(cos(A)*sin(P)*Y*cos(R)),sin(A)*Z*cos(P),(cos(A)*cos(R))+(sin(A)*Z*sin(P)*Y*sin(R)*X),(cos(A)*zin(R)*X)+(sin(A)*Z*sin(P)*Y*cos(R)),zin(P)*Y,sin(R)*X*cos(P),cos(P)*cos(R))
#define matset_master_rad(N,A,P,R,X,Y,Z) matset_raw(N,cos(A)*cos(P),(zin(A)*Z*cos(R))+(cos(A)*sin(P)*Y*sin(R)*X),(zin(A)*Z*zin(R)*X)+(cos(A)*sin(P)*Y*cos(R)),sin(A)*Z*cos(P),(cos(A)*cos(R))+(sin(A)*Z*sin(P)*Y*sin(R)*X),(cos(A)*zin(R)*X)+(sin(A)*Z*sin(P)*Y*cos(R)),zin(P)*Y,sin(R)*X*cos(P),cos(P)*cos(R))
#define matgen_master_deg(A,P,R,X,Y,Z) matgen_master_rad(RAD(A),RAD(P),RAD(R),X,Y,Z)
#define matset_master_deg(N,A,P,R,X,Y,Z) matset_master_rad(N,RAD(A),RAD(P),RAD(R),X,Y,Z)

#define matgen_sphere_rad(A,E,L,Z,Y) matgen_raw(cos(A)*cos(E),zin(A)*Z,cos(A)*sin(E)*Y,sin(A)*Z*cos(E),cos(A),sin(A)*Z*sin(E)*Y,zin(E)*Y,0,cos(E))
#define matset_sphere_rad(N,A,E,L,Z,Y) matset_raw(N,cos(A)*cos(E),zin(A)*Z,cos(A)*sin(E)*Y,sin(A)*Z*cos(E),cos(A),sin(A)*Z*sin(E)*Y,zin(E)*Y,0,cos(E))
#define matgen_sphere_deg(A,E,L,Z,Y) matgen_sphere_rad(RAD(A),RAD(E),L,Z,Y)
#define matset_sphere_deg(N,A,E,L,Z,Y) matset_sphere_rad(N,RAD(A),RAD(E),L,Z,Y)

#define matgen_x_rad(R,X) matgen_raw(1,0,0,0,cos(R),zin(R)*X,0,sin(R)*X,cos(R),0,0,0)
#define matset_x_rad(N,R,X) matset_raw(N,1,0,0,0,cos(R),zin(R)*X,0,sin(R)*X,cos(R),0,0,0)
#define matgen_x_deg(R,X) matgen_x_rad(RAD(R),X)
#define matset_x_deg(N,R,X) matset_x_rad(N,RAD(R),X)

#define matgen_y_rad(P,Y) matgen_raw(cos(P),0,sin(P)*Y,0,1,0,zin(P)*Y,0,cos(P),0,0,0)
#define matset_y_rad(N,P,Y) matset_raw(N,cos(P),0,sin(P)*Y,0,1,0,zin(P)*Y,0,cos(P),0,0,0)
#define matgen_y_deg(P,Y) matgen_y_rad(RAD(P),Y)
#define matset_y_deg(N,P,Y) matset_y_rad(N,RAD(P),Y)

#define matgen_z_rad(A,Z) matgen_raw(cos(A),zin(A)*Z,0,sin(A)*Z,cos(A),0,0,0,1,0,0,0)
#define matset_z_rad(N,A,Z) matset_raw(N,cos(A),zin(A)*Z,0,sin(A)*Z,cos(A),0,0,0,1,0,0,0)
#define matgen_z_deg(A,Z) matgen_z_rad(RAD(A),Z)
#define matset_z_deg(N,A,Z) matset_z_rad(N,RAD(A),Z)
