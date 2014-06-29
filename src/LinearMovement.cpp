#include "LinearMovement.h"

#include "GameController.h"
#include "Scenario.h"
#include <limits>
#include <utility>
#include <cassert>
#include <cmath>
#include <iostream>

extern GameController gameController;
extern Scenario scenario;

LinearMovement::LinearMovement(Movable* object, std::pair<double, double> destiny, bool forward):Movement(object, MOVEMENT_DEFAULT_SPEED), destiny(destiny), forward(forward)
{
}

LinearMovement::LinearMovement(Movable* object, std::pair<double, double> destiny, bool forward, double speed): Movement(object, speed), destiny(destiny), forward(forward)
{
}

void LinearMovement::move(){
	
    std::pair<double, double> destinyInGL = gameController.translateMapToGL(destiny);
	
	//Error accepted regarded to the discretization of the movement
	double e = speed;
	
	//Always supose one of the coordinate are equal. Because the movement is linear (one row or one column)
	assert(fabs(object->position.first - destinyInGL.first) <= e
			|| fabs(object->position.second - destinyInGL.second) <= e);
	
	//Calculate how much yet to the end of movement
	double yetToMove;
	if (fabs(object->position.first - destinyInGL.first) <= e){
		//firsts are "equal"(near enough), we are changing the second (or the movement is done)
		yetToMove = object->position.second - destinyInGL.second;
	}else{
		//Firsts are not equal, then get the remaining movement to perform
		yetToMove = object->position.first - destinyInGL.first;
	}
	
	//If there is no more movement to perform, then movement is ready
	if (fabs(yetToMove) <= e){
        ready = true;
		object->position = destiny;
        
        // notify Observers, once the movement is finished
        this->notifyObservers();
    }else{
		//Define diretion and velocity of movement
		double deltaMove;
		if (forward)
			deltaMove = speed;
		else
			deltaMove = -speed;
		
		//Let the object define where to go and behavior in case of colision
        object->takeActionToColision(this, deltaMove);
    }

}
