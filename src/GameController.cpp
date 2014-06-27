#include "GameController.h"
#include <algorithm>
#include <math.h>

#include "DiscreteDirection.h"
#include "LinearMovement.h"
#include "AngularMovement.h"

GameController::GameController(Penguin& penguin): penguinSpeed(DEFAULT_PENGUIN_SPEED), maxConceivingBlocks(DEFAULT_MAX_CONCEIVING_BLOCKS), penguin(penguin)
{
}

GameController::GameController(): penguinSpeed(DEFAULT_PENGUIN_SPEED), maxConceivingBlocks(DEFAULT_MAX_CONCEIVING_BLOCKS), penguin(penguin)
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
            blockingMovements.erase(it);
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
    if (upPressed){
        //Then creates new movement to this penguin (only one position)
        std::pair<int, int> nextPosition = penguin.getNewPosition<int>(1);
        LinearMovement* newMove = new LinearMovement(penguin, nextPosition);
        blockingMovements.push_back(newMove);
    }else if(downPressed){
        //Penguin wants to go backwards, creates a movement for this
        std::pair<int, int> nextPosition = penguin.getNewPosition<int>(-1);
        LinearMovement* newMove = new LinearMovement(penguin, nextPosition);
        blockingMovements.push_back(newMove);
    }else if(turnClockwisePressed){
        //Turn penguin right (clockwise) 90°
        double nextDirection = penguin.getNewDirection(-M_PI/2);
        AngularMovement* newMove = new AngularMovement(penguin, nextDirection, true);
        blockingMovements.push_back(newMove);
    }else if (turnCounterClockwisePressed){
        //Turn penguin left (counter-clockwise) 90°
        double nextDirection = penguin.getNewDirection(M_PI/2);
        AngularMovement* newMove = new AngularMovement(penguin, nextDirection, false);
        blockingMovements.push_back(newMove);
    }
}

void GameController::interpretNonBlockableCommand(){
}

void GameController::moveEnemy(const Enemy& enemy){
}

std::pair<double, double> GameController::translateMapToGL(std::pair<int, int> mapCoordinate){
}

void GameController::takeActionToColision(Movable actor, std::pair<int, int> desiredPosition)
{
}