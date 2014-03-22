#include "trapezoidal.h"

float trapezoidal(int m, float* x, float* y) {
	float it = 0;
	float h = (x[m] - x[0]) / m;

	it = it + y[0];
	int i;
	for (i = 1; i <= m - 1; i++) {
		it = it + 2 * y[i];
	}
	it = (it + y[m]) * h / 2;
	return it;
}
/*
 float simpsonsThreeEights(int m, float* x, float* y) {
 float it = 0;
 if (m % 3 != 0)
 return;
 float h = (x[m] - x[0]) / m;

 int i;
 for (i = 0; i <= m; i++) {
 if (i == 0 || i == m)
 it = it + y[i];
 else {
 if (i % 3 == 0)
 it = it + 2 * y[i];
 else
 it = it + 3 * y[i];
 }
 }
 it = it * h * (3 / 8);
 return it;
 }
 */
Variables readFile(char* filePath) {
	FILE* file = fopen(filePath, "r");
	float i = 0;
	float j = 0;
	int counter = 0;
	Variables v;

	fscanf(file, "%f", &i);
	v.m = i;

	float auxX[v.m];
	float auxY[v.m];

	while (!feof(file)) {
		fscanf(file, "%f\t%f", &i, &j);
		auxX[counter] = i;
		auxY[counter] = j;
		counter++;
	}

	v.x = auxX;
	v.y = auxY;

	fclose(file);

	return v;
}

int main(int argc, char* argv[]) {
	return 1;
}
