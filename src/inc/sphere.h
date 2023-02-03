#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "vec3.h"
#include "ray.h"
#include "hitable.h"

typedef struct {
    Vec3  center;
    float radius;
} Sphere;

Sphere *sphere_create(Vec3, float);

bool ray_hit_sphere_cb(Ray, float, float, hitrec *, Sphere *);

#endif

