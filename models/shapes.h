/* HERE BE DRAGONS
 * X/\ Y-> Z^ for now, will probably change
 * unroll the arrays so that each entry is on a seperate row while editing, but put them back where you found them when done
 */

void *v_line(xpos,ypos,zpos)
	float xpos;
	float ypos;
	float zpos;
	{
	vector3 (*output)[2];
	output = malloc(2 * sizeof(vector3));
	(*output)[0] = (vector3){0,0,0};
	(*output)[1] = (vector3){xpos,ypos,zpos};
	return output;
	}
#define vn_line 2

#define num_line 3
unsigned char i_line[num_line] = {9,1, 1};

#define shape_line(X,Y,Z) (shape){v_line(X,Y,Z),&i_line,num_line,vn_line}

#define frfl_shape_line(X,Y,Z) shape_line(frfl(X),frfl(Y),frfl(Z))

//---<HR>---

void *v_triangle(wid,hit)
	float wid;
	float hit;
	{
	vector3 (*output)[3];
	output = malloc(3 * sizeof(vector3));
	(*output)[0] = (vector3){0,0,0};
	(*output)[1] = (vector3){0,-wid,-hit};
	(*output)[2] = (vector3){0,wid,-hit};
	return output;
	}
#define vn_triangle 3

#define num_triangle 5
unsigned char i_wire_triangle[num_triangle] = {8,3, 0,1,2};
unsigned char i_poly_triangle[num_triangle] = {3,3, 0,1,2};

#define shape_wire_triangle(W,H) (shape){v_triangle(W,H),&i_wire_triangle,num_triangle,vn_triangle}
#define shape_poly_triangle(W,H) (shape){v_triangle(W,H),&i_poly_triangle,num_triangle,vn_triangle}

#define frfl_shape_wire_triangle(W,H) shape_wire_triangle(frfl(W),frfl(H))
#define frfl_shape_poly_triangle(W,H) shape_poly_triangle(frfl(W),frfl(H))

//---<HR>---

void * v_octo(rad)
	float rad;
	{
	vector3 (*output)[6];
	output = malloc(6 * sizeof(vector3));
	(*output)[0] = (vector3){0,0,rad};
	(*output)[1] = (vector3){rad,0,0};
	(*output)[2] = (vector3){0,rad,0};
	(*output)[3] = (vector3){-rad,0,0};
	(*output)[4] = (vector3){0,-rad,0};
	(*output)[5] = (vector3){0,0,-rad};
	return output;
	}
#define vn_octo 6

void * v_bicone(len,rad)
	float len;
	float rad;
	{
	vector3 (*output)[6];
	output = malloc(6 * sizeof(vector3));
	(*output)[0] = (vector3){0,0,0};
	(*output)[1] = (vector3){len/2,rad,0};
	(*output)[2] = (vector3){len/2,0,rad};
	(*output)[3] = (vector3){len/2,-rad,0};
	(*output)[4] = (vector3){len/2,0,-rad};
	(*output)[5] = (vector3){len,0,0};
	return output;
	}

#define num_wire_octo 14
#define num_poly_octo 16
unsigned char i_wire_octo[num_wire_octo] = {8,12, 0,1,2,5,3,2,0,3,4,5,1,4};
unsigned char i_poly_octo[num_poly_octo] = {7,6, 0,1,2,3,4,1, 7,6, 5,1,2,3,4,1};

#define shape_wire_octo(R) (shape){v_octo(R),&i_wire_octo,num_wire_octo,vn_octo}
#define shape_poly_octo(R) (shape){v_octo(R),&i_poly_octo,num_poly_octo,vn_octo}
#define shape_wire_bicone(L,R) (shape){v_bicone(L,R),&i_wire_octo,num_wire_octo,vn_octo}
#define shape_poly_bicone(L,R) (shape){v_bicone(L,R),&i_poly_octo,num_poly_octo,vn_octo}

#define frfl_shape_wire_octo(R) shape_wire_octo(frfl(R))
#define frfl_shape_poly_octo(R) shape_poly_octo(frfl(R))
#define frfl_shape_wire_bicone(L,R) shape_wire_bicone(frfl(L),frfl(R))
#define frfl_shape_poly_bicone(L,R) shape_poly_bicone(frfl(L),frfl(R))

//---<HR>---

