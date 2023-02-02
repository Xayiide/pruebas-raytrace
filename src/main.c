#include <stdio.h>
#include "vec3.h"

#define WIDTH  200
#define HEIGHT 100


int main() {
    int i, j;
    int ir, ig, ib;
    float r, g, b;

    printf("P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (j = HEIGHT - 1; j >= 0; j--) {
        for (i = 0; i < WIDTH; i++) {
            r = (float)i / (float)WIDTH;
            g = (float)j / (float)HEIGHT;
            b = 0.6;

            ir = (int)(255.99*r);
            ig = (int)(255.99*g);
            ib = (int)(255.99*b);

            printf("%d %d %d\n", ir, ig, ib);
        }
    }
    return 0;
}

