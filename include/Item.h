#ifndef ITEM_H
#define ITEM_H

#include "Movable.h"
#include "Modelable.h"

#define ITEM_KIND_PLUS_CONCEPTION 1
#define ITEM_KIND_PLUS_SPEED 2

class Item : public Movable, public Modelable
{
public:
	int kind;
	
	Item(C3DObject* model, std::pair<double, double> position, int kind);
	
	void makeMovementInMap(Movement* movement, double deltaMove){}
	
	virtual void draw();
	
	void die();
	
	void actOnGame();
};
#endif
