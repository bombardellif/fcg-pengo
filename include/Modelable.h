#ifndef MODELABLE_H
#define MODELABLE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "C3DObject.h"

class Modelable
{
public:
	virtual C3DObject getModel()=0;

};
#endif
