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
        Movement(const Movable& _object);

        Movement(const Movable& _object, double speed);

	void move();

	bool isReady();

};
#endif
