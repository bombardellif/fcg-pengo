#include "GameController.h"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "DiscreteDirection.h"
#include "LinearMovement.h"
#include "AngularMovement.h"
#include "Scenario.h"
#include "Block.h"
#include "Conception.h"
#include <iostream>

extern Scenario scenario;

GameController::GameController(Penguin* penguin):
penguinSpeed(GAMECONTROLLER_DEFAULT_PENGUIN_SPEED), 
maxConceivingBlocks(GAMECONTROLLER_DEFAULT_MAX_CONCEIVING_BLOCKS), 
penguin(penguin),
gameState(GAMECONTROLLER_STATE_PLAYING)
{
}

GameController::GameController():
penguinSpeed(GAMECONTROLLER_DEFAULT_PENGUIN_SPEED),
maxConceivingBlocks(GAMECONTROLLER_DEFAULT_MAX_CONCEIVING_BLOCKS),		
penguin(NULL),
gameState(GAMECONTROLLER_STATE_PLAYING)
{
}

void GameController::init()
{
    std::srand(std::time(NULL));
    
    // Place the enemies and Pengo all over the free spaces
    std::vector< std::pair<int,int> > freePositions = scenario.getFreeMapPositions();
    int size = freePositions.size();
    
    if (size < GAMECONTROLLER_MIN_ENEMIES + 1) {
        throw std::string("Mapa não permite criação dos elementos do jogo");
    }
    int randomPosition;
    for (int i=0; i<GAMECONTROLLER_MIN_ENEMIES + 1; i++) {
        randomPosition = std::rand() % size;
        
        std::pair<int,int> &newPosition = freePositions[randomPosition];
        
        if (i == 0) {
            this->penguin = scenario.createPenguinAt(newPosition.first, newPosition.second);
        } else {
            this->enemies.push_back(scenario.createEnemyAt(newPosition.first, newPosition.second));
        }
        
        size--;
        freePositions.erase(freePositions.begin() + randomPosition);
    }
    
    // Place the items inside random moblie blocks
    std::vector< std::pair<int,int> > mobileBlocksPos = scenario.getMobileBlockPositions();
    int sizeBlocks = mobileBlocksPos.size();
    
    if (sizeBlocks < GAMECONTROLLER_MIN_ITEMS) {
        throw std::string("Mapa não permite criação dos itens nos blocos");
    }
    for (int i=0; i<GAMECONTROLLER_MIN_ITEMS; i++) {
        randomPosition = std::rand() % sizeBlocks;
        
        std::pair<int,int> chosenBlockPos = mobileBlocksPos[randomPosition];
        
        std::cout << chosenBlockPos.first << chosenBlockPos.second <<std::endl;
        scenario.createItemInsideBlockAt(chosenBlockPos.first, chosenBlockPos.second);
        
        size--;
        mobileBlocksPos.erase(mobileBlocksPos.begin() + randomPosition);
    }
}

void GameController::update()
{
	//Verify end of match
	refreshGameState();
    if (gameState != GAMECONTROLLER_STATE_PLAYING){
		endMatch(gameState);
	}else{
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

		//Moves the enemies
		for (std::list<Enemy*>::iterator it=enemies.begin(); it != enemies.end(); ++it){
			Movement* move = (*it)->makeMovement(*this->penguin);
			if (move) {
				this->normalMovements.push_back(move);
			}
		}

		for (std::list<Movement*>::iterator it=normalMovements.begin(); it != normalMovements.end(); ++it){
			Movement* current = (*it);
			(*current).move();
			//If the movement is over, finishes it
			if ((*current).isReady()){
				it = normalMovements.erase(it);
				delete current;
				current = NULL;
			}
		}

		//Update Conceptions
		for (std::list<Conception*>::iterator it=scenario.conceptions.begin(); it != scenario.conceptions.end(); ++it){
			Conception* current = (*it);
			current->step();
			//If the conception is over, conceives it or cancels it
			if (current->isReady()){
				//If the place is clean, puts the new block there
				if (scenario.map[(int)current->position.second][(int)current->position.first] == NULL){
					scenario.map[(int)current->position.second][(int)current->position.first] = (Modelable*)(current->block);
					it = scenario.conceptions.erase(it);
				}else{
					it = scenario.conceptions.erase(it);				
					delete current;
					current = NULL;
				}
			}
		}

		//Check for new commands, that don't get blocked
		interpretNonBlockableCommand();
	}
}

