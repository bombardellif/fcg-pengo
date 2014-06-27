#include "Penguin.h"
#include "Modelable.h"
#include "Movable.h"
#include "GL/gl.h"
#include <vector>

Penguin::Penguin(C3DObject* _model, std::pair<double, double> _position)
:Movable(_position),
Modelable(_model)
{
}

void Penguin::draw()
{
    glTranslatef(0.0, 1.0, 0.0);
    glScalef(0.75, 0.75, 0.75);
    Modelable::draw();
}

std::vector<double> Penguin::getEyesPosition()
{
    std::vector<double> result;
    
    result.push_back(this->position.first);
    result.push_back(2.0);
    result.push_back(this->position.second);
    
    return result;
}

std::vector<double> Penguin::getFocusPosition()
{
    std::vector<double> result;
    std::pair<int, int> nextStep = this->getNewPosition(this->direction);
    
    result.push_back((double)nextStep.first);
    result.push_back(1.0);
    result.push_back((double)nextStep.second);
    
    return result;
}