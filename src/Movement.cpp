#include "Movement.h"

Movement::Movement(const Movable& _object): object(_object), speed(DEFAULT_SPEED), ready(false)
{
}

Movement::Movement(const Movable& object, double speed): object(object), speed(speed), ready(false)
{
}

bool Movement::isReady()
{
    return ready;
}
