#include "utils.h"
#include <utility>
#include <cmath>

double distanceBetweenPoints(const std::pair<double,double> &p1, const std::pair<double,double> &p2)
{
    return std::sqrt(std::pow(p2.first - p1.first, 2) + std::pow(p2.second - p1.second, 2));
}

std::pair<double, double> makeVector2(const std::pair<double,double> &from, const std::pair<double,double> &to)
{
    return std::pair<double, double>(to.first - from.first, to.second - from.second);
}

template <typename T1, typename T2>
    double operator* (const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
{
    return lhs.first * rhs.first + lhs.second * rhs.second;
}
template double operator*<double, double>(std::pair<double, double> const&, std::pair<double, double> const&);

template <class T1, class T2>
    std::pair<T1,T2> operator- (const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
{
    return std::pair<T1,T2>(lhs.first - rhs.first, lhs.second - rhs.second);
}

double module(const std::pair<double,double> &p)
{
    return std::sqrt(p.first*p.first + p.second*p.second);
}

template <class T1>
    std::pair<T1,T1> multScalarVector(T1 c, const std::pair<T1, T1>& v)
{
    return std::pair<T1, T1>(v.first * c, v.second * c);
}

std::pair<double, double> project(const std::pair<double,double> &p, const std::pair<double,double> &in)
{
    return multScalarVector((p * in) / (in*in), in);
}