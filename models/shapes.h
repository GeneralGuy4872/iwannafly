//HERE BE DRAGONS
//X⇗ Y→ Z↑ for now, will probably change
//unroll the arrays so that each entry is on a seperate row while editing, but put them back where you found them when done

/*m_foo opcodes:
*
* 0 = line from the first entry to here; eats 1 entry
* pos = wireframe of n consecutive lines; eats n+1 entrys
* -1 = point; eats 1 entry
* -2 = single line; eats 2 entrys
* -3 = triangle; eats 3 entrys
* -4 = quad; eats 4 entrys
*
* num_foo = {instructions,vectors}
*/

#define v_line_x(L) {{0,0,0},{L,0,0}}
#define v_line_y(L) {{0,0,0},{0,L,0}}
#define v_line_z(L) {{0,0,0},{0,0,L}}
#define m_line {-2}
#define num_line {1,2}

#define raw_wire_octo(A,N,E,S,W,Z) {Z,N,E,A,S,E,Z,S,W,A,N,W,Z}
#define v_wire_octo(R) raw_wire_octo({0,0,R},{R,0,0},{0,R,0},{-R,0,0},{0,-R,0},{0,0,-R})
#define m_wire_octo {12}
#define num_wire_octo {1,13}

#define raw_wire_crate(A,B,C,D,W,X,Y,Z) {A,B,X,A,W,X,Y,B,C,Y,Z,C,D,Z,W,D,A}
#define v_wire_crate(X,Y,Z) raw_wire_crate({X/2,Y/2,Z},{X/2,-Y/2,Z},{-X/2,-Y/2,Z},{-X/2,Y/2,Z},{X/2,Y/2,0},{X/2,-Y/2,0},{-X/2,-Y/2,0},{-X/2,Y/2,0})
#define m_wire_crate {16}
#define num_wire_crate {1,17}

#define v_poly_octo(R) {{{0,0,R},{R,0,0},{0,R,0}},{{0,0,R},{0,R,0},{-R,0,0}},{{0,0,R},{-R,0,0},{0,-R,0}},{{0,0,R},{0,-R,0},{R,0,0}},{{0,0,-R},{R,0,0},{0,-R,0}},{{0,0,-R},{0,-R,0},{-R,0,0}},{{0,0,-R},{-R,0,0},{0,R,0}},{{0,0,-R},{0,R,0},{R,0,0}}}
#define v_poly_bicone(L,R) {{{0,0,L},{R,0,L/2},{0,R,L/2}},{{0,0,L},{0,R,L/2},{-R,0,L/2}},{{0,0,L},{-R,0,L/2},{0,-R,L/2}},{{0,0,L},{0,-R,L/2},{R,0,L/2}},{{0,0,0},{R,0,L/2},{0,-R,L/2}},{{0,0,0},{0,-R,L/2},{-R,0,L/2}},{{0,0,0},{-R,0,L/2},{0,R,L/2}},{{0,0,0},{0,R,L/2},{R,0,L/2}}}
#define m_poly_octo {-3,-3,-3,-3,-3,-3,-3,-3}
#define num_poly_octo {8,24}

#define v_poly_low_half_oct(R,H) {{{R,0,0},{0,-R,0},{-R,0,0},{0,R,0}},{{0,0,-R},{R,0,0},{0,-R,0}},{{0,0,-R},{0,-R,0},{-R,0,0}},{{0,0,-R},{-R,0,0},{0,R,0}},{{0,0,-R},{0,R,0},{R,0,0}}}
#define v_poly_pyra(H,X,Y) {{{X/2,Y/2,0},{X/2,-Y/2,0},{-X/2,-Y/2,0},{-X/2,Y/2,0}},{{0,0,H},{X/2,Y/2,0},{-X/2,Y/2,0}},{{0,0,H},{-X/2,Y/2,0},{-X/2,-Y/2,0}},{{0,0,H},{-X/2,-Y/2,0},{X/2,-Y/2,0}},{{0,0,H},{X/2,-Y/2,0},{X/2,Y/2,0}}}
#define v_poly_inv_rot_pyra(H,R) {{{R,0,H},{0,R,H},{-R,0,H},{0,-R,H}},{{R,0,H},{0,-R,H},{0,0,0}},{{0,-R,H},{-R,0,H},{0,0,0}},{{-R,0,H},{0,R,H},{0,0,0}},{{0,R,H},{R,0,H},{0,0,0}}}
#define v_poly_inv_pyra(H,X,Y) {{{X/2,Y/2,H},{X/2,-Y/2,H},{-X/2,-Y/2,H},{-X/2,Y/2,H}},{{X/2,Y/2,H},{-X/2,Y/2,H},{0,0,0}},{{-X/2,Y/2,H},{-X/2,-Y/2,H},{0,0,0}},{{-X/2,-Y/2,H},{X/2,-Y/2,H},{0,0,0}},{{X/2,-Y/2,H},{X/2,Y/2,H},{0,0,0}}}
#define m_poly_pyra {-4,-3,-3,-3,-3}
#define num_poly_pyra {5,16}

#define v_poly_low_bak_quat_octo(H,R) {( (0,0,0) , (0,.5 * W,-H) , (0,.5 * -W,-H) ),( (0,0,0) , (0,.5 * W,-H) , (-D,0,0) ),( (0,0,0) , (0,.5 * -W,-H) , (-D,0,0) ),( (-D,0,0) , (0,.5 * W,-H) , (0,.5 * -W,-H) )}
#define v_poly_bak_haf_inv_rot_pyra(H,R) {( (0,0,0) , (L,0,-R) , (L,R,0) ),( (0,0,0) , (L,0,-R) , (L,-R,0) ),( (0,0,0) , (L,R,0) , (L,-R,0) ),( (L,0,-R) , (L,R,0) , (L,-R,0) )}
#define v_poly_bak_haf_rot_pyra(H,R) {( (L,0,0) , (0,0,-R) , (0,R,0) ),( (L,0,0) , (0,0,-R) , (0,-R,0) ),( (L,0,0) , (0,R,0) , (0,-R,0) ),( (0,0,-R) , (0,R,0) , (0,-R,0) )}
#define m_poly_tetra {-3,-3,-3,-3}
#define num_poly_tetra {4,12}

#define v_poly_low_inv_triangle(H,W) {{0,0,0},{0,W/2,-H},{0,-W/2,-H}}
#define m_triangle {-3}
#define num_triangle {1,3}

#define v_poly_cube(X,Y,Z) {{{X/2,Y/2,Z},{X/2,-Y/2,Z},{-X/2,-Y/2,Z},{-X/2,Y/2,Z}},{{X/2,-Y/2,Z},{X/2,Y/2,Z},{X/2,Y/2,0},{X/2,-Y/2,0}},{{X/2,Y/2,Z},{-X/2,Y/2,Z},{-X/2,Y/2,0},{X/2,Y/2,0}},{{-X/2,Y/2,Z},{-X/2,-Y/2,Z},{-X/2,-Y/2,0},{-X/2,Y/2,0}},{{-X/2,Y/2,Z},{X/2,Y/2,Z},{X/2,Y/2,0},{-X/2,Y/2,0}},{{X/2,-Y/2,0},{X/2,Y/2,0},{-X/2,Y/2,0},{-X/2,-Y/2,0}}}
#define m_poly_cube {-4,-4,-4,-4,-4,-4}
#define num_poly_cube {6,24}
