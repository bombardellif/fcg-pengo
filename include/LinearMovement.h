#ifndef LINEAR_MOVEMENT_H
#define LINEAR_MOVEMENT_H

#include "Movement.h"
#include "Movable.h"

class LinearMovement : public Movement
{
private:
	std::pair<double,double> destiny;
	bool forward;

public:
	LinearMovement(Movable* object, std::pair<double,double> destiny, bool forward);
	LinearMovement(Movable* object, std::pair<double, double> destiny, bool forward, double speed);

    void move();
};
#endif
