// Interface file for Road_Input, Road_Input is a interface class

#ifndef ROAD_INPUT_H
#define ROAD_INPUT_H


class Road_Input {

    public:
    virtual double get_road_velocity(double time) = 0;
    virtual ~Road_Input() = default;

};
#endif // ROAD_INPUT_H