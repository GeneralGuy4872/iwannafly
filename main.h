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
//but not 2 * pi.
#define M_TAU 6.283185307179586476925

//may need to be reversed globaly
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

struct bytevec
  {
  signed char x : 2
  signed char y : 2
  signed char z : 2
  signed char w : 2
  }

struct intvector4
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

struct hicolor
  {
  unsigned char r : 5
  unsigned char g : 5
  unsigned char b : 5
  bool a : 1
  }

struct webcolor
  {
  unsigned char r : 4
  unsigned char g : 4
  unsigned char b : 4
  unsigned char a : 4
  }

#define RAD(D) radians(D)
#define zin(N) (-1 * sin(N))
#define MAX(A,B) (A > B ? A : B)
#define MIN(A,B) (A < B ? A : B)
#define ABSMIN(A,B) ( A != 0 ? (((A < B) && (A > 0) || ((A > B) && (A < 0)) ? A : B) : 0)
#define SANE(N) (N == 0 ? 1 : N)
#define SIGN(N) (N > 0 ? ((tern) 1) : (N < 0 ? ((tern) -1) : (N == 0 ? ((tern) 0) : NAN)))

//HERE BE DRAGONS.
#define matgen_master_deg(X,Y,Z) {{cos(RAD(Z))*cos(RAD(Y)),sin(RAD(Z))*cos(RAD(Y)),cos(RAD(Z))*zin(RAD(Z)),0},{zin(RAD(Z))*cos(RAD(X))+cos(RAD(Z))*sin(RAD(Y))*sin(RAD(X)),cos(RAD(Z))*cos(RAD(X))+sin(RAD(Z))*sin(RAD(Y))*sin(RAD(X)),sin(RAD(Z))*sin(RAD(Y))*cos(RAD(X))+cos(RAD(Y))*sin(RAD(X)),0},{sin(RAD(Z))*sin(RAD(X))+cos(RAD(Z))*sin(RAD(Y))*cos(RAD(X)),cos(RAD(Z))*zin(RAD(X))+sin(RAD(Z))*sin(RAD(Y))*sin(RAD(X)),sin(RAD(Z))*sin(RAD(Y))*zin(RAD(X))+cos(RAD(Y))*cos(RAD(X)),0},{0,0,0,1}}
#define matgen_x_deg(X) {{1,0,0,0},{0,cos(RAD(X)),sin(RAD(X)),0},{0,zin(RAD(X)),cos(RAD(X)),0},{0,0,0,1}}
#define matgen_y_deg(Y) {{cos(RAD(Y)),0,zin(RAD(Y)),0},{0,1,0,0},{sin(RAD(Y)),0,cos(RAD(Y)),0},{0,0,0,1}}
#define matgen_z_deg(Z) {{cos(RAD(Z)),sin(RAD(Z)),0,0},{zin(RAD(Z)),cos(RAD(Z)),0,0},{0,0,1,0},{0,0,0,1}}
#define matgen_ident {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}

#define matset_master_deg(N,X,Y,Z) N[0][0] = cos(RAD(Z))*cos(RAD(Y)); N[0][1] = sin(RAD(Z))*cos(RAD(Y)); N[0][2] = cos(RAD(Z))*zin(RAD(Z)); N[0][3] = 0; N[1][0] = zin(RAD(Z))*cos(RAD(X))+cos(RAD(Z))*sin(RAD(Y))*sin(RAD(X)); N[1][1] cos(RAD(Z))*cos(RAD(X))+sin(RAD(Z))*sin(RAD(Y))*sin(RAD(X)); N[1][2] = sin(RAD(Z))*sin(RAD(Y))*cos(RAD(X))+cos(RAD(Y))*sin(RAD(X)); N[1][3] 0; N[2][0] = sin(RAD(Z))*sin(RAD(X))+cos(RAD(Z))*sin(RAD(Y))*cos(RAD(X)); N[2][1] = cos(RAD(Z))*zin(RAD(X))+sin(RAD(Z))*sin(RAD(Y))*sin(RAD(X)); N[2][2] = sin(RAD(Z))*sin(RAD(Y))*zin(RAD(X))+cos(RAD(Y))*cos(RAD(X)); N[2][3] = 0; N[3][0] = 0; N[3][1] = 0; N[3][2] = 0; N[3][3] = 1
#define matset_x_deg(N,X) N[0][0] = 1; N[0][1] = 0; N[0][2] = 0; N[0][3] = 0; N[1][0] = 0; N[1][1] = cos(RAD(X)); N[1][2] = sin(RAD(X)); N[1][3] = 0; N[2][0] = 0; N[2][1] = zin(RAD(X)); N[2][2] = cos(RAD(X)); N[2][3] = 0; N[3][0] = 0; N[3][1] = 0; N[3][2] = 0; N[3][3] = 1
#define matset_y_deg(N,Y) N[0][0] = cos(RAD(Y)); N[0][1] = 0; N[0][2] = zin(RAD(Y)); N[0][3] = 0; N[1][0] = 0; N[1][1] = 1; N[1][2] = 0; N[1][3] = 0; N[2][0] = sin(RAD(Y)); N[2][1] = 0; N[2][2] = cos(RAD(Y)); N[2][3] = 0; N[3][0] = 0; N[3][1] = 0; N[3][2] = 0; N[3][3] = 1
#define matset_z_deg(N,Z) N[0][0] = cos(RAD(Z)); N[0][1] = sin(RAD(Z)); N[0][2] = 0; N[0][3] = 0; N[1][0] = zin(RAD(Z)); N[1][1] = cos(RAD(Z)); N[1][2] = 0; N[1][3] = 0; N[2][0] = 0; N[2][1] = 0; N[2][2] = 1; N[2][3] = 0; N[3][0] = 0; N[3][1] = 0; N[3][2] = 0; N[3][3] = 1
#define matset_raw(N,A,B,C,D,E,F,G,H,I,J,K,L,W,X,Y,Z) N[0][0] = A; N[0][1] = B; N[0][2] = C; N[0][3] = D; N[1][0] = E; N[1][1] = F; N[1][2] = G; N[1][3] = H; N[2][0] = I; N[2][1] = J; N[2][2] = K; N[2][3] = L; N[3][0] = W; N[3][1] = X; N[3][2] = Y; N[3][3] = Z
#define matreset(N) N[0][0] = 1; N[0][1] = 0; N[0][2] = 0; N[0][3] = 0; N[1][0] = 0; N[1][1] = 1; N[1][2] = 0; N[1][3] = 0; N[2][0] = 0; N[2][1] = 0; N[2][2] = 1; N[2][3] = 0; N[3][0] = 0; N[3][1] = 0; N[3][2] = 0; N[3][3] = 1
