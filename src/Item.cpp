#include "Item.h"
#include "Scenario.h"
#include "GameController.h"
#include "utils.h"

#include <iostream>
#include <cassert>

extern Scenario scenario;
extern GameController gameController;

Item::Item(C3DObject* model, std::pair<double, double> position, int kind):
Movable(position),
Modelable(model),
kind(kind)
{
}

void Item::draw(){
	glTranslatef((GLfloat)position.first, 0.5, (GLfloat)position.second);
    glScalef(0.5, 0.5, 0.5);
    glRotatef(radToDegree(this->direction + MODELABLE_OFFSET_DIRECAO_MODELO), 0.0, 1.0, 0.0);
    this->model->Draw(SMOOTH_MATERIAL);
}

void Item::die(){
	std::cout <<"die"<< (int)position.second <<","<<(int)position.first<<std::endl;
	scenario.map[(int)position.second][(int)position.first] = NULL;
}

void Item::actOnGame(){
	if (kind == ITEM_KIND_PLUS_CONCEPTION){
		gameController.maxConceivingBlocks++;
	}else if (kind == ITEM_KIND_PLUS_SPEED){
		gameController.penguinSpeed += 0.25;
        if (gameController.penguinSpeed > 1.0f)
            gameController.penguinSpeed = 1.0f;
		assert(gameController.penguinSpeed <= 1.0f);
	}else{
		assert(false); //Not implemented this kind. Should it? Then develop here
	}
	scenario.map[(int)position.second][(int)position.first] = NULL;
}
