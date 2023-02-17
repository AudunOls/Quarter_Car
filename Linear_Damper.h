/* 
Linear Damper is an inherited class of Damper. It has two methods: get_damper_coeffient and 
get_damper velocityas well as one private attibute damping coefficient. 
Damping coefficient should be positive.

get_damper_coefficient takes in damper_velocity. For a negative velocity the damper will be in 
compression. The funciton returns the damping coefficient

get_damper_force takes in the damper velocity and returns: -velocity*damping_coefficient. 
When in compression the damper force will be positive. 
*/


#ifndef LINEAR_DAMPER_H
#define LINEAR_DAMPER_H
#include "Damper.h"
#include <iostream>
#include <string>


class Linear_Damper: public Damper {

    private:
    double damping_coefficient;     // Linear damper coefficient [Ns/m]
    
    public:
    Linear_Damper(double damping_coefficient = 1.0); 
    virtual double get_damper_force(double damper_velocity) override;
    virtual double get_damper_coefficent(double damper_velocity) override;
    virtual ~Linear_Damper()=default; 
};

#endif // LINEAR_DAMPER_H