#ifndef OPEN_NC_
#define OPEN_NC_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

struct variables {
	int n;
	int fn;
	float a;
	float b;
};
typedef struct variables Variables;

float f(int fn, float x);
float openNewtonCotes(int n, int fn, float a, float b);
Variables readFile(char* filePath);

#endif
