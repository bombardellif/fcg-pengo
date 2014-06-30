#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Penguin.h"
#include "Enemy.h"
#include "Movement.h"
#include "Item.h"

#include <list>

#define GAMECONTROLLER_MIN_ENEMIES 4
#define GAMECONTROLLER_MIN_ITEMS 8
#define GAMECONTROLLER_DEFAULT_PENGUIN_SPEED 0.25
#define GAMECONTROLLER_DEFAULT_MAX_CONCEIVING_BLOCKS 1
#define GAMECONTROLLER_NUM_CAMERAS 3
#define GAMECONTROLLER_LOOPS_PER_SECOND 15
#define GAMECONTROLLER_NUM_STEPS_CONCEPTION GAMECONTROLLER_LOOPS_PER_SECOND * 2

#define GAMECONTROLLER_STATE_PLAYING 0
#define GAMECONTROLLER_STATE_WIN 1
#define GAMECONTROLLER_STATE_LOSE 2

class GameController
{
private:
	std::list<Movement*> blockingMovements;

	std::list<Movement*> normalMovements;

	std::list<Enemy*> enemies;

public:
    double penguinSpeed;

    unsigned int maxConceivingBlocks;

	bool goForwardPressed;

	bool goBackwardsPressed;

	bool turnClockwisePressed;

	bool turnCounterClockwisePressed;

	bool changeCameraPressed;

	bool pushPressed;

	bool createnewBlockPressed;

	Penguin* penguin;
	
	int gameState;
    

public:
	GameController(Penguin* penguin);
	GameController();
    void init();
    
	void update();
	void interpretBlockableCommand();
	void interpretNonBlockableCommand();
	std::pair<double, double> translateMapToGL(std::pair<int, int> mapCoordinate);
	void endMatch(int state);
	void kill(Enemy* enemy);
	void kill(Item* item);
	void refreshGameState();
};
#endif
