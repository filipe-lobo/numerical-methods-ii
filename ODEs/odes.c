#include "odes.h"

void forwardEuler(Variables variables) {
	int n = ((variables.b - variables.a) / variables.h) + 1;
	Result r;

	r.t = allocateVector(n);
	r.v = allocateVector(n);

	r.t.vector[0] = variables.a;
	r.v.vector[0] = variables.v0;

	int i;
	for (i = 1; i < n; i++) {
		r.t.vector[i] = r.t.vector[i - 1] + variables.h;
		r.v.vector[i] = r.v.vector[i - 1]
				+ variables.h
						* f(variables.functionIndex, r.v.vector[i - 1],
								r.t.vector[i - 1]);
	}

	printf("Forward Euler:\n");
	printResultTable(r);
	printf("\n");

}

void rungeKutta2(Variables variables) {
	double k1, k2;
	int n = ((variables.b - variables.a) / variables.h) + 1;
	Result r;

	r.t = allocateVector(n);
	r.v = allocateVector(n);

	r.t.vector[0] = variables.a;
	r.v.vector[0] = variables.v0;

	int i;
	for (i = 1; i < n; i++) {
		r.t.vector[i] = r.t.vector[i - 1] + variables.h;

		k1 = variables.h
				* f(variables.functionIndex, r.v.vector[i - 1],
						r.t.vector[i - 1]);
		k2 = variables.h
				* f(variables.functionIndex, r.v.vector[i - 1] + k1,
						r.t.vector[i]);
		r.v.vector[i] = r.v.vector[i - 1] + 0.5 * (k1 + k2);
	}

	printf("Runge-Kutta (Second Order):\n");
	printResultTable(r);
	printf("\n");
}

void rungeKutta3(Variables variables) {
	double k1, k2, k3;
	int n = ((variables.b - variables.a) / variables.h) + 1;
	Result r;

	r.t = allocateVector(n);
	r.v = allocateVector(n);

	r.t.vector[0] = variables.a;
	r.v.vector[0] = variables.v0;

	int i;
	for (i = 1; i < n; i++) {
		r.t.vector[i] = r.t.vector[i - 1] + variables.h;

		k1 = variables.h
				* f(variables.functionIndex, r.v.vector[i - 1],
						r.t.vector[i - 1]);
		k2 = variables.h
				* f(variables.functionIndex, r.v.vector[i - 1] + 0.5 * k1,
						r.t.vector[i - 1] + variables.h / 2.0);
		k3 = variables.h
				* f(variables.functionIndex, r.v.vector[i - 1] - k1 + 2 * k2,
						r.t.vector[i - 1] + variables.h);
		r.v.vector[i] = r.v.vector[i - 1] + (1.0 / 6.0) * (k1 + 4 * k2 + k3);
	}

	printf("Runge-Kutta (Third Order):\n");
	printResultTable(r);
	printf("\n");
}

void rungeKutta4(Variables variables) {
	double k1, k2, k3, k4;
	int n = ((variables.b - variables.a) / variables.h) + 1;
	Result r;

	r.t = allocateVector(n);
	r.v = allocateVector(n);

	r.t.vector[0] = variables.a;
	r.v.vector[0] = variables.v0;

	int i;
	for (i = 1; i < n; i++) {
		r.t.vector[i] = r.t.vector[i - 1] + variables.h;

		k1 = variables.h
				* f(variables.functionIndex, r.v.vector[i - 1],
						r.t.vector[i - 1]);
		k2 = variables.h
				* f(variables.functionIndex,
						r.v.vector[i - 1] + (1.0 / 3.0) * k1,
						r.t.vector[i - 1] + variables.h / 3.0);
		k3 = variables.h
				* f(variables.functionIndex,
						r.v.vector[i - 1] + (k1 / 3.0) + (k2 / 3.0),
						r.t.vector[i - 1] + (2.0 / 3.0) * variables.h);
		k4 = variables.h
				* f(variables.functionIndex, r.v.vector[i - 1] + k1 - k2 + k3,
						r.t.vector[i - 1] + variables.h);
		r.v.vector[i] = r.v.vector[i - 1]
				+ (1.0 / 8.0) * (k1 + 3 * k2 + 3 * k3 + k4);
	}

	printf("Runge-Kutta (Fourth Order):\n");
	printResultTable(r);
	printf("\n");
}

