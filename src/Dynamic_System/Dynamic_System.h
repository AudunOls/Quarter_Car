#pragma once


// Interface for dynamic systems

#include <vector>


class Dynamic_System {

public:
    virtual std::vector<double> get_state_derivatives(double time, std::vector<double> state) = 0;
    virtual std::vector<double> analyse_results(std::vector<std::vector<double>> results) =  0;
    virtual double get_input(double time) = 0;
    virtual int get_number_of_states() = 0;
    virtual int get_number_of_inputs() = 0;
    virtual void sweep_parameters(std::vector<std::vector<std::vector<double> > > results_matrix) = 0;
    virtual void set_parameters(std::vector<std::vector<double>> parameters) = 0;
    virtual void plot(std::vector<std::vector<double>> results) = 0;
    virtual ~Dynamic_System() = default;
};
