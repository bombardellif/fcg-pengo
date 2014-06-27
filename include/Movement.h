#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Movable.h"

#define DEFAULT_SPEED 1

class Movement
{
protected:
	Movable object;
    double speed;
    bool ready;

public:
        Movement(const Movable& _object);

        Movement(const Movable& _object, double speed);

	virtual void move() = 0;

	bool isReady();

};
#endif
