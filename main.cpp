 
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
#include "Numerical_Solver.h"
#include "Forward_Euler.h"
#include <Eigen/Dense>
#include "Continuous_Damper.h"


using namespace matplot;
using namespace std;

int main(){


/**************** Initialisation of time vector ****************/

    double start_time{ 0.0 };
    double end_time{ 1.0 };
    int n{ 10000 };

    double step_size = (end_time - start_time) / n;

    std::vector <double> time_vector = linspace(start_time, end_time, n+1);

/****************Initialisation of springs and dampers****************************************/

   double sprung_mass {41.175}; // Initilize sprung mass [kg]
   double unsprung_mass {10.1}; // Initilize unsprung mass [kg]

  Spring * tyre_spring = new Linear_Spring(0.0, 87.9e3); // Initilize tyre spring [N, N/mm]  
  Damper * tyre_damper = new Linear_Damper(110);        // Initialize tyre damper [Ns/m]


  Spring* linear_suspension_spring = new Linear_Spring(0.0, 56e3);
  Spring* bilinear_suspension_spring = new Bilinear_Spring(0.0, 52e3, 10e-3, 200e3);

  Damper* linear_suspension_damper = new Linear_Damper(5000);
  Damper* bilinear_suspension_damper = new Bilinear_Damper(3e3, 5e3, 3e3, 5e3, 50e-3, 50e-3);


  Damper* cont_damper = new Continuous_Damper(810.0,12.0);


  Road_Input* impulse = new Impulse_Input(start_time, end_time, 20e-3, 0.2);
  Road_Input* sinusoidal = new Sinusoidal_Input(start_time, end_time, 0.05, 5);
  Road_Input* random = new Random_Input(0.0, 0.7);


   Numerical_Solver* euler = new Forward_Euler(start_time, end_time, step_size);
  

  /**************** Initialisation of linear quarter car ****************/

  Quarter_Car linear_QC(unsprung_mass,sprung_mass, 
                  tyre_spring, linear_suspension_spring, 
                  tyre_damper,linear_suspension_damper, 
                  impulse);


  /**************** Initialisation of bilinear quarter car ****************/
  

  Quarter_Car bilinear_QC(unsprung_mass, sprung_mass,
                        tyre_spring, bilinear_suspension_spring,
                        tyre_damper, cont_damper,
                        impulse);



    /**************** For loop ****************/

  vector<double> state_1(n+1, 0);
  vector<double> state_2(n+1, 0);
  vector<double> state_3(n+1, 0);
  vector<double> state_4(n+1, 0);
  vector<double> state_5(n+1, 0);
  vector<double> input(n+1, 0);


  vector<double> state(5, 0);
  vector<double> state_derivatives(5, 0);

  int i{ 0 };

  for (double t = start_time; t <= end_time; t = t + step_size)
  {
 
      state = euler->solve(state, bilinear_QC, t);

      state_1[i] = state[0];
      state_2[i] = state[1];
      state_3[i] = state[2];
      state_4[i] = state[3];
      state_5[i] = state[4];
      input[i] = bilinear_QC.get_road_input(t);

      ++i;
  }

    /**************** Plot Results ****************/


  tiledlayout(3, 2);

  nexttile();
  plot(time_vector, state_1);
  ylabel("Position [m]");
  title("Sprung mass position");

  nexttile();
  plot(time_vector, state_2);
  ylabel("Velocity [m/s]");
  title("Sprung mass velocity");

  nexttile();
  plot(time_vector, state_3);
  ylabel("Position [m]");
  title("Unsprung mass position");

  nexttile();
  plot(time_vector, state_4);
  ylabel("Velocity [m/s]");
  title("Unsprung mass velocity");

  nexttile();
  plot(time_vector, state_5);
  ylim({ -0.05,0.25 });
  ylabel("Position [m]");
  title("Road position");

  nexttile();
  plot(time_vector, input);
  ylabel("Velocity [m/s]");
  title("Road velocity");

show();
std::cout<< "\n=========== Completed =============\n";
    return 0;
}