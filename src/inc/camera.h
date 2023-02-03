#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vec3.h"
#include "ray.h"

typedef struct {
    Vec3 ll_corner;
    Vec3 horizontal;
    Vec3 vertical;
    Vec3 origin;
} Camera;

Camera cam_create(Vec3, Vec3, Vec3, Vec3);

Ray cam_get_ray(Camera, double, double);

#endif

