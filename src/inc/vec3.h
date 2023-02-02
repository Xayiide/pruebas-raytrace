#ifndef _VEC3_H_
#define _VEC3_H_

typedef struct {
    float x;
    float y;
    float z;
} Vec3;


Vec3 vec3_create(float, float, float);

float vec3_length(Vec3);

float vec3_squared_length(Vec3);

Vec3 vec3_unit_vector(Vec3);


/* Operaciones con vectores */

Vec3 vec3_add(Vec3, Vec3);

Vec3 vec3_sub(Vec3, Vec3);

Vec3 vec3_mul(Vec3, Vec3);

Vec3 vec3_div(Vec3, Vec3);

/* división escalar */
Vec3 vec3_div_esc(Vec3, float);

/* multiplicación escalar */
Vec3 vec3_mul_esc(Vec3, float);


/* producto escalar */
float vec3_dot(Vec3, Vec3);

/* producto vectorial */
Vec3 vec3_cross(Vec3, Vec3);

#endif
