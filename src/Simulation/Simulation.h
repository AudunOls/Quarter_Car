#pragma once
#include "Dynamic_System.h"
#include "Numerical_Solver.h"
#include <vector>
#include <matplot/matplot.h>

using namespace std;
using namespace matplot;

class Simulation {
private:
	double t_start;					// Start time simulation [s]
	double t_end;					// End time simulation [s]
	int steps;						// Number of steps
	vector<vector<double>> results;	// Resutlts vector

	Dynamic_System * system;		// Dynamic system
	Numerical_Solver * solver;		// Numerical solver


public:

	// Constructor
	Simulation(double t_start, double t_end, int steps,
		Dynamic_System * system_ptr, Numerical_Solver * solver_ptr);


	// simulate function
	void run_simulation();

	// plot results function
	void plot_result();

	// analyse funciton

	// plot analysis funciton

};
