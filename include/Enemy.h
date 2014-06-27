#ifndef ENEMY_H
#define ENEMY_H

#include "Movable.h"
#include "3DObject.h"

class Enemy : public Movable
{
private:
        //Enemy();
	double direction;

	C3DObject model;

};
#endif
