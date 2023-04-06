#define _USE_MATH_DEFINES
#include <cmath>
#include "Sinusoidal_Input.h"


Sinusoidal_Input::Sinusoidal_Input(double start_time, double end_time, double amplitude, double frequency)
    : start_time{ start_time }, end_time{ end_time }, amplitude{ amplitude }, frequency{ frequency } {

}

double Sinusoidal_Input::get_road_velocity(double time) {
    return amplitude * sin(2 * M_PI * frequency * time);

}

void Sinusoidal_Input::set_input(std::vector<double> input) {

    amplitude = double(input[0]);
    frequency = double(input[1]);

    return;
}