// Interface file for damper, damper is a interface class

#ifndef DAMPER_H
#define DAMPER_H

#include <iostream>
#include <string>

class Damper {

    public:
    virtual double get_damper_force(double damper_velocity) = 0;
    virtual double get_damper_coefficent(double damping_velocity) = 0;
    virtual ~Damper() = default;
};

#endif // DAMPER_H