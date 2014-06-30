#include "Conception.h"
#include <iostream>
#include <cmath>
#include "utils.h"

Conception::Conception(Block* block, int numSteps, C3DObject* model, std::pair<double, double> position): 
Modelable(model),
Movable(position, 3*M_PI_2),
currentStep(0),
block(block),
numSteps(numSteps)
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
	glTranslatef((GLfloat)position.first, 1.0, (GLfloat)position.second);
    glScalef(0.4, 0.4, 0.4);
    glRotatef(radToDegree(direction + MODELABLE_OFFSET_DIRECAO_MODELO), 0.0, 1.0, 0.0);
    glRotated(90, 1.0, 0.0, 0.0);
    this->model->Draw(SMOOTH);
}