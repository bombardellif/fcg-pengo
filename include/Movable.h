#ifndef MOVABLE_H
#define MOVABLE_H

#include <utility>

#include "DiscreteDirection.h"

class Movable;
#include "Movement.h"

class Movable
{
public:
    Movable(std::pair<double, double> _position);
    
    Movable(std::pair<double, double> _position, double direction);
	
	virtual ~Movable();
    
	std::pair<double, double> position;
        
    double direction;

    template<typename T> std::pair<T, T> getNewPosition(T distance);

    std::pair<int, int> getNewCeilPosition(double distance);

    double getNewDirection(double turn);

    DiscreteDirection getDiscreteDirection();
	
	virtual void takeActionToColision(Movement* movement, std::pair<int, int> desiredPosition) = 0;
};

#endif
