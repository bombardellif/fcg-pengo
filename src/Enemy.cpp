#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "Enemy.h"
#include "Modelable.h"
#include "Movement.h"
#include "GameController.h"
#include "LinearMovement.h"
#include "AngularMovement.h"
#include "utils.h"

extern GameController gameController;

Enemy::Enemy(C3DObject* _model, std::pair<double, double> _position)
:Movable(_position, 3*M_PI_2)
,Modelable(_model)
,inMovement(false)
{
}

void Enemy::draw()
{
    glTranslatef((GLfloat)position.first, 1.0, (GLfloat)position.second);
    glRotatef(radToDegree(direction), 0.0, 1.0, 0.0);
    Modelable::draw();
}

void Enemy::notify()
{
    this->inMovement = false;
}

Movement* Enemy::makeMovement(const Penguin& pengo)
{
    Movement* newMove = NULL;
    if (!this->inMovement) {
        
        if (distanceBetweenPoints(pengo.position, this->position) < 4.0) {
            
            //newMove = new LinearMovement(this);
        } else {
            
            // Random movement, first choose between a walk or a turn
            if (std::rand() % 2) {
                // Turn - Left or right
                switch (std::rand() % 2) {
                    case 0:
                
                        newMove = new AngularMovement(this, this->getNewDirection(M_PI_2), false);        
                    break;
                    default:
                        
                        newMove = new AngularMovement(this, this->getNewDirection(-M_PI_2), true);
                }
            } else {
                // Walk - Forward or backward
                
                switch (std::rand() % 2) {
                    case 0:
                        
                        newMove = new LinearMovement(this, this->getNewPosition<int>(1));
                    break;
                    default:
                        
                        newMove = new LinearMovement(this, this->getNewPosition<int>(-1));
                }
            }
            
            newMove->addObserver(this);
            this->inMovement = true;
        }
        
    }
    
    return newMove;
}

