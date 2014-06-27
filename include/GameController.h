#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "LinearMovement.h"
#include "Penguin.h"
#include "Enemy.h"

#define MAX_BLOCKING_MOVEMENTS 10
#define MAX_NORMAL_MOVEMENTS 50
#define MAX_ENEMIES 10

class GameController
{
private:
	LinearMovement blockingMovements[MAX_BLOCKING_MOVEMENTS];

	LinearMovement normalMovements[MAX_NORMAL_MOVEMENTS];

	Penguin penguin;

	Enemy enemies[MAX_ENEMIES];

public:
	bool upPressed;

	bool downPressed;

	bool rightPressed;

	bool leftPressed;


public:
	void update();

};
#endif
