#include "gauss_quadr.h"

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
		printf("Warning: Function index must be on the [1, 5] index.\n");
		return;
		break;
	}
	return fx;
}

float x(float a, float b, float t) {
	return ((b - a) / (float) 2) * t + (a + b) / (float) 2;
}

float quadrature(int n, int fn, float a, float b) {

	float it = 0;

	switch (n) {
	case 2:
		it += f(fn, x(a, b, -0.577350269189626));
		it += f(fn, x(a, b, 0.577350269189626));
		break;
	case 3:
		it += 0.555555555555556 * f(fn, x(a, b, -0.774596669241483));
		it += 0.888888888888889 * f(fn, x(a, b, 0));
		it += 0.555555555555556 * f(fn, x(a, b, 0.774596669241483));
		break;
	case 4:
		it += 0.347854845137454 * f(fn, x(a, b, -0.861136311594053));
		it += 0.652145154862546 * f(fn, x(a, b, -0.339981043584856));
		it += 0.652145154862546 * f(fn, x(a, b, 0.339981043584856));
		it += 0.347854845137454 * f(fn, x(a, b, 0.861136311594053));
		break;
	case 5:
		it += 0.236926885056189 * f(fn, x(a, b, -0.906179845938664));
		it += 0.478628670499366 * f(fn, x(a, b, -0.538469310105683));
		it += 0.568888888888889 * f(fn, x(a, b, 0));
		it += 0.478628670499366 * f(fn, x(a, b, 0.538469310105683));
		it += 0.236926885056189 * f(fn, x(a, b, 0.906179845938664));
		break;
	default:
		printf("Warning: Number of points must be on the [2, 5] interval.\n");
		return;
		break;
	}

	it *= (b - a) / (float) 2;
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
	if (argc != 2)
		printf("Usage: %s filename ", argv[0]);
	else {
		Variables v = readFile(argv[1]);
		printf("Result: %f", quadrature(v.n, v.fn, v.a, v.b));
	}
	return 1;
}
