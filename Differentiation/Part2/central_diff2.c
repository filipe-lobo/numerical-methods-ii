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
	if (argc != 2)
		printf("Usage: %s filename ", argv[0]);
	else {
		Variables v = readFile(argv[1]);
		printf("Central difference: %lf",
				central2(v.function_number, v.h, v.x));
	}
	return 1;
}
