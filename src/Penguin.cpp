#include "Penguin.h"
#include "Modelable.h"
#include "GL/gl.h"

Penguin::Penguin(C3DObject* _model)
:Modelable(_model)
{
}

void Penguin::draw()
{
    glTranslatef(0.0, 1.0, 0.0);
    glScalef(0.75, 0.75, 0.75);
    Modelable::draw();
}
