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
        Movement(const Movable& object);

        Movement(const Movable& object, double speed);

	virtual void move() = 0;

	bool isReady();

};
#endif
