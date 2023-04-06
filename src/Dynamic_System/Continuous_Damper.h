/*
Continuous_Damper is an inherited class of Damper. It has two methods: get_damper_coeffient and
get_damper velocities.

get_damper_coefficient takes in damper_velocity. For a negative velocity the damper will be in
compression. The funciton returns the damping coefficient. The damper curve is modelled using the 
equation F(v) = a tanh(b*v). Where a has most impact on the amplitude of the curve, and b the curvature.  

get_damper_force takes in the damper velocity and returns the force.
When in compression the damper force will be positive.
*/


#ifndef CONTINUOUS_DAMPER_H
#define CONTINUOUS_DAMPER_H
#include "Damper.h"
#include <cmath>
#include <vector>

class Continuous_Damper : public Damper {

private:
    double a;   // [Ns/mm]
    double b;   // [s/mm]


public:
    Continuous_Damper(double a = 600.0, double b = 7);
        
    
    
    virtual double get_damper_force(double damper_velocity) override;
    virtual double get_damper_coefficent(double damper_velocity) override;
    virtual void set_damper_coefficent(std::vector<double> damper_coeff_vec) override;
    virtual ~Continuous_Damper() = default;
};

#endif // CONTINUOUS_DAMPER_H