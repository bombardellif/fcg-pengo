#ifndef BLOCK_H
#define BLOCK_H

#include "Movable.h"
#include "3DObject.h"
#include "Item.h"
#include "Modelable.h"

class Block : public Movable, public Modelable
{
public:
	Item* item;

	bool mobile;


public:
	Block(C3DObject* _model, std::pair<double, double> _position, Item* item, bool mobile);

    virtual void draw();
	
	void makeMovementInMap(Movement* movement, double deltaMove);
    
	void conceive();

	void materialize();
	
	void die();

};
#endif
