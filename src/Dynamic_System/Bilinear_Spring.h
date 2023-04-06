/* Bilinear spring is a child class of spring and models a bilinear spring based on Hookes law:
F = K x, where F is the force [N], K is the spring rate [N/m], 
and x is the spring compression [m]
*/

#ifndef BILINEAR_SPRING_H
#define BILINEAR_SPRING_H
#include "Spring.h"
#include <iostream>
#include <string>
#include <vector>

class Bilinear_Spring: public Spring {

    private:
    double spring_preload;                  // Force on spring in static ride [N]
    double initial_spring_rate;             // Initial linear spring rate [N/m]
    double initial_spring_max_travel;       // Max travel (compression) until the second spring rate engages
    double secondary_spring_rate;           // Secondary linear_spring rate [N/m]
 
    
    public:
    Bilinear_Spring(double spring_preload = 0.0, 
    double initial_spring_rate = 10.0e-3, double initial_spring_max_travel = 10.0e3, 
    double secondary_spring_rate = 20e3); // constructor
    virtual double get_spring_force(double spring_extension) override;
    virtual double get_spring_rate(double spring_extension) override;
    virtual void set_spring_rate(std::vector<double> spring_rate_vec) override;
    virtual ~Bilinear_Spring() = default;
};


#endif // BILINEAR_SPRING_H