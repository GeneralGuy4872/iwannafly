//HERE BE DRAGONS
//X⇗ Y→ Z↑ for now, will probably change
//unroll the arrays so that each entry is on a seperate row while editing, but put them back where you found them when done
//

#define v_octo(R) {{0,0,R},{R,0,0},{0,R,0},{-R,0,0},{0,-R,0},{0,0,-R}}
#define v_bicone(L,R) {{0,0,R},{0,0,0},{0,R,0},{L,0,0},{0,-R,0},{0,0,-R}}
#define wire_octo {8,12, 0,1,2,5,3,2,0,3,4,5,1,4}
#define num_wire_octo 14
#define poly_octo {7,6, 0,1,2,3,4,1, 7,6, 5,1,2,3,4,1}
#define num_poly_octo 14
#define wire_bicone {8,12, 0,1,2,5,3,2,0,3,4,5,1,4}
#define num_wire_bicone 14
#define poly_bicone {7,6, 0,1,2,3,4,1, 7,6, 5,1,2,3,4,1}
#define num_poly_bicone 14

#define v_cube(X,Y,Z) {{X/2,Y/2,Z},{X/2,-Y/2,Z},{-X/2,-Y/2,Z},{-X/2,Y/2,Z},{X/2,Y/2,0},{X/2,-Y/2,0},{-X/2,-Y/2,0},{-X/2,Y/2,0}}
#define wire_cube {8,16, 0,1,4,5,1,2,5,6,2,3,6,7,3,0,7,4}
#define num_wire_cube 18
#define poly_cube {4,24, 0,1,2,3, 0,1,5,4, 1,2,6,5, 2,3,7,6, 3,0,4,7, 7,6,5,4}
#define num_poly_cube 26

#define v_pyra(R,H) {{0,0,H},{R,0,0},{0,R,0},{-R,0,0},{0,-R,0}}
#define v_inv_pyra(R,H) {{0,0,-H},{R,0,0},{0,R,0},{-R,0,0},{0,-R,0}}
#define wire_pyra {9,4, 1,2,3,4, 8,4, 1,2,3,4}
#define num_wire_pyra 12
#define poly_pyra {4,4, 1,2,3,4, 7,6, 0,1,2,3,4,1}
#define num_poly_pyra 13

#define v_xfan(L,R,D) {{0,0,0},{L * bos(PI_N(D)),R * zin(PI_N(D)),0},{L * bos(PI_2_N(D)),R * zin(PI_2_N(D)),0},{-L,0,0},{L * bos(PI_2_N(D)),R * sin(PI_2_N(D)),0},{L * bos(PI_N(D)),R * sin(PI_N(D)),0}}
#define v_zfan(L,R,D) {{0,0,0},{0,R * zin(PI_N(D)),L * bos(PI_N(D))},{0,R * zin(PI_2_N(D)),L * bos(PI_2_N(D))},{0,0,-L},{0,R * sin(PI_2_N(D)),L * bos(PI_2_N(D))},{0,R * sin(PI_N(D)),L * bos(PI_N(D))}}
#define wire_fan {9,5, 1,2,3,4,5}
#define num_wire_fan 7
#define poly_fan {7,5, 1,2,3,4,5}
#define num_poly_fan 7
