#ifndef ENEMY_H
#define ENEMY_H

#include "Movable.h"
#include "3DObject.h"
#include "Modelable.h"

class Enemy : public Movable, public Modelable
{
private:
        //Enemy();
	double direction;
    
public:
    Enemy(C3DObject* _model, std::pair<double, double> _position);
    
    virtual void draw();
	
	void takeActionToColision(Movement* movement, std::pair<int, int> desiredPosition);

};
#endif
