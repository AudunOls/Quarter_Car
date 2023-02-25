#ifndef RANDOM_INPUT_H
#define RANDOM_INPUT_H

#include "Road_Input.h"
#include <iostream>
#include <string>
#include <cmath>


class Random_Input : public Road_Input {

private:
    double mean;         // mean value
    double stddev;       // standard deviation


public:
    Random_Input(double mean = 0.0, double stddev = 0.1); // constructor
    virtual double get_road_velocity(double time) override;
    virtual ~Random_Input() = default;
};

#endif //RANDOM_INPUT_H