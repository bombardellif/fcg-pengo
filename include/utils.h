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

#define radToDegree(r)  ((r) * 180/M_PI)

double distanceBetweenPoints(const std::pair<double,double> &p1, const std::pair<double,double> &p2);

#endif	/* UTILS_H */

