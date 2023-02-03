#include "camera.h"
#include "vec3.h"
#include "ray.h"

Camera cam_create(Vec3 ll, Vec3 h, Vec3 v, Vec3 o) {
    Camera cam = {.ll_corner  = ll,
                  .horizontal = h,
                  .vertical   = v,
                  .origin     = o};

    return cam;
}

Ray cam_get_ray(Camera cam, float u, float v) {
    Ray r;
    r.origin = cam.origin;
    r.direction = vec3_add(cam.ll_corner,
                           vec3_add(vec3_mul_esc(cam.horizontal, u),
                                    vec3_mul_esc(cam.vertical, v)));

    return r;
}

