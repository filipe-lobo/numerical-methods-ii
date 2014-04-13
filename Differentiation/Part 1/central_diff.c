#include "central_diff.h"

double central(int points, int function_number, double h, double x) {
	double diff;
	switch (points) {
	case 2:
		diff = (f(function_number, x + h) - f(function_number, x - h))
				/ (2 * h);
		break;
	case 4:
		diff = (-f(function_number, x + 2 * h) + 8 * f(function_number, x + h)
				- 8 * f(function_number, x - h) + f(function_number, x - 2 * h))
				/ (12 * h);
		break;
	default:
		printf("Invalid number of points.\n");
		return;
		break;
	}
	return diff;
}

int main(int argc, char *argv[]) {
	return 1;
}
