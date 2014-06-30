/* 
 * File:   utils.h
 * Author: fernando
 *
 * Created on 28. Juni 2014, 00:20
 */

#ifndef UTILS_H
#define	UTILS_H

#include <cmath>
#include <utility>

#define COS_PI_4 0.70710678
#define radToDegree(r)  ((r) * 180/M_PI)
#define maxVectorInModule(a,b)    ((module(a) < module(b) ? b : a))

double distanceBetweenPoints(const std::pair<double,double> &p1, const std::pair<double,double> &p2);

std::pair<double, double> makeVector2(const std::pair<double,double> &from, const std::pair<double,double> &to);

template <class T1, class T2>
    double operator* (const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs);

template <class T1, class T2>
    std::pair<T1,T2> operator- (const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs);

double module(const std::pair<double,double> &p);

template <class T1>
    std::pair<T1,T1> multScalarVector(T1 c, const std::pair<T1, T1>& v);

std::pair<double, double> project(const std::pair<double,double> &p, const std::pair<double,double> &in);

#endif	/* UTILS_H */

