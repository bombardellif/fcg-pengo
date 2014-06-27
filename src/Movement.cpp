#include "Movement.h"

Movement::Movement(Movable* _object): object(_object), speed(MOVEMENT_DEFAULT_SPEED), ready(false)
{
}

Movement::Movement(Movable* object, double speed): object(object), speed(speed), ready(false)
{
}

bool Movement::isReady()
{
    return ready;
}
