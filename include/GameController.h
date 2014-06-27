#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Penguin.h"
#include "Enemy.h"
#include "Movement.h"

#include <list>

//#define MAX_BLOCKING_MOVEMENTS 10
//#define MAX_NORMAL_MOVEMENTS 50
//#define MAX_ENEMIES 10
#define DEFAULT_PENGUIN_SPEED 1
#define DEFAULT_MAX_CONCEIVING_BLOCKS 5

class GameController
{
private:
	std::list<Movement*> blockingMovements;

	std::list<Movement*> normalMovements;

	Penguin penguin;

	std::list<Enemy> enemies;

        double penguinSpeed;

        int maxConceivingBlocks;

public:
	bool upPressed;

	bool downPressed;

	bool turnClockwisePressed;

	bool turnCounterClockwisePressed;


public:
        GameController();
	void update();
        void interpretBlockableCommand();
        void interpretNonBlockableCommand();
        void moveEnemy(const Enemy& enemy);
};
#endif
