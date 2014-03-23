#include "open_nc.h"

float f(int fn, float x) {
	float fx;
	switch (fn) {
	case 1:
		fx = 1 / (float) sqrt(x);
		break;
	case 2:
		fx = 1 / (float) sqrt(1 - pow(x, 2));
		break;
	case 3:
		fx = 2 * pow(x, 3) + 3 * pow(x, 2) + 6 * x + 1;
		break;
	case 4:
		fx = 1 - x - 4 * pow(x, 3) + 2 * pow(x, 5);
		break;
	case 5:
		fx = 4 / (float) (1 + pow(x, 2));
		break;
	default:
		return;
		break;
	}
	return fx;
}

float openNewtonCotes(int n, int fn, float a, float b) {
	float it = 0;
	float h = (b - a) / (float) (n + 1);
	float x = a;

	switch (n) {
	case 1:
		it = it + f(fn, a + h) + f(fn, a + 2 * h);
		it = it * h * 3 / (float) 2;
		break;
	case 2:
		it = it + 2 * f(fn, a + h) - f(fn, a + 2 * h) + 2 * f(fn, a + 3 * h);
		it = it * h * 4 / (float) 3;
		break;
	case 3:
		it = it + 11 * f(fn, a + h) + f(fn, a + 2 * h) + f(fn, a + 3 * h)
				+ 11 * f(fn, a + 4 * h);
		it = it * h * 5 / (float) 24;
		break;
	case 4:
		it = it + 11 * f(fn, a + h) - 14 * f(fn, a + 2 * h)
				+ 26 * f(fn, a + 3 * h) - 14 * f(fn, a + 4 * h)
				+ 11 * f(fn, a + 5 * h);
		it = it * h * 6 / (float) 20;
		break;
	default:
		return;
		break;
	}

	return it;
}

Variables readFile(char* filePath) {
	FILE* file = fopen(filePath, "r");
	int i = 0;
	float j = 0;
	float k = 0;
	Variables v;

	fscanf(file, "%d", &i);
	v.n = i;
	fscanf(file, "%d", &i);
	v.fn = i;
	fscanf(file, "%f\t%f", &j, &k);
	v.a = j;
	v.b = k;

	fclose(file);

	return v;
}

int main(int argc, char* argv[]) {
	return 1;
}
