#ifndef IMPULSE_INPUT_H
#define IMPULSE_INPUT_H
#include "Road_Input.h"
#include <iostream>
#include <string>


class Impulse_Input: public Road_Input {

    private:
    double start_time;     // Start time of simulation [s]
    double end_time;       // end time of simulaiton [s]
    double amplitude;      // amplitude of the ramp in road position [m]
    double ramp_time;      // time it takes for the ramp in road input [t] 
    
    public:
    Impulse_Input(double start_time= 0.0, double end_time = 1.0, double amplitude = 0.1, double ramp_time= 0.2); // constructor
    virtual double get_road_velocity(double time) override;
    virtual void set_input(std::vector<double> input) override;
    virtual ~Impulse_Input()=default; 
};

#endif // IMPULSE_INPUT_H

