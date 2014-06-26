#ifndef ANGULAR_MOVEMENT_H
#define ANGULAR_MOVEMENT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Movement.h"
#include "Movable.h"

class AngularMovement : public Movement
{
private:
	boolean clockWise;

	double destiny;


public:
	void AngularMovement(Movable object, double destiny, boolean clockWise);

};
#endif
