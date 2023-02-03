#include "ray.h"

Ray ray_create(Vec3 ori, Vec3 dir) {
    Ray ray = {.origin    = ori,
               .direction = dir};

    return ray;
}

Vec3 ray_point_at_param(Ray r, double t) {
    Vec3 vec = vec3_add(r.origin, vec3_mul_esc(r.direction, t));

    return vec;
}

