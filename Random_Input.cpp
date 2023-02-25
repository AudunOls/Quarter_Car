#include "Road_Input.h"
#include "Random_Input.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iterator>
#include <random>
#include <chrono>


Random_Input::Random_Input(double mean, double stddev)
    : mean{ mean }, stddev{ stddev }{

}

double Random_Input::get_road_velocity(double time) {
    unsigned int seed = int(time*100);
    auto urbg = std::mt19937{ seed };
    auto norm = std::normal_distribution<double>{ mean,stddev };
    double value = norm(urbg);
    
        return value;
    }





