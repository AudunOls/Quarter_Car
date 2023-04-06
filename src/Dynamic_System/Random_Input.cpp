#include "Road_Input.h"
#include "Random_Input.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iterator>
#include <random>
#include <chrono>


Random_Input::Random_Input(double mean, double stddev)
    :norm{ std::normal_distribution<double>(mean, stddev) }, rd{ std::default_random_engine() } {

}

double Random_Input::get_road_velocity(double time) {
        
        return norm(rd);
    }

void Random_Input::set_input(std::vector<double> input){
    double mean = double(input[0]);
    double stddev = double(input[1]);

    norm = std::normal_distribution<double>(mean, stddev);
    rd = std::default_random_engine();

    return;
}





