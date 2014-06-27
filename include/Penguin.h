#ifndef PENGUIN_H
#define PENGUIN_H

#include "Movable.h"
#include "3DObject.h"
#include "Modelable.h"

class Penguin : public Movable, public Modelable
{
private:
	double direction;
    
public:
    Penguin(C3DObject* _model);
    
    virtual void draw();
};
#endif
