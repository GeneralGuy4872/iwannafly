//need to start moveing macros and typedefs here if neccesary


#define COS_PI_8 0.9238795325112867561282
#define COS_PI_16 0.9807852804032304491262
#define COS_PI_32 0.9951847266721968862448
#define G_RATIO 1.618033988749894848205
#define SQRT_5 2.236067977499789696409
#define S_RATIO 2.414213562373095048802
#define M_TAU 6.283185307179586476925
#define LEFT -1
#define RIGHT 1

typedef signed char tern

struct bytevec
  {
  signed char x : 2
  signed char y : 2
  signed char z : 2
  signed char w : 2
  }

struct broadcolor
  {
  struct vec3 color
  struct vec2 hyper
  }

#define RAD (D) radians(D)
#define zin (N) (-1 * sin(N)) //If I ever have to redo the matgen_<foo> macros again
#define MAX (A,B) (A > B ? A : B)
#define MIN (A,B) (A < B ? A : B)
#define MINMAG (A,B) (((A < B) && (A > 0) && (B > 0)) || ((A > B) && (A < 0) && (B < 0)) ? A : B)
#define SANE (N) (N == 0 ? 1 : N)
#define SIGN (N) (N > 0 ? ((tern) 1) : (N < 0 ? ((tern) -1) : (N == 0 ? ((tern) 0) : NAN)))

//HERE BE DRAGONS. see >=cdf81b4 for full history
#define matgen_master_deg (X,Y,Z) (cos(RAD(Z))*cos(RAD(Y)),sin(RAD(Z))*cos(RAD(Y)),cos(RAD(Z))*-1*sin(RAD(Z)),0, -1*sin(RAD(Z))*cos(RAD(X))+cos(RAD(Z))*sin(RAD(Y))*sin(RAD(X)),cos(RAD(Z))*cos(RAD(X))+sin(RAD(Z))*sin(RAD(Y))*sin(RAD(X)),sin(RAD(Z))*sin(RAD(Y))*cos(RAD(X))+cos(RAD(Y))*sin(RAD(X)),0, sin(RAD(Z))*sin(RAD(X))+cos(RAD(Z))*sin(RAD(Y))*cos(RAD(X)),cos(RAD(Z))*-1*sin(RAD(X))+sin(RAD(Z))*sin(RAD(Y))*sin(RAD(X)),sin(RAD(Z))*sin(RAD(Y))*-1*sin(RAD(X))+cos(RAD(Y))*cos(RAD(X)),0, 0,0,0,1)
#define matgen_master_rad (X,Y,Z) (cos(Z)*cos(Y),sin(Z)*cos(Y),cos(Z)*-1*sin(Z),0, -1*sin(Z)*cos(X)+cos(Z)*sin(Y)*sin(X),cos(Z)*cos(X)+sin(Z)*sin(Y)*sin(X),sin(Z)*sin(Y)*cos(X)+cos(Y)*sin(X),0, sin(Z)*sin(X)+cos(Z)*sin(Y)*cos(X),cos(Z)*-1*sin(X)+sin(Z)*sin(Y)*sin(X),sin(Z)*sin(Y)*-1*sin(X)+cos(Y)*cos(X),0, 0,0,0,1)
#define matgen_x_deg (X) (1,0,0,0, 0,cos(RAD(X)),sin(RAD(X)),0, 0,-1*sin(RAD(X)),cos(RAD(X)),0, 0,0,0,1)
#define matgen_x_rad (X) (1,0,0,0, 0,cos(X),sin(X),0, 0,-1*sin(X),cos(X),0, 0,0,0,1)
#define matgen_y_deg (Y) (cos(RAD(Y)),0,-1*sin(RAD(Y)),0, 0,1,0,0, sin(RAD(Y)),0,cos(RAD(Y)),0, 0,0,0,1)
#define matgen_y_rad (Y) (cos(Y),0,-1*sin(Y),0, 0,1,0,0, sin(Y),0,cos(Y),0, 0,0,0,1)
#define matgen_z_deg (Z) (cos(RAD(Z)),sin(RAD(Z)),0,0, -1*sin(RAD(Z)),cos(RAD(Z)),0,0, 0,0,1,0, 0,0,0,1)
#define matgen_z_rad (Z) (cos(Z),sin(Z),0,0, -1*sin(Z),cos(Z),0,0, 0,0,1,0, 0,0,0,1)
#define matgen_ident (1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1)
