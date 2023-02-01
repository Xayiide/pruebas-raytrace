#include <iostream>

int main() {
    int i, j, ir, ig, ib;
    float r, g, b;
    int nx = 200;
    int ny = 100;

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    for (j = ny - 1; j >= 0; j--) {
        for (i = 0; i < nx; i++) {
            r = float(i) / float(nx);
            g = float(j) / float(ny);
            b = 0.2;

            ir = int(255.99 * r);
            ig = int(255.99 * g);
            ib = int(255.99 * b); /* 51 */

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    return 0;
}

