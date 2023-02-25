/*
Quarter car class consists of four classes:
-   Sprung spring 
-   Spung damper
-   Tyre spring
-   Tyre damper
-   Road input

The quarter car has two private variables: Sprung mass and unsprung mass.
*/

#ifndef QUARTER_CAR_H
#define QUARTER_CAR_H
#include "Spring.h"
#include "Linear_Spring.h"
#include "Damper.h"
#include "Linear_Damper.h"
#include "Road_Input.h"
#include "Impulse_Input.h"
#include <vector>

class Quarter_Car {
	private: 
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


    // Damper get function prototpes
    double get_sprung_damper_coefficient(double damper_velocity);
    double get_unsprung_damper_coefficient(double damper_velocity);
    double get_sprung_damper_force(double damper_velocity);
    double get_unsprung_damper_force(double damper_velocity);

    // Road get function prototypes
    double get_road_input(double time);

    // Get extension and velocities form states and time
    double get_sprung_spring_extension(std::vector<double> state);
    double get_unsprung_spring_extension(std::vector<double> state);
    double get_sprung_damper_velocity(std::vector<double> state);
    double get_unsprung_damper_velocity(std::vector<double> state, double time);

    // get state derivatives retuns the state derivatives vector
    std::vector<double> get_state_derivatives(double time, std::vector<double> state);
};

#endif // QUARTER_CAR_H