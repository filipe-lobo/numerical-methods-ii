#ifndef UTILS_
#define UTILS_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct variables {
	int function_number;
	double h;
	double x;
};
typedef struct variables Variables;

double f(int function_number, double x) {
	double fx;
	switch (function_number) {
	case 1:
		fx = -0.1 * pow(x, 4) - 0.15 * pow(x, 3) - 0.5 * pow(x, 2) - 0.25 * x
				+ 1.2;
		break;
	case 2:
		fx = 2 * pow(x, 4) - 6 * pow(x, 3) - 12 * x - 8;
		break;
	case 3:
		fx = 2 * pow(x, 3) + 3 * pow(x, 2) + 6 * x + 1;
		break;
	case 4:
		fx = 1 - x - 4 * pow(x, 3) + 2 * pow(x, 5);
		break;
	default:
		printf("Invalid function number.\n");
		return;
		break;
	}
	return fx;
}

Variables readFile(char* filePath) {
	FILE* file = fopen(filePath, "r");
	int i = 0;
	double j = 0;
	Variables v;

	fscanf(file, "%d", &i);
	v.function_number = i;
	fscanf(file, "%lf", &j);
	v.h = j;
	fscanf(file, "%lf", &j);
	v.x = j;

	fclose(file);

	return v;
}

#endif

