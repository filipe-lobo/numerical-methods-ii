#ifndef SIMPSONS_38S_
#define SIMPSONS_38S_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct variables {
	int m;
	float* x;
	float* y;
};
typedef struct variables Variables;

float simpsonsThreeEights(int m, float* x, float* y);
Variables readFile(char* filePath);

#endif

