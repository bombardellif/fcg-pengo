#include "GameController.h"
#include <algorithm>
#include <cmath>

#include "DiscreteDirection.h"
#include "LinearMovement.h"
#include "AngularMovement.h"
#include "Scenario.h"
#include "Block.h"

extern Scenario scenario;

GameController::GameController(Penguin* penguin): penguinSpeed(GAMECONTROLLER_DEFAULT_PENGUIN_SPEED), maxConceivingBlocks(GAMECONTROLLER_DEFAULT_MAX_CONCEIVING_BLOCKS), penguin(penguin)
{
}

GameController::GameController(): penguinSpeed(GAMECONTROLLER_DEFAULT_PENGUIN_SPEED), maxConceivingBlocks(GAMECONTROLLER_DEFAULT_MAX_CONCEIVING_BLOCKS), penguin(NULL)
{
}

void GameController::update()
{
    
    //If there is no movements in action blocking the user input, then treat their input
    if (blockingMovements.empty()){
        interpretBlockableCommand();
    }	

    //Moves the current movements
    for (std::list<Movement*>::iterator it=blockingMovements.begin(); it != blockingMovements.end(); ++it){
        Movement* current = (*it);
        (*current).move();
        //If the movement is over, finishes it
        if ((*current).isReady()){
            it = blockingMovements.erase(it);
            delete current;
            current = NULL;
        }
    }
    for (std::list<Movement*>::iterator it=normalMovements.begin(); it != normalMovements.end(); ++it){
        Movement* current = (*it);
        (*current).move();
        //If the movement is over, finishes it
        if ((*current).isReady()){
            normalMovements.erase(it);
            delete current;
            current = NULL;
        }
    }

    //Moves the enemies
    //for (std::list<Enemy>::iterator it=enemies.begin(); it != enemies.end(); ++it){
    //    moveEnemy((*it));
    //}
    
    //@TODO: Iterate in conceptions
    
    //Check for new commands, that don't get blocked
    //interpretNonBlockableCommand();
}

void GameController::interpretBlockableCommand(){
    //Penguin wants to go forward
    if (goForwardPressed){
        //Then creates new movement to this penguin (only one position)
        std::pair<int, int> nextPosition = penguin->getNewPosition<int>(1);
        LinearMovement* newMove = new LinearMovement(penguin, nextPosition, penguinSpeed);
        blockingMovements.push_back(newMove);
    }else if(goBackwardsPressed){
        //Penguin wants to go backwards, creates a movement for this
        std::pair<int, int> nextPosition = penguin->getNewPosition<int>(-1);
        LinearMovement* newMove = new LinearMovement(penguin, nextPosition, penguinSpeed);
        blockingMovements.push_back(newMove);
    }else if(turnClockwisePressed){
        //Turn penguin right (clockwise) 90°
        double nextDirection = penguin->getNewDirection(-M_PI/2);
        AngularMovement* newMove = new AngularMovement(penguin, nextDirection, true);
        blockingMovements.push_back(newMove);
    }else if (turnCounterClockwisePressed){
        //Turn penguin left (counter-clockwise) 90°
        double nextDirection = penguin->getNewDirection(M_PI/2);
        AngularMovement* newMove = new AngularMovement(penguin, nextDirection, false);
        blockingMovements.push_back(newMove);
    }

    //Penguin wants to push a block
    if (pushPressed){
        //Take the position in front and verify if it is a block
        std::pair<int, int> frontPosition = penguin->getNewPosition<int>(1);
        if (!scenario.outOfMap(frontPosition)){
            
            Block* block = dynamic_cast<Block*>(scenario.map[frontPosition.first][frontPosition.second]);
            if (block != NULL && block->mobile){ //It is a block
				//Push it to the bounds
				std::pair<int, int> blockDestiny = penguin->getNewPosition<int>(SCENARIO_MAP_SIZE);				
				LinearMovement* newBlockMove = new LinearMovement(block, blockDestiny);
                normalMovements.push_back(newBlockMove);
            }
        }
    }

	//Change camera position
	if (changeCameraPressed)
		scenario.cameraState = (scenario.cameraState + 1) % GAMECONTROLLER_NUM_CAMERAS;
	
	//Create new Block
	//if(createNewBlockPressed)
}

void GameController::interpretNonBlockableCommand(){
}

void GameController::moveEnemy(const Enemy& enemy){
}

std::pair<double, double> GameController::translateMapToGL(std::pair<int, int> mapCoordinate){
	return (std::pair<double, double>)(mapCoordinate);
}

void GameController::takeActionToColision(const Movable* actor, std::pair<int, int> desiredPosition)
{
}