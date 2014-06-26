#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Movable.h"
#include "C3DObject.h"
#include "Item.h"

class Block : public Movable
{
private:
	C3DObject model;

public:
	Item item;

	boolean mobile;


public:
	void Block(Item item, boolean mobile);

	void conceive();

	void materialize();

};
#endif
