#ifndef CONCEPTION_H
#define CONCEPTION_H

#include "Block.h"

class Conception
{
private:
	Block block;

	int numSteps;


public:
	Conception(const Block& block, int numSteps);

	void step();

};
#endif
