#pragma once
#include "Dynamic_System.h"
#include "Numerical_Solver.h"
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Simulation {
private:
	double t_start;					// Start time simulation [s]
	double t_end;					// End time simulation [s]
	int steps;						// Number of steps
	vector<vector<double>> results;	// Results vector [states, input, state derivatives, time vector]

	Dynamic_System * system;		// Dynamic system
	Numerical_Solver * solver;		// Numerical solver


public:

	// Constructor of the simulation:
	// t_start is the start time of the simulation [s]
	// t_end is the end time of the simulation [s]
	// steps is the number of simulation steps
	// Dynamic system is the system to be simulated
	// Numerical solver is the chosen numerical solver 
	Simulation(double t_start, double t_end, int steps,
		Dynamic_System * system_ptr, Numerical_Solver * solver_ptr);


	/*********** run_simulation ***********/
	// Runs a the declared simulation and 
	// stores the results in a results vector
	// in order to access these results, call 
	// the get_results(); method.
	void run_simulation();


	/*********** plot_results ***********/
	// Plots the result of a simulation, 
	// NOTE: in order not to plot pre-allocated 
	// zero vectors run a simulation before 
	// plotting it. 
	void plot_result();


	/*********** analyse_results ***********/
	// Runs an analysis of the simulated system
	void analyse_results();

	/*********** get_results_vector ***********/
	// Returns the results vector the length of 
	// the number of states + number of inputs + 
	// number of state derivatives + 1 (time vector).
	// The results vector contains all the states, then
	// all the inputs, then all the state derivatives 
	// then a time vector. 
	// Note that the a simulation has to be run  
	// NOTE: in order not to get a pre-allocated 0 vector. 
	// in order to run a simulation call the 
	// run_simulation() method
	vector<vector<double>> get_results();


	/*********** get_time_vector ***********/
	// Returns the time vector the length of 
	// the number of simulation steps + 1, starting
	// in the declared start time and ends at the end
	// end time. Note that the a simulation has to be run
	// NOTE: in order not to get a pre-allocated 0 vector. 
	// in order to run a simulation call the 
	// run_simulation() method
	vector<double> get_time_vector();



	/*********** Sweep parameters function ***********/
	// Sweeps parameters defined in the 3D sweep_matrix [i,j,k]
	// where i is a new sweep with all the parameters,
	// j is the parameters, in the case of a Quarter_Car these are:   
	//[i][0] - unsprung mass [kg]
	//[i][1] - sprung mass [kg]
	//[i][2] - unsprung spring rate vec [N/m]
	//[i][3] - unsprung damper coefficient [Ns/m]
	//[i][4] - sprung spring rate [N/m]
	//[i][5] - sprung damper coefficient [Ns/m]
	// k will be dependent on how many parameters in the chosen
	// spring or damper
	void sweep_parameters(vector<vector<vector<double> > > sweep_matrix);


	/*********** set_input ***********/
	// Sets the input of the dynamic system
	// for road inputs this is:
	// impulse input: [amplitude, ramp time] 
	// sinusoidal input: [amplitude, frequency]
	// random input: [mean, standard deviation] 
	void set_input(vector<double> input);

};

