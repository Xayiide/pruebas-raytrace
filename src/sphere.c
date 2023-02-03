#include <math.h>    /* sqrt   */
#include <stdlib.h>  /* malloc */
#include <stdbool.h> /* bool   */
#include "vec3.h"
#include "ray.h"
#include "sphere.h"

Sphere *sphere_create(Vec3 c, double r) {
    Sphere *sp = malloc(sizeof(Sphere));
    sp->center = c;
    sp->radius = r;

    return sp;
}

bool ray_hit_sphere_cb(Ray r, double t_min, double t_max,
                       hitrec *rec, Sphere *sp) {
    Vec3  oc;
    double a, b, c;
    double discriminant;

    double temp;

    oc = vec3_sub(r.origin, sp->center);
    a  = vec3_dot(r.direction, r.direction);
    b  = vec3_dot(oc, r.direction);
    c  = vec3_dot(oc, oc) - (sp->radius * sp->radius);
    discriminant = b*b - a*c;

    if (discriminant > 0) {
        temp = (-b - sqrt(b*b - a*c))/a;
        if (temp < t_max && temp > t_min) {
            rec->t = temp;
            rec->p = ray_point_at_param(r, rec->t);
            rec->normal = vec3_div_esc(vec3_sub(rec->p, sp->center),
                                       sp->radius);
            return true;
        }

        temp = (-b + sqrt(b*b - a*c))/a;

        if (temp < t_max && temp > t_min) {
            rec->t = temp;
            rec->p = ray_point_at_param(r, rec->t);
            rec->normal = vec3_div_esc(vec3_sub(rec->p, sp->center),
                                       sp->radius);
            return true;
        }
    }
    return false;
}
