#include "Penguin.h"
#include "Modelable.h"
#include "Movable.h"
#include "GL/gl.h"
#include <vector>
#include <cmath>

Penguin::Penguin(C3DObject* _model, std::pair<double, double> _position)
:Movable(_position, 3*M_PI_2),
Modelable(_model)
{
}

void Penguin::draw()
{
	glTranslatef((GLfloat)position.first, 1.0, (GLfloat)position.second);
    glScalef(0.75, 0.75, 0.75);
    Modelable::draw();
}

std::vector<double> Penguin::getEyesPosition()
{
    std::vector<double> result;
    
    result.push_back(this->position.first);
    result.push_back(1.75);
    result.push_back(this->position.second);
    
    return result;
}

std::vector<double> Penguin::getFocusPosition()
{
    std::vector<double> result;
    std::pair<double, double> nextStep = this->getNewPosition(1.0);
    
    result.push_back(nextStep.first);
    result.push_back(1.25);
    result.push_back(nextStep.second);
    
    return result;
}