#ifndef ROMBERG_
#define ROMBERG_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

struct variables {
	float h;
	int fn;
	float a;
	float b;
};
typedef struct variables Variables;

float f(int fn, float x);
float rombergTrap(float h, int fn, float a, float b);
float rombergInt(float h, int fn, float a, float b);
Variables readFile(char* filePath);

#endif
