#include "LinearMovement.h"


LinearMovement::LinearMovement(const Movable& object, std::pair<double, double> destiny):Movement(object), destiny(destiny)
{
}
