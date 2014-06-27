#ifndef PENGUIN_H
#define PENGUIN_H

#include "Movable.h"
#include "3DObject.h"

class Penguin : public Movable
{
private:
	double direction;

	C3DObject model;

};
#endif