void * v_cube(dep,wid,hit)
	float dep;
	float wid;
	float hit;
	{
	vector3 (*output)[8];
	output = malloc(8 * sizeof(vector3));
	(*output)[0] = (vector3){dep/2,wid/2,hit};
	(*output)[1] = (vector3){dep/2,-wid/2,hit};
	(*output)[2] = (vector3){-dep/2,-wid/2,hit};
	(*output)[3] = (vector3){-dep/2,wid/2,hit};
	(*output)[4] = (vector3){dep/2,wid/2,0};
	(*output)[5] = (vector3){dep/2,-wid/2,0};
	(*output)[6] = (vector3){-dep/2,-wid/2,0};
	(*output)[7] = (vector3){-dep/2,wid/2,0};
	return output;
	}
#define vn_cube

#define num_wire_cube 18
#define num_poly_cube 22
unsigned char i_wire_cube[num_wire_cube] = {8,16, 0,1,4,5,1,2,5,6,2,3,6,7,3,0,7,4};
unsigned char i_poly_cube[num_poly_cube] = {4,8, 0,1,2,3, 7,6,5,4, 12,10, 0,1,5,4,2,6,3,7,0,1};

#define shape_wire_cube(X,Y,Z) (shape){v_cube(X,Y,Z),&i_wire_cube,num_wire_cube,vn_cube}
#define shape_poly_cube(X,Y,Z) (shape){v_cube(X,Y,Z),&i_poly_cube,num_poly_cube,vn_cube}

#define frfl_shape_wire_cube(X,Y,Z) shape_wire_cube(frfl(X),frfl(Y),frfl(Z))
#define frfl_shape_poly_cube(X,Y,Z) shape_poly_cube(frfl(X),frfl(Y),frfl(Z))

//---<HR>---

void * v_pyra(rad,hit)
	float rad;
	float hit;
	{
	vector3 (*output)[5];
	output = malloc(5 * sizeof(vector3));
	(*output)[0] = (vector3){0,0,hit};
	(*output)[1] = (vector3){rad,0,0};
	(*output)[2] = (vector3){0,rad,0};
	(*output)[3] = (vector3){-rad,0,0};
	(*output)[4] = (vector3){0,-rad,0};
	}
#define vn_pyra 5

#define num_wire_pyra 12
#define num_poly_pyra 14
unsigned char i_wire_pyra[num_wire_pyra] = {9,4, 1,2,3,4, 8,4, 1,2,3,4};
unsigned char i_poly_pyra[num_poly_pyra] = {4,4, 1,2,3,4, 7,6, 0,1,2,3,4,1};

#define shape_wire_pyra(R,H) (shape){v_pyra(R,H),&i_wire_pyra,num_wire_pyra,vn_pyra}
#define shape_poly_pyra(R,H) (shape){v_pyra(R,H),&i_poly_pyra,num_poly_pyra,vn_pyra}

#define frfl_shape_wire_pyra(R,H) shape_wire_pyra(frfl(R),frfl(H))
#define frfl_shape_poly_pyra(R,H) shape_poly_pyra(frfl(R),frfl(H))

//---<HR>---

void * v_fan(len,rad,ang)
	float len;
	float rad;
	float ang;
	{
	vector3 (*output)[6];
	output = malloc(6 * sizeof(vector3));
	(*output)[0] = (vector3){0,0,0};
	(*output)[1] = (vector3){0,rad * zin(PI_N(ang)),-len * cos(PI_N(ang))};
	(*output)[2] = (vector3){0,rad * zin(PI_2_N(ang)),-len * cos(PI_2_N(ang))};
	(*output)[3] = (vector3){0,0,-len};
	(*output)[4] = (vector3){0,rad * sin(PI_2_N(ang)),-len * cos(PI_2_N(ang))};
	(*output)[5] = (vector3){0,rad * sin(PI_N(ang)),-len * cos(PI_N(ang))};
	return output;
	}
#define vn_fan 6

#define num_wire_fan 12
#define num_poly_fan 7
unsigned char i_wire_fan[num_wire_fan] = {10,5, 1,2,3,4,5, 9,3, 2,3,4};
unsigned char i_poly_fan[num_poly_fan] = {7,5, 1,2,3,4,5};

#define shape_wire_fan(L,R,A) (shape){v_fan(L,R,A),&i_wire_fan,num_wire_fan,vn_fan}
#define shape_poly_fan(L,R,A) (shape){v_fan(L,R,A),&i_poly_fan,num_poly_fan,vn_fan}

#define frfl_shape_wire_fan(L,R,A) shape_wire_fan(frfl(L),frfl(R),frfl(A))
#define frfl_shape_poly_fan(L,R,A) shape_poly_fan(frfl(L),frfl(R),frfl(A))
