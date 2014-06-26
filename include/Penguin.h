#ifndef PENGUIN_H
#define PENGUIN_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Movable.h"
#include "C3DObject.h"

class Penguin : public Movable
{
private:
	double direction;

	C3DObject model;

};
#endif
