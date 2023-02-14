#include "Linear_Spring.h"

// Linear spring cnstructor
Linear_Spring::Linear_Spring(double spring_preload, double spring_rate) 
    : spring_preload {spring_preload}, spring_rate {spring_rate}{

}
    
// Overriding the pure viritual funciton in spring class
double Linear_Spring::get_spring_rate(double spring_compression){
    return spring_rate;
}

// Overriding the pure viritual funciton in spring class
double Linear_Spring::get_spring_force(double spring_compression) {
    return spring_preload - get_spring_rate(spring_compression)*spring_compression;
}