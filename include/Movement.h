#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Movable.h"
#include "Observable.h"

#define MOVEMENT_DEFAULT_SPEED 1

class Movement: public Observable
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
