/* 
 * File:   Observable.cpp
 * Author: fernando
 * 
 * Created on 27. Juni 2014, 22:26
 */

#include <list>
#include <algorithm>

#include "Observable.h"

Observable::Observable() {
}

Observable::~Observable() {
}

void Observable::addObserver(Observer* observer)
{
    this->observers.push_back(observer);
}

void Observable::callNotify(Observer* observer)
{
    observer->notify();
}

void Observable::notifyObservers()
{
    std::for_each(this->observers.begin(), this->observers.end(), Observable::callNotify);
}