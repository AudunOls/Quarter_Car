 
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <set>
#include "Spring.h"
#include "Linear_Spring.h"
#include "Damper.h"
#include "Linear_Damper.h"
#include "Quarter_Car.h"
#include "Road_Input.h"
#include "Impulse_Input.h"
#include "Bilinear_Spring.h"
#include "Bilinear_Damper.h"
#include "Sinusoidal_Input.h"
#include "Random_Input.h"
#include <cmath>
#include <matplot/matplot.h>

using namespace matplot;

int main(){


/**************** Initialisation of time vector ****************/

    double start_time{ 0 };
    double end_time{ 1 };
    double step_size{ 0.01 };

    int n = (end_time - start_time) / step_size;

    std::vector <double> time_vector = linspace(start_time, end_time, n);

/****************Initialisation of springs and dampers****************************************/

   double sprung_mass {41.175}; // Initializing sprung mass [kg]
   double unsprung_mass {10.1}; // Initializing unsprung mass [kg]

  Spring * tyre_spring = new Linear_Spring(0.0, 87.9e3);
  Damper * tyre_damper = new Linear_Damper(110);


  Spring* linear_suspension_spring = new Linear_Spring(0.0, 56e3);
  Spring* bilinear_suspension_spring = new Bilinear_Spring(0.0, 52e3, 10e-3, 200e3);

  Damper* linear_suspension_damper = new Linear_Damper(4000);
  Damper* bilinear_suspension_damper = new Bilinear_Damper(3e3, 5e3, 3e3, 5e3, 50e-3, 50e-3);


  Road_Input* impulse = new Impulse_Input(start_time, end_time, 200e-3, 0.3);
  Road_Input* sinusoidal = new Sinusoidal_Input(start_time, end_time, 0.5, 5);
  Road_Input* random = new Random_Input();


  // Add these parameters to default parameters


  /**************** Initialisation of linear quarter car ****************/

  Quarter_Car linear_QC(unsprung_mass,sprung_mass, 
                  tyre_spring, linear_suspension_spring, 
                  tyre_damper,linear_suspension_damper, 
                  impulse);


  /**************** Initialisation of bilinear quarter car ****************/
  

  Quarter_Car bilinear_QC(unsprung_mass, sprung_mass,
                        tyre_spring, bilinear_suspension_spring,
                        tyre_damper, bilinear_suspension_damper,
                        sinusoidal);


    /**************** Initialisation of results vector ****************/

    //five rows, n colums


    /**************** For loop ****************/


    // for loop(t<t_end, delta_t)

        // vector x_dot = quarter_car.update_state_derivatives(x)

        // vector x_new = solver.integrate(x_dot, x, delta_t)

        // vector forces = quarter_car_get_forces(x_new)

        // vector results_vector.pushback(x_new, forces)

    /**************** Plot Results ****************/

    //plot states and state derivatives
    //plot forces


std::cout<< "\n=========== Completed =============\n";
    return 0;
}