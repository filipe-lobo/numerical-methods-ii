#ifndef SIMPSONS_TRD_
#define SIMPSONS_TRD_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct variables {
	int m;
	float* x;
	float* y;
};
typedef struct variables Variables;

float simpsonsThird(int m, float* x, float* y);
Variables readFile(char* filePath);

#endif
