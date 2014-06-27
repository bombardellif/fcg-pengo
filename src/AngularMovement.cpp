#include "AngularMovement.h"


AngularMovement::AngularMovement(Movable* object, double destiny, bool clockWise): Movement(object, MOVEMENT_DEFAULT_SPEED), destiny(destiny), clockWise(clockWise)
{
}

void AngularMovement::move()
{
}
