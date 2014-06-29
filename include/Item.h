#ifndef ITEM_H
#define ITEM_H

#include "Movable.h"
#include "Modelable.h"

class Item : public Movable, public Modelable
{
public:
	Item(C3DObject* model, std::pair<double, double> position);
	
	void takeActionToColision(Movement* movement, double deltaMove){}
	
	void draw(){}
};
#endif
