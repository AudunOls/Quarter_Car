#ifndef NUMERICAL_SOLVER
#define NUMERICAL_SOLVER

#include <vector>
#include "Quarter_Car.h"

class Numerical_Solver {

public:
    virtual std::vector<double> solve(std::vector<double> state,
        Quarter_Car qc, double time) = 0;
    virtual ~Numerical_Solver() = default;
};

#endif // NUMERICAL_SOLVER