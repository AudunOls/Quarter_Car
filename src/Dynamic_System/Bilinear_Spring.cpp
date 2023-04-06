#include "Bilinear_Spring.h"

// Bilinear spring cnstructor
Bilinear_Spring::Bilinear_Spring(double spring_preload, 
    double initial_spring_rate, double initial_spring_max_travel, 
    double secondary_spring_rate)
    : spring_preload {spring_preload}, 
    initial_spring_rate {initial_spring_rate}, initial_spring_max_travel{initial_spring_max_travel},
    secondary_spring_rate {secondary_spring_rate}{

}
    
// Overriding the pure viritual funciton in spring class
double Bilinear_Spring::get_spring_rate(double spring_extension){
    if (spring_extension<-initial_spring_max_travel){ 
        return secondary_spring_rate;
    }
    else 
        return initial_spring_rate;

}

void Bilinear_Spring::set_spring_rate(std::vector<double> spring_rate_vec) {
    initial_spring_rate = spring_rate_vec[0];
    secondary_spring_rate = spring_rate_vec[1];
    return;
}

// Overriding the pure viritual funciton in spring class
double Bilinear_Spring::get_spring_force(double spring_extension) {
    if (spring_extension<-initial_spring_max_travel){
        return  -spring_preload + initial_spring_rate*initial_spring_max_travel - 
                secondary_spring_rate*(spring_extension+initial_spring_max_travel);    
    }

    else{
        return -spring_preload - initial_spring_rate*spring_extension;
    }
}