#include <stdio.h>
//#include <stdbool.h> /* bool */
#include "sphere.h"
#include "vec3.h"
#include "ray.h"

#define WIDTH  200
#define HEIGHT 100

Vec3 color(Ray r) {
    Vec3   unit_dir;
    float  t;
    Vec3   ret;
    Vec3   sphere_pos = vec3_create(0, 0, -1);

    unit_dir = vec3_unit_vector(r.direction);
    t        = 0.5 * (unit_dir.y + 1.0);

    if (ray_sphere_collide(r, (Sphere){.center = sphere_pos, .radius = 0.5}))
    {
        return vec3_create(1, 0, 0);
    }


    ret = vec3_add(vec3_mul_esc(vec3_create(1, 1, 1), (1 - t)),
                   vec3_mul_esc(vec3_create(0.5, 0.7, 1), t));

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
    Vec3 vertical   = vec3_create(1, 2, 0);
    Vec3 origin     = vec3_create(0, 0, 0);

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
    return 0;
}

