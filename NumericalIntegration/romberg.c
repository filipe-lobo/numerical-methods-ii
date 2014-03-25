#include "romberg.h"

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
		printf("Warning: Function index must be on the [1, 5] interval.\n");
		return;
		break;
	}
	return fx;
}

float rombergTrap(float h, int fn, float a, float b) {
	float it = 0;
	float aux = a;

	while (aux <= b) {
		if (aux == a || aux == b)
			it += f(fn, aux);
		else
			it += 2 * f(fn, aux);
		aux += h;
	}

	it *= h / (float) 2;
	return it;
}

float rombergInt(float h, int fn, float a, float b) {
	float it = 1.333333333333333 * rombergTrap(h / (float) 2, fn, a, b)
			- 0.333333333333333 * rombergTrap(h, fn, a, b);
	return it;
}

Variables readFile(char* filePath) {
	FILE* file = fopen(filePath, "r");
	int i = 0;
	float j = 0;
	float k = 0;
	Variables v;

	fscanf(file, "%f", &j);
	v.h = j;
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
		printf("Result: %f", rombergInt(v.h, v.fn, v.a, v.b));
	}
	return 1;
}
