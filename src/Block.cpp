#include "Block.h"
#include "Modelable.h"
#include "Scenario.h"

extern Scenario scenario;

Block::Block(C3DObject* _model, std::pair<double, double> _position, Item item, bool mobile)
:Movable(_position),
Modelable(_model),
mobile(mobile)
{
}

void Block::draw()
{
	glTranslatef((GLfloat)position.first, 1.0, (GLfloat)position.second);
    glScalef(0.5, 0.5, 0.5);
    Modelable::draw();
}

void Block::takeActionToColision(Movement* movement, std::pair<int, int> desiredPosition)
{
	if (scenario.outOfMap(desiredPosition)){
		movement->ready = true;
	}
}


void Block::conceive()
{
}

void Block::materialize()
{
}
