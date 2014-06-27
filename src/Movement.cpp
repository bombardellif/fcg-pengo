#include "Movement.h"

Movement::Movement(const Movable& object): speed(DEFAULT_SPPED){
}


void Movement::move()
{
}

bool Movement::isReady()
{
	return true;
}
