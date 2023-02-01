#include <iostream>
#include "vec3.h"

int main() {
    int i, j, ir, ig, ib;
    int nx = 200;
    int ny = 100;

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";

    for (j = ny - 1; j >= 0; j--) {
        for (i = 0; i < nx; i++) {
            vec3 col(float(i) / float(nx),
                     float(j)   / float(ny),
                     0.6);
            ir = int(255.99 * col[0]);
            ig = int(255.99 * col[1]);
            ib = int(255.99 * col[2]); /* 51 */

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
    return 0;
}

