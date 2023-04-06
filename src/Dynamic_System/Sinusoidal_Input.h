#ifndef SINUSOIDAL_INPUT_H
#define SINUSOIDAL_INPUT_H
#include "Road_Input.h"
#include <cmath>


class Sinusoidal_Input : public Road_Input{

private:
    double start_time;     // Start time of simulation [s]
    double end_time;       // end time of simulaiton [s]
    double amplitude;      // amplitude of the ramp in road position [m]
    double frequency;      // time it takes for the ramp in road input [t] 

public:
    Sinusoidal_Input(double start_time = 0.0, double end_time = 1.0, double amplitude = 0.5, double frequency = 5); // constructor
    virtual double get_road_velocity(double time) override;
    virtual void set_input(std::vector<double> input) override;
    virtual ~Sinusoidal_Input() = default;
};

#endif // !SINUSOIDAL_INPUT_H

