#include "Impulse_Input.h"


Impulse_Input::Impulse_Input(double start_time, double end_time, double amplitude, double ramp_time) 
    : start_time {start_time}, end_time {end_time}, amplitude {amplitude}, ramp_time{ramp_time}{

}

double Impulse_Input::get_road_velocity(double time){

    double step_start = start_time + (end_time - start_time) * 0.25; // the velocity starts at 1/4 of the simulation time
    double road_velocity = amplitude/ramp_time;
    double step_end = step_start + ramp_time;

    if (time>=step_start && time<=step_end) {
        return road_velocity;
    } else{
        return 0.0; 
    }
}
    
