#ifndef BLOCK_H
#define BLOCK_H

#include "Movable.h"
#include "3DObject.h"
#include "Item.h"

class Block : public Movable
{
private:
	C3DObject model;

public:
	Item item;

	bool mobile;


public:
	Block(Item item, bool mobile);

	void conceive();

	void materialize();

};
#endif
