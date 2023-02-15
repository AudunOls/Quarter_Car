#include <iostream>
#include <string>
#include "Spring.h"
#include "Linear_Spring.h"
#include "Quarter_Car.h"
#include "Road_Input.h"
#include "Impulse_Input.h"

// Quarter_Car constructor
Quarter_Car::Quarter_Car(double unsprung_mass, double sprung_mass, 
    Spring * unsprung_spring_ptr, Spring * sprung_spring_ptr, 
    Damper * unsprung_damper_ptr, Damper * sprung_damper_ptr, 
    Road_Input * road_input_ptr) {

    unsprung_mass = unsprung_mass;    
    sprung_mass = sprung_mass;
    unsprung_spring = unsprung_spring_ptr;
    sprung_spring = sprung_spring_ptr;
    unsprung_damper = unsprung_damper_ptr;
    sprung_damper = sprung_damper_ptr;
    road_input = road_input_ptr;
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


// Get road velocity:
  double Quarter_Car::get_road_input(double time){
    return road_input->get_road_velocity(time);
  }
