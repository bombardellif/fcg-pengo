#ifndef MOVEMENT_H
#define MOVEMENT_H

#define MOVEMENT_DEFAULT_SPEED 1

class Movement;
#include "Movable.h"

class Movement
{
public:
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
