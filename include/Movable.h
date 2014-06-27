#ifndef MOVABLE_H
#define MOVABLE_H

#include <utility>

#include "DiscreteDirection.h"

class Movable
{
public:
    Movable(std::pair<double, double> _position);
    
	std::pair<double, double> position;
        
    double direction;

    std::pair<int, int> getNewPosition(int distance);

    double getNewDirection(double turn);

    DiscreteDirection getDiscreteDirection();
};
#endif
