#ifndef OPEN_NC_
#define OPEN_NC_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

struct variablesSnd {
	float n;
	float fn;
	float a;
	float b;
};
typedef struct variablesSnd VariablesSnd;

float f(int fn, float x);
float openNewtonCotes(float n, int fn, float a, float b);

#endif
