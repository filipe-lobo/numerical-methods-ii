#ifndef TRAPEZOIDAL_
#define TRAPEZOIDAL_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct variables {
	int m;
	float* x;
	float* y;
};
typedef struct variables Variables;

float trapezoidal(int m, float* x, float* y);
//float simpsonsThird(int m, float* x, float* y);
//float simpsonsThreeEights(int m, float* x, float* y);
Variables readFile(char* filePath);

#endif
