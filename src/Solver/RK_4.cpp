
#include "RK_4.h"



RK_4::RK_4(double a, double b, double h) : a{ a }, b{ b }, h{ h }
{
}


std::vector<double> RK_4::solve(std::vector<double> state,
	Quarter_Car qc, double time)
{
	std::vector<double> new_state(state.size(), 0);
std::vector<double> state_derivative(state.size(), 0);

state_derivative = qc.get_state_derivatives(time, state);

int i{ 0 };

std::vector<double> k1_vec = qc.get_state_derivatives(time, state);
std::vector<double> k2_vec = qc.get_state_derivatives(time, state);
std::vector<double> k3_vec = qc.get_state_derivatives(time, state);
std::vector<double> k4_vec = qc.get_state_derivatives(time, state);


for (i = 0; i < state.size(); i++) {

	// Apply Runge Kutta Formulas to find
	// next value of x
	//k1 = h * qc.get_state_derivatives(time, state[i])[i];
	//k2 = h * qc.get_state_derivatives(t + 0.5 * h, x + 0.5 * k1);
	//k3 = h * qc.get_state_derivatives(t + 0.5 * h, x + 0.5 * k2);
	//k4 = h * qc.get_state_derivatives(t + h, x + k3);

	// Update next value of x
	//new_state[i] = state[i] + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
	new_state[i] = 1;
}
return new_state;
}