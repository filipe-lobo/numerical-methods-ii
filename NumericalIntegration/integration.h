/*
*	Integration Methods: Header File
*	Author: Filipe Lobo - 344066
*/

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

// Structure "Variables" with the values used by the integration fuctions.

struct variables {
	int m;
	float* x;
	float* y;
};

typedef struct variables Variables;

// Function signatures.

float trapezoidal(int m, float* x, float* y);
float simpsonsThird(int m, float* x, float* y);
float simpsonsThreeEights(int m, float* x, float* y);
Variables readFile(char* filePath);
