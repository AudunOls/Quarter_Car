#include "Simulation.h"
using namespace std;

Simulation::Simulation(double t_start, double t_end, int steps,
Dynamic_System* system_ptr, Numerical_Solver* solver_ptr):
    t_start{ t_start }, t_end{ t_end }, steps{ steps }
{
    system = system_ptr;
    solver = solver_ptr;
	vector<vector<double>> res(2*(system->get_number_of_states()) + (system->get_number_of_inputs()+2), 
		vector<double>(steps + 1, 0));
	results = res; 
}


/*********** run_simulation ***********/
// For each time step the run_simulation function:
// Stores the results of a time t in the res_temp vector
// in order to obtain the res_temp vector, the 
// the solver takes in the current state vector,
// the system and the time and integrates the 
// state derivatives vector the solver gets from the 
// dynamic system itself. The results for each time step 
// is stored in the results vector

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
		vector <double> state_derivatives = system->get_state_derivatives(t,res_temp);

		for (j = 0; j < (num_states); j++) {
			results[j][i] = res_temp[j];
			results[num_states + num_inputs + j][i] = state_derivatives[j];
		}
		results[num_states][i] = system->get_input(t);
		results[2 * num_states + num_inputs + 1][i] = t;
		++i;	// Increment i for each time step
		j = 0;	// Set j to zero for each time step
	}

	return;
};



/*********** plot_results ***********/
// Passes the results vector to a plot_results method of a 
// Dynamic_System inherited class
void Simulation::plot_result() {
	 system->plot(results);
	return;	
};



/*********** analyse_results ***********/
// runs the analysis defined in the given dynamic system
void Simulation::analyse_results()
{
	vector<double> kpi_vec = system->analyse_results(results);
	std::cout << "KPI Ride: RMS sprung acceleration: " << kpi_vec[0] << std::endl;
	std::cout << "KPI Roadholding: RMS unsprung acceleration: " << kpi_vec[1] << std::endl;
}


/*********** get_time_vector ***********/
// Returns the whole results vector
vector<vector<double>> Simulation::get_results() {
	return results;
}


/*********** get_time_vector ***********/
// Returns the time vector stored at the last element 
// in the results vector
vector<double> Simulation::get_time_vector() {
	return results.back();
}


/*********** Sweep parameters function ***********/

// Gets passed a 3D sweep_matrix [i,j,k]. For each iterations of the sweep matrix 
// it runs a simulation and appends the results in the 3D results matrix [i,j,k],
// where i will be the number of sweeps
// j will be the number of elements in the results vector
// k will be the length of the simulation (number of steps +1)
// the results_matrix is passed in a sweep_parameters implementation in a Dynamic system
// there the results gets plotted

	//Sweeping matrix 
	//[i][0] - unsprung mass [kg]
	//[i][1] - sprung mass [kg]
	//[i][2] - unsprung spring rate vec [N/m]
	//[i][3] - unsprung damper coefficient [Ns/m]
	//[i][4] - sprung spring rate [N/m]
	//[i][5] - sprung damper coefficient [Ns/m
void Simulation::sweep_parameters(vector<vector<vector<double> > > sweep_matrix) {
	
	int n_sweeps = int(sweep_matrix.size());
	vector<vector<vector<double> > > results_matrix(n_sweeps,
		vector<vector<double> >(2 * (system->get_number_of_states()) + system->get_number_of_inputs()+1,
		vector<double>(steps + 1, 0)));
	
	for (int i = 0; i < n_sweeps; i++) {
		system->set_parameters(sweep_matrix[i]);
		run_simulation();
		results_matrix[i] = get_results();
	}

	system->sweep_parameters(results_matrix);
	
	return;
}