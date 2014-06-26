#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Movable.h"

class Movement
{
private:
	Movable object;


public:
	void move();

	boolean isReady();

};
#endif
