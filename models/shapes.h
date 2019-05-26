//HERE BE DRAGONS
//X⇗ Y→ Z↑ for now, will probably change
//unroll the arrays so that each entry is on a seperate row while editing, but put them back where you found them when done
//

#define v_octo(R) {{0,0,R},{R,0,0},{0,R,0},{-R,0,0},{0,-R,0},{0,0,-R}}
#define v_bicone(L,R) {{0,0,R},{0,0,0},{0,R,0},{L,0,0},{0,-R,0},{0,0,-R}}
#define wire_octo {8,12, 0,1,2,5,3,2,0,3,4,5,1,4}
#define num_wire_octo 14
#define poly_octo {7,5, 0,1,2,3,4, 7,5, 5,1,2,3,4}
#define num_poly_octo 14
#define wire_bicone {8,12, 0,1,2,5,3,2,0,3,4,5,1,4}
#define num_wire_bicone 14
#define poly_bicone {7,5, 0,1,2,3,4, 7,5, 5,1,2,3,4}
#define num_poly_bicone 14

#define v_cube(X,Y,Z) {{X/2,Y/2,Z},{X/2,-Y/2,Z},{-X/2,-Y/2,Z},{-X/2,Y/2,Z},{X/2,Y/2,0},{X/2,-Y/2,0},{-X/2,-Y/2,0},{-X/2,Y/2,0}}
#define wire_cube {8,16, 0,1,4,5,1,2,5,6,2,3,6,7,3,0,7,4}
#define num_wire_cube 18
#define poly_cube {4,24, 0,1,2,3, 0,1,5,4, 1,2,6,5, 2,3,7,6, 3,0,4,7, 7,6,5,4}
#define num_poly_cube 26

#define v_pyra(R,H) {{0,0,H},{R,0,0},{0,R,0},{-R,0,0},{0,-R,0}}
#define v_inv_pyra(R,H) {{0,0,-H},{R,0,0},{0,R,0},{-R,0,0},{0,-R,0}}
#define wire_pyra {9,3, 1,2,3,4, 8,4, 1,2,3,4}
#define num_wire_pyra 12
#define poly_pyra {4,4, 1,2,3,4, 7,5, 0,1,2,3,4}
#define num_poly_pyra 13

#define v_tetra(H,W,L) {{0,0,0},{0,W/2,-H},{0,-W/2,-H},{-L,0,0}}
#define wire_tetra {9,3, 1,2,3, 8,3, 1,2,3}
#define num_wire_tetra 10
#define poly_tetra {3,3, 1,2,3, 7,4, 0,1,2,3}
#define num_poly_tetra 11
