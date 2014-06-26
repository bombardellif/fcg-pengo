#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "LinearMovement.h"
#include "Penguin.h"
#include "Enemy.h"
#include "java/util/List.h"

class GameController
{
private:
	static GameController instance;

	java::util::List<LinearMovement> blockingMovements;

	java::util::List<LinearMovement> normalMovements;

	Penguin penguin;

	java::util::List<Enemy> enemies;

public:
	boolean upPressed;

	boolean downPressed;

	boolean rightPressed;

	boolean leftPressed;


public:
	static GameController getInstance();

	void update();

};
#endif
