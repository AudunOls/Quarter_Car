#ifndef NUMERICAL_SOLVER
#define NUMERICAL_SOLVER

#include <vector>
#include "Dynamic_System.h"

class Numerical_Solver {

public:
    virtual std::vector<double> solve(std::vector<double> state,
        Dynamic_System * dyn_sys, double time) = 0;
    virtual ~Numerical_Solver() = default;
};

#endif // NUMERICAL_SOLVER