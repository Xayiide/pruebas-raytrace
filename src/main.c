#include <stdio.h>
//#include <stdbool.h> /* bool */
#include "sphere.h"
#include "vec3.h"
#include "ray.h"

#define WIDTH  200
#define HEIGHT 100

Vec3 color(Ray r) {
    Vec3   ret;
    Vec3   unit_dir;
    float  t;

    hitrec rec;
    if (hitable_call_all(r, 0.0, 100000000, &rec)) {
        ret = vec3_mul_esc(vec3_create(rec.normal.x + 1,
                                       rec.normal.y + 1,
                                       rec.normal.z + 1),
                           0.5);
    }
    else {
        unit_dir = vec3_unit_vector(r.direction);
        t = 0.5 * (unit_dir.y + 1);
        ret = vec3_add(vec3_mul_esc(vec3_create(1, 1, 1), (1 - t)),
                       vec3_mul_esc(vec3_create(0.5, 0.7, 1), t));
    }
    return ret;
}

int main() {
    int   i, j;
    int   ir, ig, ib;
    float u, v;
    Ray  r;
    Vec3 col;
    Vec3 lower_left = vec3_create(-2, -1, -1);
    Vec3 horizontal = vec3_create(4, 0, 0);
    Vec3 vertical   = vec3_create(0, 2, 0);
    Vec3 origin     = vec3_create(0, 0, 0);

    /* sphere needs to be created with malloc for this to work */
    hitable_create((hit_cb)ray_hit_sphere_cb,
                   sphere_create(vec3_create(0, 0, -1), 0.5));
    hitable_create((hit_cb)ray_hit_sphere_cb,
                   sphere_create(vec3_create(0, -100.5, -1), 100));

    printf("P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (j = HEIGHT - 1; j >= 0; j--) {
        for (i = 0; i < WIDTH; i++) {
            u = (float)i / (float)WIDTH;
            v = (float)j / (float)HEIGHT;
            r.origin = origin;
            r.direction = vec3_add(lower_left,
                                   vec3_add(vec3_mul_esc(horizontal, u),
                                            vec3_mul_esc(vertical, v)));
            col = color(r);

            ir = (int)(255.99*col.x);
            ig = (int)(255.99*col.y);
            ib = (int)(255.99*col.z);

            printf("%d %d %d\n", ir, ig, ib);
        }
    }

    hitable_destroy();
    return 0;
}

