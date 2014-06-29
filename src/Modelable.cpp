#include "Modelable.h"
#include "3DObject.h"
#include <iostream>

Modelable::Modelable(C3DObject* _model)
:model(_model)
{
}
    
Modelable::~Modelable()
{
    if (this->model)
		delete (this->model);
}

void Modelable::draw()
{
    this->model->Draw(SMOOTH_MATERIAL_TEXTURE);
}
