/* 
 * File:   Observer.h
 * Author: fernando
 *
 * Created on 27. Juni 2014, 22:23
 */

#ifndef OBSERVER_H
#define	OBSERVER_H

class Observer;

#include "Observable.h"


class Observer {
public:
    Observer();
    virtual ~Observer();
    
    virtual void notify() = 0;
private:

};

#endif	/* OBSERVER_H */

