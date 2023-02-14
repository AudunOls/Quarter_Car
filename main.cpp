 
#include <iostream>
#include "Spring.h"
#include "Linear_Spring.h"
#include "Damper.h"
#include "Linear_Damper.h"
#include "Quarter_Car.h"

int main(){

/*************** Pseudocode ****************
 
// initialize Spring classes

// initialize Damper classes

 // initialize Road_Input class

 // initialize Quarter_Car class

 // double initialize t_start, delta_t, t_end

 // vector initialize results_vector (elements = (t_end-t_start)/delta_t)
 
 // for loop(t<t_end, delta_t)

    // vector x_dot = quarter_car.update_state_derivatives(x)

    // vector x_new = solver.integrate(x_dot, x, delta_t)

    // vector forces = quarter_car_get_forces(x_new)

    // vector results_vector.pushback(x_new, forces)

 // Plot result
    //plot results
    //plot states
    //plot forces

*****************************************/

// Test of Linear_Spring, Linear_Damper and Quarter_Car class:

  Spring * tyre_spring = new Linear_Spring(0.0, 1);
  Spring * suspension_spring  = new Linear_Spring(0.0,2.0);
  Damper * tyre_damper = new Linear_Damper(3.0);
  Damper * suspension_damper = new Linear_Damper(4.0);

  Quarter_Car QC_1(tyre_spring, suspension_spring, tyre_damper,suspension_damper);
 
  std::cout << "\n=========== Classes ===========\n"; 
  std::cout << "Unsprung spring rate: " << tyre_spring->get_spring_rate(10) << std::endl;
  std::cout <<"Sprung spring rate: " << suspension_spring->get_spring_rate(10)<<std::endl;
  std::cout << "Unsprung damper coefficient: " << tyre_damper->get_damper_coefficent(10)<<std::endl;
  std::cout <<"Sprung damper coeffient: " << suspension_damper->get_damper_coefficent(10)<<std::endl;

  std::cout << "Unsprung spring force: " << tyre_spring->get_spring_force(10) << std::endl;
  std::cout <<"Sprung spring force: " << suspension_spring->get_spring_force(10)<<std::endl;
  std::cout << "Unsprung damper force: " << tyre_damper->get_damper_force(10)<<std::endl;
  std::cout <<"Sprung damper force: " << suspension_damper->get_damper_force(10)<<std::endl;


  std::cout << "\n=========== QC_1 ===========\n"; 
  std::cout << "Unsprung spring rate: " << QC_1.get_unsprung_spring_rate(10) << std::endl;
  std::cout <<"Sprung spring rate: " << QC_1.get_sprung_spring_rate(10)<<std::endl;
  std::cout << "Unsprung damper coefficient: " << QC_1.get_unsprung_damper_coefficient(10)<<std::endl;
  std::cout <<"spring damper coeffient: " << QC_1.get_sprung_damper_coefficient(10)<<std::endl;

  std::cout << "Unsprung spring force: " << QC_1.get_unsprung_spring_force(10) << std::endl;
  std::cout <<"Sprung spring force: " << QC_1.get_sprung_spring_force(10)<<std::endl;
  std::cout << "Unsprung damper force: " << QC_1.get_unsprung_damper_force(10)<<std::endl;
  std::cout <<"Sprung damper force: " << QC_1.get_sprung_damper_force(10)<<std::endl;


  std::cout<< "\n=========== Completed =============\n";
    return 0;
}

