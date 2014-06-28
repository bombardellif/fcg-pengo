#include "Enemy.h"
#include "Modelable.h"

Enemy::Enemy(C3DObject* _model, std::pair<double, double> _position)
:Movable(_position)
,Modelable(_model)
{
}

void Enemy::draw()
{
    glTranslatef((GLfloat)position.first, 1.0, (GLfloat)position.second);
    Modelable::draw();
}

