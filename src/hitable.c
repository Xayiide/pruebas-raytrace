#include "hitable.h"
#include <stdlib.h>  /* free    */
#include <stdbool.h> /* bool    */
#include <stdint.h>  /* uint8_t */

static uint8_t num_hitables = 0;
static hitable hitable_array[256];

void hitable_create(hit_cb callback, void *self) {
    hitable r;

    r.callback = callback;
    r.self     = self;

    hitable_array[num_hitables] = r;
    num_hitables++;
}


bool hitable_call_all(Ray r, float t_min, float t_max, hitrec *rec) {
    hitrec temp;
    bool hit_anything = false;
    uint8_t i;

    double closest = t_max; /* types? */
    for (i = 0; i < num_hitables; i++) {
        if (hitable_array[i].callback(r, t_min, closest,
                                      &temp, hitable_array[i].self)) {
            hit_anything = true;
            closest = temp.t;
            *rec = temp;
        }
    }
    return hit_anything;
}

void hitable_destroy() {
    uint8_t i;
    for (i = 0; i < num_hitables; i++)
        if (hitable_array[i].self)
            free(hitable_array[i].self);

}
