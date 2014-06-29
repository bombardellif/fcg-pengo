#ifndef MODELABLE_H
#define MODELABLE_H

#include "3DObject.h"
#define MODELABLE_OFFSET_DIRECAO_MODELO M_PI_2

class Modelable
{
protected:
    C3DObject* model;
public:
    Modelable(C3DObject* _model);
    
    virtual ~Modelable();
    
	virtual void draw();

};
#endif
