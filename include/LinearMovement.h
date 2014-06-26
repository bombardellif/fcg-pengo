#ifndef LINEAR_MOVEMENT_H
#define LINEAR_MOVEMENT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Movement.h"
#include "pair.h"
#include "Movable.h"

class LinearMovement : public Movement
{
private:
	pair destiny;


public:
	void Movement(Movable object, pair destiny);

};
#endif
