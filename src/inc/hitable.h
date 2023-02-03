#ifndef _HITABLE_H_
#define _HITABLE_H_

#include <stdbool.h>
#include "ray.h"

typedef struct {
    double t;
    Vec3  p;
    Vec3  normal;
} hitrec;

/* puntero a función hit_cb que toma parámetros ... y retorna bool.
 * Declarado como tipo para poder usarlo dentro de un struct */
typedef bool (*hit_cb)(Ray r, double t_min, double t_max, 
                       hitrec *rec, void *self);

typedef struct {
    hit_cb callback; /* función que calcula el hit */
    void *self;      /* puntero al objeto que sea  */
} hitable;


void hitable_create(hit_cb, void *);

bool hitable_call_all(Ray, double, double, hitrec *);

void hitable_destroy();



#endif
