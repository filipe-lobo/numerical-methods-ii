#ifndef UTILS_
#define UTILS_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>

struct variables {
	double v0;
	int functionIndex;
	double h;
	double a;
	double b;
};
typedef struct variables Variables;

struct vector {
	int length;
	float *vector;
};
typedef struct vector Vector;

struct result {
	Vector t;
	Vector v;
};
typedef struct result Result;

Vector allocateVector(int length) {
	Vector v;
	v.length = length;
	v.vector = malloc(length * sizeof(double));
	return v;
}

void printResultTable(Result result) {
	int index = result.v.length;
	int i;

	printf("i\tt\t\tv\n");

	for (i = 0; i < index; i++)
		printf("%d\t%lf\t%lf\n", i, result.t.vector[i], result.v.vector[i]);
}

double f(int index, double v, double t) {
	double fvt;

	switch (index) {
	case 1:
		fvt = v * pow(t, 3) - 1.5 * v;
		break;
	case 2:
		fvt = (1 + 4 * t) * sqrt(v);
		break;
	case 3:
		fvt = -2 * v + pow(t, 2);
		break;
	default:
		printf("Insert a valid function index.\n");
		break;
	}

	return fvt;
}

Variables readFile(char* filePath) {

	FILE* file = fopen(filePath, "r");
	int i;
	double j, k;
	Variables v;

	fscanf(file, "%lf", &j);
	v.v0 = j;
	fscanf(file, "%d", &i);
	v.functionIndex = i;
	fscanf(file, "%lf", &j);
	v.h = j;
	fscanf(file, "%lf\t%lf", &j, &k);
	v.a = j;
	v.b = k;

	fclose(file);

	return v;
}

char* scriptFunction(int index) {
	switch (index) {
	case 1:
		return "e^(0.25*x^4-1.5*x)";
		break;
	case 2:
		return "(1.0/4.0)*(2.0*t^2+t+2.0)^2";
		break;
	case 3:
		return "(1.0/4.0)*(2.0*t^2-2.0*t+3.0*e^(-2*t)+1.0)";
		break;
	default:
		printf("Insert a valid function index.\n");
		break;
	}

	return "";
}

void writeVectorToFile(FILE *file, Vector v) {
	fprintf(file, "[");
	int i;

	for (i = 0; i < v.length; i++) {
		if (i != v.length - 1)
			fprintf(file, "%lf, ", v.vector[i]);
		else
			fprintf(file, "%lf]\n", v.vector[i]);
	}
}

#endif
