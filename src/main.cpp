#include <iostream>
#include "ray.h"

vec3 color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
}

int main() {
    int i, j, ir, ig, ib;
    int nx = 200;
    int ny = 100;
    float u, v;

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical  (0.0, 2.0, 0.0);
    vec3 origin    (0.0, 0.0, 0.0);
    for (j = ny-1; j >= 0; j--) {
        for (i = 0; i < nx; i++) {
            u = float(i)/float(nx);
            v = float(j)/float(ny);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical);
            vec3 col = color(r);
            ir = int(255.99*col[0]);
            ig = int(255.99*col[1]);
            ib = int(255.99*col[2]);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
    return 0;
}

