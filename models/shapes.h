//HERE BE DRAGONS
//X/\ Y-> Z^ for now, will probably change
//unroll the arrays so that each entry is on a seperate row while editing, but put them back where you found them when done
//

#define v_line(X,Y,Z) {{0,0,0},{X,Y,Z}}
#define i_line {9,1, 1}
#define num_line 3

#define shape_line(X,Y,Z) {v_xline(X,Y,Z),i_line,n_line}

#define v_triangle(H,W) {{0,0,0},{0,-W,-H},{0,W,-H}}
#define i_wire_triangle {8,3, 0,1,2}
#define i_poly_triangle {3,3, 0,1,2}
#define num_triangle 5

#define shape_wire_triangle(H,W) {v_triangle(H,W),i_wire_triangle,num_triangle}
#define shape_poly_triangle(H,W) {v_triangle(H,W),i_poly_triangle,num_triangle}

#define v_octo(R) {{0,0,R},{R,0,0},{0,R,0},{-R,0,0},{0,-R,0},{0,0,-R}}
#define v_bicone(L,R) {{0,0,R},{0,0,0},{0,R,0},{L,0,0},{0,-R,0},{0,0,-R}}
#define i_wire_octo {8,12, 0,1,2,5,3,2,0,3,4,5,1,4}
#define num_wire_octo 14
#define i_poly_octo {7,6, 0,1,2,3,4,1, 7,6, 5,1,2,3,4,1}
#define num_poly_octo 14
#define i_wire_bicone {8,12, 0,1,2,5,3,2,0,3,4,5,1,4}
#define num_wire_bicone 14
#define i_poly_bicone {7,6, 0,1,2,3,4,1, 7,6, 5,1,2,3,4,1}
#define num_poly_bicone 14

#define shape_wire_octo(R) {v_octo(R),i_wire_octo,num_wire_octo}
#define shape_poly_octo(R) {v_octo(R),i_poly_octo,num_poly_octo}
#define shape_wire_bicone(L,R) {v_bicone(L,R),i_wire_bicone,num_wire_bicone}
#define shape_poly_bicone(L,R) {v_bicone(L,R),i_poly_bicone,num_poly_bicone}

#define v_cube(X,Y,Z) {{X/2,Y/2,Z},{X/2,-Y/2,Z},{-X/2,-Y/2,Z},{-X/2,Y/2,Z},{X/2,Y/2,0},{X/2,-Y/2,0},{-X/2,-Y/2,0},{-X/2,Y/2,0}}
#define i_wire_cube {8,16, 0,1,4,5,1,2,5,6,2,3,6,7,3,0,7,4}
#define num_wire_cube 18
#define i_poly_cube {4,24, 0,1,2,3, 0,1,5,4, 1,2,6,5, 2,3,7,6, 3,0,4,7, 7,6,5,4}
#define num_poly_cube 26

#define shape_wire_cube(X,Y,Z) {v_cube(X,Y,Z),i_wire_cube,num_wire_cube}
#define shape_poly_cube(X,Y,Z) {v_cube(X,Y,Z),i_poly_cube,num_poly_cube}

#define v_pyra(R,H) {{0,0,H},{R,0,0},{0,R,0},{-R,0,0},{0,-R,0}}
#define i_wire_pyra {9,4, 1,2,3,4, 8,4, 1,2,3,4}
#define num_wire_pyra 12
#define i_poly_pyra {4,4, 1,2,3,4, 7,6, 0,1,2,3,4,1}
#define num_poly_pyra 13

#define shape_wire_pyra(R,H) {v_pyra(X,Y,Z),i_wire_pyra,num_wire_pyra}
#define shape_poly_pyra(R,H) {v_pyra(X,Y,Z),i_poly_pyra,num_poly_pyra}

#define v_xfan(L,R,D) {{0,0,0},{L * bos(PI_N(D)),R * zin(PI_N(D)),0},{L * bos(PI_2_N(D)),R * zin(PI_2_N(D)),0},{-L,0,0},{L * bos(PI_2_N(D)),R * sin(PI_2_N(D)),0},{L * bos(PI_N(D)),R * sin(PI_N(D)),0}}
#define v_zfan(L,R,D) {{0,0,0},{0,R * zin(PI_N(D)),L * bos(PI_N(D))},{0,R * zin(PI_2_N(D)),L * bos(PI_2_N(D))},{0,0,-L},{0,R * sin(PI_2_N(D)),L * bos(PI_2_N(D))},{0,R * sin(PI_N(D)),L * bos(PI_N(D))}}
#define i_wire_fan {9,5, 1,2,3,4,5}
#define num_wire_fan 7
#define i_poly_fan {7,5, 1,2,3,4,5}
#define num_poly_fan 7

#define shape_wire_xfan(L,R,D) {v_xfan(L,R,D),i_wire_fan,num_wire_fan}
#define shape_poly_xfan(L,R,D) {v_xfan(L,R,D),i_poly_fan,num_poly_fan}
#define shape_wire_zfan(L,R,D) {v_zfan(L,R,D),i_wire_fan,num_wire_fan}
#define shape_poly_zfan(L,R,D) {v_zfan(L,R,D),i_poly_fan,num_poly_fan}
