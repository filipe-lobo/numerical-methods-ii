#include "open_nc.h"

float f(int fn, float x) {
	float fx;
	switch (fn) {
	case 1:
		fx = 1 / sqrt(x);
		break;
	case 2:
		fx = 1 / sqrt(1 - pow(x, 2));
		break;
	case 3:
		fx = 2 * pow(x, 3) + 3 * pow(x, 2) + 6 * x + 1;
		break;
	case 4:
		fx = 1 - x - 4 * pow(x, 3) + 2 * pow(x, 5);
		break;
	case 5:
		fx = 4 / (1 + pow(x, 2));
		break;
	default:
		return;
		break;
	}
	return fx;
}

float openNewtonCotes(float n, int fn, float a, float b) {
	float it = 0;

	if (n >= 1 && n <= 4) {
		float* alpha = { 0, 3 / 2, 4 / 3, 5 / 24, 6 / 20 };
		float** w = { { 0 }, { 0, 1, 1, 0 }, { 0, 2, -1, 2, 0 }, { 0, 11, 1, 1,
				11, 0 }, { 0, 11, -14, 26, -14, 11, 0 } };
		float h = (b - a) / (n + 1);
		float x = a;

		int i;
		for (i = 0; i <= n + 2; i++) {
			if (f(fn, a)) {
				it = it + w[n][i] * f(fn, a);
				x = x + h;
			} else
				return;
		}
		it = it * h * alpha[n];
	} else
		return;

	return it;
}
