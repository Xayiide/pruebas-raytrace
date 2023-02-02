#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <stdbool.h> /* bool */
#include "vec3.h"
#include "ray.h"

typedef struct {
    Vec3  center;
    float radius;
} Sphere;

Sphere sphere_create(Vec3, float);

bool ray_hit_sphere(Ray, Sphere);

bool ray_sphere_collide(Ray, Sphere);

#endif

