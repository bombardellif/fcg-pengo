#include "Modelable.h"
#include "3DObject.h"

Modelable::Modelable(C3DObject* _model)
:model(_model)
{
}
    
Modelable::~Modelable()
{
    if (this->model)
        free(this->model);
}

void Modelable::draw()
{
    this->model->Draw(SMOOTH_MATERIAL_TEXTURE);
}
