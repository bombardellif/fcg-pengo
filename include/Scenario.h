#ifndef SCENARIO_H
#define SCENARIO_H

#include <string>

#include "Modelable.h"

#define SCENARIO_MAP_SIZE 15
#define SCENARIO_MAP_FILENAME "map.bmp"
#define SCENARIO_MAP_COLOR_IMBLOCK 0x000000FF
#define SCENARIO_MAP_COLOR_BLOCK 0x0000FF00
#define SCENARIO_IMBLOCK_FILENAME "al.obj"
#define SCENARIO_BLOCK_FILENAME "al.obj"

class Scenario
{
private:
    float backgrundColor[4];
    
    std::string resourceFolder;
    
    void initTexture();
    
    void initMap();
    
    void initLight();
    
public:
	C3DObject* map[SCENARIO_MAP_SIZE][SCENARIO_MAP_SIZE];

	int cameraState;

	Scenario(std::string _resourceFolder);

	void render();

	void init();

	void updateWindow(int windowWidth, int windowHeight);

};
#endif
