#include "Block.h"
#include "Modelable.h"
#include "Scenario.h"
#include "GameController.h"
#include <cassert>

extern Scenario scenario;
extern GameController gameController;

Block::Block(C3DObject* _model, std::pair<double, double> _position, Item* item, bool mobile)
:Movable(_position),
Modelable(_model),
item(item),
mobile(mobile)
{
}

void Block::draw()
{
	glTranslatef((GLfloat)position.first, 1.0, (GLfloat)position.second);
    glScalef(0.5, 0.5, 0.5);
    Modelable::draw();
}

void Block::makeMovementInMap(Movement* movement, double deltaMove)
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
		//If colided with a block
		if (dynamic_cast<Block*>(other)){
			//Just stop
			movement->ready = true;
			
		}else if (dynamic_cast<Item*>(other)){
			//Colided with an Item 
			movement->ready = true;
			
		}else if (dynamic_cast<Enemy*>(other)){
			//Colided with an Enemy
			movement->ready = true;
			
			gameController.kill((Enemy*)other);
			
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


void Block::conceive()
{
}

void Block::materialize()
{
}

void Block::die()
{
	scenario.map[(int)position.second][(int)position.first] = NULL;
}