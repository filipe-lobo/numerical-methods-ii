#include "richardson_backward.h"

double richardsonBackward(double h, int function_number, double x) {
	double h2 = h / (double) 2;
	double diff = (4 * backward(h2, function_number, x) / (double) 3)
			- (backward(h, function_number, x) / (double) 3);
	return diff;
}

int main(int argc, char *argv[]) {
	return 1;
}
