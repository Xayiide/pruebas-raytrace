#ifndef _RAY_H_
#define _RAY_H_

#include "vec3.h"

typedef struct {
    Vec3 origin;
    Vec3 direction;
} Ray;

Ray ray_create(Vec3, Vec3);

Vec3 ray_point_at_param(Ray, double);


#endif

