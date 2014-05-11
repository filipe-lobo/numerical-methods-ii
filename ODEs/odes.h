#ifndef ODES_
#define ODES_

#include "utils.h"

void forwardEuler(Variables variables);
void rungeKutta2(Variables variables);
void rungeKutta3(Variables variables);
void rungeKutta4(Variables variables);
void predictorCorrector3(Variables variables);
void predictorCorrector4(Variables variables);

#endif
