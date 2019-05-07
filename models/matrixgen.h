//HERE BE DRAGONS

#define matgen_master (X,Y,Z,A,P,R) (X*cos(A)*cos(P),Y*sin(A)*cos(P),Z*cos(A)*-sin(A),0, X*(-sin(A)*cos(R)+cos(A)*sin(P)*sin(R)),Y*(cos(A)*cos(R)+sin(A)*sin(P)*sin(R)),Z*(sin(A)*sin(P)*cos(R)+cos(P)*sin(R)),0, X*(sin(A)*sin(R)+cos(A)*sin(P)*cos(R)),Y*(cos(A)*-sin(R)+sin(A)*sin(P)*sin(R)),Z*(sin(A)*sin(P)*-sin(R)+cos(P)*cos(R)),0, 0,0,0,1)
#define matgen_ident (N) (N,0,0,0, 0,N,0,0, 0,0,N,0, 0,0,0,1)
#define matgen_translate (X,Y,Z) (1,0,0,0, 0,1,0,0, 0,0,1,0, X,Y,Z,1)
