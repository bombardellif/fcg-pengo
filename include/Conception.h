#ifndef CONCEPTION_H
#define CONCEPTION_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Block.h"

class Conception
{
private:
	Block block;

	int numSteps;


public:
	void Conception(Block block, int numStep);

	void step();

};
#endif
