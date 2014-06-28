#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "Enemy.h"
#include "Modelable.h"
#include "Movement.h"
#include "GameController.h"
#include "LinearMovement.h"
#include "AngularMovement.h"
#include "utils.h"
#include "Scenario.h"

extern Scenario scenario;

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
    glScalef(0.75, 0.75, 0.75);
    glRotatef(radToDegree(this->direction + MODELABLE_OFFSET_DIRECAO_MODELO), 0.0, 1.0, 0.0);
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
        
        if (distanceBetweenPoints(pengo.position, this->position) < ENEMY_DISTANCE_LOOK_PENGUIN && pengo.position != this->position) {
            // As it is near Pengo, go after him
            
            // unitary vectors in the axis
            std::pair<double, double> vecUniX(1.0, 0.0);
            std::pair<double, double> vecUniZ(0.0, 1.0);
            std::pair<double, double> nullV(0.0, 0.0);
            
            // project the vector that goes from this enemy to pengo in the axis X and Z
            std::pair<double, double> vectorToPengo = makeVector2(this->position, pengo.position);
            // Get the vector of the current direction of the enemy
            std::pair<double, double> vectorNextStep = makeVector2(this->position, this->getNewPosition<int>(1));
            // Get the cossin of the angle between vectorToPengo and vectorNextStep
            double cosOfTheta = (vectorToPengo * vectorNextStep) / (module(vectorToPengo) * module(vectorNextStep));
            
            // If the pengo is forward the enemy, then just walk
            if (cosOfTheta > COS_PI_4) {
                
                newMove = new LinearMovement(this, this->getNewPosition<int>(1), true, ENEMEY_SPEED);
            } else {
            // Else, then have to turn
                
                if (vectorToPengo.first < 0) {
                    newMove = new AngularMovement(this, this->getNewDirection(M_PI_2), false, ENEMEY_SPEED);
                } else {
                    newMove = new AngularMovement(this, this->getNewDirection(-M_PI_2), true, ENEMEY_SPEED);
                }
            }
        } else {
            // Random movement, first choose between a walk or a turn
            if (std::rand() % 2) {
                // Turn - Left or right
                switch (std::rand() % 2) {
                    case 0:
                
                        newMove = new AngularMovement(this, this->getNewDirection(M_PI_2), false, ENEMEY_SPEED);        
                    break;
                    default:
                        
                        newMove = new AngularMovement(this, this->getNewDirection(-M_PI_2), true, ENEMEY_SPEED);
                }
            } else {
                // Walk - Forward or backward
                
                switch (std::rand() % 2) {
                    case 0:
                        
                        newMove = new LinearMovement(this, this->getNewPosition<int>(1), true, ENEMEY_SPEED);
                    break;
                    default:
                        
                        newMove = new LinearMovement(this, this->getNewPosition<int>(-1), false, ENEMEY_SPEED);
                }
            }
            
        }
        
        newMove->addObserver(this);
        this->inMovement = true;
    }
    
    return newMove;
}

void Enemy::takeActionToColision(Movement* movement, std::pair<int, int> desiredPosition)
{
	if (scenario.outOfMap(desiredPosition)){
		movement->ready = false;
	}
}
