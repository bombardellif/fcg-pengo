#include "Enemy.h"
#include "Modelable.h"

Enemy::Enemy(C3DObject* _model)
:Modelable(_model)
{
}

void Enemy::draw()
{
    
    Modelable::draw();
}

