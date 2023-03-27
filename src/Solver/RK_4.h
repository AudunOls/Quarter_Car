#pragma once

#include "Numerical_Solver.h"
#include <vector>

class RK_4 : public Numerical_Solver {

private:
    double a; // start time       
    double b; // end time
    double h; // step size time

public:
    RK_4(double a = 0.0, double b = 1.0, double h = 0.01); // constructor
    virtual std::vector<double> solve(std::vector<double> state,
        Quarter_Car qc, double time) override;
    virtual ~RK_4() = default;
};

