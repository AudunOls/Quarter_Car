#include <iostream>
#include <string>
#include "Spring.h"
#include "Linear_Spring.h"
#include "Quarter_Car.h"


// Quarter_Car constructor
Quarter_Car::Quarter_Car(Spring * unsprung_spring_ptr, Spring * sprung_spring_ptr, Damper * unsprung_damper_ptr, Damper * sprung_damper_ptr) {
    unsprung_spring = unsprung_spring_ptr;
    sprung_spring = sprung_spring_ptr;
    unsprung_damper = unsprung_damper_ptr;
    sprung_damper = sprung_damper_ptr;
}

// Get spring rate functions:
double Quarter_Car::get_unsprung_spring_rate(double spring_compression) {
    	return unsprung_spring->get_spring_rate(spring_compression);
}

double Quarter_Car::get_sprung_spring_rate(double spring_compression){
  		return sprung_spring->get_spring_rate(spring_compression);
}

// Get spring forces functions:
double Quarter_Car::get_unsprung_spring_force(double spring_compression) {
    	return unsprung_spring->get_spring_force(spring_compression);
 }
double Quarter_Car::get_sprung_spring_force(double spring_compression){
  		return sprung_spring->get_spring_force(spring_compression);
}


// Get damper coefficient functions:
double Quarter_Car::get_sprung_damper_coefficient(double damper_velocity){
    return sprung_damper->get_damper_coefficent(damper_velocity);
}
double Quarter_Car::get_unsprung_damper_coefficient(double damper_velocity){
    return unsprung_damper->get_damper_coefficent(damper_velocity);
}


// Get damper force functions:
double Quarter_Car::get_sprung_damper_force(double damper_velocity){
    return sprung_damper->get_damper_force(damper_velocity);
}

double Quarter_Car::get_unsprung_damper_force(double damper_velocity){
    return unsprung_damper->get_damper_force(damper_velocity);
}

