#include "utils.h"
#include <utility>

double distanceBetweenPoints(const std::pair<double,double> &p1, const std::pair<double,double> &p2)
{
    return std::sqrt(std::pow(p2.first - p1.first, 2) + std::pow(p2.second - p1.second, 2));
}
