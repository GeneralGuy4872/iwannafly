//HERE BE DRAGONS

#define matgen_master_deg (X,Y,Z) (cos(RAD(Z))*cos(RAD(Y)),sin(RAD(Z))*cos(RAD(Y)),cos(RAD(Z))*-1*sin(RAD(Z)),0, -1*sin(RAD(Z))*cos(RAD(X))+cos(RAD(Z))*sin(RAD(Y))*sin(RAD(X)),cos(RAD(Z))*cos(RAD(X))+sin(RAD(Z))*sin(RAD(Y))*sin(RAD(X)),sin(RAD(Z))*sin(RAD(Y))*cos(RAD(X))+cos(RAD(Y))*sin(RAD(X)),0, sin(RAD(Z))*sin(RAD(X))+cos(RAD(Z))*sin(RAD(Y))*cos(RAD(X)),cos(RAD(Z))*-1*sin(RAD(X))+sin(RAD(Z))*sin(RAD(Y))*sin(RAD(X)),sin(RAD(Z))*sin(RAD(Y))*-1*sin(RAD(X))+cos(RAD(Y))*cos(RAD(X)),0, 0,0,0,1)
#define matgen_master_rad (X,Y,Z) (cos(Z)*cos(Y),sin(Z)*cos(Y),cos(Z)*-1*sin(Z),0, -1*sin(Z)*cos(X)+cos(Z)*sin(Y)*sin(X),cos(Z)*cos(X)+sin(Z)*sin(Y)*sin(X),sin(Z)*sin(Y)*cos(X)+cos(Y)*sin(X),0, sin(Z)*sin(X)+cos(Z)*sin(Y)*cos(X),cos(Z)*-1*sin(X)+sin(Z)*sin(Y)*sin(X),sin(Z)*sin(Y)*-1*sin(X)+cos(Y)*cos(X),0, 0,0,0,1)
#define matgen_x_deg (X) (1,0,0,0, 0,cos(RAD(X)),sin(RAD(X)),0, 0,-1*sin(RAD(X)),cos(RAD(X)),0, 0,0,0,1)
#define matgen_x_rad (X) (1,0,0,0, 0,cos(X),sin(X),0, 0,-1*sin(X),cos(X),0, 0,0,0,1)
#define matgen_y_deg (Y) (cos(RAD(Y)),0,-1*sin(RAD(Y)),0, 0,1,0,0, sin(RAD(Y)),0,cos(RAD(Y)),0, 0,0,0,1)
#define matgen_y_rad (Y) (cos(Y),0,-1*sin(Y),0, 0,1,0,0, sin(Y),0,cos(Y),0, 0,0,0,1)
#define matgen_z_deg (Z) (cos(RAD(Z)),sin(RAD(Z)),0,0, -1*sin(RAD(Z)),cos(RAD(Z)),0,0, 0,0,1,0, 0,0,0,1)
#define matgen_z_rad (Z) (cos(Z),sin(Z),0,0, -1*sin(Z),cos(Z),0,0, 0,0,1,0, 0,0,0,1)
#define matgen_ident (1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1)
