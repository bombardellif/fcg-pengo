#ifndef SCENARIO_H
#define SCENARIO_H

#include "Modelable.h"

#define SCENARIO_MAP_SIZE 15

class Scenario
{
private:
    float backgrundColor[4];
    
public:
	Modelable* map[SCENARIO_MAP_SIZE][SCENARIO_MAP_SIZE];

	int cameraState;

	Scenario();

	void render();

	void init();

	void updateWindow(int windowWidth, int windowHeight);

};
#endif
