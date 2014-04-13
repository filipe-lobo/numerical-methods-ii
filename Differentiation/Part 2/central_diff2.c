#include "central_diff2.h"

double central2(int function_number, double h, double x) {
	double diff;
	if (f(function_number, x))
		diff = (f(function_number, x + h) - 2 * f(function_number, x)
				+ f(function_number, x - h)) / pow(h, 2);
	else {
		printf("Invalid function number.\n");
		return;
	}
	return diff;
}

int main(int argc, char *argv[]) {
	return 1;
}
