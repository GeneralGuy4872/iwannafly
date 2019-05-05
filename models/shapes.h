//HERE BE DRAGONS
//X⇗ Y→ Z↑ for now, will probably change
//unroll the arrays so that each vec3 is on a seperate row while editing, but put them back where you found them when done

float hr2 = root(2) / 2; //Half Root 2

#define bone_octo(R) {( (R,0,0) , (0,R,0) , (0,0,R) ),( (R,0,0) , (0,R,0) , (0,0,-R) ),( (R,0,0) , (0,-R,0) , (0,0,R) ),( (R,0,0) , (0,-R,0) , (0,0,-R) ),( (-R,0,0) , (0,R,0) , (0,0,R) ),( (-R,0,0) , (0,R,0) , (0,0,-R) ),( (-R,0,0) , (0,-R,0) , (0,0,R) ),( (-R,0,0) , (0,-R,0) , (0,0,-R) )}
#define bone_tetra(H,W,D) {( (0,0,0) , (0,.5 * W,-H) , (0,.5 * -W,-H) ),( (0,0,0) , (0,.5 * W,-H) , (-D,0,0) ),( (0,0,0) , (0,.5 * -W,-H) , (-D,0,0) ),( (-D,0,0) , (0,.5 * W,-H) , (0,.5 * -W,-H) )}
#define bone_inv_triangle(H,W) {( (0,0,0) , (0,.5 * W,-H) , (0,.5 * -W,-H) )}
#define bone_rt_triangle(L,H) {( (0,0,0) , (L,0,0) , (0,0,-H) )}
#define bone_bicone(L,R) {( (L/2,0,R) , (L/2,R,0) , (L,0,0) ),( (L/2,0,R) , (L/2,R,0) , (0,0,0) ),( (L/2,0,R) , (L/2,-R,0) , (L,0,0) ),( (L/2,0,R) , (L/2,-R,0) , (0,0,0) ),( (L/2,0,-R) , (L/2,R,0) , (L,0,0) ),( (L/2,0,-R) , (L/2,R,0) , (0,0,0) ),( (L/2,0,-R) , (L/2,-R,0) , (L,0,0) ),( (L/2,0,-R) , (L/2,-R,0) , (0,0,0) )}
#define bone_pyra(L,R) {( (L,0,0) , (0,R * hr2,R * hr2) , (0,R * hr2,-R * hr2) ),( (L,0,0) , (0,R * hr2,R * hr2) , (0,-R * hr2,R * hr2) ),( (L,0,0) , (0,-R * hr2,-R * hr2) , (0,R * hr2,-R * hr2) ),( (L,0,0) , (0,-R * hr2,-R * hr2) , (0,-R * hr2,R * hr2) ),( (0,R * hr2,R * hr2) , (0,R * hr2,-R * hr2) , (0,-R * hr2,R * hr2) ),( (0,-R * hr2,-R * hr2) , (0,R * hr2,-R * hr2) , (0,-R * hr2,R * hr2) )}
#define bone_inv_pyra(L,R) {( (0,0,0) , (L,R * hr2,R * hr2) , (L,R * hr2,-R * hr2) ),( (0,0,0) , (L,R * hr2,R * hr2) , (L,-R * hr2,R * hr2) ),( (0,0,0) , (L,-R * hr2,-R * hr2) , (L,R * hr2,-R * hr2) ),( (0,0,0) , (L,-R * hr2,-R * hr2) , (L,-R * hr2,R * hr2) ),( (L,R * hr2,R * hr2) , (L,R * hr2,-R * hr2) , (L,-R * hr2,R * hr2) ),( (L,-R * hr2,-R * hr2) , (L,R * hr2,-R * hr2,H) , (L,-R * hr2,R * hr2)}
#define bone_inv_rot_pyra(L,R) {( (0,0,0) , (L,0,R) , (L,R,0) ),( (0,0,0) , (L,0,R) , (L,-B,0) ),( (0,0,0) , (L,0,-R) , (L,B,0) ),( (0,0,0) , (L,0,-R) , (L,-B,0) ),( (L,0,R) , (L,R,0) , (L,-B,0) ),( (L,0,-R) , (L,R,0) , (L,-B,0) )}
#define bone_haf_inv_rot_pyra(L,R) {( (0,0,0) , (L,0,-R) , (L,R,0) ),( (0,0,0) , (L,0,-R) , (L,-R,0) ),( (0,0,0) , (L,R,0) , (L,-R,0) ),( (L,0,-R) , (L,R,0) , (L,-R,0) )}
#define bone_haf_rot_pyra(L,R) {( (L,0,0) , (0,0,-R) , (0,R,0) ),( (L,0,0) , (0,0,-R) , (0,-R,0) ),( (L,0,0) , (0,R,0) , (0,-R,0) ),( (0,0,-R) , (0,R,0) , (0,-R,0) )}
#define bone_cube(X,Y,Z) {( (-X/2,-Y/2,-Z/2) , (X/2,-Y/2,-Z/2) , (-X/2,Y/2,-Z/2) ),( (-X/2,-Y/2,-Z/2) , (X/2,-Y/2,-Z/2) , (-X/2,-Y/2,Z/2) ),( (-X/2,-Y/2,-Z/2) , (-X/2,Y/2,-Z/2) , (-X/2,-Y,Z/2) ),( (X/2,-Y/2,-Z/2) , (-X/2,Y/2,-Z/2) , (X/2,Y/2,-Z/2) ),( (X/2,-Y/2,-Z/2) , (-X/2,-Y/2,Z/2) , (X/2,-Y/2,Z/2) ),( (-X/2,Y/2,-Z/2) , (-X/2,-Y/2,Z/2) , (-X/2,Y/2,Z/2) ),( (X/2,Y/2,Z/2) , (-X/2,Y/2,Z/2) , (X/2,-Y/2,Z/2) ),( (X/2,Y/2,Z/2) , (-X/2,Y/2,Z/2) , (X/2,Y/2,-Z/2) ),( (X/2,Y/2,Z/2) , (X/2,-Y/2,Z/2) , (X/2,Y/2,-Z/2) ),( (-X/2,Y/2,Z/2) , (X/2,-Y/2,Z/2) , (-X/2,-Y/2,Z/2) ),( (-X/2,Y/2,Z/2) , (X/2,Y/2,-Z/2) , (-X/2,Y/2,-Z/2) ),( (X/2,-Y/2,Z/2) , (X/2,Y/2,-Z/2) , (X/2,-Y/2,-Z/2) )}
