// Linear spring is a child class of spring and models a linear spring based on Hookes law:
// F = K x, where F is the force [N], K is the spring rate [N/m], 
// and x is the spring compression [m]

#ifndef LINEAR_SPRING_H
#define LINEAR_SPRING_H
#include "Spring.h"



class Linear_Spring: public Spring {

    private:
    double spring_preload;          // Force on spring in static ride [N]
    double spring_rate;             // Linear spring rate [N/m]
    
    public:
    Linear_Spring(double spring_preload = 0.0, double spring_rate = 0.0); // constructor
    virtual double get_spring_force(double spring_extension) override;
    virtual double get_spring_rate(double spring_extension) override;
    virtual ~Linear_Spring() = default;
};


#endif // LINEAR_SPRING_H