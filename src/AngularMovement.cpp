#include "AngularMovement.h"

#include <cmath>
#include <iostream>


AngularMovement::AngularMovement(Movable* object, double destiny, bool clockWise): Movement(object, ANGULARMOVEMENT_DEFAULT_SPEED), destiny(destiny), clockWise(clockWise)
{
}

AngularMovement::AngularMovement(Movable* object, double destiny, bool clockWise, double speed)
: Movement(object, speed)
,destiny(destiny)
, clockWise(clockWise)
{
}

void AngularMovement::move()
{
	//If the movement is not over yet, then do it
    if (!isReady()){
		//Error accepted regarded to the discretization of the movement
		double e = speed;

		//Calculate how much yet to the end of movement
		double yetToMove = object->direction - destiny;
		//If there is no more movement to perform, then movement is ready
		if (fabs(yetToMove) <= e){
			ready = true;
			object->direction = destiny;

			// notify Observers, once the movement is finished
			this->notifyObservers();

		}else{
			//Define diretion and velocity of movement
			double deltaMove;
			if (clockWise)
				deltaMove = -speed;
			else
				deltaMove = speed;

			//Since it has not finished moving yet, keep moving
			object->direction = object->getNewDirection(deltaMove);
		}
	}
}
