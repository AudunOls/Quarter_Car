 
#include <iostream>
#include "Spring.h"
#include "Linear_Spring.h"
#include "Damper.h"
#include "Linear_Damper.h"
#include "Quarter_Car.h"
#include "Road_Input.h"
#include "Impulse_Input.h"
#include "Bilinear_Spring.h"
#include "Bilinear_Damper.h"


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


/******************Test of Linear_Spring, Linear_Damper and Quarter_Car class *******************/
/*
   double sprung_mass {41.2}; // Initializing sprung mass [kg]
   double unsprung_mass {10.1}; // Initializing unsprung mass [kg]

  Spring * tyre_spring = new Linear_Spring(0.0, 1);
  Spring * suspension_spring  = new Linear_Spring(0.0,2.0);
  Damper * tyre_damper = new Linear_Damper(3.0);
  Damper * suspension_damper = new Linear_Damper(4.0);
  Road_Input * impulse = new Impulse_Input();

  Quarter_Car QC_1(unsprung_mass,sprung_mass, 
                  tyre_spring, bilinear_spring, 
                  tyre_damper,suspension_damper, 
                  impulse);
 
 
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


std::cout << "Road input Impulse Class: " << impulse->get_road_velocity(0.1) << std::endl;
std::cout << "Road input QC_1: " << QC_1.get_road_input(0.1) << std::endl;
*/

/******************************* Test of bilinear dampers and springs ********************************/

// preload= 1, intial_spring_rate = 1.0, max_travel_intial_spring_rate = 2  sec_spring_rate = 3
Spring * bilinear_spring = new Bilinear_Spring(1, 1.0, 2, 3);

// LS-C = 1, HS-C = 2, LS-R = 1, HS-R = 2, Knee-C = 2, Knee-R = 2
Damper * bilinear_damper = new Bilinear_Damper(1, 2, 1, 2, 2, 2); 


std::cout<< "Spring Rates: \n"<< std::endl; 
std::cout<< bilinear_spring->get_spring_rate(-1)<< std::endl; // K_1 = 1
std::cout<< bilinear_spring->get_spring_rate(-3)<< std::endl; // K_2 = 3
std::cout<< bilinear_spring->get_spring_rate(1)<< std::endl;  // K_1 = 1
std::cout<< bilinear_spring->get_spring_rate(3)<< std::endl;  // K_2 = 1


std::cout<< "Spring Forces: \n"<< std::endl; 
std::cout<< bilinear_spring->get_spring_force(-1)<< std::endl; // -(1*(-1)) - 1 = 0
std::cout<< bilinear_spring->get_spring_force(-3)<< std::endl; // -2*(-1) - 3*((-3)+2)-1 = 4
std::cout<< bilinear_spring->get_spring_force(1)<< std::endl;  // -(1*1) - 1 = -2
std::cout<< bilinear_spring->get_spring_force(3)<< std::endl;  // -(1*3) - 1 = -4


std::cout<< "Damper Coeffs: \n"<< std::endl; 
std::cout<< bilinear_damper->get_damper_coefficent(-1)<< std::endl; // LS-C: 1
std::cout<< bilinear_damper->get_damper_coefficent(-3)<< std::endl; // HS-C: 2
std::cout<< bilinear_damper->get_damper_coefficent(1)<< std::endl; // LS-R: 1
std::cout<< bilinear_damper->get_damper_coefficent(3)<< std::endl; // HS-R: 2

std::cout<< "Damper Forces: \n"<< std::endl; 
std::cout<< bilinear_damper->get_damper_force(-1)<< std::endl; // LS-C: -(1 *-1) = 1
std::cout<< bilinear_damper->get_damper_force(-3)<< std::endl; // HS-C: -1*(-2)-2*(-3+2)) = 4
std::cout<< bilinear_damper->get_damper_force(1)<< std::endl; // LS-R: -(1*1) = -1
std::cout<< bilinear_damper->get_damper_force(3)<< std::endl; // HS-R: -(1*4) = -4


  std::cout<< "\n=========== Completed =============\n";
    return 0;
}

