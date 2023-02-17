/*
Spring is a interface class with two methods, get spring force and get_spring_rate.

get_spring_rate takes in the extension of the spring measured from an unloaded spring, 
where compression is defined as negative, and exentsion as positive. The function returns
the spring rate of the spring for a given compression, which is specified in the inherited classes
of the spring. 

get_spring_force takes in spring extension and returns the spring force
*/

#ifndef SPRING_H
#define SPRING_H
#include <iostream>
#include <string>

class Spring {

    public:
    virtual double get_spring_force(double spring_extension) = 0;
    virtual double get_spring_rate(double spring_extension) = 0;
    virtual ~Spring() = default;

};
#endif // SPRING_H

