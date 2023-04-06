#ifndef RANDOM_INPUT_H
#define RANDOM_INPUT_H

#include "Road_Input.h"
#include <cmath>
#include <random>


class Random_Input : public Road_Input {

private:
    std::normal_distribution<double> norm;
    std::default_random_engine rd;


public:
    Random_Input(double mean = 0.0, double stddev = 0.1); // constructor
    virtual double get_road_velocity(double time) override;
    virtual void set_input(std::vector<double> input) override;
    virtual ~Random_Input() = default;
};

#endif //RANDOM_INPUT_H