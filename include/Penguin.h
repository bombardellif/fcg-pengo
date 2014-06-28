#ifndef PENGUIN_H
#define PENGUIN_H

#include <utility>
#include <vector>
#include "Movable.h"
#include "3DObject.h"
#include "Modelable.h"

class Penguin : public Movable, public Modelable
{    
public:
    Penguin(C3DObject* _model, std::pair<double, double> _position);
    
    virtual void draw();
    
    std::vector<double> getEyesPosition();
    
    std::vector<double> getFocusPosition();
};
#endif
