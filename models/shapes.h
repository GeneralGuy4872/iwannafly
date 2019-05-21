//HERE BE DRAGONS
//X⇗ Y→ Z↑ for now, will probably change
//unroll the arrays so that each entry is on a seperate row while editing, but put them back where you found them when done

/*m_foo opcodes:
*
* 0 = line from the first entry to here
* pos = wireframe of n consecutive lines
* -1 = point
* -2 = single line
* -3 = triangle
* -4 = quad
*/

#define v_line_x(L) {{0,0,0},{L,0,0}}
#define v_line_y(L) {{0,0,0},{0,L,0}}
#define v_line_z(L) {{0,0,0},{0,0,L}}
#define m_line {1}

#define raw_wire_octo(A,N,E,S,W,Z) {Z,N,E,A,S,E,Z,S,W,A,N,W,Z}
#define v_wire_octo(R) raw_wire_octo({0,0,R},{R,0,0},{0,R,0},{-R,0,0},{0,-R,0},{0,0,-R})
#define m_wire_octo {12}

#define raw_wire_crate(A,B,C,D,W,X,Y,Z) {A,B,X,A,W,X,Y,B,C,Y,Z,C,D,Z,W,D,A}
#define v_wire_crate(X,Y,Z) raw_wire_crate({X,Y,Z},{X,-Y,Z},{-X,-Y,Z},{-X,Y,Z},{X,Y,0},{X,-Y,0},{-X,-Y,0},{-X,Y,0})
#define m_wire_crate {16}

#define v_poly_octo(R) {{{0,0,R},{R,0,0},{0,R,0}},{{0,0,R},{0,R,0},{-R,0,0}},{{0,0,R},{-R,0,0},{0,-R,0}},{{0,0,R},{0,-R,0},{R,0,0}},{{0,0,-R},{R,0,0},{0,-R,0}},{{0,0,-R},{0,-R,0},{-R,0,0}},{{0,0,-R},{-R,0,0},{0,R,0}},{{0,0,-R},{0,R,0},{R,0,0}}}
#define bone_bicone(L,R) {( (L/2,0,R) , (L/2,R,0) , (L,0,0) ),( (L/2,0,R) , (L/2,R,0) , (0,0,0) ),( (L/2,0,R) , (L/2,-R,0) , (L,0,0) ),( (L/2,0,R) , (L/2,-R,0) , (0,0,0) ),( (L/2,0,-R) , (L/2,R,0) , (L,0,0) ),( (L/2,0,-R) , (L/2,R,0) , (0,0,0) ),( (L/2,0,-R) , (L/2,-R,0) , (L,0,0) ),( (L/2,0,-R) , (L/2,-R,0) , (0,0,0) )}
#define m_poly_octo {-3,-3,-3,-3,-3,-3,-3,-3}

#define v_poly_half_oct(R,H) {{{R,0,0},{0,-R,0},{-R,0,0},{0,R,0}},{{0,0,-R},{R,0,0},{0,-R,0}},{{0,0,-R},{0,-R,0},{-R,0,0}},{{0,0,-R},{-R,0,0},{0,R,0}},{{0,0,-R},{0,R,0},{R,0,0}}}
#define bone_pyra(L,R) {( (L,0,0) , (0,R * M_SQRT1_2,R * M_SQRT1_2) , (0,R * M_SQRT1_2,-R * M_SQRT1_2) ),( (L,0,0) , (0,R * M_SQRT1_2,R * M_SQRT1_2) , (0,-R * M_SQRT1_2,R * M_SQRT1_2) ),( (L,0,0) , (0,-R * M_SQRT1_2,-R * M_SQRT1_2) , (0,R * M_SQRT1_2,-R * M_SQRT1_2) ),( (L,0,0) , (0,-R * M_SQRT1_2,-R * M_SQRT1_2) , (0,-R * M_SQRT1_2,R * M_SQRT1_2) ),( (0,R * M_SQRT1_2,R * M_SQRT1_2) , (0,R * M_SQRT1_2,-R * M_SQRT1_2) , (0,-R * M_SQRT1_2,R * M_SQRT1_2) ),( (0,-R * M_SQRT1_2,-R * M_SQRT1_2) , (0,R * M_SQRT1_2,-R * M_SQRT1_2) , (0,-R * M_SQRT1_2,R * M_SQRT1_2) )}
#define bone_inv_rot_pyra(L,R) {( (0,0,0) , (L,0,R) , (L,R,0) ),( (0,0,0) , (L,0,R) , (L,-B,0) ),( (0,0,0) , (L,0,-R) , (L,B,0) ),( (0,0,0) , (L,0,-R) , (L,-B,0) ),( (L,0,R) , (L,R,0) , (L,-B,0) ),( (L,0,-R) , (L,R,0) , (L,-B,0) )}
#define bone_inv_pyra(L,R) {( (0,0,0) , (L,R * M_SQRT1_2,R * M_SQRT1_2) , (L,R * M_SQRT1_2,-R * M_SQRT1_2) ),( (0,0,0) , (L,R * M_SQRT1_2,R * M_SQRT1_2) , (L,-R * M_SQRT1_2,R * M_SQRT1_2) ),( (0,0,0) , (L,-R * M_SQRT1_2,-R * M_SQRT1_2) , (L,R * M_SQRT1_2,-R * M_SQRT1_2) ),( (0,0,0) , (L,-R * M_SQRT1_2,-R * M_SQRT1_2) , (L,-R * M_SQRT1_2,R * M_SQRT1_2) ),( (L,R * M_SQRT1_2,R * M_SQRT1_2) , (L,R * M_SQRT1_2,-R * M_SQRT1_2) , (L,-R * M_SQRT1_2,R * M_SQRT1_2) ),( (L,-R * M_SQRT1_2,-R * M_SQRT1_2) , (L,R * M_SQRT1_2,-R * M_SQRT1_2) , (L,-R * M_SQRT1_2,R * M_SQRT1_2)}

#define m_poly_pyra {-4,-3,-3,-3,-3}

#define bone_tetra(H,W,D) {( (0,0,0) , (0,.5 * W,-H) , (0,.5 * -W,-H) ),( (0,0,0) , (0,.5 * W,-H) , (-D,0,0) ),( (0,0,0) , (0,.5 * -W,-H) , (-D,0,0) ),( (-D,0,0) , (0,.5 * W,-H) , (0,.5 * -W,-H) )}
#define bone_haf_inv_rot_pyra(L,R) {( (0,0,0) , (L,0,-R) , (L,R,0) ),( (0,0,0) , (L,0,-R) , (L,-R,0) ),( (0,0,0) , (L,R,0) , (L,-R,0) ),( (L,0,-R) , (L,R,0) , (L,-R,0) )}
#define bone_haf_rot_pyra(L,R) {( (L,0,0) , (0,0,-R) , (0,R,0) ),( (L,0,0) , (0,0,-R) , (0,-R,0) ),( (L,0,0) , (0,R,0) , (0,-R,0) ),( (0,0,-R) , (0,R,0) , (0,-R,0) )}

#define bone_inv_triangle(H,W) {( (0,0,0) , (0,.5 * W,-H) , (0,.5 * -W,-H) )}

#define v_poly_cube(X,Y,Z) {
#define m_poly_cube {-4,-4,-4,-4,-4,-4}
