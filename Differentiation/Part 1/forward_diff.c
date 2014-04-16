#include "forward_diff.h"

double forward(int points, int function_number, double h, double x) {
	double diff;
	switch (points) {
	case 2:
		diff = (f(function_number, x + h) - f(function_number, x)) / h;
		break;
	case 3:
		diff = (-f(function_number, x + 2 * h) + 4 * f(function_number, x + h)
				- 3 * f(function_number, x)) / (double) (2 * h);
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
		printf("Forward difference: %lf",
				forward(v.points, v.function_number, v.h, v.x));
	}
	return 1;
}
