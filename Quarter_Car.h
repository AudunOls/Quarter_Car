#ifndef QUARTER_CAR_H
#define QUARTER_CAR_H
#include <iostream>
#include <string>
#include "Spring.h"
#include "Linear_Spring.h"
#include "Damper.h"
#include "Linear_Damper.h"

class Quarter_Car {
	private: 
    	Spring * unsprung_spring;
        Spring * sprung_spring;
        Damper * unsprung_damper; 
        Damper * sprung_damper;
        // Add sprung and unsprung mass
        // Add road input
   public:

    // Constructor
   	Quarter_Car(Spring * unsprung_spring_ptr, Spring * sprung_spring_ptr, Damper * unsprung_damper_ptr, Damper * sprung_damper_ptr);

    // Spring get function prototypes
    double get_unsprung_spring_rate(double spring_compression);
    double get_sprung_spring_rate(double spring_compression);
    double get_unsprung_spring_force(double spring_compression);
    double get_sprung_spring_force(double spring_compression);


    // Damper get function prototpes
    double get_sprung_damper_coefficient(double damper_velocity);
    double get_unsprung_damper_coefficient(double damper_velocity);
    double get_sprung_damper_force(double damper_velocity);
    double get_unsprung_damper_force(double damper_velocity);

};

#endif // QUARTER_CAR_H