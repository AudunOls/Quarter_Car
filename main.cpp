 
#include "main.h"

int main(){

/**************** Initialisation of time vector ****************/
    
    double start_time{ 0.0 };
    double end_time{ 1.0 };
    int n{ 10000 };

    double step_size = (end_time - start_time) / n;
    
/**************** Initialisation of springs and dampers ****************/

   double sprung_mass {41.175}; // Initilize sprung mass [kg]
   double unsprung_mass {10.1}; // Initilize unsprung mass [kg]

  Spring * tyre_spring = new Linear_Spring(0.0, 87.9e3); // Initilize tyre spring [N, N/mm]  
  Damper * tyre_damper = new Linear_Damper(110);        // Initialize tyre damper [Ns/m]


  Spring* linear_suspension_spring = new Linear_Spring(0.0, 56e3);
  Spring* bilinear_suspension_spring = new Bilinear_Spring(0.0, 52e3, 10e-3, 200e3);

  Damper* linear_suspension_damper = new Linear_Damper(5000);
  Damper* bilinear_suspension_damper = new Bilinear_Damper(3e3, 5e3, 3e3, 5e3, 50e-3, 50e-3);


  Damper* cont_damper = new Continuous_Damper(810.0,12.0);


  /**************** Road input ****************/

  Road_Input* impulse = new Impulse_Input(start_time, end_time, 20e-3, 0.2);
  Road_Input* sinusoidal = new Sinusoidal_Input(start_time, end_time, 0.05, 5);
  Road_Input* random = new Random_Input(0.0, 0.7);

  
  /**************** Dynamic System (Quarter Car) ****************/
 
  Dynamic_System* qc = new Quarter_Car(unsprung_mass, sprung_mass,
      tyre_spring, linear_suspension_spring,
      tyre_damper, cont_damper,
      random);
  

  /**************** Numerical Solver (Euler) ****************/

  Numerical_Solver* euler = new Forward_Euler(start_time, end_time, step_size);


  /**************** Simulation  ****************/

  Simulation sim(start_time, end_time, n, qc, euler);
  
  sim.run_simulation();
  sim.plot_result();

std::cout<< "\n=========== Completed =============\n";
    return 0;
}