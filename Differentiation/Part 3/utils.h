#ifndef UTILS_
#define UTILS_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct variables {
	int points;
	double *x;
	double *y;
	double value;
};
typedef struct variables Variables;

double absoluteDouble(double number) {
	if (number < 0)
		return -number;
	else
		return number;
}

double max(double* array, int length) {
	int i;
	double aux = 0;
	for (i = 0; i < length; i++)
		if (array[i] > aux)
			aux = array[i];
	return aux;
}

int minIndex(double* array, int length) {
	int i, index;
	double aux = array[0];
	for (i = 0; i < length; i++)
		if (array[i] < aux) {
			aux = array[i];
			index = i;
		}
	return index;
}

Variables readFile(char* filePath) {
	FILE* file = fopen(filePath, "r");
	int i = 0;
	double j = 0;
	double k = 0;
	Variables v;

	fscanf(file, "%d", &i);
	v.points = i;

	v.x = malloc((v.points) * sizeof(double));
	v.y = malloc((v.points) * sizeof(double));

	for (i = 0; i < v.points; i++) {
		fscanf(file, "%lf\t%lf", &j, &k);
		v.x[i] = j;
		v.y[i] = k;
	}

	fscanf(file, "%lf", &j);
	v.value = j;

	fclose(file);

	return v;
}

#endif
