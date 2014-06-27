#ifndef LINEAR_MOVEMENT_H
#define LINEAR_MOVEMENT_H

#include "Movement.h"
#include "Movable.h"

class LinearMovement : public Movement
{
private:
	std::pair<double,double> destiny;

public:
	LinearMovement(Movable* object, std::pair<double,double> destiny);
	LinearMovement(Movable* object, std::pair<double, double> destiny, double speed);

    void move();
};
#endif
