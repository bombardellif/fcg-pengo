#ifndef MODELABLE_H
#define MODELABLE_H

#include "3DObject.h"

class Modelable
{
public:
	virtual C3DObject getModel()=0;

};
#endif
