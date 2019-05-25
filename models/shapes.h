//HERE BE DRAGONS
//X⇗ Y→ Z↑ for now, will probably change
//unroll the arrays so that each entry is on a seperate row while editing, but put them back where you found them when done

/*m_foo opcodes:
*
* -n = line from n nodes back to here; eats 1 entry
* 0 = line from first entry to here; eats 1 entry
* 1 = point; eats 1 entry
* 2 = single line; eats 2 entrys
* 3 = triangle; eats 3 entrys
* 4 = quad; eats 4 entrys
*/

#define v_line_x(L) {{0,0,0},{L,0,0}}
#define v_line_y(L) {{0,0,0},{0,L,0}}
#define v_line_z(L) {{0,0,0},{0,0,L}}
#define m_line {2}
#define num_p_line 1
#define num_v_line 2

#define v_wire_origin(X,Y,Z) {{0,0,0},{X,0,0},{0,Y,0},{0,0,Z}}
#define m_wire_origin {2,0,0}
#define num_p_wire_origin 3
#define num_v_wire_origin 4

#define raw_wire_octo(A,N,E,S,W,Z) {Z,N,E,A,S,E,Z,S,W,A,N,W,Z}
#define v_wire_octo(R) raw_wire_octo({0,0,R},{R,0,0},{0,R,0},{-R,0,0},{0,-R,0},{0,0,-R})
#define m_wire_octo {2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
#define num_p_wire_octo 12
#define num_v_wire_octo 13

#define raw_wire_crate(A,B,C,D,W,X,Y,Z) {A,B,X,A,W,X,Y,B,C,Y,Z,C,D,Z,W,D,A}
#define v_wire_crate(X,Y,Z) raw_wire_crate({X/2,Y/2,Z},{X/2,-Y/2,Z},{-X/2,-Y/2,Z},{-X/2,Y/2,Z},{X/2,Y/2,0},{X/2,-Y/2,0},{-X/2,-Y/2,0},{-X/2,Y/2,0})
#define m_wire_crate {2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
#define num_p_wire_crate 16
#define num_v_wire_crate 17

#define v_poly_octo(R) {{{0,0,R},{R,0,0},{0,R,0}},{{0,0,R},{0,R,0},{-R,0,0}},{{0,0,R},{-R,0,0},{0,-R,0}},{{0,0,R},{0,-R,0},{R,0,0}},{{0,0,-R},{R,0,0},{0,-R,0}},{{0,0,-R},{0,-R,0},{-R,0,0}},{{0,0,-R},{-R,0,0},{0,R,0}},{{0,0,-R},{0,R,0},{R,0,0}}}
#define v_poly_bicone(L,R) {{{L,0,0},{L/2,0,R},{L/2,R,0}},{{L,0,0},{L/2,R,0},{L/2,0,-R}},{{L,0,0},{L/2,0,-R},{L/2,-R,0}},{{L,0,0},{L/2,-R,0},{L/2,0,R}},{{0,0,0},{L/2,0,R},{L/2,-R,0}},{{0,0,0},{L/2,-R,0},{L/2,0,-R}},{{0,0,0},{L/2,0,-R},{L/2,R,0}},{{0,0,0},{L/2,R,0},{L/2,0,R}}}
#define m_poly_octo {3,3,3,3,3,3,3,3}
#define num_p_poly_octo 8
#define num_v_poly_octo 24

#define v_poly_low_half_oct(R,H) {{{R,0,0},{0,-R,0},{-R,0,0},{0,R,0}},{{0,0,-H},{R,0,0},{0,-R,0}},{{0,0,-H},{0,-R,0},{-R,0,0}},{{0,0,-H},{-R,0,0},{0,R,0}},{{0,0,-H},{0,R,0},{R,0,0}}}
#define m_poly_pyra {4,3,3,3,3}
#define num_p_poly_pyra 5
#define num_v_poly_pyra 16

#define v_poly_tetra(H,X,Y) {{{0,0,0},{0,-Y/2,-H},{0,Y/2,-H}},{{0,0,0},{-X,0,0},{0,-Y/2,-H}},{{-X,0,0},{0,0,0},{0,Y/2,-H}},{{-X,0,0},{0,Y/2,-H},{0,-Y/2,-H}}}
#define m_poly_tetra {3,3,3,3}
#define num_p_poly_tetra 4
#define num_v_poly_tetra 12

#define v_poly_low_triangle(H,W) {{0,0,0},{0,W/2,-H},{0,-W/2,-H}}
#define v_poly_triangle(H,W) {{0,-W/2,0},{0,0,H},{0,W/2,0}}
#define m_triangle {3}
#define num_p_triangle 1
#define num_v_triangle 3

#define v_poly_cube(X,Y,Z) {{{X/2,Y/2,Z},{X/2,-Y/2,Z},{-X/2,-Y/2,Z},{-X/2,Y/2,Z}},{{X/2,-Y/2,Z},{X/2,Y/2,Z},{X/2,Y/2,0},{X/2,-Y/2,0}},{{X/2,Y/2,Z},{-X/2,Y/2,Z},{-X/2,Y/2,0},{X/2,Y/2,0}},{{-X/2,Y/2,Z},{-X/2,-Y/2,Z},{-X/2,-Y/2,0},{-X/2,Y/2,0}},{{-X/2,Y/2,Z},{X/2,Y/2,Z},{X/2,Y/2,0},{-X/2,Y/2,0}},{{X/2,-Y/2,0},{X/2,Y/2,0},{-X/2,Y/2,0},{-X/2,-Y/2,0}}}
#define m_poly_cube {4,4,4,4,4,4}
#define num_p_poly_cube 6
#define num_v_poly_cube 24
