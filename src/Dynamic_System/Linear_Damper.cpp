#include "Linear_Damper.h"
#include "Damper.h"


//Constructor
Linear_Damper::Linear_Damper( double damping_coefficient) 
    : damping_coefficient {damping_coefficient}{

}

double Linear_Damper::get_damper_force(double damper_velocity){
    return -damping_coefficient*damper_velocity;
}
    
    
double Linear_Damper::get_damper_coefficent(double damper_velocity){
    return damping_coefficient;
}



void Linear_Damper::set_damper_coefficent(std::vector<double> damper_coeff_vec) {
    damping_coefficient = damper_coeff_vec[0];
    return;
}