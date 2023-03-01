#include "Forward_Euler.h"

Forward_Euler::Forward_Euler(double a, double b, double h) : a{ a }, b{ b }, h{ h }
{
}

std::vector<double> Forward_Euler::solve(std::vector<double> state, std::vector<double> state_derivative, double time)
{
	std::vector<double> new_state(state.size(), 0);

	int i{ 0 };

	for (i = 0; i < state.size(); i++) {
		new_state[i] = state[i] + state_derivative[i] * h;

	}
	return new_state;
}
