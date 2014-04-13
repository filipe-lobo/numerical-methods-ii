#ifndef GAUSS_QUAD_
#define GAUSS_QUAD_

#include "open_nc.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

float x(float a, float b, float t);
float quadrature(int n, int fn, float a, float b);

#endif
