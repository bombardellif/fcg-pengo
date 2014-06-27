#include "LinearMovement.h"

#include "GameController.h"
#include "Scenario.h"
#include <limits>
#include <utility>

extern GameController gameController;
extern Scenario scenario;

LinearMovement::LinearMovement(const Movable& object, std::pair<double, double> destiny):Movement(object, DEFAULT_SPEED), destiny(destiny)
{
}


void LinearMovement::move(){
    //If object has arrived at the destiny
    std::pair<double, double> destinyInGL = gameController.translateMapToGL(destiny);
    if (object.position.first - destinyInGL.first <= std::numeric_limits<double>::round_error()
            && object.position.second - destinyInGL.second <= std::numeric_limits<double>::round_error()){
        ready = true;
    }else{
        //If it has not finished moving yet, keep trying
        std::pair<int, int> nextPos = object.getNewPosition<int>(1);
        //Colision?
        if (!scenario.outOfMap(nextPos) && scenario.map[nextPos.first][nextPos.second] != NULL){
            //Colision Occurred
            gameController.takeActionToColision(object, nextPos);
        }else{
            //Normal exection, keep moving
            object.position = object.getNewPosition<double>(1);
        }
    }

}