#include "trapezoidal.h"

float trapezoidal(int m, float* x, float* y) {
	float it = 0;
	float h = (x[m] - x[0]) / (float) m;

	it = it + y[0];
	int i;
	for (i = 1; i <= m - 1; i++) {
		it = it + 2 * y[i];
	}
	it = (it + y[m]) * h / (float) 2;
	return it;
}

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
	if (argc != 2)
		printf("Usage: %s filename ", argv[0]);
	else {
		Variables v = readFile(argv[1]);
		printf("Result: %f", trapezoidal(v.m, v.x, v.y));
	}
	return 1;
}
