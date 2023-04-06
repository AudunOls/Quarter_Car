 
#include "main.h"

#include <nlopt.hpp>

int main() {

    /**************** Defining parameters ****************/

    // Mass
    double sprung_mass{ 41.175 }; // Initilize sprung mass [kg]
    double unsprung_mass{ 10.1 }; // Initilize unsprung mass [kg]

    // Spring rates
    double sprung_spring_rate{ 56e3 };      // Sprung/suspension spring rate [N/m]
    double unsprung_spring_rate{ 89e3 };    // Unsprung/tyre spring rate [N/m]

    // Damper coefficients
    double unsprung_damper_coefficient{ 110.0 };    // Unsprung/tyre damper coefficient [Ns/m]
    double sprung_damper_coefficient{1.0e3};        // Sprung damper coefficient [Ns/m]

    // Simulation parameters
    double start_time{ 0.0 };   // Simulation start time [s]
    double end_time{ 2.0 };     // Simulation end time [s]
    int n{ 10000 };             // Number of steps in simulaiton
    double step_size = (end_time - start_time) / n; // simulation step size



    /**************** Initialisation of Quarter Car components ****************/

    // Unsprung spring and damper
    Spring* tyre_spring = new Linear_Spring(0.0, unsprung_spring_rate);     // Initialize tyre spring [N, N/mm]  
    Damper* tyre_damper = new Linear_Damper(unsprung_damper_coefficient);   // Initialize tyre damper [Ns/m]

    // Suspension springs
    Spring* suspension_spring = new Linear_Spring(0.0, sprung_spring_rate); 
    //Spring* suspension_spring = new Bilinear_Spring(0.0, 52e3, 10e-3, 200e3);

    // Suspension dampers
    //Damper* suspension_damper = new Linear_Damper(sprung_damper_coefficient);
    //Damper* suspension_damper = new Bilinear_Damper(1e3, 5e3, 1e3, 5e3, 50e-3, 50e-3);
    Damper* suspension_damper = new Continuous_Damper(800, 12.0);

    
    // Road input
    //Road_Input* road_input = new Impulse_Input(start_time, end_time, 20e-3, 0.2);
    Road_Input* road_input = new Sinusoidal_Input(start_time, end_time, 0.05, 5);
    //Road_Input* road_input = new Random_Input(0.0, 0.7);


    /**************** Dynamic System (Quarter Car) ****************/

    Dynamic_System* quarter_car = new Quarter_Car(unsprung_mass, sprung_mass,
        tyre_spring, suspension_spring,
        tyre_damper, suspension_damper,
        road_input);

    /**************** Numerical Solver (Euler) ****************/

    
    Numerical_Solver* euler = new Forward_Euler(start_time, end_time, step_size);
    Simulation sim(start_time, end_time, n, quarter_car, euler);


    /**************** Simulation ****************/

    std::cout << "\n=========== Starting Simulation =============\n";
    sim.run_simulation();
                                                    //[m_u,    m_s,     k_u,    c_u,      k_s,      c_s]
    vector<vector<vector<double> > > sweep_matrix{
                                                    { {10.1}, {41.2},  {89e3}, {110,5}, {56e3}, {400,5.0} },   // iteration 1
                                                    { {10.1}, {41.2},  {89e3}, {110,5}, {56e3}, {400,5.0} },   // iteration 2
                                                    { {10.1}, {41.2},  {89e3}, {110,5}, {56e3}, {400,5.0} } };// iteration 3   

    sim.plot_result();

    sim.sweep_parameters(sweep_matrix);
    
    std::cout<< "\n=========== Simulation Completed =============\n";
    return 0;
}