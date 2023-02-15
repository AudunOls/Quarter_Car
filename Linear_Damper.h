
#ifndef LINEAR_DAMPER_H
#define LINEAR_DAMPER_H
#include "Damper.h"
#include <iostream>
#include <string>


class Linear_Damper: public Damper {

    private:
    double damping_coefficient;     // Linear damper coefficient [Ns/m]
    
    public:
    Linear_Damper(double damping_coefficient = 0.0); 
    virtual double get_damper_force(double damper_velocity) override;
    virtual double get_damper_coefficent(double damper_velocity) override;
    virtual ~Linear_Damper()=default; 
};

#endif // LINEAR_DAMPER_H