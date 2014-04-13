#include "forward_diff.h"

double forward(int points, int function_number, double h, double x) {
	double diff;
	switch (points) {
	case 2:
		diff = (f(function_number, x + h) - f(function_number, x)) / h;
		break;
	case 3:
		diff = (-f(function_number, x + 2 * h) + 4 * f(function_number, x + h)
				- 3 * f(function_number, x)) / (2 * h);
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
