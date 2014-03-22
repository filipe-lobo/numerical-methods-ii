#ifndef GAUSS_QUAD_
#define GAUSS_QUAD_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

/*
 struct variables {
 float n;
 float fn;
 float a;
 float b;
 };
 typedef struct variables Variables;
 */

// float f(float fn, float x);
float x(float a, float b, float t);
float quadrature(float n, float fn, float a, float b);

#endif
