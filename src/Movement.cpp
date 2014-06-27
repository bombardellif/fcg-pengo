#include "Movement.h"

Movement::Movement(const Movable& _object): object(_object), speed(DEFAULT_SPPED){
}


void Movement::move()
{
}

bool Movement::isReady()
{
	return true;
}
