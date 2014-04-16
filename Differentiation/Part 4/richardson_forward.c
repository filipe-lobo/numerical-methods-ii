#include "richardson_forward.h"

double richardsonForward(double h, int function_number, double x) {
	double h2 = h / (double) 2;
	double diff = (4 * forward(h2, function_number, x) / (double) 3)
			- (forward(h, function_number, x) / (double) 3);
	return diff;
}

int main(int argc, char *argv[]) {
	if (argc != 2)
		printf("Usage: %s filename ", argv[0]);
	else {
		Variables v = readFile(argv[1]);
		printf("Richardson's Extrapolation (Forward): %lf",
				richardsonForward(v.h, v.function_number, v.x));
	}
	return 1;
}
