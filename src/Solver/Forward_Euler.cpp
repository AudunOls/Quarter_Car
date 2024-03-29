#include "Forward_Euler.h"


Forward_Euler::Forward_Euler(double a, double b, double h) : a{ a }, b{ b }, h{ h }
{
}

std::vector<double> Forward_Euler::solve(std::vector<double> state,
	Dynamic_System * dyn_sys, double time)
{
	std::vector<double> new_state(state.size(), 0);
	std::vector<double> state_derivative(state.size(), 0);



	state_derivative = dyn_sys->get_state_derivatives(time, state);

	for (int i = 0; i < state.size(); i++) {
		new_state[i] = state[i] + state_derivative[i] * h;

	}
	return new_state;
}
