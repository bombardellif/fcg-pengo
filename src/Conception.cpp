#include "Conception.h"
#include <iostream>


Conception::Conception(Block* block, int numSteps, C3DObject* model, std::pair<int, int> position): 
Modelable(model),
currentStep(0),
block(block),
numSteps(numSteps),
model (model),
position(position)
{
}

void Conception::step()
{
	currentStep++;
}

bool Conception::isReady(){
	return currentStep >= numSteps;
}

void Conception::draw()
{
	//glTranslatef((GLfloat)position.first, 1.0, (GLfloat)position.second);
    //glScalef(0.5, 0.5, 0.5);
    Modelable::draw();
}