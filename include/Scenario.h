#ifndef SCENARIO_H
#define SCENARIO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Modelable.h"

class Scenario
{
public:
	Modelable map[15][15];

	int cameraState;


public:
	void Cenario();

	void render();

	void init();

	void updateWindow();

};
#endif
