#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Penguin.h"
#include "Enemy.h"
#include "Movement.h"

#include <list>

//#define MAX_BLOCKING_MOVEMENTS 10
//#define MAX_NORMAL_MOVEMENTS 50
//#define MAX_ENEMIES 10
#define GAMECONTROLLER_MIN_ENEMIES 1
#define GAMECONTROLLER_DEFAULT_PENGUIN_SPEED 0.25
#define GAMECONTROLLER_DEFAULT_MAX_CONCEIVING_BLOCKS 5
#define GAMECONTROLLER_NUM_CAMERAS 3

class GameController
{
private:
	std::list<Movement*> blockingMovements;

	std::list<Movement*> normalMovements;

	std::list<Enemy*> enemies;

    double penguinSpeed;

    int maxConceivingBlocks;

public:

	bool goForwardPressed;

	bool goBackwardsPressed;

	bool turnClockwisePressed;

	bool turnCounterClockwisePressed;

	bool changeCameraPressed;

	bool pushPressed;

	bool createnewBlockPressed;

	Penguin* penguin;
    

public:
	GameController(Penguin* penguin);
	GameController();
    void init();
    
	void update();
	void interpretBlockableCommand();
	void interpretNonBlockableCommand();
	std::pair<double, double> translateMapToGL(std::pair<int, int> mapCoordinate);
	void endMatch();
	void kill(Enemy* enemy);
};
#endif
