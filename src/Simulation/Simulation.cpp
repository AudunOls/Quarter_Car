#include "Simulation.h"


Simulation::Simulation(double t_start, double t_end, int steps,
Dynamic_System* system_ptr, Numerical_Solver* solver_ptr):
    t_start{ t_start }, t_end{ t_end }, steps{ steps }
{
    system = system_ptr;
    solver = solver_ptr;
	vector<vector<double>> res(5 + 1, vector<double>(steps + 1, 0));
	results = res;
}


void Simulation::run_simulation() {

	int i{ 0 };
	int j{ 0 };
	double stepsize = (t_end - t_start) / steps;

	int num_inputs = system->get_number_of_inputs();
	int num_states = system->get_number_of_states();

	vector <double> res_temp(num_states, 0);

	for (double t = t_start; t <= t_end; t = t + stepsize)
	{
		res_temp = solver->solve(res_temp, system, t);

		for (j = 0; j < (num_states); j++) {
			results[j][i] = res_temp[j];
		}
		results[num_states][i] = system->get_input(t);
		++i;	// Increment i for each time step
		j = 0;	// Set j to zero for each time step
	}
	return;
};



void Simulation::plot_result() {
	vector <double> time_vector = linspace(t_start, t_end, steps + 1);

	tiledlayout(3, 2);

	nexttile();
	plot(time_vector, results[0]);
	ylabel("Position [m]");
	title("Sprung mass position");

	nexttile();
	plot(time_vector, results[1]);
	ylabel("Velocity [m/s]");
	title("Sprung mass velocity");

	nexttile();
	plot(time_vector, results[2]);
	ylabel("Position [m]");
	title("Unsprung mass position");

	nexttile();
	plot(time_vector, results[3]);
	ylabel("Velocity [m/s]");
	title("Unsprung mass velocity");

	nexttile();
	plot(time_vector, results[4]);
	ylabel("Position [m]");
	title("Road position");

	nexttile();
	plot(time_vector, results[5]);
	ylabel("Velocity [m/s]");
	title("Road velocity");

	show();
	return;
	
};
