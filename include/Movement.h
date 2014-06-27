#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Movable.h"

class Movement
{
protected:
	Movable object;


public:
        Movement(const Movable& object);

	void move();

	bool isReady();

};
#endif
