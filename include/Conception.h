#ifndef CONCEPTION_H
#define CONCEPTION_H

#include "Block.h"
#include "Modelable.h"

class Conception: Modelable
{
private:
	int currentStep;
	
public:
	Block* block;

	int numSteps;
	
	C3DObject* model;
	
	std::pair<int, int> position;

public:
	Conception(Block* block, int numSteps, C3DObject* model, std::pair<int, int> position);

	void step();
	
	bool isReady();
	
	virtual void draw();

};
#endif