void predictorCorrector3(Variables variables) {
	double k1, k2, k3, k4;
	int n = ((variables.b - variables.a) / variables.h) + 1;
	Vector p;
	Result r;

	r.t = allocateVector(n);
	r.v = allocateVector(n);
	p = allocateVector(n);

	r.t.vector[0] = variables.a;
	r.v.vector[0] = variables.v0;

	int i;
	for (i = 1; i < n; i++) {
		r.t.vector[i] = r.t.vector[i - 1] + variables.h;

		if (i == 1 || i == 2) {
			k1 = variables.h
					* f(variables.functionIndex, r.v.vector[i - 1],
							r.t.vector[i - 1]);
			k2 = variables.h
					* f(variables.functionIndex,
							r.v.vector[i - 1] + (1.0 / 3.0) * k1,
							r.t.vector[i - 1] + variables.h / 3.0);
			k3 = variables.h
					* f(variables.functionIndex,
							r.v.vector[i - 1] + (k1 / 3.0) + (k2 / 3.0),
							r.t.vector[i - 1] + (2.0 / 3.0) * variables.h);
			k4 = variables.h
					* f(variables.functionIndex,
							r.v.vector[i - 1] + k1 - k2 + k3,
							r.t.vector[i - 1] + variables.h);
			r.v.vector[i] = r.v.vector[i - 1]
					+ (1.0 / 8.0) * (k1 + 3 * k2 + 3 * k3 + k4);
		}
	}

	for (i = 3; i < n; i++) {
		p.vector[i] = r.v.vector[i - 1]
				+ (variables.h / 12.0)
						* (23.0
								* f(variables.functionIndex, r.v.vector[i - 1],
										r.t.vector[i - 1])
								- 16.0
										* f(variables.functionIndex,
												r.v.vector[i - 2],
												r.t.vector[i - 2])
								+ 5.0
										* f(variables.functionIndex,
												r.v.vector[i - 3],
												r.t.vector[i - 3]));
		r.v.vector[i] = r.v.vector[i - 1]
				+ (variables.h / 12.0)
						* (5.0
								* f(variables.functionIndex, p.vector[i],
										r.t.vector[i])
								+ 8.0
										* f(variables.functionIndex,
												r.v.vector[i - 1],
												r.t.vector[i - 1])
								- f(variables.functionIndex, r.v.vector[i - 2],
										r.t.vector[i - 2]));
	}

	printf("Predictor-Corrector Method (Third Order):\n");
	printResultTable(r);
	printf("\n");
}

void predictorCorrector4(Variables variables) {
	double k1, k2, k3, k4;
	int n = ((variables.b - variables.a) / variables.h) + 1;
	Vector p;
	Result r;

	r.t = allocateVector(n);
	r.v = allocateVector(n);
	p = allocateVector(n);

	r.t.vector[0] = variables.a;
	r.v.vector[0] = variables.v0;

	int i;
	for (i = 1; i < n; i++) {
		r.t.vector[i] = r.t.vector[i - 1] + variables.h;

		if (i == 1 || i == 2 || i == 3) {
			k1 = variables.h
					* f(variables.functionIndex, r.v.vector[i - 1],
							r.t.vector[i - 1]);
			k2 = variables.h
					* f(variables.functionIndex,
							r.v.vector[i - 1] + (1.0 / 3.0) * k1,
							r.t.vector[i - 1] + variables.h / 3.0);
			k3 = variables.h
					* f(variables.functionIndex,
							r.v.vector[i - 1] + (k1 / 3.0) + (k2 / 3.0),
							r.t.vector[i - 1] + (2.0 / 3.0) * variables.h);
			k4 = variables.h
					* f(variables.functionIndex,
							r.v.vector[i - 1] + k1 - k2 + k3,
							r.t.vector[i - 1] + variables.h);
			r.v.vector[i] = r.v.vector[i - 1]
					+ (1.0 / 8.0) * (k1 + 3 * k2 + 3 * k3 + k4);
		}
	}

	for (i = 4; i < n; i++) {
		p.vector[i] = r.v.vector[i - 1]
				+ (variables.h / 24.0)
						* (55.0
								* f(variables.functionIndex, r.v.vector[i - 1],
										r.t.vector[i - 1])
								- 59.0
										* f(variables.functionIndex,
												r.v.vector[i - 2],
												r.t.vector[i - 2])
								+ 37.0
										* f(variables.functionIndex,
												r.v.vector[i - 3],
												r.t.vector[i - 3])
								- 9.0
										* f(variables.functionIndex,
												r.v.vector[i - 4],
												r.t.vector[i - 4]));
		r.v.vector[i] = r.v.vector[i - 1]
				+ (variables.h / 24.0)
						* (9.0
								* f(variables.functionIndex, p.vector[i],
										r.t.vector[i])
								+ 19.0
										* f(variables.functionIndex,
												r.v.vector[i - 1],
												r.t.vector[i - 1])
								- 5.0
										* f(variables.functionIndex,
												r.v.vector[i - 2],
												r.t.vector[i - 2])
								+ f(variables.functionIndex, r.v.vector[i - 3],
										r.t.vector[i - 3]));
	}

	printf("Predictor-Corrector Method (Fourth Order):\n");
	printResultTable(r);
	printf("\n");
}

int main(int argc, char *argv[]) {
	if (argc != 2)
		printf("Usage: %s filename ", argv[0]);
	else {
		Variables v = readFile(argv[1]);
		forwardEuler(v);
		rungeKutta2(v);
		rungeKutta3(v);
		rungeKutta4(v);
		predictorCorrector3(v);
		predictorCorrector4(v);
	}

	return 1;
}
