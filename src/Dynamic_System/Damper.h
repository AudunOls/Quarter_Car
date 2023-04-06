/*
Damper is an interface class with two methods get_damper_force and get_damper_coefficient

get_damper_coefficient inputs damper_velocity and returns the damper coefficient

get_damper_force inputs the damper_velocity and return the force in the damper
*/

#ifndef DAMPER_H
#define DAMPER_H

#include <vector>


class Damper {

    public:
    virtual double get_damper_force(double damper_velocity) = 0;
    virtual double get_damper_coefficent(double damper_velocity) = 0;
    virtual void set_damper_coefficent(std::vector<double> damper_coeff_vec) = 0;
    virtual ~Damper() = default;
};

#endif // DAMPER_H