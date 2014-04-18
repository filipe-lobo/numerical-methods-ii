#include "backward_diff.h"

double backward(int points, int function_number, double h, double x) {
	double diff;
	switch (points) {
	case 2:
		diff = (f(function_number, x) - f(function_number, x - h)) / h;
		break;
	case 3:
		diff = (3 * f(function_number, x) - 4 * f(function_number, x - h)
				+ f(function_number, x - 2 * h)) / (double) (2 * h);
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
		printf("Backward difference: %lf",
				backward(v.points, v.function_number, v.h, v.x));
	}
	return 1;
}
