/*
Quarter car class consists of four classes:
-   Sprung spring 
-   Spung damper
-   Tyre spring
-   Tyre damper
-   Road input

The quarter car has four private variables: Sprung mass and unsprung mass
and the number of states and the number of inputs
*/

#ifndef QUARTER_CAR_H
#define QUARTER_CAR_H
#include "Spring.h"
#include "Dynamic_System.h"
#include "Linear_Spring.h"
#include "Damper.h"
#include "Linear_Damper.h"
#include "Road_Input.h"
#include "Impulse_Input.h"
#include <sciplot/sciplot.hpp>
#include <vector>
#include <Simulation.h>


using namespace sciplot;
using namespace std;

class Quarter_Car:public Dynamic_System {
	private: 
        int number_of_states{ 5 };
        int number_of_inputs{ 1 };

        double unsprung_mass;       // [kg]
        double sprung_mass;         // [kg]
    	Spring * unsprung_spring;   // Spring rate [N/m], Force [N]
        Spring * sprung_spring;     // Spring rate [N/m], Force [N]
        Damper * unsprung_damper;   // Damper coefficient [N/m/s], Force [N]
        Damper * sprung_damper;     // Damper coefficient [N/m/s], Force [N]
        Road_Input * road_input;    // Road velocity [m/s]

   public:

    // Constructor
   	Quarter_Car(double unsprung_mass, double sprung_mass, 
        Spring * unsprung_spring_ptr, Spring * sprung_spring_ptr, 
        Damper * unsprung_damper_ptr, Damper * sprung_damper_ptr, 
        Road_Input * road_input_prt);

    // Spring get function prototypes
    double get_unsprung_spring_rate(double spring_extension);
    double get_sprung_spring_rate(double spring_extension);
    double get_unsprung_spring_force(double spring_extension);
    double get_sprung_spring_force(double spring_extension);


    // Set funcitons for spring rates and damper coefficients
    void set_unsprung_spring_rates(std::vector<double> spring_rates);
    void set_sprung_spring_rates(std::vector<double> spring_rates);
    void set_sprung_damper_coefficient(std::vector<double> spring_rates);
    void set_unsprung_damper_coefficient(std::vector<double> spring_rates);


    // Damper get function prototpes
    double get_sprung_damper_coefficient(double damper_velocity);
    double get_unsprung_damper_coefficient(double damper_velocity);
    double get_sprung_damper_force(double damper_velocity);
    double get_unsprung_damper_force(double damper_velocity);

    // Road get function prototypes
    double get_input(double time) override;

    // Get extension and velocities form states and time
    double get_sprung_spring_extension(std::vector<double> state);
    double get_unsprung_spring_extension(std::vector<double> state);
    double get_sprung_damper_velocity(std::vector<double> state);
    double get_unsprung_damper_velocity(std::vector<double> state, double time);

    // get state derivatives retuns the state derivatives vector
    virtual std::vector<double> get_state_derivatives(double time, std::vector<double> state) override;

    // get number of states
    virtual int get_number_of_states() override;
    virtual int get_number_of_inputs() override;
    virtual std::vector<double> analyse_results(std::vector<std::vector<double>> results) override;

    // simple calculate rms function
    double calculate_rms(std::vector <double> vec);


    // Plots the results of the finished simulated quarter car
    void plot(std::vector <std::vector<double>> results); 



    /************** sweep parameters *************/
    // Sweep parameters plots the results obtained in the simulation function sweep_parameters()
    // the function takes in a 3D vector the length of number of sweeps. Each of the sweeps contain the reuslt from one 
    // entire simulation. 
    virtual void sweep_parameters(std::vector<std::vector<std::vector<double> > > results_matrix) override;

    /***************************************/



    /************* set_parameters *************/
    // Sets the following parameters in the quarter car in the following order: 
    // unsprung mass, sprung mass, 
    //unsprung spring stiffness,unsprung damper coefficients, 
    //sprung spring rate, sprung damper coefficients 
    virtual void set_parameters(vector<vector<double>> parameters) override;

    /***************************************/

    virtual void set_input(vector<double> input) override;

};

#endif // QUARTER_CAR_H