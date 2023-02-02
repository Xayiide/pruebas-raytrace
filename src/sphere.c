#include <stdbool.h> /* bool */
#include "vec3.h"
#include "ray.h"
#include "sphere.h"

Sphere sphere_create(Vec3 c, float r) {
    Sphere sp = {.center = c,
                 .radius = r};

    return sp;
}

bool ray_hit_sphere(Ray r, Sphere s) {
    Vec3  oc;
    float a, b, c;
    float discriminant;

    oc = vec3_sub(r.origin, s.center);
    a  = vec3_dot(r.direction, r.direction);
    b  = 2.0 * vec3_dot(oc, r.direction);
    c  = vec3_dot(oc, oc) - (s.radius * s.radius);
    discriminant = b * b - 4 * a * c;

    return discriminant > 0;
}

bool ray_sphere_collide(Ray ray, Sphere sphere)
{
    Vec3 oc = vec3_sub(ray.origin, sphere.center);
    float a = vec3_dot(ray.direction, ray.direction);
    float b = 2 * vec3_dot(oc, ray.direction);
    float c = vec3_dot(oc, oc) - (sphere.radius * sphere.radius);
    float discriminant = b * b - 4 * a * c;
    return discriminant > 0;
}
