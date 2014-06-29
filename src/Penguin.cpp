#include "Penguin.h"
#include "Modelable.h"
#include "Movable.h"
#include "Scenario.h"
#include "Movement.h"
#include "Block.h"
#include "utils.h"

#include "GL/gl.h"
#include "GameController.h"
#include <vector>
#include <cmath>
#include <cassert>

#define PENGUIN_OFFSET_DIRECAO_MODELO M_PI_2

extern Scenario scenario;
extern GameController gameController;

Penguin::Penguin(C3DObject* _model, std::pair<double, double> _position)
:Movable(_position, 3*M_PI_2),
Modelable(_model)
{
}

void Penguin::draw()
{
	glTranslatef((GLfloat)position.first, 1.0, (GLfloat)position.second);
    glScalef(0.75, 0.75, 0.75);
	glRotatef(radToDegree(direction + MODELABLE_OFFSET_DIRECAO_MODELO), 0.0, 1.0, 0.0);
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

void Penguin::takeActionToColision(Movement* movement, double deltaMove)
{
	std::pair<int, int> desiredPosition = getNextLinearPosition(deltaMove); //Next integer position
	
	//If intends to go outside the map. End of scenario
	if (scenario.outOfMap(desiredPosition)){
		//Stop
		movement->ready = true;
		
	}else if (scenario.map[desiredPosition.second][desiredPosition.first] != NULL
			&& scenario.map[desiredPosition.second][desiredPosition.first] != (Modelable*)this) {
		//Here, there is something on the way. Colided with something
		
		Modelable* other = scenario.map[desiredPosition.second][desiredPosition.first];
		//If collided with a block
		if (dynamic_cast<Block*>(other)){
			//Just stop
			movement->ready = true;
			
		}else if (dynamic_cast<Item*>(other)){
			//Collided with an Item 
			//@TODO
			
		}else if (dynamic_cast<Enemy*>(other)){
			//Collided with an Enemy
			movement->ready = true;
			
			gameController.endMatch();
			
		}else if (dynamic_cast<Penguin*>(other)){
			assert (false); //There shouldn't be more than one penguin
		}
		
	}else{
		//Normal exection, keep moving
		
		Modelable* other = scenario.map[desiredPosition.second][desiredPosition.first];
		//If hasn't put this object in the next position, then it's the first move. So, put it
		if (other != (Modelable*)this){
			//free the old position
			scenario.map[(int)position.second][(int)position.first] = NULL;
			//place itself in the next position
			scenario.map[desiredPosition.second][desiredPosition.first] = this;
		}
		
        position = getNewPosition<double>(deltaMove);
		
	}
}

void Penguin::die(){
	scenario.map[(int)position.second][(int)position.first] = NULL;
}