#ifndef BLOCK_H
#define BLOCK_H

#include "Movable.h"
#include "3DObject.h"
#include "Item.h"
#include "Modelable.h"

class Block : public Movable, public Modelable
{
public:
	Item item;

	bool mobile;


public:
	Block(C3DObject* _model, Item item, bool mobile);

    virtual void draw();
    
	void conceive();

	void materialize();

};
#endif
