// Interface file for spring, spring is a interface class

#ifndef SPRING_H
#define SPRING_H
#include <iostream>
#include <string>

class Spring {

    public:
    virtual double get_spring_force(double spring_compression) = 0;
    virtual double get_spring_rate(double spring_compression) = 0;
    virtual ~Spring() = default;

};
#endif // SPRING_H

