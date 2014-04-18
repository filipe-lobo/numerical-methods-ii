#include "gendiff.h"

double genDiff(int points, double* x, double* y, double value) {
	double diff = 0;

	int idx[3] = { 0, 1, 2 };

	if (points > 3) {
		double temp[points];
		int i;

		for (i = 0; i < points; i++)
			temp[i] = absoluteDouble(x[i] - value);

		double auxMax = max(temp, points);

		for (i = 0; i < 3; i++) {
			idx[i] = minIndex(temp, points);
			temp[idx[i]] = auxMax;
		}

	} else {
		if (points != 3) {
			printf("Invalid number of points.\n");
			return;
		}
	}

	diff += y[idx[0]]
			* ((2 * value - x[idx[1]] - x[idx[2]])
					/ ((x[idx[0]] - x[idx[1]]) * (x[idx[0]] - x[idx[2]])));
	diff += y[idx[1]]
			* ((2 * value - x[idx[0]] - x[idx[2]])
					/ ((x[idx[1]] - x[idx[0]]) * (x[idx[1]] - x[idx[2]])));
	diff += y[idx[2]]
			* ((2 * value - x[idx[0]] - x[idx[1]])
					/ ((x[idx[2]] - x[idx[0]]) * (x[idx[2]] - x[idx[1]])));
	return diff;
}

int main(int argc, char *argv[]) {
	if (argc != 2)
		printf("Usage: %s filename ", argv[0]);
	else {
		Variables v = readFile(argv[1]);
		printf("Result: %lf", genDiff(v.points, v.x, v.y, v.value));
	}
	return 1;
}
