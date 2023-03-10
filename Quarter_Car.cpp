#include "Spring.h"
#include "Linear_Spring.h"
#include "Quarter_Car.h"
#include "Road_Input.h"
#include "Impulse_Input.h"

// Quarter_Car constructor
Quarter_Car::Quarter_Car(double unsprung_mass, double sprung_mass, 
    Spring * unsprung_spring_ptr, Spring * sprung_spring_ptr, 
    Damper * unsprung_damper_ptr, Damper * sprung_damper_ptr, 
    Road_Input* road_input_ptr) 
    :unsprung_mass{ unsprung_mass }, sprung_mass{ sprung_mass } 
{
    unsprung_spring = unsprung_spring_ptr;
    sprung_spring = sprung_spring_ptr;
    unsprung_damper = unsprung_damper_ptr;
    sprung_damper = sprung_damper_ptr;
    road_input = road_input_ptr;
}

// Get spring rate functions:
double Quarter_Car::get_unsprung_spring_rate(double spring_extension){
    	return unsprung_spring->get_spring_rate(spring_extension);
}

double Quarter_Car::get_sprung_spring_rate(double spring_extension){
  		return sprung_spring->get_spring_rate(spring_extension);
}

// Get spring forces functions:
double Quarter_Car::get_unsprung_spring_force(double spring_extension) {
    	return unsprung_spring->get_spring_force(spring_extension);
 }
double Quarter_Car::get_sprung_spring_force(double spring_extension){
  		return sprung_spring->get_spring_force(spring_extension);
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

  
  // Get sprung spring extension
  double Quarter_Car::get_sprung_spring_extension(std::vector<double> state)
  {
      return state[0] - state[2];
  }

  double Quarter_Car::get_unsprung_spring_extension(std::vector<double> state)
  {
      return state[2] - state[4];
  }

  double Quarter_Car::get_sprung_damper_velocity(std::vector<double> state)
  {
      return state[1] - state[3];
  }

  double Quarter_Car::get_unsprung_damper_velocity(std::vector<double> state, double time)
  {
      return state[3] - get_road_input(time);
  }



  std::vector<double> Quarter_Car::get_state_derivatives(double time, std::vector<double> state)
  {
      // Finding the extension and velocities to be used to find rates and coefficients
      double sprung_spring_extension = get_sprung_spring_extension(state);
      double sprung_damper_velocity = get_sprung_damper_velocity(state);

      double unsprung_spring_extension = get_unsprung_spring_extension(state);
      double unsprung_damper_velocity = get_unsprung_damper_velocity(state, time);

      std::vector<double> state_derivatives(5, 0);

      state_derivatives[0] = state[1];
      state_derivatives[1] = (-sprung_spring_extension* get_sprung_spring_rate(sprung_spring_extension)
                             - sprung_damper_velocity* get_sprung_damper_coefficient(sprung_damper_velocity))
                             /sprung_mass;
      state_derivatives[2] = state[3];
      state_derivatives[3] = (sprung_spring_extension * get_sprung_spring_rate(sprung_spring_extension)
                            + sprung_damper_velocity * get_sprung_damper_coefficient(sprung_damper_velocity)
                            - unsprung_spring_extension * get_unsprung_spring_rate(unsprung_spring_extension)
                            - unsprung_damper_velocity * get_unsprung_damper_coefficient(unsprung_damper_velocity))
                            / unsprung_mass;
      state_derivatives[4] = get_road_input(time);

     
      return state_derivatives;
  }
