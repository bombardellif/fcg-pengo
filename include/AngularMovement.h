#ifndef ANGULAR_MOVEMENT_H
#define ANGULAR_MOVEMENT_H

#include "Movement.h"
#include "Movable.h"

class AngularMovement : public Movement
{
private:
	double destiny;

	bool clockWise;



public:
	AngularMovement(Movable* object, double destiny, bool clockWise);

        void move();
};
#endif
