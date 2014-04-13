#include "forward_diff2.h"

double forward2(int function_number, double h, double x) {
	double diff;
	if (f(function_number, x))
		diff = (f(function_number, x + 2 * h) - 2 * f(function_number, x + h)
				+ f(function_number, x)) / pow(h, 2);
	else {
		printf("Invalid function number.\n");
		return;
	}
	return diff;
}

int main(int argc, char *argv[]) {
	return 1;
}
