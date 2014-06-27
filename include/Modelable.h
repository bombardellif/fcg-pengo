#ifndef MODELABLE_H
#define MODELABLE_H

#include "3DObject.h"

class Modelable
{
private:
    C3DObject* model;
public:
    Modelable(C3DObject* _model);
    
    virtual ~Modelable();
    
	virtual void draw();

};
#endif
