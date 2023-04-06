#include "Damper.h"
#include "Continuous_Damper.h"


Continuous_Damper::Continuous_Damper(
    double a,
    double b) :
    a{ a },
    b{ b }
  {
  }


double Continuous_Damper::get_damper_coefficent(double damper_velocity) {
    return (a * b * (1 - pow(tanh(b * damper_velocity), 2)));
}

double Continuous_Damper::get_damper_force(double damper_velocity) {
    return a * tanh(b * damper_velocity);
}

void Continuous_Damper::set_damper_coefficent(std::vector<double> damper_coeff_vec) {
    a = damper_coeff_vec[0];
    b = damper_coeff_vec[1];
    return;
}