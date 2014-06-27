#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Movable.h"

#define MOVEMENT_DEFAULT_SPEED 1

class Movement
{
protected:
	Movable* object;
    double speed;
    bool ready;

public:
        Movement(Movable* _object);

        Movement(Movable* _object, double speed);

	virtual void move() = 0;

	bool isReady();

};
#endif
