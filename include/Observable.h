/* 
 * File:   Observable.h
 * Author: fernando
 *
 * Created on 27. Juni 2014, 22:26
 */

#ifndef OBSERVABLE_H
#define	OBSERVABLE_H

class Observable;

#include "Observer.h"
#include <list>

class Observable {
private:
    std::list<Observer*> observers;
    
public:
    Observable();
    virtual ~Observable();
    
    void addObserver(Observer *observer);
    void notifyObservers();
    static void callNotify(Observer *observer);
};

#endif	/* OBSERVABLE_H */

