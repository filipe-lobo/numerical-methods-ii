#ifndef ODES_
#define ODES_

#include "utils.h"

Result forwardEuler(Variables variables);
Result rungeKutta2(Variables variables);
Result rungeKutta3(Variables variables);
Result rungeKutta4(Variables variables);
Result predictorCorrector3(Variables variables);
Result predictorCorrector4(Variables variables);

void makeScript(Variables variables);

#endif
