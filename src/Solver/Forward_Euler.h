#ifndef FORWARD_EULER
#define FORWARD_EULER
#include "Numerical_Solver.h"
#include "Dynamic_System.h"



class Forward_Euler : public Numerical_Solver {

private:
    double a; // start time       
    double b; // end time
    double h; // step size time

public:
    Forward_Euler(double a = 0.0, double b = 1.0, double h = 0.01); // constructor
    virtual std::vector<double> solve(std::vector<double> state,
        Dynamic_System * dyn_sys, double time) override;
    virtual ~Forward_Euler() = default;
};
#endif // FORWARD_EULER
