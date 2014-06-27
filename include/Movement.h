#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Movable.h"

#define DEFAULT_SPPED 1

class Movement
{
protected:
	Movable object;
        double speed;


public:
        Movement(const Movable& object);

        Movement(const Movable& object, double speed);

	void move();

	bool isReady();

};
#endif
