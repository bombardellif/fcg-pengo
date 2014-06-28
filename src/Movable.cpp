#include "Movable.h"

#include <assert.h>
#include <cmath>
#include <limits>
#include <iostream>

Movable::Movable(std::pair<double, double> _position)
:position(_position)
{
}

Movable::Movable(std::pair<double, double> _position, double _direction)
:position(_position),
direction(_direction)
{
}

Movable::~Movable() {

}


DiscreteDirection Movable::getDiscreteDirection(){

    assert(direction >= 0.0);
	assert((direction - 2*M_PI) <= std::numeric_limits<double>::epsilon());

    if (direction > M_PI/4 && direction <= 3*M_PI/4)
        return UP;
    else if (direction > 3*M_PI/4 && direction <= 5*M_PI/4)
        return LEFT;
    else if (direction > 5*M_PI/4 && direction <= 7*M_PI/4)
        return DOWN;
    else
        return RIGHT;
}

/**
 * Retornar a nova posição (de mapa) deste objeto, dado uma distância que será percorrida em linha por este objeto.
 * Verifica a direção atual do objeto e calcula a posição final dele após percorrer a distância "distance".
 * @param distance Distância percorrida por this em linha na direção atual dele. Cada unidade de distância é uma posição do mapa
 * @return Nova posição do objeto após percorrer "distance" em linha reta na direção atual
 * @see Movable::getDiscreteDirection
 */
template<typename T> std::pair<T, T> Movable::getNewPosition(T distance){

    std::pair<T, T> newPosition = position;

    if (getDiscreteDirection() == UP)
        newPosition.second -= distance;
    else if (getDiscreteDirection() == RIGHT)
        newPosition.first += distance;
    else if (getDiscreteDirection() == DOWN)
            newPosition.second += distance;
    else if (getDiscreteDirection() == LEFT)
            newPosition.first -= distance;
    else
        assert(false); //Shall never happen

    return newPosition;
}

template std::pair<int, int> Movable::getNewPosition<int>(int distance);
template std::pair<double, double> Movable::getNewPosition<double>(double distance);

/**
 * Return the suposed next position of this object. Evaluating the discrete direction
 * and the distance intended to move, the function return the new position discrete position.
 * @param distance Distance performed, can be negative
 * @return the discrete new position that this object would occupy
 * @see Movable::getDiscreteDirection, Movable::getNewPosition
 */
std::pair<int, int> Movable::getNextLinearPosition(double distance){

    std::pair<double, double> newPosition = getNewPosition<double>(distance);
	
	//If the movement is rightwards or downwards, then take the ceil as next discrete position
	if ((getDiscreteDirection() == RIGHT && distance > 0) ||
			(getDiscreteDirection() == DOWN && distance > 0) ||
			(getDiscreteDirection() == LEFT && distance < 0) ||
			(getDiscreteDirection() == UP && distance < 0)){
		
		std::cout <<"CEILL*********"<< newPosition.first <<","<<newPosition.second<< std::endl;
		newPosition.first = newPosition.first < 0 ? -ceil(fabs(newPosition.first)) : ceil(newPosition.first);
		newPosition.second = newPosition.second < 0 ? -ceil(fabs(newPosition.second)) : ceil(newPosition.second);
	}else{
		//Otherwise it is going upwards or leftwards, newPosition is less than current. Use then floor
		std::cout <<"FLOOR*********"<< newPosition.first <<","<<newPosition.second<< std::endl;
		newPosition.first = newPosition.first < 0 ? -ceil(fabs(newPosition.first)) : floor(newPosition.first);
		newPosition.second = newPosition.second < 0 ? -ceil(fabs(newPosition.second)) : floor(newPosition.second);
	}
	
    return newPosition;
}

/**
 * Return the new direction (related to the map) of this object, given theta (in rad) around its own center.
 * @param theta Quantity of rotation to add to this direction. Must be in rad.
 * @return New direction of this object. Doesn't modify it.
 */
double Movable::getNewDirection(double theta){

    double newDirection = direction;
	
    newDirection += theta;

    //Normalize newDirection between 0 and 2PI (inclusive both)
    //Take the fractional part of the division by 2PI and multiply it by 2*PI
    double intPart; //not used
    newDirection = 2*M_PI * modf(newDirection/(2*M_PI), &intPart);
    // |newDirection| here is surely less or equal than 2*PI
    assert(fabs(newDirection) <= 2*M_PI);
    
    //Make newDirection positive, but representing the same angle as before
    if (newDirection < 0){
        newDirection = 2*M_PI + newDirection;
    }
	
	assert(newDirection >= 0.0);
	assert((newDirection - 2*M_PI) <= std::numeric_limits<double>::epsilon());

    return newDirection;
}