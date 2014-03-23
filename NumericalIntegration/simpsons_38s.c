#include "simpsons_38s.h"

float simpsonsThreeEights(int m, float* x, float* y) {
	float it = 0;
	if (m % 3 != 0) {
		return;
	}
	float h = (x[m] - x[0]) / (float) m;

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
	it = it * h * 3 / (float) 8;
	return it;
}

Variables readFile(char* filePath) {
	FILE* file = fopen(filePath, "r");
	int m = 0;
	float i = 0;
	float j = 0;
	int counter = 0;
	Variables v;

	fscanf(file, "%d", &m);
	v.m = m;

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
