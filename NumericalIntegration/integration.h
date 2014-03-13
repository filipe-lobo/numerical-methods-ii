/*
*	Integration Methods: Header File
*	Author: Filipe Lobo - 344066
*/

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

// Structure "Variables" with the values used by the integration fuctions.

struct variables {
	float m;
	float* x;
	float* y;
};

typedef struct variables Variables;

// Function signatures.

float trapezoidal(float m, float* x, float* y);
float simpsonsThird(float m, float* x, float* y);
float simpsonsThreeEights(float m, float* x, float* y);
float romberg(float m, float* x, float* y);
float closedNewtonCotes(float n, float* x, float* y);
float openNewtonCotes(float n, float* x, float* y);
float gaussianX(float a, float b, float t);
Variables readFile(char* filePath);
