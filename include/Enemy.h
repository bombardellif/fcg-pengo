#ifndef ENEMY_H
#define ENEMY_H

#include "Movable.h"
#include "3DObject.h"
#include "Modelable.h"
#include "Movement.h"
#include "Penguin.h"
#include "Observable.h"

#define ENEMY_DISTANCE_LOOK_PENGUIN 4.0
#define ENEMEY_SPEED 0.25

class Enemy : public Movable, public Modelable, public Observer
{
private:
    bool inMovement;
    
public:
    Enemy(C3DObject* _model, std::pair<double, double> _position);
    
    virtual void draw();
	
	void makeMovementInMap(Movement* movement, double deltaMove);

    virtual void notify();
    
    Movement* makeMovement(const Penguin &pengo);
	
	void die();
};
#endif
