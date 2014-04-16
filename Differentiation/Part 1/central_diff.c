#include "central_diff.h"

double central(int points, int function_number, double h, double x) {
	double diff;
	switch (points) {
	case 2:
		diff = (f(function_number, x + h) - f(function_number, x - h))
				/ (double) (2 * h);
		break;
	case 4:
		diff = (-f(function_number, x + 2 * h) + 8 * f(function_number, x + h)
				- 8 * f(function_number, x - h) + f(function_number, x - 2 * h))
				/ (double) (12 * h);
		break;
	default:
		printf("Invalid number of points.\n");
		return;
		break;
	}
	return diff;
}

int main(int argc, char *argv[]) {
	if (argc != 2)
		printf("Usage: %s filename ", argv[0]);
	else {
		Variables v = readFile(argv[1]);
		printf("Central difference: %lf",
				central(v.points, v.function_number, v.h, v.x));
	}
	return 1;
}
