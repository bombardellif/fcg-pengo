#ifndef CONCEPTION_H
#define CONCEPTION_H

#include "Block.h"
#include "Modelable.h"

class Conception: public Modelable, public Movable
{
private:
	int currentStep;
	
public:
	Block* block;

	int numSteps;

public:
	Conception(Block* block, int numSteps, C3DObject* model, std::pair<double, double> position);

	void step();
	
	bool isReady();
	
	virtual void draw();

    virtual void makeMovementInMap(Movement* movement, double deltaMove) {};
};
#endif
