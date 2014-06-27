#include "AngularMovement.h"


AngularMovement::AngularMovement(const Movable& object, double destiny, bool clockWise): Movement(object, DEFAULT_SPEED), destiny(destiny), clockWise(clockWise)
{
}

void AngularMovement::move()
{
}
