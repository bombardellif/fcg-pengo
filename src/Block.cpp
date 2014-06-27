#include "Block.h"
#include "Modelable.h"

Block::Block(C3DObject* _model, Item item, bool mobile)
:Modelable(_model)
{
}

void Block::draw()
{
    glTranslatef(0.0, 1.0, 0.0);
    glScalef(0.5, 0.5, 0.5);
    Modelable::draw();
}


void Block::conceive()
{
}

void Block::materialize()
{
}
