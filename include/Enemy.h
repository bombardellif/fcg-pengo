#ifndef ENEMY_H
#define ENEMY_H

#include "Movable.h"
#include "3DObject.h"
#include "Modelable.h"
#include "Movement.h"
#include "Penguin.h"
#include "Observable.h"

class Enemy : public Movable, public Modelable, public Observer
{
private:
	double direction;
    
    bool inMovement;
    
public:
    Enemy(C3DObject* _model, std::pair<double, double> _position);
    
    virtual void draw();

    virtual void notify();
    
    Movement* makeMovement(const Penguin &pengo);
};
#endif
