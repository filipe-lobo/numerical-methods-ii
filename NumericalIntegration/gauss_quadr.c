#include "gauss_quadr.h"
// #include "open_nc.h"

/*
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
 return NULL;
 break;
 }
 return fx;
 }
 */

float x(float a, float b, float t) {
	return (b - a) / 2 * t - (a + b) / 2;
}

float quadrature(float n, float fn, float a, float b) {
	float it = 0;

	if (n >= 2 && n <= 5) {
		float** t = { { 0 }, { sqrt(1 / 3), -sqrt(1 / 3) }, { 0, sqrt(3 / 5),
				-sqrt(3 / 5) }, { sqrt((3 - 2 * sqrt(6 / 5)) / 7), -sqrt(
				(3 - 2 * sqrt(6 / 5)) / 7), sqrt((3 + 2 * sqrt(6 / 5)) / 7),
				-sqrt((3 + 2 * sqrt(6 / 5)) / 7) }, { 0, (1 / 3)
				* sqrt(5 - 2 * sqrt(10 / 7)), -(1 / 3)
				* sqrt(5 - 2 * sqrt(10 / 7)), (1 / 3)
				* sqrt(5 + 2 * sqrt(10 / 7)), -(1 / 3)
				* sqrt(5 + 2 * sqrt(10 / 7)) } };
		float** upperA = { { 2 }, { 1, 1 }, { 8 / 9, 5 / 9, 5 / 9 }, { (18
				+ sqrt(30)) / 36, (18 + sqrt(30)) / 36, (18 - sqrt(30)) / 36,
				(18 - sqrt(30)) / 36 }, { 128 / 225, (322 + 13 * sqrt(70))
				/ 900, (322 + 13 * sqrt(70)) / 900, (322 - 13 * sqrt(70)) / 900,
				(322 - 13 * sqrt(70)) / 900 } };

		int i;
		for (i = 0; i < n; i++) {
			if (f(fn, x(a, b, t[n - 1][i])))
				it = it + upperA[n - 1][i] * f(fn, x(a, b, t[n - 1][i]));
			else
				return NULL;
		}
		it = it * (b - a) / 2;
	} else
		return NULL;

	return it;
}
