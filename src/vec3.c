#include <math.h> /* sqrt */
#include "vec3.h"

Vec3 vec3_create(float x, float y, float z) {
    Vec3 v = {.x = x,
              .y = y,
              .z = z};

    return v;
}

/* sqrt(x^2 + y^2 + z^2) */
float vec3_length(Vec3 vec) {
    float r = sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
    
    return r;
}

float vec3_squared_length(Vec3 vec) {
    float r = ((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));

    return r;
}

/* unit(vec) = vec/(length(vec)) */
Vec3 vec3_unit_vector(Vec3 vec) {
    Vec3 new = vec3_div_esc(vec, vec3_length(vec));

    return new;
}



/* Operaciones con vectores */

Vec3 vec3_add(Vec3 v1, Vec3 v2) {
    Vec3 new = {.x = v1.x + v2.x,
                .y = v1.y + v2.y,
                .z = v1.z + v2.z};

    return new;
}


Vec3 vec3_sub(Vec3 v1, Vec3 v2) {
    Vec3 new = {.x = v1.x - v2.x,
                .y = v1.y - v2.y,
                .z = v1.z - v2.z};

    return new;
}


Vec3 vec3_mul(Vec3 v1, Vec3 v2) {
    Vec3 new = {.x = v1.x * v2.x,
                .y = v1.y * v2.y,
                .z = v1.z * v2.z};

    return new;
}


Vec3 vec3_div(Vec3 v1, Vec3 v2) {
    Vec3 new = {.x = v1.x / v2.x,
                .y = v1.y / v2.y,
                .z = v1.z / v2.z};

    return new;
}


/* división de vector por escalar */
Vec3 vec3_div_esc(Vec3 v, float e) {
    Vec3 new = {.x = v.x / e,
                .y = v.y / e,
                .z = v.z / e};

    return new;
}

/* multiplicación de vector por escalar */
Vec3 vec3_mul_esc(Vec3 v, float e) {
    Vec3 new = {.x = v.x * e,
                .y = v.y * e,
                .z = v.z * e};

    return new;
}


/* producto escalar de dos vectores */
float vec3_dot(Vec3 v1, Vec3 v2) {
    float r = ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));

    return r;
}

/* producto vectorial de dos vectores */
Vec3 vec3_cross(Vec3 v1, Vec3 v2) {
    Vec3 new = {.x =   (v1.y * v2.z) - (v1.z * v2.y),
                .y = -((v1.x * v2.z) - (v1.z * v2.x)),
                .z =   (v1.x * v2.y) - (v1.y * v2.x)};

    return new;
}
