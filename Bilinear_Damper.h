/* 
Bilinear_Damper is an inherited class of Damper. It has two methods: get_damper_coeffient and 
get_damper velocityas well as six private attibutes. Damping coefficients should be positive. 

get_damper_coefficient takes in damper_velocity. For a negative velocity the damper will be in 
compression. The funciton returns the damping coefficient

get_damper_force takes in the damper velocity and returns the force. 
When in compression the damper force will be positive. 
*/


#ifndef BILINEAR_DAMPER_H
#define BILINEAR_DAMPER_H
#include "Damper.h"
#include <iostream>
#include <string>


class Bilinear_Damper: public Damper {

    private:   
    double lowspeed_compression_damping_coefficient;    //damper coefficient [Ns/m]
    double highspeed_compression_damping_coefficient;   //damper coefficient [Ns/m]
    double lowspeed_rebound_damping_coefficient;        //damper coefficient [Ns/m]
    double highspeed_rebound_damping_coefficient;       //damper coefficient [Ns/m]
    double compression_kneespeed;                       //[m/s]
    double rebound_kneespeed;                           //[m/s]
    
    public:
    Bilinear_Damper(double lowspeed_compression_damping_coefficient = 1.0, 
        double highspeed_compression_damping_coefficient = 1.0, 
        double lowspeed_rebound_damping_coefficient = 1.0, 
        double highspeed_rebound_damping_coefficient = 1.0, 
        double compression_kneespeed = 10,
        double rebound_kneespeed = 10);
    virtual double get_damper_force(double damper_velocity) override;
    virtual double get_damper_coefficent(double damper_velocity) override;
    virtual ~Bilinear_Damper()=default; 
};

#endif // BILINEAR_DAMPER_H