void GameController::interpretBlockableCommand(){
	if(gameState ==  GAMECONTROLLER_STATE_PLAYING){
		//Penguin wants to go forward
		if (goForwardPressed){
			//Then creates new movement to this penguin (only one position)
			std::pair<int, int> nextPosition = penguin->getNewPosition<int>(1);
			LinearMovement* newMove = new LinearMovement(penguin, nextPosition, true, penguinSpeed);
			blockingMovements.push_back(newMove);

		}else if(goBackwardsPressed){
			//Penguin wants to go backwards, creates a movement for this
			std::pair<int, int> nextPosition = penguin->getNewPosition<int>(-1);
			LinearMovement* newMove = new LinearMovement(penguin, nextPosition, false, penguinSpeed);
			blockingMovements.push_back(newMove);

		}else if(turnClockwisePressed){
			//Turn penguin right (clockwise) 90°
			double nextDirection = penguin->getNewDirection(-M_PI_2);
			AngularMovement* newMove = new AngularMovement(penguin, nextDirection, true);
			blockingMovements.push_back(newMove);

		}else if (turnCounterClockwisePressed){
			//Turn penguin left (counter-clockwise) 90°
			double nextDirection = penguin->getNewDirection(M_PI_2);
			AngularMovement* newMove = new AngularMovement(penguin, nextDirection, false);
			blockingMovements.push_back(newMove);
		}

		//Penguin wants to push a block
		if (pushPressed){
			//Take the position in front and verify if it is a block
			std::pair<int, int> frontPosition = penguin->getNewPosition<int>(1);
			if (!scenario.outOfMap(frontPosition)){

				Block* block = dynamic_cast<Block*>(scenario.map[frontPosition.second][frontPosition.first]);
				if (block != NULL && block->mobile){ //It is a mobile block

					std::pair<int, int> twoPosAway = penguin->getNewPosition<int>(2);
					//If it is a push towards the wall, destroy the block
					if (scenario.outOfMap(twoPosAway)){
						//Destroy it
						block->die();
						delete block;
						block = NULL;

					} else {

						Modelable* other;
						//If there is another block in front of this one...
						if (((other = scenario.map[twoPosAway.second][twoPosAway.first]) != NULL)
						&& (dynamic_cast<Block*>(other))) {
							//Destroy it
							block->die();
							delete block;
							block = NULL;
						} else {
							//The way is free, push it to the bounds
							block->direction = penguin->direction;
							std::pair<int, int> blockDestiny = penguin->getNewPosition<int>(SCENARIO_MAP_SIZE+1);
							LinearMovement* newBlockMove = new LinearMovement(block, blockDestiny, true);
							normalMovements.push_back(newBlockMove);
						}
					}
				}
			}
		}

		//Create new Block
		if(createnewBlockPressed){
			std::pair<int, int> nextPosition = penguin->getNewPosition<int>(1);
			if (scenario.conceptions.size() < maxConceivingBlocks)
				scenario.createConceptionAt(nextPosition.second, nextPosition.first, GAMECONTROLLER_NUM_STEPS_CONCEPTION);
		}
}
}

void GameController::interpretNonBlockableCommand(){
	//Change camera position
	if (changeCameraPressed)
		scenario.cameraState = (scenario.cameraState + 1) % GAMECONTROLLER_NUM_CAMERAS;
}

std::pair<double, double> GameController::translateMapToGL(std::pair<int, int> mapCoordinate){
	return (std::pair<double, double>)(mapCoordinate);
}

void GameController::endMatch(int state)
{
	//penguin->die();
	//Do not disalloc penguim. There is no need
	gameState = state;
}

void GameController::kill(Enemy* enemy)
{
	enemy->die();
	
	enemies.remove(enemy);
	delete enemy;
}

void GameController::kill(Item* item)
{
	item->die();
	delete item;			
}

void GameController::refreshGameState()
{
	if (enemies.size() == 0)
		gameState = GAMECONTROLLER_STATE_WIN;
	else if (penguin == NULL)
		gameState = GAMECONTROLLER_STATE_LOSE;
}
