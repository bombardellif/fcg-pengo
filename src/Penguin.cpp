#include "Penguin.h"
#include "Modelable.h"
#include "Movable.h"
#include "Scenario.h"
#include "Movement.h"
#include "Block.h"
#include "GL/gl.h"
#include <vector>
#include <cmath>

#define PENGUIN_OFFSET_DIRECAO_MODELO M_PI_2
#define radToDegree(r) (r + PENGUIN_OFFSET_DIRECAO_MODELO) * 180/M_PI

extern Scenario scenario;

Penguin::Penguin(C3DObject* _model, std::pair<double, double> _position)
:Movable(_position, 3*M_PI_2),
Modelable(_model)
{
}

void Penguin::draw()
{
	glTranslatef((GLfloat)position.first, 1.0, (GLfloat)position.second);
    glScalef(0.75, 0.75, 0.75);
	glRotatef(radToDegree(direction), 0.0, 1.0, 0.0);
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

void Penguin::takeActionToColision(Movement* movement, std::pair<int, int> desiredPosition)
{
	if (scenario.outOfMap(desiredPosition)){
		movement->ready = true;
	}else{
		//other = 
		if (dynamic_cast<Block*>(scenario.map[desiredPosition.second][desiredPosition.first])){
			movement->ready = true;
			//position = desiredPosition;
		}
	}
}