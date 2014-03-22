#include "romberg.h"
// #include "open_nc.h"
// #include "closed_nc.h"

float rombergTrap(float h, float fn, float a, float b) {
	float it = 0;
	float n = (b - a) / h;
	float aux =;

	while (aux <= b) {
		if (aux == a || aux == b)
			it = it + f(fn, aux);
		else
			it = it + 2 * f(fn, aux);
		aux = aux + h;
	}

	it = it * h / 2;
	return it;
}

float rombergInt(float h, float fn, float a, float b) {
	return (4 / 3) * rombergTrap(h / 2, fn, a, b)
			- (1 / 3) * rombergTrap(h, fn, a, b);
}
