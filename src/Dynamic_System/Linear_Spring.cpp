#include "Linear_Spring.h"

// Linear spring cnstructor
Linear_Spring::Linear_Spring(double spring_preload, double spring_rate) 
    : spring_preload {spring_preload}, spring_rate {spring_rate}{

}
    
// Overriding the pure viritual funciton in spring class
double Linear_Spring::get_spring_rate(double spring_extension){
    return spring_rate;
}

// Overriding the pure viritual funciton in spring class
double Linear_Spring::get_spring_force(double spring_extension) {
    return -spring_preload - get_spring_rate(spring_extension)*spring_extension;
}

void Linear_Spring::set_spring_rate(std::vector<double> spring_rate_vec) {
    spring_rate = spring_rate_vec[0];
    return;
}