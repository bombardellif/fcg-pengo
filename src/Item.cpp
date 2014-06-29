#include "Item.h"

Item::Item(C3DObject* model, std::pair<double, double> position):
Movable(position),
Modelable(model)
{
}

void Item::draw()
{
    glTranslatef((GLfloat)position.first, 1.0, (GLfloat)position.second);
    glScalef(0.5, 0.5, 0.5);
    this->model->Draw(SMOOTH_MATERIAL);
}