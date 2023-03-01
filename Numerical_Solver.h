#ifndef NUMERICAL_SOLVER
#define NUMERICAL_SOLVER

#include <vector>

class Numerical_Solver {

public:
    virtual std::vector<double> solve(std::vector<double>, std::vector<double>, double) = 0;
    virtual ~Numerical_Solver() = default;
};

#endif // NUMERICAL_SOLVER